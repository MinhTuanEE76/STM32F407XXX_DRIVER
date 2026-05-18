#include "stm32f407xxx_exti.h"
#include "stm32f407xxx_nvic.h"

#define EXTI_IRQ_NUMBER     7U

static void (*EXTI_CallbackTable[EXTI_LINE_NUMBER])(void) = {0};

static uint8_t IRQNumber_EXTI[EXTI_IRQ_NUMBER] = {
    IRQ_NO_EXTI0,
    IRQ_NO_EXTI1,
    IRQ_NO_EXTI2,
    IRQ_NO_EXTI3,
    IRQ_NO_EXTI4,
    IRQ_NO_EXTI9_5,
    IRQ_NO_EXTI15_10
};

/*< Exti set callback from user*/
void EXTI_SetCallback(uint16_t EXTI_LINEx, void (*callback)(void))
{
    for(uint8_t i = 0 ; i < EXTI_LINE_NUMBER ; i++)
    {
        if(EXTI_LINEx & (1U << i))
        {
            EXTI_CallbackTable[i] = callback;
            break;
        }
    }
}

void EXTI_Init(EXTI_Handle_t *hexti)
{
    /*< step1: configure EXTI paranmeter*/
    //unmask bit in IMR
    EXTI->IMR |= hexti->Config->Pin;
    //Unmask event request
    EXTI->EMR |= hexti->Config->Pin;
    //select trigger
    if(hexti->Config->Trigger == EXTI_TRIGGER_RISING)
    {
        EXTI->RTSR |= hexti->Config->Pin;
    }
    else if(hexti->Config->Trigger == EXTI_TRIGGER_FALLING)
    {
        EXTI->FTSR |= hexti->Config->Pin;
    }
    else
    {
        //BOTH
        EXTI->RTSR |= hexti->Config->Pin;
        EXTI->FTSR |= hexti->Config->Pin;
    }
    /*< step2 : select PORT SYSCFGR_EXTICR[n] */
    for(uint8_t i = 0 ; i < EXTI_LINE_NUMBER ; i++)
    {
        if(hexti->Config->Pin & (1U << i))
        {
            SYSCFG->EXTICR[i >> 2] &= ~(PIN_MASK_4BITS << (4*(i & 0x03U)));
            SYSCFG->EXTICR[i >> 2] |= hexti->Config->Port; 

            /*> Enable interrupt in NVIC controller*/
            if( (i >= 5) && (i <= 9))
            {
                NVIC_EnableIRQ(IRQNumber_EXTI[5]);
                NVIC_ClearPendingIRQ(IRQNumber_EXTI[5]);
                continue;
            }
            if( (i >= 10) && (i <= 15))
            {
                NVIC_EnableIRQ(IRQNumber_EXTI[7]);
                NVIC_ClearPendingIRQ(IRQNumber_EXTI[6]);
                continue;
            }
            NVIC_EnableIRQ(IRQNumber_EXTI[i]);
        }
    }
    //assign callback to EXTI_CallbackTabe
    /*Note: hexti->config->Pin ~ EXTI_LINEx (pin mask define)*/
    EXTI_SetCallback(hexti->Config->Pin,hexti->EXTI_Callback);  
}

/*< generic handler*/
void EXTI_IRQHandler(uint16_t EXTI_LINEx)
{
    if(EXTI->PR & (EXTI_LINEx))
    {
         /* Clear pending bit (write 1 to clear) */
        EXTI->PR = EXTI_LINEx;
        /*call user callback*/
        for(uint8_t i = 0 ; i < EXTI_LINE_NUMBER ; i++)
        {
            if(EXTI_LINEx & (1U << i))
            {
                if(EXTI_CallbackTable[i])
                {
                    EXTI_CallbackTable[i]();
                }
                break;
            }
        }
        
    }
}
