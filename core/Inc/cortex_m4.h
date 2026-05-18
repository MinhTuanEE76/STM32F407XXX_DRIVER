#ifndef __CORTEX_M4_H
#define __CORTEX_M4_H

#include <stdint.h>

/*
 * Cortex-M4 Processor Exceptions
 * Negative IRQ numbers
 */

#define IRQ_NO_NMI                     -14
#define IRQ_NO_HARDFAULT               -13
#define IRQ_NO_MEMMANAGE               -12
#define IRQ_NO_BUSFAULT                -11
#define IRQ_NO_USAGEFAULT              -10
#define IRQ_NO_SVCALL                  -5
#define IRQ_NO_DEBUGMON                -4
#define IRQ_NO_PENDSV                  -2
#define IRQ_NO_SYSTICK                 -1


/*
 * STM32F407 Peripheral Interrupt Numbers
 * Reference: Vector table in startup file / reference manual
 */

#define IRQ_NO_WWDG                    0U
#define IRQ_NO_PVD                     1U
#define IRQ_NO_TAMP_STAMP              2U
#define IRQ_NO_RTC_WKUP                3U
#define IRQ_NO_FLASH                   4U
#define IRQ_NO_RCC                     5U
#define IRQ_NO_EXTI0                   6U
#define IRQ_NO_EXTI1                   7U
#define IRQ_NO_EXTI2                   8U
#define IRQ_NO_EXTI3                   9U
#define IRQ_NO_EXTI4                   10U
#define IRQ_NO_DMA1_STREAM0            11U
#define IRQ_NO_DMA1_STREAM1            12U
#define IRQ_NO_DMA1_STREAM2            13U
#define IRQ_NO_DMA1_STREAM3            14U
#define IRQ_NO_DMA1_STREAM4            15U
#define IRQ_NO_DMA1_STREAM5            16U
#define IRQ_NO_DMA1_STREAM6            17U
#define IRQ_NO_ADC                     18U
#define IRQ_NO_CAN1_TX                 19U
#define IRQ_NO_CAN1_RX0                20U
#define IRQ_NO_CAN1_RX1                21U
#define IRQ_NO_CAN1_SCE                22U
#define IRQ_NO_EXTI9_5                 23U
#define IRQ_NO_TIM1_BRK_TIM9           24U
#define IRQ_NO_TIM1_UP_TIM10           25U
#define IRQ_NO_TIM1_TRG_COM_TIM11      26U
#define IRQ_NO_TIM1_CC                 27U
#define IRQ_NO_TIM2                    28U
#define IRQ_NO_TIM3                    29U
#define IRQ_NO_TIM4                    30U
#define IRQ_NO_I2C1_EV                 31U
#define IRQ_NO_I2C1_ER                 32U
#define IRQ_NO_I2C2_EV                 33U
#define IRQ_NO_I2C2_ER                 34U
#define IRQ_NO_SPI1                    35U
#define IRQ_NO_SPI2                    36U
#define IRQ_NO_USART1                  37U
#define IRQ_NO_USART2                  38U
#define IRQ_NO_USART3                  39U
#define IRQ_NO_EXTI15_10               40U
#define IRQ_NO_RTC_ALARM               41U
#define IRQ_NO_OTG_FS_WKUP             42U
#define IRQ_NO_TIM8_BRK_TIM12          43U
#define IRQ_NO_TIM8_UP_TIM13           44U
#define IRQ_NO_TIM8_TRG_COM_TIM14      45U
#define IRQ_NO_TIM8_CC                 46U
#define IRQ_NO_DMA1_STREAM7            47U
#define IRQ_NO_FSMC                    48U
#define IRQ_NO_SDIO                    49U
#define IRQ_NO_TIM5                    50U
#define IRQ_NO_SPI3                    51U
#define IRQ_NO_UART4                   52U
#define IRQ_NO_UART5                   53U
#define IRQ_NO_TIM6_DAC                54U
#define IRQ_NO_TIM7                    55U
#define IRQ_NO_DMA2_STREAM0            56U
#define IRQ_NO_DMA2_STREAM1            57U
#define IRQ_NO_DMA2_STREAM2            58U
#define IRQ_NO_DMA2_STREAM3            59U
#define IRQ_NO_DMA2_STREAM4            60U
#define IRQ_NO_ETH                     61U
#define IRQ_NO_ETH_WKUP                62U
#define IRQ_NO_CAN2_TX                 63U
#define IRQ_NO_CAN2_RX0                64U
#define IRQ_NO_CAN2_RX1                65U
#define IRQ_NO_CAN2_SCE                66U
#define IRQ_NO_OTG_FS                  67U
#define IRQ_NO_DMA2_STREAM5            68U
#define IRQ_NO_DMA2_STREAM6            69U
#define IRQ_NO_DMA2_STREAM7            70U
#define IRQ_NO_USART6                  71U
#define IRQ_NO_I2C3_EV                 72U
#define IRQ_NO_I2C3_ER                 73U
#define IRQ_NO_OTG_HS_EP1_OUT          74U
#define IRQ_NO_OTG_HS_EP1_IN           75U
#define IRQ_NO_OTG_HS_WKUP             76U
#define IRQ_NO_OTG_HS                  77U
#define IRQ_NO_DCMI                    78U
#define IRQ_NO_CRYP                    79U
#define IRQ_NO_HASH_RNG                80U
#define IRQ_NO_FPU                     81U

/*!< SysTick base address */
#define SYSTICK_BASE          0xE000E010UL

/*!< NVIC base addresses */
#define NVIC_ISER_BASE        0xE000E100UL
#define NVIC_ICER_BASE        0xE000E180UL
#define NVIC_ISPR_BASE        0xE000E200UL
#define NVIC_ICPR_BASE        0xE000E280UL
#define NVIC_IPR_BASE         0xE000E400UL

#define SCB_BASE              0xE000ED00UL


/* typedef for NVIC register structure */
typedef struct
{
    volatile uint32_t ISER[8];      // Interrupt Set Enable Registers,        Offset: 0x000 - 0x01C
             uint32_t RESERVED0[24];
    
    volatile uint32_t ICER[8];      // Interrupt Clear Enable Registers,      Offset: 0x080 - 0x09C
             uint32_t RESERVED1[24];

    volatile uint32_t ISPR[8];      // Interrupt Set Pending Registers,       Offset: 0x100 - 0x11C
             uint32_t RESERVED2[24];

    volatile uint32_t ICPR[8];      // Interrupt Clear Pending Registers,     Offset: 0x180 - 0x19C
             uint32_t RESERVED3[24];

    volatile uint32_t IABR[8];      // Interrupt Active Bit Registers,        Offset: 0x200 - 0x21C
             uint32_t RESERVED4[56];

    volatile uint8_t  IPR[240];     // Interrupt Priority Registers,          Offset: 0x300 - 0x3EF

} NVIC_Reg_TypeDef_t;
/* map NVIC base address to NVIC register structure */
#define NVIC      ((NVIC_Reg_TypeDef_t*)(NVIC_ISER_BASE))

typedef struct
{
    volatile uint32_t CPUID;        // CPUID Base Register
    volatile uint32_t ICSR;         // Interrupt Control and State Register
    volatile uint32_t VTOR;         // Vector Table Offset Register
    volatile uint32_t AIRCR;        // Application Interrupt and Reset Control Register
    volatile uint32_t SCR;          // System Control Register
    volatile uint32_t CCR;          // Configuration and Control Register
    volatile uint8_t  SHP[12];      // System Handler Priority Registers
    volatile uint32_t SHCSR;        // System Handler Control and State Register

} SCB_Reg_TypeDef_t;
#define SCB         ((SCB_Reg_TypeDef_t*)(SCB_BASE))

/* typedef for SysTick register structure */
typedef struct
{
    volatile uint32_t CTRL;         // SysTick control and status register,              Address offset: 0x00
    volatile uint32_t LOAD;         // SysTick reload value register,                    Address offset: 0x04
    volatile uint32_t VAL;          // SysTick current value register,                   Address offset: 0x08
    volatile uint32_t CALIB;        // SysTick calibration value register,               Address offset: 0x0C

} SYSTICK_Reg_TypeDef_t;

/* map SysTick base address to SysTick register structure */
#define SYSTICK    ((SYSTICK_Reg_TypeDef_t*)(SYSTICK_BASE))


#endif