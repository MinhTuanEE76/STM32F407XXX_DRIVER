#include "stm32f407xxx_it.h"
#include "stm32f407xxx_exti.h"
#include "stm32f407xxx_uart.h"

extern USART_Handle_t huart;

/*----------------------------------USART_Handler-------------------------------------*/
void USART1_IRQHandler(void)
{
    USART_IRQHandler(&huart);
}

void USART2_IRQHandler(void)
{
    USART_IRQHandler(&huart);
}

void USART3_IRQHandler(void)
{
    USART_IRQHandler(&huart);
}

void UART4_IRQHandler(void)
{
    USART_IRQHandler(&huart);
}
void UART5_IRQHandler(void)
{
    USART_IRQHandler(&huart);
}
void USART6_IRQHandler(void)
{
    USART_IRQHandler(&huart);
}

/*---------------------------------EXTI_Handler--------------------------------------*/
/*< EXTI0_Handler*/
void EXTI0_IRQHandler(void)
{
    EXTI_IRQHandler(EXTI_LINE_0);
}
/*< EXTI1_Handler*/
void EXTI1_IRQHandler(void)
{
    EXTI_IRQHandler(EXTI_LINE_1);
}
/*< EXTI2_Handler*/
void EXTI2_IRQHandler(void)
{
    EXTI_IRQHandler(EXTI_LINE_2);
}
/*< EXTI3_Handler*/
void EXTI3_IRQHandler(void)
{
    EXTI_IRQHandler(EXTI_LINE_3);
}
/*< EXTI4_Handler*/
void EXTI4_IRQHandler(void)
{
    EXTI_IRQHandler(EXTI_LINE_4);
}
/* ========================================================= */
/*               SHARED INTERRUPT GROUP 10-15                 */
/* ========================================================= */

void EXTI15_10_IRQHandler(void)
{
    for(uint8_t i = 10; i <= 15; i++)
    {
        if(EXTI->PR & (1U << i))
        {
            switch(i)
            {
                case 10:
                    EXTI_IRQHandler(EXTI_LINE_10);
                    break;
                case 11:
                    EXTI_IRQHandler(EXTI_LINE_11);
                    break;
                case 12:
                    EXTI_IRQHandler(EXTI_LINE_12);
                    break;
                case 13:
                    EXTI_IRQHandler(EXTI_LINE_13);
                    break;
                case 14:
                    EXTI_IRQHandler(EXTI_LINE_14);
                    break;
                case 15:
                    EXTI_IRQHandler(EXTI_LINE_15);
                    break;
                default:
                    break;
            }
        }
        break;
    }
}

/* ========================================================= */
/*              SHARED INTERRUPT GROUP 5-9                */
/* ========================================================= */

void EXTI9_5_IRQHandler(void)
{
    for(uint8_t i = 5; i <= 9; i++)
    {
        if(EXTI->PR & (1U << i))
        {
            switch(i)
            {
                case 5:
                    EXTI_IRQHandler(EXTI_LINE_5);
                    break;
                case 6:
                    EXTI_IRQHandler(EXTI_LINE_6);
                    break;
                case 7:
                    EXTI_IRQHandler(EXTI_LINE_7);
                    break;
                case 8:
                    EXTI_IRQHandler(EXTI_LINE_8);
                    break;
                case 9:
                    EXTI_IRQHandler(EXTI_LINE_9);
                    break;
                default:
                    break;
            }
        }
        break;
    }
}