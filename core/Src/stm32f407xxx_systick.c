#include "stm32f407xxx_systick.h"

static volatile uint32_t global_tick = 0;

void SysTick_Handler(void);

void SYSTICK_Init(uint32_t ticks)
{
    if((ticks == 0U) || (ticks > SYSTICK_MAX_RELOAD))
    {
        return;
    }
    SYSTICK->CTRL  &= ~SYSTICK_CTRL_ENABLE;
    SYSTICK->VAL   = 0U ;//clear value of reg to zero
    SYSTICK->CTRL = 0U;
    SYSTICK->LOAD   = ticks -1;
    /*Select clocksource:
        0: AHB/8
        1: AHB
    */
    SYSTICK->CTRL |= SYSTICK_CTRL_CLKSOURCE;
    /*Counting down to zero to asserts the SysTick exception request*/ 
    SYSTICK->CTRL |= SYSTICK_CTRL_TICKINT;

    //enable systick
    SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE;
}
/*Delay 1ms function using systick*/
void SYSTICK_DelayMs(uint32_t ms)
{
    uint32_t tickstart = SYSTICK_GetTick();
    while((SYSTICK_GetTick() - tickstart) < ms);
}

uint32_t SYSTICK_GetTick(void)
{
    return global_tick;
}

void SYSTICK_IncTick(void)
{
    global_tick++;
}
/*systick handler when val_reg = 0*/
void SysTick_Handler(void)
{
    SYSTICK_IncTick();
}

