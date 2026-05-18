#ifndef __STM32F407XXX_NVIC_H
#define __STM32F407XXX_NVIC_H

#include "cortex_m4.h"

void NVIC_EnableIRQ(uint8_t IRQNumber);
void NVIC_DisableIRQ(uint8_t IRQNumber);
void NVIC_SetPendingIRQ(uint8_t IRQNumber);
void NVIC_ClearPendingIRQ(uint8_t IRQNumber);
void NVIC_SetPriority(uint8_t IRQNumber, uint8_t IRQPriority);
                            
#endif