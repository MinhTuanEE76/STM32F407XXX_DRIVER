#ifndef  __STM32F407XXX_FLASH_H
#define  __STM32F407XXX_FLASH_H

#include "stm32f407xxx.h"

/*define bit positions*/
#define FLASH_ACR_LATENCY_Pos          0U   

/*define bit masks*/
#define FLASH_ACR_LATENCY              (0x7U << FLASH_ACR_LATENCY_Pos)   //LATENCY[2:0] bits (Latency)


//define latency values for different system clock frequencies
#define FLASH_ACR_LATENCY_0WS          0U   //0 wait states, for 0 < SYSCLK <= 30MHz
#define FLASH_ACR_LATENCY_1WS          1U   //1 wait state, for 30MHz < SYSCLK <= 60MHz
#define FLASH_ACR_LATENCY_2WS          2U   //2 wait states, for 60MHz < SYSCLK <= 90MHz
#define FLASH_ACR_LATENCY_3WS          3U   //3 wait states, for 90MHz < SYSCLK <= 120MHz
#define FLASH_ACR_LATENCY_4WS          4U   //4 wait states, for 120MHz < SYSCLK <= 150MHz
#define FLASH_ACR_LATENCY_5WS          5U   //5 wait states, for 150MHz < SYSCLK <= 168MHz
#define FLASH_ACR_LATENCY_6WS          6U   //6 wait states, for 168MHz < SYSCLK <= 180MHz
#define FLASH_ACR_LATENCY_7WS          7U   //7 wait states, for 180MHz < SYSCLK <= 216MHz

/*function declarations*/
void FLASH_SetLatency(uint8_t freq_MHz);   //configure flash latency according to system clock frequency

#endif /* __STM32F407XXX_FLASH_H */
