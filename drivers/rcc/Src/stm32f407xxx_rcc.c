#include "stm32f407xxx_rcc.h"
#include "stm32f407xxx_flash.h"

static const uint16_t AHBPrescalerTable[16] =
{
    1, 1, 1, 1,
    1, 1, 1, 1,
    2, 4, 8, 16,
    64, 128, 256, 512
};

static const uint8_t APBPrescalerTable[8] =
{
    1, 1, 1, 1,
    2, 4, 8, 16
};


void RCC_EnableHSI(void)      //enable HSI clock
{
    RCC->CR |= RCC_CR_HSION;
    while(!(RCC->CR & RCC_CR_HSIRDY));    //wait until HSI is ready
}

void RCC_DisableHSI(void)     //disable HSI clock
{
    RCC->CR &= ~RCC_CR_HSION;
    while(RCC->CR & RCC_CR_HSIRDY);     //wait until HSI is disabled
}

void RCC_EnableHSE(void)       //enable HSE clock
{
    RCC->CR |= RCC_CR_HSEON;
    while(!(RCC->CR & RCC_CR_HSERDY));    //wait until HSE is ready
}

void RCC_DisableHSE(void)      //disable HSE clock
{
    RCC->CR &= ~RCC_CR_HSEON;
    while(RCC->CR & RCC_CR_HSERDY);     //wait until HSE is disabled
}

void RCC_EnablePLL(void)       //enable PLL clock
{
    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY));    //wait until PLL is ready
}

void RCC_DisablePLL(void)      //disable PLL clock
{
    RCC->CR &= ~RCC_CR_PLLON;
    while(RCC->CR & RCC_CR_PLLRDY);     //wait until PLL is disabled
}

static void RCC_Configure_Bus_Prescalers(RCC_Clock_Config_t *RCC_ClockConfig)
{
    //configure AHB, APB1 and APB2 bus prescalers in RCC_CFGR register
    RCC->CFGR &= ~RCC_CFGR_HPRE;   //clear AHB prescaler bits
    RCC->CFGR |= (RCC_ClockConfig->AHB_Prescaler << RCC_CFGR_HPRE_Pos);   //set AHB prescaler value

    RCC->CFGR &= ~RCC_CFGR_PPRE1;  //clear APB1 prescaler bits
    RCC->CFGR |= (RCC_ClockConfig->APB1_Prescaler << RCC_CFGR_PPRE1_Pos);  //set APB1 prescaler value

    RCC->CFGR &= ~RCC_CFGR_PPRE2;  //clear APB2 prescaler bits
    RCC->CFGR |= (RCC_ClockConfig->APB2_Prescaler << RCC_CFGR_PPRE2_Pos);  //set APB2 prescaler value
}

//System clock initialization function
//general flow for system clock configuration:
/*
1. Check the selected clock source (HSI, HSE or PLL) and enable it
2. If PLL is selected as clock source, configure PLLM, PLLN, PLLP
    and PLLQ values in RCC_PLLCFGR register and select PLL clock source (HSI or HSE)
3. Configure AHB, APB1 and APB2 bus prescalers in RCC_CFGR register
4. Configure flash latency according to system clock frequency
5. Select the desired clock source (HSI, HSE or PLL) as system clock source in RCC_CFGR register 
and wait until it is used as system clock source

*/
void RCC_Init(RCC_Clock_Config_t *RCC_ClockConfig)
{
    //check the clock source and enable it
    if(RCC_ClockConfig->ClockSource == RCC_SYSCLK_HSI)
    {
        //HSI is selected as system clock source
        RCC_EnableHSI();
        RCC_Configure_Bus_Prescalers(RCC_ClockConfig);   //configure AHB, APB1 and APB2 bus prescalers
        FLASH_SetLatency(RCC_ClockConfig->SYSCLK_MHZ);    //configure flash
        RCC->CFGR &= ~RCC_CFGR_SW;    //select HSI as system clock
        while((RCC->CFGR & RCC_CFGR_SWS) != (RCC_SYSCLK_STATUS_HSI << RCC_CFGR_SWS_Pos) );   //wait until HSI is used as system clock source
    }
    else if(RCC_ClockConfig->ClockSource == RCC_SYSCLK_HSE)
    {
        //HSE is selected as system clock source
        RCC_EnableHSE();
        RCC_Configure_Bus_Prescalers(RCC_ClockConfig);   //configure AHB, APB1 and APB2 bus prescalers
        FLASH_SetLatency(RCC_ClockConfig->SYSCLK_MHZ);   //configure flash
        RCC->CFGR &= ~RCC_CFGR_SW;    //clear SW bits
        RCC->CFGR |= RCC_SYSCLK_HSE;  //select HSE as system clock
        while((RCC->CFGR & RCC_CFGR_SWS) != (RCC_SYSCLK_STATUS_HSE << RCC_CFGR_SWS_Pos));   //wait until HSE is used as system clock source
    }
    else if(RCC_ClockConfig->ClockSource == RCC_SYSCLK_PLL)
    {
        RCC_DisablePLL();
        RCC_Configure_Bus_Prescalers(RCC_ClockConfig);   //configure AHB, APB1 and APB2 bus prescalers
        FLASH_SetLatency(RCC_ClockConfig->SYSCLK_MHZ);   //configure flash latency according to system clock frequency
        
        //configure PLLM, PLLN, PLLP and PLLQ values in RCC_PLLCFGR register
        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;
        RCC->PLLCFGR |= (RCC_ClockConfig->PLLConfig.PLLM << RCC_PLLCFGR_PLLM_Pos);

        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;
        RCC->PLLCFGR |= (RCC_ClockConfig->PLLConfig.PLLN << RCC_PLLCFGR_PLLN_Pos);

        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP;
        RCC->PLLCFGR |= (RCC_ClockConfig->PLLConfig.PLLP << RCC_PLLCFGR_PLLP_Pos);

        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQ;
        RCC->PLLCFGR |= (RCC_ClockConfig->PLLConfig.PLLQ << RCC_PLLCFGR_PLLQ_Pos);

       
        
        if(RCC_ClockConfig->PLLConfig.PLLSource == RCC_PLLSRC_HSI)
        {
            RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;    //select HSI as PLL clock source
            RCC_EnableHSI();
        }
        else if(RCC_ClockConfig->PLLConfig.PLLSource == RCC_PLLSRC_HSE)
        {
            RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;    
            RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;     //select HSE as PLL clock source
            RCC_EnableHSE();
        }
       
        RCC_EnablePLL();    //enable PLL after configuring PLL parameters and clock source

        RCC->CFGR &= ~RCC_CFGR_SW;    //clear SW bits
        RCC->CFGR |= RCC_SYSCLK_PLL;  //select PLL as system clock

        while((RCC->CFGR & RCC_CFGR_SWS) != (RCC_SYSCLK_STATUS_PLL << RCC_CFGR_SWS_Pos));   //wait until PLL is used as system clock source
    }
}


/*default*/

/*
===========================================================
Default configuration:
SYSCLK = 168 MHz

HSE      = 8 MHz
PLLM     = 8
PLLN     = 336
PLLP     = 2
PLLQ     = 7

VCO_IN   = 8 / 8     = 1 MHz
VCO_OUT  = 1 * 336   = 336 MHz
SYSCLK   = 336 / 2   = 168 MHz
USB_CLK  = 336 / 7   = 48 MHz

AHB  = 168 MHz
APB1 = 42 MHz
APB2 = 84 MHz
===========================================================
*/

void RCC_SetSystemClockTo168MHz(void)
{
    RCC_Clock_Config_t RCC_ClockConfig;

    RCC_ClockConfig.ClockSource = RCC_SYSCLK_PLL;

    RCC_ClockConfig.SYSCLK_MHZ = 168;

    /* PLL configuration */
    RCC_ClockConfig.PLLConfig.PLLSource = RCC_PLLSRC_HSE;
    RCC_ClockConfig.PLLConfig.PLLM      = 8;
    RCC_ClockConfig.PLLConfig.PLLN      = 336;
    RCC_ClockConfig.PLLConfig.PLLP      = RCC_PLLP_DIV2;
    RCC_ClockConfig.PLLConfig.PLLQ      = 7;

    /* Bus prescalers */
    RCC_ClockConfig.AHB_Prescaler  = RCC_AHB_PRESCALER_DIV1;
    RCC_ClockConfig.APB1_Prescaler = RCC_APB1_PRESCALER_DIV4;
    RCC_ClockConfig.APB2_Prescaler = RCC_APB2_PRESCALER_DIV2;

    RCC_Init(&RCC_ClockConfig);
}


/*
===========================================================
Default configuration:
SYSCLK = 84 MHz

HSE      = 8 MHz
PLLM     = 8
PLLN     = 336
PLLP     = 4
PLLQ     = 7

VCO_IN   = 8 / 8     = 1 MHz
VCO_OUT  = 1 * 336   = 336 MHz
SYSCLK   = 336 / 4   = 84 MHz

AHB  = 84 MHz
APB1 = 42 MHz
APB2 = 84 MHz
===========================================================
*/

void RCC_SetSystemClockTo84MHz(void)
{
    RCC_Clock_Config_t RCC_ClockConfig;

    RCC_ClockConfig.ClockSource = RCC_SYSCLK_PLL;

    RCC_ClockConfig.SYSCLK_MHZ = 84;

    /* PLL configuration */
    RCC_ClockConfig.PLLConfig.PLLSource = RCC_PLLSRC_HSE;
    RCC_ClockConfig.PLLConfig.PLLM      = 8;
    RCC_ClockConfig.PLLConfig.PLLN      = 336;
    RCC_ClockConfig.PLLConfig.PLLP      = RCC_PLLP_DIV4;
    RCC_ClockConfig.PLLConfig.PLLQ      = 7;

    /* Bus prescalers */
    RCC_ClockConfig.AHB_Prescaler  = RCC_AHB_PRESCALER_DIV1;
    RCC_ClockConfig.APB1_Prescaler = RCC_APB1_PRESCALER_DIV2;
    RCC_ClockConfig.APB2_Prescaler = RCC_APB2_PRESCALER_DIV1;

    RCC_Init(&RCC_ClockConfig);
}
/*function to get system clock frequency in Hz*/
uint32_t RCC_GetSYSCLKValue(void)
{
    uint32_t sysclk;
    uint32_t clk_src;

    clk_src = (RCC->CFGR >> RCC_CFGR_SWS_Pos) & 0x03U;

    switch(clk_src)
    {
        case RCC_SYSCLK_STATUS_HSI:
            sysclk = HSI_CLOCK;
            break;

        case RCC_SYSCLK_STATUS_HSE:
            sysclk = HSE_CLOCK;
            break;

        case RCC_SYSCLK_STATUS_PLL:
        {
            uint32_t pllsrc;
            uint32_t pllm;
            uint32_t plln;
            uint32_t pllp;
            uint32_t vco_in;
            uint32_t vco_out;

            pllsrc = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);

            pllm = (RCC->PLLCFGR & RCC_PLLCFGR_PLLM)
                    >> RCC_PLLCFGR_PLLM_Pos;

            plln = (RCC->PLLCFGR & RCC_PLLCFGR_PLLN)
                    >> RCC_PLLCFGR_PLLN_Pos;

            pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP)
                    >> RCC_PLLCFGR_PLLP_Pos) + 1) * 2;

            if(pllsrc)
            {
                vco_in = HSE_CLOCK / pllm;
            }
            else
            {
                vco_in = HSI_CLOCK / pllm;
            }

            vco_out = vco_in * plln;

            sysclk = vco_out / pllp;

            break;
        }

        default:
            sysclk = HSI_CLOCK;
            break;
    }

    return sysclk;
}

uint32_t RCC_GetHCLKValue(void)
{
    uint32_t hpre;
    uint32_t hclk;

    hpre = (RCC->CFGR & RCC_CFGR_HPRE)
            >> RCC_CFGR_HPRE_Pos;

    hclk = RCC_GetSYSCLKValue() /
            AHBPrescalerTable[hpre];

    return hclk;
}

uint32_t RCC_GetPCLK1Value(void)
{
    uint32_t ppre1;
    uint32_t pclk1;

    ppre1 = (RCC->CFGR & RCC_CFGR_PPRE1)
            >> RCC_CFGR_PPRE1_Pos;

    pclk1 = RCC_GetHCLKValue() /
            APBPrescalerTable[ppre1];

    return pclk1;
}

uint32_t RCC_GetPCLK2Value(void)
{
    uint32_t ppre2;
    uint32_t pclk2;

    ppre2 = (RCC->CFGR & RCC_CFGR_PPRE2)
            >> RCC_CFGR_PPRE2_Pos;

    pclk2 = RCC_GetHCLKValue() /
            APBPrescalerTable[ppre2];

    return pclk2;
}
