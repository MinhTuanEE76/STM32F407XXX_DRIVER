#ifndef __STM32F407XXX_EXTI_H
#define __STM32F407XXX_EXTI_H

#include "stm32f407xxx.h"

/* EXTI_IMR 
    0: Interrupt request from line x is masked (masked = disable)
    1: Interrupt request from line x is not masked(unmasked == enable)
*/
#define EXTI_IMR_MR0                      (1UL << 0U)
#define EXTI_IMR_MR1                      (1UL << 1U)
#define EXTI_IMR_MR2                      (1UL << 2U)
#define EXTI_IMR_MR3                      (1UL << 3U)
#define EXTI_IMR_MR4                      (1UL << 4U)
#define EXTI_IMR_MR5                      (1UL << 5U)
#define EXTI_IMR_MR6                      (1UL << 6U)
#define EXTI_IMR_MR7                      (1UL << 7U)
#define EXTI_IMR_MR8                      (1UL << 8U)
#define EXTI_IMR_MR9                      (1UL << 9U)
#define EXTI_IMR_MR10                     (1UL << 10U)
#define EXTI_IMR_MR11                     (1UL << 11U)
#define EXTI_IMR_MR12                     (1UL << 12U)
#define EXTI_IMR_MR13                     (1UL << 13U)
#define EXTI_IMR_MR14                     (1UL << 14U)
#define EXTI_IMR_MR15                     (1UL << 15U)
#define EXTI_IMR_MR16                     (1UL << 16U)
#define EXTI_IMR_MR17                     (1UL << 17U)
#define EXTI_IMR_MR18                     (1UL << 18U)
#define EXTI_IMR_MR19                     (1UL << 19U)
#define EXTI_IMR_MR20                     (1UL << 20U)
#define EXTI_IMR_MR21                     (1UL << 21U)
#define EXTI_IMR_MR22                     (1UL << 22U)


/* EXTI_EMR 
    0: Event request from line x is masked
    1: Event request from line x is not masked

*/
#define EXTI_EMR_MR0                      (1UL << 0U)
#define EXTI_EMR_MR1                      (1UL << 1U)
#define EXTI_EMR_MR2                      (1UL << 2U)
#define EXTI_EMR_MR3                      (1UL << 3U)
#define EXTI_EMR_MR4                      (1UL << 4U)
#define EXTI_EMR_MR5                      (1UL << 5U)
#define EXTI_EMR_MR6                      (1UL << 6U)
#define EXTI_EMR_MR7                      (1UL << 7U)
#define EXTI_EMR_MR8                      (1UL << 8U)
#define EXTI_EMR_MR9                      (1UL << 9U)
#define EXTI_EMR_MR10                     (1UL << 10U)
#define EXTI_EMR_MR11                     (1UL << 11U)
#define EXTI_EMR_MR12                     (1UL << 12U)
#define EXTI_EMR_MR13                     (1UL << 13U)
#define EXTI_EMR_MR14                     (1UL << 14U)
#define EXTI_EMR_MR15                     (1UL << 15U)
#define EXTI_EMR_MR16                     (1UL << 16U)
#define EXTI_EMR_MR17                     (1UL << 17U)
#define EXTI_EMR_MR18                     (1UL << 18U)
#define EXTI_EMR_MR19                     (1UL << 19U)
#define EXTI_EMR_MR20                     (1UL << 20U)
#define EXTI_EMR_MR21                     (1UL << 21U)
#define EXTI_EMR_MR22                     (1UL << 22U)


/* EXTI_RTSR : Rising trigger select register
    0: Rising trigger disabled (for Event and Interrupt) for input line
    1: Rising trigger enabled (for Event and Interrupt) for input line
*/
#define EXTI_RTSR_TR0                     (1UL << 0U)
#define EXTI_RTSR_TR1                     (1UL << 1U)
#define EXTI_RTSR_TR2                     (1UL << 2U)
#define EXTI_RTSR_TR3                     (1UL << 3U)
#define EXTI_RTSR_TR4                     (1UL << 4U)
#define EXTI_RTSR_TR5                     (1UL << 5U)
#define EXTI_RTSR_TR6                     (1UL << 6U)
#define EXTI_RTSR_TR7                     (1UL << 7U)
#define EXTI_RTSR_TR8                     (1UL << 8U)
#define EXTI_RTSR_TR9                     (1UL << 9U)
#define EXTI_RTSR_TR10                    (1UL << 10U)
#define EXTI_RTSR_TR11                    (1UL << 11U)
#define EXTI_RTSR_TR12                    (1UL << 12U)
#define EXTI_RTSR_TR13                    (1UL << 13U)
#define EXTI_RTSR_TR14                    (1UL << 14U)
#define EXTI_RTSR_TR15                    (1UL << 15U)
#define EXTI_RTSR_TR16                    (1UL << 16U)
#define EXTI_RTSR_TR17                    (1UL << 17U)
#define EXTI_RTSR_TR18                    (1UL << 18U)
#define EXTI_RTSR_TR19                    (1UL << 19U)
#define EXTI_RTSR_TR20                    (1UL << 20U)
#define EXTI_RTSR_TR21                    (1UL << 21U)
#define EXTI_RTSR_TR22                    (1UL << 22U)


/* EXTI_FTSR : Falling trigger seclect register
    0: Falling trigger disabled (for Event and Interrupt) for input line
    1: Falling trigger enabled (for Event and Interrupt) for input line.
*/
#define EXTI_FTSR_TR0                     (1UL << 0U)
#define EXTI_FTSR_TR1                     (1UL << 1U)
#define EXTI_FTSR_TR2                     (1UL << 2U)
#define EXTI_FTSR_TR3                     (1UL << 3U)
#define EXTI_FTSR_TR4                     (1UL << 4U)
#define EXTI_FTSR_TR5                     (1UL << 5U)
#define EXTI_FTSR_TR6                     (1UL << 6U)
#define EXTI_FTSR_TR7                     (1UL << 7U)
#define EXTI_FTSR_TR8                     (1UL << 8U)
#define EXTI_FTSR_TR9                     (1UL << 9U)
#define EXTI_FTSR_TR10                    (1UL << 10U)
#define EXTI_FTSR_TR11                    (1UL << 11U)
#define EXTI_FTSR_TR12                    (1UL << 12U)
#define EXTI_FTSR_TR13                    (1UL << 13U)
#define EXTI_FTSR_TR14                    (1UL << 14U)
#define EXTI_FTSR_TR15                    (1UL << 15U)
#define EXTI_FTSR_TR16                    (1UL << 16U)
#define EXTI_FTSR_TR17                    (1UL << 17U)
#define EXTI_FTSR_TR18                    (1UL << 18U)
#define EXTI_FTSR_TR19                    (1UL << 19U)
#define EXTI_FTSR_TR20                    (1UL << 20U)
#define EXTI_FTSR_TR21                    (1UL << 21U)
#define EXTI_FTSR_TR22                    (1UL << 22U)


/* EXTI_SWIER 
    Software Interrupt on line x
*/
#define EXTI_SWIER_SWIER0                 (1UL << 0U)
#define EXTI_SWIER_SWIER1                 (1UL << 1U)
#define EXTI_SWIER_SWIER2                 (1UL << 2U)
#define EXTI_SWIER_SWIER3                 (1UL << 3U)
#define EXTI_SWIER_SWIER4                 (1UL << 4U)
#define EXTI_SWIER_SWIER5                 (1UL << 5U)
#define EXTI_SWIER_SWIER6                 (1UL << 6U)
#define EXTI_SWIER_SWIER7                 (1UL << 7U)
#define EXTI_SWIER_SWIER8                 (1UL << 8U)
#define EXTI_SWIER_SWIER9                 (1UL << 9U)
#define EXTI_SWIER_SWIER10                (1UL << 10U)
#define EXTI_SWIER_SWIER11                (1UL << 11U)
#define EXTI_SWIER_SWIER12                (1UL << 12U)
#define EXTI_SWIER_SWIER13                (1UL << 13U)
#define EXTI_SWIER_SWIER14                (1UL << 14U)
#define EXTI_SWIER_SWIER15                (1UL << 15U)
#define EXTI_SWIER_SWIER16                (1UL << 16U)
#define EXTI_SWIER_SWIER17                (1UL << 17U)
#define EXTI_SWIER_SWIER18                (1UL << 18U)
#define EXTI_SWIER_SWIER19                (1UL << 19U)
#define EXTI_SWIER_SWIER20                (1UL << 20U)
#define EXTI_SWIER_SWIER21                (1UL << 21U)
#define EXTI_SWIER_SWIER22                (1UL << 22U)


/* EXTI_PR 
    0: No trigger request occurred
    1: selected trigger request occurred
    This bit is set when the selected edge event arrives on the external interrupt line. 
    This bit is cleared by programming it to ‘1’. 
*/
#define EXTI_PR_PR0                       (1UL << 0U)
#define EXTI_PR_PR1                       (1UL << 1U)
#define EXTI_PR_PR2                       (1UL << 2U)
#define EXTI_PR_PR3                       (1UL << 3U)
#define EXTI_PR_PR4                       (1UL << 4U)
#define EXTI_PR_PR5                       (1UL << 5U)
#define EXTI_PR_PR6                       (1UL << 6U)
#define EXTI_PR_PR7                       (1UL << 7U)
#define EXTI_PR_PR8                       (1UL << 8U)
#define EXTI_PR_PR9                       (1UL << 9U)
#define EXTI_PR_PR10                      (1UL << 10U)
#define EXTI_PR_PR11                      (1UL << 11U)
#define EXTI_PR_PR12                      (1UL << 12U)
#define EXTI_PR_PR13                      (1UL << 13U)
#define EXTI_PR_PR14                      (1UL << 14U)
#define EXTI_PR_PR15                      (1UL << 15U)
#define EXTI_PR_PR16                      (1UL << 16U)
#define EXTI_PR_PR17                      (1UL << 17U)
#define EXTI_PR_PR18                      (1UL << 18U)
#define EXTI_PR_PR19                      (1UL << 19U)
#define EXTI_PR_PR20                      (1UL << 20U)
#define EXTI_PR_PR21                      (1UL << 21U)
#define EXTI_PR_PR22                      (1UL << 22U)

#define SYSCFG_EXTICR_PORTA               0x0U
#define SYSCFG_EXTICR_PORTB               0x1U
#define SYSCFG_EXTICR_PORTC               0x2U
#define SYSCFG_EXTICR_PORTD               0x3U
#define SYSCFG_EXTICR_PORTE               0x4U
#define SYSCFG_EXTICR_PORTF               0x5U
#define SYSCFG_EXTICR_PORTG               0x6U
#define SYSCFG_EXTICR_PORTH               0x7U
#define SYSCFG_EXTICR_PORTI               0x8U
/*                    SYSCFG_EXTICR1                         */
#define SYSCFG_EXTICR1_EXTI0              (0xFUL << 0U)
#define SYSCFG_EXTICR1_EXTI1              (0xFUL << 4U)
#define SYSCFG_EXTICR1_EXTI2              (0xFUL << 8U)
#define SYSCFG_EXTICR1_EXTI3              (0xFUL << 12U)
/*                    SYSCFG_EXTICR2                         */
#define SYSCFG_EXTICR2_EXTI4              (0xFUL << 0U)
#define SYSCFG_EXTICR2_EXTI5              (0xFUL << 4U)
#define SYSCFG_EXTICR2_EXTI6              (0xFUL << 8U)
#define SYSCFG_EXTICR2_EXTI7              (0xFUL << 12U)
/*                    SYSCFG_EXTICR3                         */
#define SYSCFG_EXTICR3_EXTI8              (0xFUL << 0U)
#define SYSCFG_EXTICR3_EXTI9              (0xFUL << 4U)
#define SYSCFG_EXTICR3_EXTI10             (0xFUL << 8U)
#define SYSCFG_EXTICR3_EXTI11             (0xFUL << 12U)
/*                    SYSCFG_EXTICR4                         */
#define SYSCFG_EXTICR4_EXTI12             (0xFUL << 0U)
#define SYSCFG_EXTICR4_EXTI13             (0xFUL << 4U)
#define SYSCFG_EXTICR4_EXTI14             (0xFUL << 8U)
#define SYSCFG_EXTICR4_EXTI15             (0xFUL << 12U)

#define EXTI_TRIGGER_RISING               0U
#define EXTI_TRIGGER_FALLING              1U
#define EXTI_TRIGGER_BOTH                 2U


#define EXTI_LINE_NUMBER        16U

#define EXTI_LINE_0             (1U << 0U)
#define EXTI_LINE_1             (1U << 1U)
#define EXTI_LINE_2             (1U << 2U)
#define EXTI_LINE_3             (1U << 3U)
#define EXTI_LINE_4             (1U << 4U)
#define EXTI_LINE_5             (1U << 5U)
#define EXTI_LINE_6             (1U << 6U)
#define EXTI_LINE_7             (1U << 7U)
#define EXTI_LINE_8             (1U << 8U)
#define EXTI_LINE_9             (1U << 9U)
#define EXTI_LINE_10            (1U << 10U)
#define EXTI_LINE_11            (1U << 11U)
#define EXTI_LINE_12            (1U << 12U)
#define EXTI_LINE_13            (1U << 13U)
#define EXTI_LINE_14            (1U << 14U)
#define EXTI_LINE_15            (1U << 15U)

#define PIN_MASK_4BITS          15U

/*typedef struct consist of initial parameter*/
typedef struct {
    uint16_t Pin;           //select PINx -> EXTIx
    uint8_t Port;          //select portsource for EXTI
    uint8_t Trigger;
} EXTI_Config_t;

typedef struct {
    EXTI_Config_t *Config;
    void (*EXTI_Callback)(void);
} EXTI_Handle_t;

/*--------------------------------Function Prototype---------------------------------*/
void EXTI_Init(EXTI_Handle_t *hexti);


void EXTI_IRQHandler(uint16_t EXTI_LINEx);
void EXTI_SetCallback(uint16_t EXTI_LINEx, void (*callback)(void));
#endif