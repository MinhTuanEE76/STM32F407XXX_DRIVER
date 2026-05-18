#ifndef __STM32F407XXX_RCC_H
#define __STM32F407XXX_RCC_H

#include "stm32f407xxx.h"

/*
 * bit position definition for RCC CR REGISTER
 */
#define RCC_CR_HSION_Pos                0U
#define RCC_CR_HSIRDY_Pos               1U
#define RCC_CR_HSEON_Pos                16U
#define RCC_CR_HSERDY_Pos               17U
#define RCC_CR_HSEBYP_Pos               18U
#define RCC_CR_CSSON_Pos                19U
#define RCC_CR_PLLON_Pos                24U
#define RCC_CR_PLLRDY_Pos               25U
#define RCC_CR_PLLI2SON_Pos             26U
#define RCC_CR_PLLI2SRDY_Pos            27U

/*
 * bit position definition for RCC PLLCFGR REGISTER
 */
#define RCC_PLLCFGR_PLLM_Pos            0U
#define RCC_PLLCFGR_PLLN_Pos            6U
#define RCC_PLLCFGR_PLLP_Pos            16U
#define RCC_PLLCFGR_PLLSRC_Pos          22U
#define RCC_PLLCFGR_PLLQ_Pos            24U

/*
 * bit position definition for RCC CFGR REGISTER
 */
#define RCC_CFGR_SW_Pos                 0U
#define RCC_CFGR_SWS_Pos                2U
#define RCC_CFGR_HPRE_Pos               4U
#define RCC_CFGR_PPRE1_Pos              10U
#define RCC_CFGR_PPRE2_Pos              13U
#define RCC_CFGR_RTCPRE_Pos             16U
#define RCC_CFGR_MCO1_Pos               21U
#define RCC_CFGR_I2SSRC_Pos             23U
#define RCC_CFGR_MCO1PRE_Pos            24U
#define RCC_CFGR_MCO2PRE_Pos            27U
#define RCC_CFGR_MCO2_Pos               30U

/*
 * bit position definition for RCC CIR REGISTER
 */
#define RCC_CIR_LSIRDYF_Pos             0U
#define RCC_CIR_LSERDYF_Pos             1U
#define RCC_CIR_HSIRDYF_Pos             2U
#define RCC_CIR_HSERDYF_Pos             3U
#define RCC_CIR_PLLRDYF_Pos             4U
#define RCC_CIR_PLLI2SRDYF_Pos          5U
#define RCC_CIR_CSSF_Pos                7U

#define RCC_CIR_LSIRDYIE_Pos            8U
#define RCC_CIR_LSERDYIE_Pos            9U
#define RCC_CIR_HSIRDYIE_Pos            10U
#define RCC_CIR_HSERDYIE_Pos            11U
#define RCC_CIR_PLLRDYIE_Pos            12U
#define RCC_CIR_PLLI2SRDYIE_Pos         13U

#define RCC_CIR_LSIRDYC_Pos             16U
#define RCC_CIR_LSERDYC_Pos             17U
#define RCC_CIR_HSIRDYC_Pos             18U
#define RCC_CIR_HSERDYC_Pos             19U
#define RCC_CIR_PLLRDYC_Pos             20U
#define RCC_CIR_PLLI2SRDYC_Pos          21U
#define RCC_CIR_CSSC_Pos                23U

/*
 * bit position definition for RCC AHB1ENR REGISTER
 */
#define RCC_AHB1ENR_GPIOAEN_Pos         0U
#define RCC_AHB1ENR_GPIOBEN_Pos         1U
#define RCC_AHB1ENR_GPIOCEN_Pos         2U
#define RCC_AHB1ENR_GPIODEN_Pos         3U
#define RCC_AHB1ENR_GPIOEEN_Pos         4U
#define RCC_AHB1ENR_GPIOFEN_Pos         5U
#define RCC_AHB1ENR_GPIOGEN_Pos         6U
#define RCC_AHB1ENR_GPIOHEN_Pos         7U
#define RCC_AHB1ENR_GPIOIEN_Pos         8U
#define RCC_AHB1ENR_CRCEN_Pos           12U
#define RCC_AHB1ENR_BKPSRAMEN_Pos       18U
#define RCC_AHB1ENR_DMA1EN_Pos          21U
#define RCC_AHB1ENR_DMA2EN_Pos          22U
#define RCC_AHB1ENR_ETHMACEN_Pos        25U
#define RCC_AHB1ENR_ETHMACTXEN_Pos      26U
#define RCC_AHB1ENR_ETHMACRXEN_Pos      27U
#define RCC_AHB1ENR_ETHMACPTPEN_Pos     28U
#define RCC_AHB1ENR_OTGHSEN_Pos         29U
#define RCC_AHB1ENR_OTGHSULPIEN_Pos     30U

/*
 * bit position definition for RCC AHB2ENR REGISTER
 */
#define RCC_AHB2ENR_DCMIEN_Pos          0U
#define RCC_AHB2ENR_CRYPEN_Pos          4U
#define RCC_AHB2ENR_HASHEN_Pos          5U
#define RCC_AHB2ENR_RNGEN_Pos           6U
#define RCC_AHB2ENR_OTGFSEN_Pos         7U

/*
 * bit position definition for RCC AHB3ENR REGISTER
 */
#define RCC_AHB3ENR_FMCEN_Pos           0U

/*
 * bit position definition for RCC APB1ENR REGISTER
 */
#define RCC_APB1ENR_TIM2EN_Pos          0U
#define RCC_APB1ENR_TIM3EN_Pos          1U
#define RCC_APB1ENR_TIM4EN_Pos          2U
#define RCC_APB1ENR_TIM5EN_Pos          3U
#define RCC_APB1ENR_TIM6EN_Pos          4U
#define RCC_APB1ENR_TIM7EN_Pos          5U
#define RCC_APB1ENR_TIM12EN_Pos         6U
#define RCC_APB1ENR_TIM13EN_Pos         7U
#define RCC_APB1ENR_TIM14EN_Pos         8U
#define RCC_APB1ENR_WWDGEN_Pos          11U
#define RCC_APB1ENR_SPI2EN_Pos          14U
#define RCC_APB1ENR_SPI3EN_Pos          15U
#define RCC_APB1ENR_USART2EN_Pos        17U
#define RCC_APB1ENR_USART3EN_Pos        18U
#define RCC_APB1ENR_UART4EN_Pos         19U
#define RCC_APB1ENR_UART5EN_Pos         20U
#define RCC_APB1ENR_I2C1EN_Pos          21U
#define RCC_APB1ENR_I2C2EN_Pos          22U
#define RCC_APB1ENR_I2C3EN_Pos          23U
#define RCC_APB1ENR_CAN1EN_Pos          25U
#define RCC_APB1ENR_CAN2EN_Pos          26U
#define RCC_APB1ENR_PWREN_Pos           28U
#define RCC_APB1ENR_DACEN_Pos           29U

/*
 * bit position definition for RCC APB2ENR REGISTER
 */
#define RCC_APB2ENR_TIM1EN_Pos          0U
#define RCC_APB2ENR_TIM8EN_Pos          1U
#define RCC_APB2ENR_USART1EN_Pos        4U
#define RCC_APB2ENR_USART6EN_Pos        5U
#define RCC_APB2ENR_ADC1EN_Pos          8U
#define RCC_APB2ENR_ADC2EN_Pos          9U
#define RCC_APB2ENR_ADC3EN_Pos          10U
#define RCC_APB2ENR_SDIOEN_Pos          11U
#define RCC_APB2ENR_SPI1EN_Pos          12U
#define RCC_APB2ENR_SYSCFGEN_Pos        14U
#define RCC_APB2ENR_TIM9EN_Pos          16U
#define RCC_APB2ENR_TIM10EN_Pos         17U
#define RCC_APB2ENR_TIM11EN_Pos         18U


/*
 * bit definition for RCC CR REGISTER
 */
#define RCC_CR_HSION                    (1U << 0U)
#define RCC_CR_HSIRDY                   (1U << 1U)
#define RCC_CR_HSEON                    (1U << 16U)
#define RCC_CR_HSERDY                   (1U << 17U)
#define RCC_CR_HSEBYP                   (1U << 18U)
#define RCC_CR_CSSON                    (1U << 19U)
#define RCC_CR_PLLON                    (1U << 24U)
#define RCC_CR_PLLRDY                   (1U << 25U)
#define RCC_CR_PLLI2SON                 (1U << 26U)
#define RCC_CR_PLLI2SRDY                (1U << 27U)
/*
 * bit definition for RCC PLLCFGR REGISTER
 */
#define RCC_PLLCFGR_PLLM                (0x3FU << 0U)
#define RCC_PLLCFGR_PLLN                (0x1FFU << 6U)
#define RCC_PLLCFGR_PLLP                (0x3U << 16U)
#define RCC_PLLCFGR_PLLSRC              (1U << 22U)
#define RCC_PLLCFGR_PLLQ                (0xFU << 24U)
/*
 * bit definition for RCC CFGR REGISTER
 */
#define RCC_CFGR_SW                     (0x3U << 0U)
#define RCC_CFGR_SWS                    (0x3U << 2U)
#define RCC_CFGR_HPRE                   (0xFU << 4U)
#define RCC_CFGR_PPRE1                  (0x7U << 10U)
#define RCC_CFGR_PPRE2                  (0x7U << 13U)
#define RCC_CFGR_RTCPRE                 (0x1FU << 16U)
#define RCC_CFGR_MCO1                   (0x3U << 21U)
#define RCC_CFGR_I2SSRC                 (1U << 23U)
#define RCC_CFGR_MCO1PRE                (0x7U << 24U)
#define RCC_CFGR_MCO2PRE                (0x7U << 27U)
#define RCC_CFGR_MCO2                   (0x3U << 30U)
/*
 * bit definition for RCC CIR REGISTER
*/
#define RCC_CIR_LSIRDYF                 (1U << 0U)
#define RCC_CIR_LSERDYF                 (1U << 1U)
#define RCC_CIR_HSIRDYF                 (1U << 2U)
#define RCC_CIR_HSERDYF                 (1U << 3U)
#define RCC_CIR_PLLRDYF                 (1U << 4U)
#define RCC_CIR_PLLI2SRDYF              (1U << 5U)
#define RCC_CIR_CSSF                    (1U << 7U)
#define RCC_CIR_LSIRDYIE                (1U << 8U)
#define RCC_CIR_LSERDYIE                (1U << 9U)
#define RCC_CIR_HSIRDYIE                (1U << 10U)
#define RCC_CIR_HSERDYIE                (1U << 11U)
#define RCC_CIR_PLLRDYIE                (1U << 12U)
#define RCC_CIR_PLLI2SRDYIE             (1U << 13U)
#define RCC_CIR_LSIRDYC                 (1U << 16U)
#define RCC_CIR_LSERDYC                 (1U << 17U)
#define RCC_CIR_HSIRDYC                 (1U << 18U)
#define RCC_CIR_HSERDYC                 (1U << 19U)
#define RCC_CIR_PLLRDYC                 (1U << 20U)
#define RCC_CIR_PLLI2SRDYC              (1U << 21U)
#define RCC_CIR_CSSC                    (1U << 23U)
/*
 * bit definition for RCC AHB1ENR REGISTER
 */
#define RCC_AHB1ENR_GPIOAEN             (1U << 0U)
#define RCC_AHB1ENR_GPIOBEN             (1U << 1U)
#define RCC_AHB1ENR_GPIOCEN             (1U << 2U)
#define RCC_AHB1ENR_GPIODEN             (1U << 3U)
#define RCC_AHB1ENR_GPIOEEN             (1U << 4U)
#define RCC_AHB1ENR_GPIOFEN             (1U << 5U)
#define RCC_AHB1ENR_GPIOGEN             (1U << 6U)
#define RCC_AHB1ENR_GPIOHEN             (1U << 7U)
#define RCC_AHB1ENR_GPIOIEN             (1U << 8U)
#define RCC_AHB1ENR_CRCEN               (1U << 12U)
#define RCC_AHB1ENR_BKPSRAMEN           (1U << 18U)
#define RCC_AHB1ENR_DMA1EN              (1U << 21U)
#define RCC_AHB1ENR_DMA2EN              (1U << 22U)
#define RCC_AHB1ENR_ETHMACEN            (1U << 25U)
#define RCC_AHB1ENR_ETHMACTXEN          (1U << 26U)
#define RCC_AHB1ENR_ETHMACRXEN          (1U << 27U)
#define RCC_AHB1ENR_ETHMACPTPEN         (1U << 28U)
#define RCC_AHB1ENR_OTGHSEN             (1U << 29U)
#define RCC_AHB1ENR_OTGHSULPIEN         (1U << 30U)
/*
 * bit definition for RCC AHB2ENR REGISTER
 */
#define RCC_AHB2ENR_DCMIEN              (1U << 0U)
#define RCC_AHB2ENR_CRYPEN              (1U << 4U)
#define RCC_AHB2ENR_HASHEN              (1U << 5U)
#define RCC_AHB2ENR_RNGEN               (1U << 6U)
#define RCC_AHB2ENR_OTGFSEN             (1U << 7U)
/*
 * bit definition for RCC AHB3ENR REGISTER
*/
#define RCC_AHB3ENR_FMCEN               (1U << 0U)
/*
 * bit definition for RCC APB1ENR REGISTER
*/
#define RCC_APB1ENR_TIM2EN              (1U << 0U)
#define RCC_APB1ENR_TIM3EN              (1U << 1U)
#define RCC_APB1ENR_TIM4EN              (1U << 2U)
#define RCC_APB1ENR_TIM5EN              (1U << 3U)
#define RCC_APB1ENR_TIM6EN              (1U << 4U)
#define RCC_APB1ENR_TIM7EN              (1U << 5U)
#define RCC_APB1ENR_TIM12EN             (1U << 6U)
#define RCC_APB1ENR_TIM13EN             (1U << 7U)
#define RCC_APB1ENR_TIM14EN             (1U << 8U)
#define RCC_APB1ENR_WWDGEN              (1U << 11U)
#define RCC_APB1ENR_SPI2EN              (1U << 14U)
#define RCC_APB1ENR_SPI3EN              (1U << 15U)
#define RCC_APB1ENR_USART2EN            (1U << 17U)
#define RCC_APB1ENR_USART3EN            (1U << 18U)
#define RCC_APB1ENR_UART4EN             (1U << 19U)
#define RCC_APB1ENR_UART5EN             (1U << 20U)
#define RCC_APB1ENR_I2C1EN              (1U << 21U)
#define RCC_APB1ENR_I2C2EN              (1U << 22U)
#define RCC_APB1ENR_I2C3EN              (1U << 23U)
#define RCC_APB1ENR_CAN1EN              (1U << 25U)
#define RCC_APB1ENR_CAN2EN              (1U << 26U)
#define RCC_APB1ENR_PWREN               (1U << 28U)
#define RCC_APB1ENR_DACEN               (1U << 29U)
/*
 * bit definition for RCC APB2ENR REGISTER
*/
#define RCC_APB2ENR_TIM1EN              (1U << 0U)
#define RCC_APB2ENR_TIM8EN              (1U << 1U)
#define RCC_APB2ENR_USART1EN            (1U << 4U)
#define RCC_APB2ENR_USART6EN            (1U << 5U)
#define RCC_APB2ENR_ADC1EN              (1U << 8U)
#define RCC_APB2ENR_ADC2EN              (1U << 9U)
#define RCC_APB2ENR_ADC3EN              (1U << 10U)
#define RCC_APB2ENR_SDIOEN              (1U << 11U)
#define RCC_APB2ENR_SPI1EN              (1U << 12U)
#define RCC_APB2ENR_SYSCFGEN            (1U << 14U)
#define RCC_APB2ENR_TIM9EN              (1U << 16U)
#define RCC_APB2ENR_TIM10EN             (1U << 17U)
#define RCC_APB2ENR_TIM11EN             (1U << 18U)
/*============================End of bitmasks definitions============================*/

/*macro definitions for enabling clock ports*/
#define RCC_ENABLE_PORTA_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN) 
#define RCC_ENABLE_PORTB_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN)
#define RCC_ENABLE_PORTC_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN)
#define RCC_ENABLE_PORTD_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN)
#define RCC_ENABLE_PORTE_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN)  
#define RCC_ENABLE_PORTF_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN)
#define RCC_ENABLE_PORTG_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN)
#define RCC_ENABLE_PORTH_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN)
#define RCC_ENABLE_PORTI_CLK()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN)

/*macro definition for disabling clock ports*/
#define RCC_DISABLE_PORTA_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN)
#define RCC_DISABLE_PORTB_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN)
#define RCC_DISABLE_PORTC_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN)
#define RCC_DISABLE_PORTD_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN)
#define RCC_DISABLE_PORTE_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN)
#define RCC_DISABLE_PORTF_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN)
#define RCC_DISABLE_PORTG_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN)
#define RCC_DISABLE_PORTH_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN)
#define RCC_DISABLE_PORTI_CLK()   (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN)

/*macro definitions for enabling clock for peripherals*/
#define RCC_ENABLE_TIM1_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_TIM1EN)
#define RCC_ENABLE_TIM2_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_TIM2EN)
#define RCC_ENABLE_TIM3_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_TIM3EN)
#define RCC_ENABLE_TIM4_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_TIM4EN)
#define RCC_ENABLE_TIM5_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_TIM5EN)
#define RCC_ENABLE_TIM6_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_TIM6EN)
#define RCC_ENABLE_TIM7_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_TIM7EN)
#define RCC_ENABLE_TIM8_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_TIM8EN)
#define RCC_ENABLE_TIM9_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_TIM9EN)
#define RCC_ENABLE_TIM10_CLK()    (RCC->APB2ENR |= RCC_APB2ENR_TIM10EN)
#define RCC_ENABLE_TIM11_CLK()    (RCC->APB2ENR |= RCC_APB2ENR_TIM11EN)

#define RCC_ENABLE_SPI1_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_SPI1EN)
#define RCC_ENABLE_SPI2_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_SPI2EN)
#define RCC_ENABLE_SPI3_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_SPI3EN)

#define RCC_ENABLE_USART1_CLK()   (RCC->APB2ENR |= RCC_APB2ENR_USART1EN)
#define RCC_ENABLE_USART2_CLK()   (RCC->APB1ENR |= RCC_APB1ENR_USART2EN)
#define RCC_ENABLE_USART3_CLK()   (RCC->APB1ENR |= RCC_APB1ENR_USART3EN)
#define RCC_ENABLE_UART4_CLK()    (RCC->APB1ENR |= RCC_APB1ENR_UART4EN)
#define RCC_ENABLE_UART5_CLK()    (RCC->APB1ENR |= RCC_APB1ENR_UART5EN)

#define RCC_ENABLE_I2C1_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_I2C1EN)
#define RCC_ENABLE_I2C2_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_I2C2EN)
#define RCC_ENABLE_I2C3_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_I2C3EN)

#define RCC_ENABLE_CAN1_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_CAN1EN)
#define RCC_ENABLE_CAN2_CLK()     (RCC->APB1ENR |= RCC_APB1ENR_CAN2EN)

#define RCC_ENABLE_PWR_CLK()      (RCC->APB1ENR |= RCC_APB1ENR_PWREN)
#define RCC_ENABLE_DAC_CLK()      (RCC->APB1ENR |= RCC_APB1ENR_DACEN)

#define RCC_ENABLE_USART6_CLK()   (RCC->APB2ENR |= RCC_APB2ENR_USART6EN)
#define RCC_ENABLE_ADC1_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_ADC1EN)
#define RCC_ENABLE_ADC2_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_ADC2EN)
#define RCC_ENABLE_ADC3_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_ADC3EN)
#define RCC_ENABLE_SDIO_CLK()     (RCC->APB2ENR |= RCC_APB2ENR_SDIOEN)

#define RCC_ENABLE_SYSCFG_CLK()   (RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN)

/*
    SYSCLK is selected from one of the following:
    1. HSI oscillator clock (16 MHz)    
    2. HSE oscillator clock (X MHz)
    3. PLL clock (configured as 168 MHz in this driver)

    PLL clock is derived from HSI or HSE clock
    PLL clock frequency can be calculated as follows:
    F_PLL = (F_CLK / PLLM) * PLLN / PLLP
    where F_CLK is the frequency of the clock source (HSI or HSE)
    PLLM can be a value from 2 to 63
    PLLN can be a value from 192 to 432
    PLLP can be 2, 4, 6 or 8 

    About register settings for PLL clock configuration:
    1. Select the clock source for PLL (HSI or HSE) by configuring PLLSRC bit in RCC_PLLCFGR register
    2. Configure PLLM, PLLN and PLLP values in RCC_PLLCFGR register
    3. Enable PLL by setting PLLON bit in RCC_CR register

    If choose HSE or HSI as PLL clock source, enable the respective clock and wait until it is ready before enabling
    PLL in RCC_CR register. After enabling PLL, wait until PLL is ready before switching system clock to PLL.

    Configure the system clock source by configuring SW bits in RCC_CFGR register. 
    After switching system clock source,

    prescaler for AHB bus can be configured to divide system clock by 1, 2, 4, 8, 16, 64, 128, 256 or 512
    by configuring HPRE bits in RCC_CFGR register
    prescaler for APB1 bus can be configured to divide AHB clock by 1, 2, 4, 8 or 16 by configuring 
    PPRE1 bits in RCC_CFGR register
    prescaler for APB2 bus can be configured to divide AHB clock by 1, 2, 4, 8 or 16 by configuring 
    PPRE2 bits in RCC_CFGR register
*/
// PLL configuration parameters PLLP = 2, 4, 6 or 8 -> 00, 01, 10 or 11 in PLLP bits of RCC_PLLCFGR register
#define RCC_PLLP_DIV2     0U
#define RCC_PLLP_DIV4     1U
#define RCC_PLLP_DIV6     2U
#define RCC_PLLP_DIV8     3U
// PLL clock source selection values for PLLSRC bit in RCC_PLLCFGR register
#define RCC_PLLSRC_HSI    0U
#define RCC_PLLSRC_HSE    1U
// System clock source selection values for SW bits in RCC_CFGR register 
#define RCC_SYSCLK_HSI    0U
#define RCC_SYSCLK_HSE    1U
#define RCC_SYSCLK_PLL    2U
// AHB prescaler values for HPRE bits in RCC_CFGR register
#define RCC_AHB_PRESCALER_DIV1     0U
#define RCC_AHB_PRESCALER_DIV2     8U
#define RCC_AHB_PRESCALER_DIC4     9U
#define RCC_AHB_PRESCALER_DIV8     10U
#define RCC_AHB_PRESCALER_DIV16    11U
#define RCC_AHB_PRESCALER_DIV64    12U
#define RCC_AHB_PRESCALER_DIV128   13U
#define RCC_AHB_PRESCALER_DIV256   14U
#define RCC_AHB_PRESCALER_DIV512   15U
// APB1 prescaler values for PPRE1 bits in RCC_CFGR register
#define RCC_APB1_PRESCALER_DIV1     0U
#define RCC_APB1_PRESCALER_DIV2     4U
#define RCC_APB1_PRESCALER_DIV4     5U
#define RCC_APB1_PRESCALER_DIV8     6U
#define RCC_APB1_PRESCALER_DIV16    7U
// APB2 prescaler values for PPRE2 bits in RCC_CFGR register
#define RCC_APB2_PRESCALER_DIV1     0U
#define RCC_APB2_PRESCALER_DIV2     4U  
#define RCC_APB2_PRESCALER_DIV4     5U
#define RCC_APB2_PRESCALER_DIV8     6U
#define RCC_APB2_PRESCALER_DIV16    7U
//define system clock switch status
#define RCC_SYSCLK_STATUS_HSI    0U
#define RCC_SYSCLK_STATUS_HSE    1U 
#define RCC_SYSCLK_STATUS_PLL    2U

#define HSI_CLOCK      16000000U
#define HSE_CLOCK      8000000U

//PLL configuration structure
typedef struct{
    uint32_t PLLM;      //PLL M value 2 <= PLLM <= 63 (6-bit value)
    uint32_t PLLN;      //PLL N value 50 <= PLLN <= 432 (9-bit value)
    uint32_t PLLP;      //PLL P value
    uint32_t PLLQ;      //PLL Q value
    uint8_t PLLSource;  //PLL clock source (HSI or HSE)
} RCC_PLL_Config_t;    

typedef struct{
    uint16_t SYSCLK_MHZ;    //system clock frequency in MHz

    uint32_t ClockSource;    //system clock source  
    uint32_t AHB_Prescaler;   //AHB prescaler value
    uint32_t APB1_Prescaler;  //APB1 prescaler value
    uint32_t APB2_Prescaler;  //APB2 prescaler value

    RCC_PLL_Config_t PLLConfig;   //PLL configuration parameters
} RCC_Clock_Config_t;    

/*----------------------------function_declarations-----------------------------*/
void RCC_Init(RCC_Clock_Config_t *RCC_ClockConfig);            //system clock initialization

void RCC_EnableHSI(void);       //enable HSI clock

void RCC_DisableHSI(void);      //disable HSI clock

void RCC_EnableHSE(void);       //enable HSE clock
void RCC_DisableHSE(void);      //disable HSE clock

void RCC_EnablePLL(void);       //enable PLL clock
void RCC_DisablePLL(void);      //disable PLL clock

void RCC_SetSystemClockTo84MHz(void);
void RCC_SetSystemClockTo168MHz(void);

uint32_t RCC_GetSYSCLKValue(void);
uint32_t RCC_GetHCLKValue(void);
uint32_t RCC_GetPCLK1Value(void);
uint32_t RCC_GetPCLK2Value(void);

#endif /* __STM32F407XXX_RCC_H */
