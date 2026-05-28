#include "stm32f407xxx_i2c.h"
#include "stm32f407xxx_rcc.h"
#include "stm32f407xxx_systick.h"

#define NULL ((void*)0)
#define MHz  1000000U

#define MAX_RISE_TIME_SM 1000U   //in nanoseconds
#define MAX_RISE_TIME_FM 300U    //in nanoseconds

I2C_Handle_t hi2c1;
I2C_Handle_t hi2c2;
I2C_Handle_t hi2c3;

static uint32_t tickstart = 0U;

I2C_Status_t I2C_Start(I2C_Handle_t *hi2c)
{
    hi2c->Instance->CR1 |= I2C_CR1_START;    //generate start condition
    return I2C_OK;
}

I2C_Status_t I2C_Stop(I2C_Handle_t *hi2c)
{
    hi2c->Instance->CR1 |= I2C_CR1_STOP;     //generate stop condition
    return I2C_OK;
}


/* I2C Initialization Function */
/*
    Calculate CCR 
    Standard mode (Sm = 0):
    CCR = Fpclk1 / (2 * I2C_ClockSpeed)
    TRISE = (1000 ns / Tclk1) + 1


    Fast mode (Sm = 1):
    If duty cycle = 0 (Tlow/Thigh = 2):
    CCR = Fpclk1 / (3 * I2C_ClockSpeed)

    If duty cycle = 1 (Tlow/Thigh = 16/9):
    CCR = Fpclk1 / (25 * I2C_ClockSpeed)
    TRISE = (300 ns / Tclk1) + 1

*/
I2C_Status_t I2C_Init(I2C_Handle_t *hi2c)
{
    if(hi2c == NULL)
    {
        return I2C_ERROR;
    }

    /*Disable I2C peripheral */
    hi2c->Instance->CR1 &= ~I2C_CR1_PE;

    /* Configure I2C_CR2 */
    uint32_t pclk1_freq = RCC_GetPCLK1Value()/MHz;
    hi2c->Instance->CR2 &= ~I2C_CR2_FREQ_Msk;
    hi2c->Instance->CR2 |= pclk1_freq;

    if(hi2c->Init.Mode == I2C_MODE_STANDARD)
    {
        hi2c->Instance->CCR &= ~I2C_CCR_FS;    //select standard mode
        uint32_t ccr_value = (RCC_GetPCLK1Value())/(2U*(hi2c->Init.ClockSpeed));//  PCLK1/(2*f_i2c)
        hi2c->Instance->CCR &= ~I2C_CCR_CCR_Msk;
        hi2c->Instance->CCR |= ccr_value;

        /*configure trise*/
        uint32_t trise_value = (MAX_RISE_TIME_SM / (1000000000U / RCC_GetPCLK1Value())) + 1;
        hi2c->Instance->TRISE &= ~I2C_TRISE_TRISE_Msk;
        hi2c->Instance->TRISE |= trise_value;

    }
    else if(hi2c->Init.Mode == I2C_MODE_FAST)
    {
        hi2c->Instance->CCR |= I2C_CCR_FS;    //select fast mode
        
        if(hi2c->Init.FastModeDutyCycle == I2C_DUTY_CYCLE_2)
        {
            //Tlow/Thigh = 2
            uint32_t ccr_value = (RCC_GetPCLK1Value())/(3U*(hi2c->Init.ClockSpeed));//  PCLK1/(3*f_i2c)
            hi2c->Instance->CCR &= ~I2C_CCR_CCR_Msk;
            hi2c->Instance->CCR |= ccr_value;
            hi2c->Instance->CCR &= ~I2C_CCR_FS;    //clear FS bit to select duty cycle 2
        }
        else
        {
            //Tlow/Thigh = 16/9
            uint32_t ccr_value = (RCC_GetPCLK1Value())/(25U*(hi2c->Init.ClockSpeed));//  PCLK1/(25*f_i2c)
            hi2c->Instance->CCR &= ~I2C_CCR_CCR_Msk;
            hi2c->Instance->CCR |= ccr_value;
            hi2c->Instance->CCR |= I2C_CCR_FS;    //set FS bit to select duty cycle 16/9
        }

        /*configure trise*/
        uint32_t trise_value = (MAX_RISE_TIME_FM / (1000000000U / RCC_GetPCLK1Value())) + 1;
        hi2c->Instance->TRISE &= ~I2C_TRISE_TRISE_Msk;
        hi2c->Instance->TRISE |= trise_value;
    }
    else
    {
        return I2C_ERROR;
    }

    hi2c->Instance->CR1 |= I2C_CR1_PE;     //enable I2C peripheral

    return I2C_OK;
}

/*> I2C Master Transmit Function */
I2C_Status_t I2C_Master_Transmit(I2C_Handle_t *hi2c, uint8_t DevAddress,
                                 uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    if(hi2c == NULL || pData == NULL || Size == 0)
    {
        return I2C_ERROR;
    }

    if(hi2c->State != I2C_STATE_READY)
    {
        return I2C_BUSY;
    }

    hi2c->State = I2C_STATE_TX_BUSY;

    tickstart = SYSTICK_GetTick();

    //wait until start condition is generated (SB bit is set)
    while(!(hi2c->Instance->SR1 & I2C_SR1_SB))
    {
        if((SYSTICK_GetTick() - tickstart) > Timeout)
        {
            return I2C_TIMEOUT;
        }
    }
    //send slave address + R/W bit
    /*DevAddress = I2C address << 1 | R/W bit */
    hi2c->Instance->DR = (DevAddress << 1) | 0; //R/W bit = 0 for write

    /*wait until address is sent (ADDR bit is set)*/
    while(!(hi2c->Instance->SR1 & I2C_SR1_ADDR))
    {
        if((SYSTICK_GetTick() - tickstart) > Timeout)
        {
            return I2C_TIMEOUT;
        }
    }

    /*clear ADDR flag by reading SR1 and SR2 registers*/
    (void)hi2c->Instance->SR1;
    (void)hi2c->Instance->SR2;

    /*send data until all data is sent*/
    for (uint16_t i = 0; i < Size; i++)
    {
        while (!(hi2c->Instance->SR1 & I2C_SR1_TXE))
        {
            if ((SYSTICK_GetTick() - tickstart) > Timeout)
            {
                return I2C_TIMEOUT;
            }
        }

        hi2c->Instance->DR = pData[i];
        if(i == (Size - 1))
        {
            //wait until byte transfer finished (BTF bit is set) after sending last byte
            while (!(hi2c->Instance->SR1 & I2C_SR1_BTF))
            {
                if ((SYSTICK_GetTick() - tickstart) > Timeout)
                {
                    return I2C_TIMEOUT;
                }
            }
        }
    }
    hi2c->State = I2C_STATE_READY;
    return I2C_OK;
}  

/*> I2C Master Receive Function */
I2C_Status_t I2C_Master_Receive(I2C_Handle_t *hi2c, uint8_t DevAddress,
                                uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    if(hi2c == NULL || pData == NULL || Size == 0)
    {
        return I2C_ERROR;
    }

    if(hi2c->State != I2C_STATE_READY)
    {
        return I2C_BUSY;
    }

    hi2c->State = I2C_STATE_RX_BUSY;
    tickstart = SYSTICK_GetTick();

    /* wait SB */
    while(!(hi2c->Instance->SR1 & I2C_SR1_SB))
    {
        if((SYSTICK_GetTick() - tickstart) > Timeout)
        {
            return I2C_TIMEOUT;
        }
    }

    /* send slave address + read bit */
    hi2c->Instance->DR = (DevAddress << 1) | 1U; //R/W bit = 1 for read

    /* wait ADDR */
    while(!(hi2c->Instance->SR1 & I2C_SR1_ADDR))
    {
        if((SYSTICK_GetTick() - tickstart) > Timeout)
        {
            return I2C_TIMEOUT;
        }
    }

    /*================ SINGLE BYTE =================*/
    if(Size == 1U)
    {
        /* NACK next(received) byte */
        hi2c->Instance->CR1 &= ~I2C_CR1_ACK;

        /* clear ADDR */
        (void)hi2c->Instance->SR1;
        (void)hi2c->Instance->SR2;

        /* generate STOP */
        I2C_Stop(hi2c);

        /* wait RXNE */
        while(!(hi2c->Instance->SR1 & I2C_SR1_RXNE))
        {
            if((SYSTICK_GetTick() - tickstart) > Timeout)
            {
                return I2C_TIMEOUT;
            }
        }

        pData[0] = hi2c->Instance->DR;

        return I2C_OK;
    }

    /* enable ACK */
    hi2c->Instance->CR1 |= I2C_CR1_ACK;

    /* clear ADDR */
    (void)hi2c->Instance->SR1;
    (void)hi2c->Instance->SR2;

    for(uint16_t i = 0; i < Size; i++)
    {
        /*Last 3 byte: N-2 | N-1 | N   */
        if(i == (Size - 3U))
        {
            /*
                wait until:
                DR     = N-2
                SHIFT  = N-1
                BTF=1
            */
            while(!(hi2c->Instance->SR1 & I2C_SR1_BTF))
            {
                if((SYSTICK_GetTick() - tickstart) > Timeout)
                {
                    return I2C_TIMEOUT;
                }
            }

            /* NACK byte N */
            hi2c->Instance->CR1 &= ~I2C_CR1_ACK;

            /* read N-2 */
            pData[i++] = hi2c->Instance->DR;

            /* generate STOP */
            I2C_Stop(hi2c);

            /*
                now:
                DR    = N-1
                SHIFT = N
            */

            /* read N-1 */
            pData[i++] = hi2c->Instance->DR;

            /* wait until N moves into DR */
            while(!(hi2c->Instance->SR1 & I2C_SR1_RXNE))
            {
                if((SYSTICK_GetTick() - tickstart) > Timeout)
                {
                    return I2C_TIMEOUT;
                }
            }

            /* read N */
            pData[i] = hi2c->Instance->DR;

            break;
        }

        /* wait RXNE */
        while(!(hi2c->Instance->SR1 & I2C_SR1_RXNE))
        {
            if((SYSTICK_GetTick() - tickstart) > Timeout)
            {
                return I2C_TIMEOUT;
            }
        }

        pData[i] = hi2c->Instance->DR;
    }
    hi2c->State = I2C_STATE_READY;
    return I2C_OK;
}

/*
    * I2C Master Transmit Function with Interrupts
    * Note: This function only initiates the transmission. 
    * The actual data transfer will be handled in the I2C event interrupt handler.
*/
I2C_Status_t I2C_Master_Transmit_IT(I2C_Handle_t *hi2c, uint8_t DevAddress,
                                    uint8_t *pData, uint16_t Size)
{
    if(hi2c == NULL || pData == NULL || Size == 0)
    {
        return I2C_ERROR;
    }

    //Check state of I2C
    if(hi2c->State != I2C_STATE_READY)
    {
        return I2C_BUSY;
    }

    //Save context information in handler
    hi2c->pTxBuffer = pData;
    hi2c->TxLength = Size;
    hi2c->DevAddress = DevAddress;
    hi2c->TxCount = 0U;
    hi2c->State = I2C_STATE_TX_BUSY;

    /*>Enable Interrupts */
    hi2c->Instance->CR2 |= I2C_CR2_ITEVTEN;   //Event interrupt
    hi2c->Instance->CR2 |= I2C_CR2_ITERREN;   //Error interrupt
    /*Tranfer data in IRQhandler*/
    /*>Generate start condition to initiate communication */
    hi2c->Instance->CR1 |= I2C_CR1_START;    //generate start condition
}

void I2C_EV_IRQHandler(I2C_Handle_t *hi2c)
{
    if(hi2c->Instance->SR1 & I2C_SR1_SB)
    {
        if(hi2c->State == I2C_STATE_TX_BUSY)
        {
            /*Start condition generated, send device address */
            uint8_t DevAddress = hi2c->DevAddress << 1; //R/W bit = 0 for transmit
            hi2c->Instance->DR = DevAddress;
        }
        else if(hi2c->State == I2C_STATE_RX_BUSY)
        {
            /*Start condition generated, send device address with read bit set*/
            uint8_t DevAddress = (hi2c->DevAddress << 1) | 1U; //R/W bit = 1 for receive
            hi2c->Instance->DR = DevAddress;
        }
        
    }
    /*Address sent, wait for ADDR flag and clear it in order to move forward with data transmission*/
    if(hi2c->Instance->SR1 & I2C_SR1_ADDR)
    {
        /*Address sent, clear ADDR flag by reading SR1 and SR2*/
        (void)hi2c->Instance->SR1;
        (void)hi2c->Instance->SR2;

        /*Trigger for data transmission-> Enable ITBUFEN*/
        hi2c->Instance->CR2 |= I2C_CR2_ITBUFEN;

    }
}

void I2C_BUF_IRQHandler(I2C_Handle_t *hi2c)
{
    if(hi2c->State == I2C_STATE_TX_BUSY)        //Transmit data until all data is transmitted
    {
        if(hi2c->Instance->SR1 & I2C_SR1_TXE)
        {
            hi2c->Instance->DR = hi2c->pTxBuffer[hi2c->TxCount++];

            if(hi2c->TxCount == hi2c->TxLength)
            {
                tickstart = SYSTICK_GetTick();
                while(!(hi2c->Instance->SR1 & I2C_SR1_BTF))
                {
                    //wait until byte transfer finished (BTF bit is set) after sending last byte
                    if((SYSTICK_GetTick() - tickstart) > 1000U)
                    {
                        //timeout
                        break;
                    }
                }
                /*All data transmitted, generate stop condition*/
                I2C_Stop(hi2c);
                hi2c->State = I2C_STATE_READY;
                /*Disable ITBUFEN to prevent further interrupts until next transmission*/
                hi2c->Instance->CR2 &= ~I2C_CR2_ITBUFEN;
            }
        }
    }
    else if(hi2c->State == I2C_STATE_RX_BUSY)       //Receive data until all data is received
    {
        if(hi2c->Instance->SR1 & I2C_SR1_RXNE) 
        {
            hi2c->pRxBuffer[hi2c->RxCount++] = hi2c->Instance->DR;

            if(hi2c->RxCount == hi2c->RxLength)
            {
                /*All data received, generate stop condition*/
                I2C_Stop(hi2c);
                hi2c->State = I2C_STATE_READY;
            }
        }
    }
}
                        