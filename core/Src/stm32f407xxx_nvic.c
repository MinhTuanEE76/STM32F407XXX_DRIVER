#include "stm32f407xxx_nvic.h"


/*----------------------------inline function---------------------------------*/
/*
    1. set interupt enable in ISERx
    2. set pending interupt in ISPRx
    3. configure priority interupt in IPSRx
*/
#define NO_PR_BITS_IMPLEMENTED         4U
/*
 * Enable interrupt in NVIC
 */
void NVIC_EnableIRQ(uint8_t IRQNumber)
{
    NVIC->ISER[IRQNumber >> 5U] |= (1U << (IRQNumber & 0x1FU));
}
/*
 * Disable interrupt in NVIC
 */
void NVIC_DisableIRQ(uint8_t IRQNumber)
{
    NVIC->ICER[IRQNumber >> 5U] |= (1U << (IRQNumber & 0x1FU));
}
/*
 * Set pending interrupt
 */
void NVIC_SetPendingIRQ(uint8_t IRQNumber)
{
    NVIC->ISPR[IRQNumber >> 5U] |= (1U << (IRQNumber & 0x1FU));
}

/*
 * Clear pending interrupt
 */
void NVIC_ClearPendingIRQ(uint8_t IRQNumber)
{
    NVIC->ICPR[IRQNumber >> 5U] |= (1U << (IRQNumber & 0x1FU));
}
/*
 * Set interrupt priority
 */
inline void NVIC_SetPriority(uint8_t IRQNumber,
                                    uint8_t IRQPriority)
{
    NVIC->IPR[IRQNumber] = (IRQPriority << (8U - NO_PR_BITS_IMPLEMENTED));
}