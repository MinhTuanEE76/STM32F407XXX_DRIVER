#ifndef STM32F407XXX_SYSTICK_H
#define STM32F407XXX_SYSTICK_H

#include "cortex_m4.h"


/*!< SysTick CTRL register bit definition */
#define SYSTICK_CTRL_ENABLE_Pos        0U
#define SYSTICK_CTRL_TICKINT_Pos       1U
#define SYSTICK_CTRL_CLKSOURCE_Pos     2U
#define SYSTICK_CTRL_COUNTFLAG_Pos     16U

#define SYSTICK_CTRL_ENABLE        (1UL << SYSTICK_CTRL_ENABLE_Pos)
#define SYSTICK_CTRL_TICKINT       (1UL << SYSTICK_CTRL_TICKINT_Pos)
#define SYSTICK_CTRL_CLKSOURCE     (1UL << SYSTICK_CTRL_CLKSOURCE_Pos)
#define SYSTICK_CTRL_COUNTFLAG     (1UL << SYSTICK_CTRL_COUNTFLAG_Pos)

/*!< SysTick VAL register bit definition */
#define SYSTICK_VAL                (0xFFFU << 0)
/*!< SysTick RELOAD register bit definition */

#define SYSTICK_RELOAD             (0xFFFU << 0)

/*!< SysTick CALIB register bit definition */
#define SYSTICK_CALIB_TENMS_Pos        0U
#define SYSTICK_CALIB_SKEW_Pos         30U
#define SYSTICK_CALIB_NOREF_Pos        31U

#define SYSTICK_CALIB_TENMS        (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)
#define SYSTICK_CALIB_SKEW         (1UL << SYSTICK_CALIB_SKEW_Pos)
#define SYSTICK_CALIB_NOREF        (1UL << SYSTICK_CALIB_NOREF_Pos)

/*!< SysTick reload max value */
#define SYSTICK_MAX_RELOAD             0xFFFFFFUL


void SYSTICK_Init(uint32_t ticks);

uint32_t SYSTICK_GetTick(void);

void SYSTICK_DelayMs(uint32_t ms);

void SYSTICK_IncTick(void);

#endif
