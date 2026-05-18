#include "stm32f407xxx_flash.h"

void FLASH_SetLatency(uint8_t freq_MHz)
{
    if(freq_MHz <= 30)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_0WS;   //0 wait states
    }
    else if(freq_MHz > 30 && freq_MHz <= 60)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_1WS;   //1 wait state
    }
    else if(freq_MHz > 60 && freq_MHz <= 90)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_2WS;   //2 wait states
    }
    else if(freq_MHz > 90 && freq_MHz <= 120)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_3WS;   //3 wait states
    }
    else if(freq_MHz > 120 && freq_MHz <= 150)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_4WS;   //4 wait states
    }
    else if(freq_MHz > 150 && freq_MHz <= 168)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_5WS;   //5 wait states
    }
    else if(freq_MHz > 168 && freq_MHz <= 180)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_6WS;   //6 wait states
    }
    else if(freq_MHz > 180 && freq_MHz <= 216)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_LATENCY_7WS;   //7 wait states
    }
}

