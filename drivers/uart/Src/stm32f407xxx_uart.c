#include "stm32f407xxx_uart.h"
#include "stm32f407xxx_rcc.h"

#define USART_MASK_2BITS                       3U

#define USART_CR2_STOP_Pos                     12U

static void USART_Set_Baudrate(USART_Handle_t *huart)
{
    uint32_t PCLK;
    uint32_t USART_DIV;
    uint32_t DIV_Mantissa;
    uint32_t DIV_Fraction;

    if(huart->Instance == USART1 || huart->Instance == USART6)
    {
        PCLK = RCC_GetPCLK2Value();
    }
    else
    {
        PCLK = RCC_GetPCLK1Value();
    }

    if(huart->Config->OverSampling == USART_OVERSAMPLING_8)
    {
        USART_DIV = (25*PCLK)/(2*(huart->Config->Baudrate));
        DIV_Mantissa = USART_DIV / 100;
        DIV_Fraction = USART_DIV - (DIV_Mantissa * 100);
        DIV_Fraction = ((DIV_Fraction * 8) + 50) / 100;   //rounding
        huart->Instance->BRR = (DIV_Mantissa << 4) | (DIV_Fraction & 0x07U);
    }
    else
    {
        USART_DIV = (25*PCLK)/(4*(huart->Config->Baudrate));
        DIV_Mantissa = USART_DIV / 100;
        DIV_Fraction = USART_DIV - (DIV_Mantissa * 100);
        DIV_Fraction = ((DIV_Fraction * 16) + 50) / 100;   //rounding
        huart->Instance->BRR = (DIV_Mantissa << 4) | (DIV_Fraction & 0x0FU);
    }
}


/*
    Note: USART1 and USART6 are connected to APB2 bus, others are connected to APB1 bus
    APB2 max freqency 84Mhz, APB1 max frequency 42MHz
    Baudrate = fCK / (8 * (2 - OVER8) * USARTDIV)
    where USARTDIV = fCK / (16 * Baudrate) when OVER8 = 0
          USARTDIV = fCK / (8 * Baudrate) when OVER8 = 1
*/

/*< USART initialization*/
void USART_Init(USART_Handle_t *huart)
{   
    USART_Config_t *config = huart->Config;

    //disable USART before configuration
    huart->Instance->CR1 &= ~USART_CR1_UE;

    /*< Configure uart frame*/
    //1. Word Length
    if(config->WordLength == USART_WORD_LENGTH_8BITS)
    {
        huart->Instance->CR1 &= ~USART_CR1_M;
    }
    else
    {
        huart->Instance->CR1 |= USART_CR1_M;
    }
    // 2. parity
    if(config->Parity == USART_PARITY_NONE)
    {
        huart->Instance->CR1 &= ~USART_CR1_PCE;
    }
    else if(config->Parity == USART_PARITY_EVEN)
    {
        huart->Instance->CR1 |= USART_CR1_PCE;  //enable parity check
        huart->Instance->CR1 &= ~USART_CR1_PS;
    }
    else
    {
        huart->Instance->CR1 |= USART_CR1_PCE; //enable parity check
        huart->Instance->CR1 |= USART_CR1_PS;   
    }
    //3. stop bits
    huart->Instance->CR2 &= ~(USART_MASK_2BITS << USART_CR2_STOP_Pos);
    huart->Instance->CR2 |= (config->StopBits  << USART_CR2_STOP_Pos);

    /*< Select oversampling*/
    if(config->OverSampling == USART_OVERSAMPLING_8)
    {
        huart->Instance->CR1 |= USART_CR1_OVER8;
    }
    else
    {
        huart->Instance->CR1 &= ~USART_CR1_OVER8;
    }

    /*< Configure USART mode */
    if(config->Mode == USART_MODE_TX)
    {
        huart->Instance->CR1 &= ~USART_CR1_RE;
        huart->Instance->CR1 |=  USART_CR1_TE;
    }
    else if(config->Mode == USART_MODE_RX)
    {
        huart->Instance->CR1 &= ~USART_CR1_TE;
        huart->Instance->CR1 |= USART_CR1_RE;
    }
    else
    {
        huart->Instance->CR1 &= ~(USART_CR1_TE | USART_CR1_RE);
        huart->Instance->CR1 |= USART_CR1_TE | USART_CR1_RE;
    }

    
    /*<Configure Baud Rate*/
    USART_Set_Baudrate(huart);
    //Enable USART peripheral
    huart->Instance->CR1 |= USART_CR1_UE;
}

/*
    Flow of USART transmission:
    1. Check if USART is ready for transmission by checking TXE bit in SR register
    2. If TXE is set, write the data to be transmitted in DR register
    3. Repeat steps 1 and 2 until all data is transmitted
*/
void USART_Transmit_Polling(USART_Handle_t *huart,uint8_t *pTxBuffer,uint32_t Len)
{
    for(uint32_t i = 0 ; i < Len ; i++)
    {
        while(!(huart->Instance->SR & USART_SR_TXE))
        {
            //wait until TXE is set
        }
        huart->Instance->DR = pTxBuffer[i];
        while(!(huart->Instance->SR & USART_SR_TC));
    }
}
/*
    Flow of USART reception:
    1. Check if USART has received data by checking RXNE bit in SR register
    2. If RXNE is set, read the received data from DR register
    3. Repeat steps 1 and 2 until all data is received
*/
void USART_Receive_Polling(USART_Handle_t *huart,uint8_t *pRxBuffer, uint32_t Len)
{
    for(uint32_t i = 0 ; i < Len ; i++)
    {
        while(!(huart->Instance->SR & USART_SR_RXNE))
        {
            //wait until RXNE is set
        }
        pRxBuffer[i] = huart->Instance->DR;
    }
}
/*
    Flow of USART transmission in interrupt mode:
    1. Enable the USART transmit interrupt by setting the TXEIE bit in CR1 register
    2. In the USART IRQ handler, check if the TXE flag is set in SR register
    3. If TXE is set, write the data to be transmitted in DR register and clear the TXE flag
    4. Repeat steps 2 and 3 until all data is transmitted
    Flow of USART reception in interrupt mode:
    1. Enable the USART receive interrupt by setting the RXNEIE bit in CR1 register
    2. In the USART IRQ handler, check if the RXNE flag is set in SR register
    3. If RXNE is set, read the received data from DR register and clear the RXNE flag
    4. Repeat steps 2 and 3 until all data is received
*/
void USART_Transmit_IT(USART_Handle_t *huart,uint8_t *pTxBuffer,uint32_t Len)
{   
    if(huart->TxState != USART_TX_READY)
    {
        return;
    }
    huart->TxState = USART_TX_BUSY;
    //assign the data to be transmitted to the handle structure
    huart->pTxBuffer = pTxBuffer;
    huart->TxLen = Len;
    //enable USART transmit interrupt
    huart->Instance->CR1 |= USART_CR1_TXEIE;
}
void USART_Receive_IT(USART_Handle_t *huart,uint8_t *pRxBuffer, uint32_t Len)
{
    if(huart->RxState != USART_RX_READY)
    {
        return;
    }
    huart->RxState = USART_RX_BUSY;
    //assign the buffer to store received data to the handle structure
    huart->pRxBuffer = pRxBuffer;
    huart->RxLen = Len;
    //enable USART receive interrupt
    huart->Instance->CR1 |= USART_CR1_RXNEIE;
}
/*
    Note: The USART IRQ handler should be implemented in the application code and should call the USART_IRQHandler function
    defined in the USART driver to handle the interrupt events. The USART_IRQHandler function will check the interrupt flags
    and perform the necessary actions based on the type of interrupt (e.g., transmission complete, reception complete, etc.).
*/
void USART_IRQHandler(USART_Handle_t *huart)
{
    //check if the interrupt is caused by TXE flag
    if((huart->Instance->SR & USART_SR_TXE) && (huart->Instance->CR1 & USART_CR1_TXEIE))
    {
        if(huart->TxState == USART_TX_BUSY)
        {
            huart->Instance->DR = *(huart->pTxBuffer++);
            huart->TxLen--;
            if(huart->TxLen == 0)
            {
                //transmission complete, disable TXE interrupt and enable TC interrupt
                huart->Instance->CR1 &= ~USART_CR1_TXEIE;
                huart->Instance->CR1 |= USART_CR1_TCIE;
            }
        }
    }
    //check if the interrupt is caused by TC flag
    else if((huart->Instance->SR & USART_SR_TC) && (huart->Instance->CR1 & USART_CR1_TCIE))
    {
        huart->Instance->CR1 &= ~USART_CR1_TCIE;//clear TC interrupt enable bit
        huart->TxState = USART_TX_READY;
        //call the transmission complete callback function
        if(huart->TxCompleteCallback)
        {
            huart->TxCompleteCallback();
        }
    }
    //check if the interrupt is caused by RXNE flag
    else if((huart->Instance->SR & USART_SR_RXNE) && (huart->Instance->CR1 & USART_CR1_RXNEIE))
    {
        if(huart->RxState == USART_RX_BUSY)
        {
            *huart->pRxBuffer = huart->Instance->DR;
            huart->pRxBuffer++;
            huart->RxLen--;
            if(huart->RxLen == 0)
            {
                //reception complete, disable RXNE interrupt
                huart->Instance->CR1 &= ~USART_CR1_RXNEIE;
                huart->RxState = USART_RX_READY;
                //call the reception complete callback function
                if(huart->RxCompleteCallback)
                {
                    huart->RxCompleteCallback();
                }
            }
        }
    }
}        