#ifndef __STM32F407XXX_H
#define __STM32F407XXX_H

#include <stdint.h>
#include "cortex_m4.h"


/*!< Peripheral memory map */
#define PERIPH_BASE           0x40000000UL 
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000UL)
#define I2S2ext_BASE          (APB1PERIPH_BASE + 0x3400UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
#define I2S3ext_BASE          (APB1PERIPH_BASE + 0x4000UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400UL)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400UL)

/*!< APB2 peripherals */
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000UL)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2100UL)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x2200UL)
#define ADC123_COMMON_BASE    (APB2PERIPH_BASE + 0x2300UL)
/* Legacy define */
#define ADC_BASE               ADC123_COMMON_BASE
#define SDIO_BASE             (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800UL)

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00UL)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000UL)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010UL)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028UL)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040UL)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058UL)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070UL)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088UL)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0UL)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8UL)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400UL)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010UL)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028UL)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040UL)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058UL)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070UL)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088UL)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0UL)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8UL)
#define ETH_BASE              (AHB1PERIPH_BASE + 0x8000UL)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MMC_BASE          (ETH_BASE + 0x0100UL)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700UL)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000UL)


/*typedef for RCC register structure*/
typedef struct
{
    volatile uint32_t CR;            // RCC clock control register,                        Address offset: 0x00
    volatile uint32_t PLLCFGR;       // RCC PLL configuration register,                    Address offset: 0x04
    volatile uint32_t CFGR;          // RCC clock configuration register,                  Address offset: 0x08
    volatile uint32_t CIR;           // RCC clock interrupt register,                      Address offset: 0x0C
    volatile uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register,                Address offset: 0x10
    volatile uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register,                Address offset: 0x14
    volatile uint32_t AHB3RSTR;      // RCC AHB3 peripheral reset register,                Address offset: 0x18
             uint32_t RESERVED0;     // Reserved, 0x1C
    volatile uint32_t APB1RSTR;      // RCC APB1 peripheral reset register,                Address offset: 0x20
    volatile uint32_t APB2RSTR;      // RCC APB2 peripheral reset register,                Address offset: 0x24
             uint32_t RESERVED1[2];  // Reserved, 0x28-0x2C
    volatile uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register,         Address offset: 0x30
    volatile uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register,         Address offset: 0x34
    volatile uint32_t AHB3ENR;       // RCC AHB3 peripheral clock enable register,         Address offset: 0x38
             uint32_t RESERVED2;     // Reserved, 0x3C
    volatile uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register,         Address offset: 0x40
    volatile uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register,         Address offset: 0x44
             uint32_t RESERVED3[2];  // Reserved, 0x48-0x4C
    volatile uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable register,         Address offset: 0x50
} RCC_Reg_TypeDef_t;
//map RCC base address to RCC register structure
#define RCC     ((RCC_Reg_TypeDef_t*)(RCC_BASE))

/*typedef for GPIO register structure*/
typedef struct
{
    volatile uint32_t MODER;         // GPIO port mode register,                         Address offset: 0x00
    volatile uint32_t OTYPER;        // GPIO port output type register,                  Address offset: 0x04
    volatile uint32_t OSPEEDR;       // GPIO port output speed register,                 Address offset: 0x08
    volatile uint32_t PUPDR;         // GPIO port pull-up/pull-down register,            Address offset: 0x0C
    volatile uint32_t IDR;           // GPIO port input data register,                   Address offset: 0x10
    volatile uint32_t ODR;           // GPIO port output data register,                  Address offset: 0x14
    volatile uint32_t BSRR;          // GPIO port bit set/reset register,                Address offset: 0x18
    volatile uint32_t LCKR;          // GPIO port configuration lock register,           Address offset: 0x1C
    volatile uint32_t AFR[2];        // GPIO alternate function registers,               Address offset: 0x20-0x24
} GPIO_Reg_TypeDef_t;
//map GPIO base addresses to GPIO register structure
#define GPIOA   ((GPIO_Reg_TypeDef_t*)(GPIOA_BASE))
#define GPIOB   ((GPIO_Reg_TypeDef_t*)(GPIOB_BASE))
#define GPIOC   ((GPIO_Reg_TypeDef_t*)(GPIOC_BASE))
#define GPIOD   ((GPIO_Reg_TypeDef_t*)(GPIOD_BASE))
#define GPIOE   ((GPIO_Reg_TypeDef_t*)(GPIOE_BASE))
#define GPIOF   ((GPIO_Reg_TypeDef_t*)(GPIOF_BASE))
#define GPIOG   ((GPIO_Reg_TypeDef_t*)(GPIOG_BASE))
#define GPIOH   ((GPIO_Reg_TypeDef_t*)(GPIOH_BASE))
#define GPIOI   ((GPIO_Reg_TypeDef_t*)(GPIOI_BASE))


/*typedef for flash register structure*/
typedef struct
{
    volatile uint32_t ACR;           // Flash access control register,                    Address offset: 0x00
    volatile uint32_t KEYR;          // Flash key register,                               Address offset: 0x04
    volatile uint32_t OPTKEYR;       // Flash option key register,                        Address offset: 0x08
    volatile uint32_t SR;            // Flash status register,                            Address offset: 0x0C
    volatile uint32_t CR;            // Flash control register,                           Address offset: 0x10
    volatile uint32_t OPTCR;         // Flash option control register,                    Address offset: 0x14
    volatile uint32_t OPTCR1;        // Flash option control register 1,                  Address offset: 0x18
} FLASH_Reg_TypeDef_t;
//map FLASH base address to FLASH register structure
#define FLASH   ((FLASH_Reg_TypeDef_t*)(FLASH_R_BASE))

/*typedef for exti register structure*/
typedef struct
{
    volatile uint32_t IMR;       // Interrupt mask register,              Address offset: 0x00
    volatile uint32_t EMR;       // Event mask register,                  Address offset: 0x04
    volatile uint32_t RTSR;      // Rising trigger selection register,    Address offset: 0x08
    volatile uint32_t FTSR;      // Falling trigger selection register,   Address offset: 0x0C
    volatile uint32_t SWIER;     // Software interrupt event register,    Address offset: 0x10
    volatile uint32_t PR;        // Pending register,                     Address offset: 0x14
} EXTI_Reg_TypeDef_t;

//map EXTI base address to EXTI register structure
#define EXTI        ((EXTI_Reg_TypeDef_t*)(EXTI_BASE))

/*typedef for SYSCFG register structure*/
typedef struct
{
    volatile uint32_t MEMRMP;        // memory remap register,                    Address offset: 0x00
    volatile uint32_t PMC;           // peripheral mode configuration register,   Address offset: 0x04
    volatile uint32_t EXTICR[4];     // external interrupt configuration registers Address offset: 0x08-0x14
             uint32_t RESERVED1[2];  // Reserved, 0x18-0x1C
    volatile uint32_t CMPCR;         // Compensation cell control register,       Address offset: 0x20
} SYSCFG_Reg_TypeDef_t;

//map SYSCFG base address to SYSCFG register structure
#define SYSCFG     ((SYSCFG_Reg_TypeDef_t*)(SYSCFG_BASE))

/*typedef struct for USART register */
typedef struct{
    volatile uint32_t SR;           //Status register                             Address offset: 0x00
    volatile uint32_t DR;           //Data register                               Address offset: 0x04
    volatile uint32_t BRR;          //Baud Rate Register                          Address offset: 0x08
    volatile uint32_t CR1;          //Control register 1                          Address offset: 0x0C
    volatile uint32_t CR2;          //Control register 2                          Address offset: 0x10
    volatile uint32_t CR3;          //Control register 3                          Address offset: 0x14
    volatile uint32_t GTPR;         //Guard time and prescaler register           Address offset: 0x18
} USART_Reg_TypeDef_t;

//map USART base address to USART register struct
#define USART1      ((USART_Reg_TypeDef_t*)(USART1_BASE))
#define USART2      ((USART_Reg_TypeDef_t*)(USART2_BASE))
#define USART3      ((USART_Reg_TypeDef_t*)(USART3_BASE))
#define UART4       ((USART_Reg_TypeDef_t*)(UART4_BASE))
#define UART5       ((USART_Reg_TypeDef_t*)(UART5_BASE))
#define USART6      ((USART_Reg_TypeDef_t*)(USART6_BASE))


/*> Typedef struct for CAN registers */
/*===========================
 * CAN Tx MailBox
 *===========================*/
typedef struct{
    volatile uint32_t TIR;      // TX mailbox identifier register           Address offset: 0x00
    volatile uint32_t TDTR;     // TX mailbox data length control register  Address offset: 0x04
    volatile uint32_t TDLR;     // TX mailbox data low register             Address offset: 0x08
    volatile uint32_t TDHR;     // TX mailbox data high register            Address offset: 0x0C
} CAN_TxMailBox_TypeDef_t;

/*===========================
 * CAN FIFO MailBox
 *===========================*/
typedef struct{
    volatile uint32_t RIR;      // RX FIFO mailbox identifier register      Address offset: 0x00
    volatile uint32_t RDTR;     // RX FIFO mailbox data length control reg  Address offset: 0x04
    volatile uint32_t RDLR;     // RX FIFO mailbox data low register        Address offset: 0x08
    volatile uint32_t RDHR;     // RX FIFO mailbox data high register       Address offset: 0x0C
} CAN_FIFOMailBox_TypeDef_t;

/*===========================
 * CAN Filter Register
 *===========================*/
typedef struct{
    volatile uint32_t FR1;      // Filter bank register 1                   Address offset: 0x00
    volatile uint32_t FR2;      // Filter bank register 2                   Address offset: 0x04
} CAN_FilterRegister_TypeDef_t;

/*===========================
 * Main CAN Register
 *===========================*/
typedef struct{

    volatile uint32_t MCR;          // master control register                   Address offset: 0x00
    volatile uint32_t MSR;          // master status register                    Address offset: 0x04
    volatile uint32_t TSR;          // transmit status register                  Address offset: 0x08
    volatile uint32_t RF0R;         // receive FIFO 0 register                   Address offset: 0x0C
    volatile uint32_t RF1R;         // receive FIFO 1 register                   Address offset: 0x10
    volatile uint32_t IER;          // interrupt enable register                 Address offset: 0x14
    volatile uint32_t ESR;          // error status register                     Address offset: 0x18
    volatile uint32_t BTR;          // bit timing register                       Address offset: 0x1C

    uint32_t RESERVED0[88];         // Reserved                                  0x20 -> 0x17F

    CAN_TxMailBox_TypeDef_t sTxMailBox[3];
    // Mailbox0 : 0x180
    // Mailbox1 : 0x190
    // Mailbox2 : 0x1A0

    CAN_FIFOMailBox_TypeDef_t sFIFOMailBox[2];
    // FIFO0 : 0x1B0
    // FIFO1 : 0x1C0

    uint32_t RESERVED1[12];         // Reserved                                  0x1D0 -> 0x1FF

    volatile uint32_t FMR;          // filter master register                    Address offset: 0x200
    volatile uint32_t FM1R;         // filter mode register                      Address offset: 0x204

    uint32_t RESERVED2;             // Reserved                                  0x208

    volatile uint32_t FS1R;         // filter scale register                     Address offset: 0x20C

    uint32_t RESERVED3;             // Reserved                                  0x210

    volatile uint32_t FFA1R;        // filter FIFO assignment register           Address offset: 0x214

    uint32_t RESERVED4;             // Reserved                                  0x218

    volatile uint32_t FA1R;         // filter activation register                Address offset: 0x21C

    uint32_t RESERVED5[8];          // Reserved                                  0x220 -> 0x23F

    CAN_FilterRegister_TypeDef_t sFilterRegister[28];
    // Filter0  : 0x240
    // Filter27 : 0x31C
} CAN_Reg_TypeDef_t;

//map CAN base address to CAN register structure
#define CAN1    ((CAN_Reg_TypeDef_t*)(CAN1_BASE))
#define CAN2    ((CAN_Reg_TypeDef_t*)(CAN2_BASE))

/*Typedef for I2C registers */
typedef struct{
    volatile uint32_t CR1;      // I2C control register 1                    Address offset: 0x00
    volatile uint32_t CR2;      // I2C control register 2                    Address offset: 0x04
    volatile uint32_t OAR1;     // I2C own address register 1                Address offset: 0x08
    volatile uint32_t OAR2;     // I2C own address register 2                Address offset: 0x0C
    volatile uint32_t DR;       // I2C data register                         Address offset: 0x10
    volatile uint32_t SR1;      // I2C status register 1                     Address offset: 0x14
    volatile uint32_t SR2;      // I2C status register 2                     Address offset: 0x18
    volatile uint32_t CCR;      // I2C clock control register                Address offset: 0x1C
    volatile uint32_t TRISE;    // I2C TRISE register                        Address offset: 0x20
} I2C_Reg_TypeDef_t;

//map I2C base address to I2C register structure
#define I2C1    ((I2C_Reg_TypeDef_t*)(I2C1_BASE))
#define I2C2    ((I2C_Reg_TypeDef_t*)(I2C2_BASE))
#define I2C3    ((I2C_Reg_TypeDef_t*)(I2C3_BASE))


#endif // __STM32F407XXX_H

