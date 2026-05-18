#ifndef __STM32F407XXX_GPIO_H
#define __STM32F407XXX_GPIO_H

#include "stm32f407xxx.h"

/*Define pin mask*/
#define PIN_MASK_1BIT       1U
#define PIN_MASK_2BIT       3U
#define PIN_MASK_3BIT       7U
#define PIN_MASK_4BIT       15U


/*Define GPIO_PIN*/
#define GPIO_PIN_0          ((uint16_t)0x0001)
#define GPIO_PIN_1          ((uint16_t)0x0002)
#define GPIO_PIN_2          ((uint16_t)0x0004)
#define GPIO_PIN_3          ((uint16_t)0x0008)
#define GPIO_PIN_4          ((uint16_t)0x0010)
#define GPIO_PIN_5          ((uint16_t)0x0020)
#define GPIO_PIN_6          ((uint16_t)0x0040)
#define GPIO_PIN_7          ((uint16_t)0x0080)
#define GPIO_PIN_8          ((uint16_t)0x0100)
#define GPIO_PIN_9          ((uint16_t)0x0200)
#define GPIO_PIN_10         ((uint16_t)0x0400)
#define GPIO_PIN_11         ((uint16_t)0x0800)
#define GPIO_PIN_12         ((uint16_t)0x1000)
#define GPIO_PIN_13         ((uint16_t)0x2000)
#define GPIO_PIN_14         ((uint16_t)0x4000)
#define GPIO_PIN_15         ((uint16_t)0x8000)

/* STM32F407 Alternate Function Defines (PA0 to PI15) */

#define GPIO_AF0      0U
#define GPIO_AF1      1U
#define GPIO_AF2      2U
#define GPIO_AF3      3U
#define GPIO_AF4      4U
#define GPIO_AF5      5U
#define GPIO_AF6      6U
#define GPIO_AF7      7U
#define GPIO_AF8      8U
#define GPIO_AF9      9U
#define GPIO_AF10     10U
#define GPIO_AF11     11U
#define GPIO_AF12     12U
#define GPIO_AF13     13U
#define GPIO_AF14     14U
#define GPIO_AF15     15U
//PA0
#define GPIO_AF_PA0_TIM2_CH1_ETR         GPIO_AF1
#define GPIO_AF_PA0_TIM5_CH1             GPIO_AF2
#define GPIO_AF_PA0_TIM8_ETR             GPIO_AF3
#define GPIO_AF_PA0_USART2_CTS           GPIO_AF7
#define GPIO_AF_PA0_UART4_TX             GPIO_AF8
#define GPIO_AF_PA0_ETH_MII_CRS          GPIO_AF11
#define GPIO_AF_PA0_EVENTOUT             GPIO_AF15
//PA1
#define GPIO_AF_PA1_TIM2_CH2             GPIO_AF1
#define GPIO_AF_PA1_TIM5_CH2             GPIO_AF2
#define GPIO_AF_PA1_USART2_RTS           GPIO_AF7
#define GPIO_AF_PA1_UART4_RX             GPIO_AF8
#define GPIO_AF_PA1_ETH_MII_RX_CLK       GPIO_AF11
#define GPIO_AF_PA1_ETH_RMII_REF_CLK     GPIO_AF11
#define GPIO_AF_PA1_EVENTOUT             GPIO_AF15
//PA2
#define GPIO_AF_PA2_TIM2_CH3             GPIO_AF1
#define GPIO_AF_PA2_TIM5_CH3             GPIO_AF2
#define GPIO_AF_PA2_TIM9_CH1             GPIO_AF3
#define GPIO_AF_PA2_USART2_TX            GPIO_AF7
#define GPIO_AF_PA2_ETH_MDIO             GPIO_AF11
#define GPIO_AF_PA2_EVENTOUT             GPIO_AF15
//PA3
#define GPIO_AF_PA3_TIM2_CH4             GPIO_AF1
#define GPIO_AF_PA3_TIM5_CH4             GPIO_AF2
#define GPIO_AF_PA3_TIM9_CH2             GPIO_AF3
#define GPIO_AF_PA3_USART2_RX            GPIO_AF7
#define GPIO_AF_PA3_OTG_HS_ULPI_D0       GPIO_AF10
#define GPIO_AF_PA3_ETH_MII_COL          GPIO_AF11
//PA4
#define GPIO_AF_PA3_EVENTOUT             GPIO_AF15
#define GPIO_AF_PA4_SPI1_NSS             GPIO_AF5
#define GPIO_AF_PA4_SPI3_NSS             GPIO_AF6
#define GPIO_AF_PA4_I2S3_WS              GPIO_AF6
#define GPIO_AF_PA4_USART2_CK            GPIO_AF7
#define GPIO_AF_PA4_OTG_HS_SOF           GPIO_AF12
#define GPIO_AF_PA4_DCMI_HSYNC           GPIO_AF13
#define GPIO_AF_PA4_EVENTOUT             GPIO_AF15
//PA5
#define GPIO_AF_PA5_TIM2_CH1_ETR         GPIO_AF1
#define GPIO_AF_PA5_TIM8_CH1N            GPIO_AF3
#define GPIO_AF_PA5_SPI1_SCK             GPIO_AF5
#define GPIO_AF_PA5_OTG_HS_ULPI_CK       GPIO_AF10
#define GPIO_AF_PA5_EVENTOUT             GPIO_AF15
//PA6
#define GPIO_AF_PA6_TIM1_BKIN            GPIO_AF1
#define GPIO_AF_PA6_TIM3_CH1             GPIO_AF2
#define GPIO_AF_PA6_TIM8_BKIN            GPIO_AF3
#define GPIO_AF_PA6_SPI1_MISO            GPIO_AF5
#define GPIO_AF_PA6_DCMI_PIXCK           GPIO_AF13
#define GPIO_AF_PA6_EVENTOUT             GPIO_AF15
//PA7
#define GPIO_AF_PA7_TIM1_CH1N            GPIO_AF1
#define GPIO_AF_PA7_TIM3_CH2             GPIO_AF2
#define GPIO_AF_PA7_TIM8_CH1N            GPIO_AF3
#define GPIO_AF_PA7_SPI1_MOSI            GPIO_AF5
#define GPIO_AF_PA7_ETH_MII_RX_DV        GPIO_AF11
#define GPIO_AF_PA7_ETH_RMII_CRS_DV      GPIO_AF11
#define GPIO_AF_PA7_EVENTOUT             GPIO_AF15
//PA8
#define GPIO_AF_PA8_MCO1                 GPIO_AF0
#define GPIO_AF_PA8_TIM1_CH1             GPIO_AF1
#define GPIO_AF_PA8_I2C3_SCL             GPIO_AF4
#define GPIO_AF_PA8_OTG_FS_SOF           GPIO_AF10
#define GPIO_AF_PA8_EVENTOUT             GPIO_AF15
//PA9
#define GPIO_AF_PA9_TIM1_CH2             GPIO_AF1
#define GPIO_AF_PA9_I2C3_SMBA            GPIO_AF4
#define GPIO_AF_PA9_USART1_TX            GPIO_AF7
#define GPIO_AF_PA9_DCMI_D0              GPIO_AF13
#define GPIO_AF_PA9_EVENTOUT             GPIO_AF15
//PA10
#define GPIO_AF_PA10_TIM1_CH3             GPIO_AF1
#define GPIO_AF_PA10_USART1_RX            GPIO_AF7
#define GPIO_AF_PA10_OTG_FS_ID            GPIO_AF10
#define GPIO_AF_PA10_DCMI_D1              GPIO_AF13
#define GPIO_AF_PA10_EVENTOUT             GPIO_AF15
//PA11
#define GPIO_AF_PA11_TIM1_CH4             GPIO_AF1
#define GPIO_AF_PA11_USART1_CTS           GPIO_AF7
#define GPIO_AF_PA11_CAN1_RX              GPIO_AF9
#define GPIO_AF_PA11_OTG_FS_DM            GPIO_AF10
#define GPIO_AF_PA11_EVENTOUT             GPIO_AF15
//PA12
#define GPIO_AF_PA12_TIM1_ETR             GPIO_AF1
#define GPIO_AF_PA12_USART1_RTS           GPIO_AF7
#define GPIO_AF_PA12_CAN1_TX              GPIO_AF9
#define GPIO_AF_PA12_OTG_FS_DP            GPIO_AF10
#define GPIO_AF_PA12_EVENTOUT             GPIO_AF15
//PA13
#define GPIO_AF_PA13_JTMS_SWDIO           GPIO_AF0
#define GPIO_AF_PA13_EVENTOUT             GPIO_AF15
//PA14
#define GPIO_AF_PA14_JTCK_SWCLK           GPIO_AF0
#define GPIO_AF_PA14_EVENTOUT             GPIO_AF15
//PA15
#define GPIO_AF_PA15_JTDI                 GPIO_AF0
#define GPIO_AF_PA15_TIM2_CH1_ETR         GPIO_AF1
#define GPIO_AF_PA15_SPI1_NSS             GPIO_AF5
#define GPIO_AF_PA15_SPI3_NSS             GPIO_AF6
#define GPIO_AF_PA15_I2S3_WS              GPIO_AF6
#define GPIO_AF_PA15_EVENTOUT             GPIO_AF15
//PB0
#define GPIO_AF_PB0_TIM1_CH2N            GPIO_AF1
#define GPIO_AF_PB0_TIM3_CH3             GPIO_AF2
#define GPIO_AF_PB0_TIM8_CH2N            GPIO_AF3
#define GPIO_AF_PB0_OTG_HS_ULPI_D1       GPIO_AF10
#define GPIO_AF_PB0_ETH_MII_RXD2         GPIO_AF11
#define GPIO_AF_PB0_EVENTOUT             GPIO_AF15
//PB1
#define GPIO_AF_PB1_TIM1_CH3N            GPIO_AF1
#define GPIO_AF_PB1_TIM3_CH4             GPIO_AF2
#define GPIO_AF_PB1_TIM8_CH3N            GPIO_AF3
#define GPIO_AF_PB1_OTG_HS_ULPI_D2       GPIO_AF10
#define GPIO_AF_PB1_ETH_MII_RXD3         GPIO_AF11
#define GPIO_AF_PB1_EVENTOUT             GPIO_AF15
//PB2
#define GPIO_AF_PB2_EVENTOUT             GPIO_AF15
//PB3
#define GPIO_AF_PB3_JTDO                 GPIO_AF0
#define GPIO_AF_PB3_TRACESWO             GPIO_AF0
#define GPIO_AF_PB3_TIM2_CH2             GPIO_AF1
#define GPIO_AF_PB3_SPI1_SCK             GPIO_AF5
#define GPIO_AF_PB3_SPI3_SCK             GPIO_AF6
#define GPIO_AF_PB3_I2S3_CK              GPIO_AF6
#define GPIO_AF_PB3_EVENTOUT             GPIO_AF15
//PB4
#define GPIO_AF_PB4_NJTRST               GPIO_AF0
#define GPIO_AF_PB4_TIM3_CH1             GPIO_AF2
#define GPIO_AF_PB4_SPI1_MISO            GPIO_AF5
#define GPIO_AF_PB4_SPI3_MISO            GPIO_AF6
#define GPIO_AF_PB4_EVENTOUT             GPIO_AF15
//PB5
#define GPIO_AF_PB5_TIM3_CH2             GPIO_AF2
#define GPIO_AF_PB5_I2C1_SMBA            GPIO_AF4
#define GPIO_AF_PB5_SPI1_MOSI            GPIO_AF5
#define GPIO_AF_PB5_SPI3_MOSI            GPIO_AF6
#define GPIO_AF_PB5_I2S3_SD              GPIO_AF6
#define GPIO_AF_PB5_CAN2_RX              GPIO_AF9
#define GPIO_AF_PB5_OTG_HS_ULPI_D7       GPIO_AF10
#define GPIO_AF_PB5_ETH_PPS_OUT          GPIO_AF11
#define GPIO_AF_PB5_DCMI_D10             GPIO_AF13
#define GPIO_AF_PB5_EVENTOUT             GPIO_AF15
//PB6
#define GPIO_AF_PB6_TIM4_CH1             GPIO_AF1
#define GPIO_AF_PB6_I2C1_SCL             GPIO_AF4
#define GPIO_AF_PB6_USART1_TX            GPIO_AF7
#define GPIO_AF_PB6_CAN2_TX              GPIO_AF9
#define GPIO_AF_PB6_DCMI_D5              GPIO_AF13
#define GPIO_AF_PB6_EVENTOUT             GPIO_AF15
//PB7
#define GPIO_AF_PB7_TIM4_CH2             GPIO_AF1
#define GPIO_AF_PB7_I2C1_SDA             GPIO_AF4
#define GPIO_AF_PB7_USART1_RX            GPIO_AF7
#define GPIO_AF_PB7_FSMC_NL              GPIO_AF12
#define GPIO_AF_PB7_DCMI_VSYNC           GPIO_AF13
#define GPIO_AF_PB7_EVENTOUT             GPIO_AF15
//PB8
#define GPIO_AF_PB8_TIM4_CH3             GPIO_AF1
#define GPIO_AF_PB8_TIM10_CH1            GPIO_AF1
#define GPIO_AF_PB8_I2C1_SCL             GPIO_AF4
#define GPIO_AF_PB8_CAN1_RX              GPIO_AF9
#define GPIO_AF_PB8_ETH_MII_TXD3         GPIO_AF11
#define GPIO_AF_PB8_SDIO_D4              GPIO_AF12
#define GPIO_AF_PB8_DCMI_D6              GPIO_AF13
#define GPIO_AF_PB8_EVENTOUT             GPIO_AF15
//PB9
#define GPIO_AF_PB9_TIM4_CH4             GPIO_AF1
#define GPIO_AF_PB9_TIM11_CH1            GPIO_AF1
#define GPIO_AF_PB9_I2C1_SDA             GPIO_AF4
#define GPIO_AF_PB9_SPI2_NSS             GPIO_AF5
#define GPIO_AF_PB9_I2S2_WS              GPIO_AF5
#define GPIO_AF_PB9_CAN1_TX              GPIO_AF9
#define GPIO_AF_PB9_ETH_MII_TXD3         GPIO_AF11
#define GPIO_AF_PB9_SDIO_D5              GPIO_AF12
#define GPIO_AF_PB9_DCMI_D7              GPIO_AF13
#define GPIO_AF_PB9_EVENTOUT             GPIO_AF15
//PB10
#define GPIO_AF_PB10_TIM2_CH3             GPIO_AF1
#define GPIO_AF_PB10_I2C2_SCL             GPIO_AF4
#define GPIO_AF_PB10_SPI2_SCK             GPIO_AF5
#define GPIO_AF_PB10_I2S2_CK              GPIO_AF5
#define GPIO_AF_PB10_USART3_TX            GPIO_AF7
#define GPIO_AF_PB10_OTG_HS_ULPI_D3       GPIO_AF10
#define GPIO_AF_PB10_ETH_MII_RX_ER        GPIO_AF11
#define GPIO_AF_PB10_EVENTOUT             GPIO_AF15
//PB11
#define GPIO_AF_PB11_TIM2_CH4             GPIO_AF1
#define GPIO_AF_PB11_I2C2_SDA             GPIO_AF4
#define GPIO_AF_PB11_USART3_RX            GPIO_AF7
#define GPIO_AF_PB11_OTG_HS_ULPI_D4       GPIO_AF10
#define GPIO_AF_PB11_ETH_MII_TX_EN        GPIO_AF11
#define GPIO_AF_PB11_ETH_RMII_TX_EN       GPIO_AF11
#define GPIO_AF_PB11_EVENTOUT             GPIO_AF15
//PB12
#define GPIO_AF_PB12_TIM1_BKIN            GPIO_AF1
#define GPIO_AF_PB12_I2C2_SMBA            GPIO_AF4
#define GPIO_AF_PB12_SPI2_NSS             GPIO_AF5
#define GPIO_AF_PB12_I2S2_WS              GPIO_AF5
#define GPIO_AF_PB12_USART3_CK            GPIO_AF7
#define GPIO_AF_PB12_CAN2_RX              GPIO_AF9
#define GPIO_AF_PB12_OTG_HS_ULPI_D5       GPIO_AF10
#define GPIO_AF_PB12_ETH_MII_TXD0         GPIO_AF11
#define GPIO_AF_PB12_ETH_RMII_TXD0        GPIO_AF11
#define GPIO_AF_PB12_OTG_HS_ID            GPIO_AF12
#define GPIO_AF_PB12_EVENTOUT             GPIO_AF15
//PB13
#define GPIO_AF_PB13_TIM1_CH1N            GPIO_AF1
#define GPIO_AF_PB13_SPI2_SCK             GPIO_AF5
#define GPIO_AF_PB13_I2S2_CK              GPIO_AF5
#define GPIO_AF_PB13_USART3_CTS           GPIO_AF7
#define GPIO_AF_PB13_CAN2_TX              GPIO_AF9
#define GPIO_AF_PB13_OTG_HS_ULPI_D6       GPIO_AF10
#define GPIO_AF_PB13_ETH_MII_TXD1         GPIO_AF11
#define GPIO_AF_PB13_ETH_RMII_TXD1        GPIO_AF11
#define GPIO_AF_PB13_EVENTOUT             GPIO_AF15
//PB14
#define GPIO_AF_PB14_TIM1_CH2N            GPIO_AF1
#define GPIO_AF_PB14_TIM8_CH2N            GPIO_AF2
#define GPIO_AF_PB14_TIM12_CH1            GPIO_AF1
#define GPIO_AF_PB14_SPI2_MISO            GPIO_AF5
#define GPIO_AF_PB14_I2S2ext_SD           GPIO_AF5
#define GPIO_AF_PB14_USART3_RTS           GPIO_AF7
#define GPIO_AF_PB14_EVENTOUT             GPIO_AF15
//PB15
#define GPIO_AF_PB15_RTC_REFIN            GPIO_AF0
#define GPIO_AF_PB15_TIM1_CH3N            GPIO_AF1
#define GPIO_AF_PB15_TIM8_CH3N            GPIO_AF2
#define GPIO_AF_PB15_TIM12_CH2            GPIO_AF1
#define GPIO_AF_PB15_SPI2_MOSI            GPIO_AF5
#define GPIO_AF_PB15_I2S2_SD              GPIO_AF5
#define GPIO_AF_PB15_EVENTOUT             GPIO_AF15
//PC0
#define GPIO_AF_PC0_OTG_HS_ULPI_STP      GPIO_AF10
#define GPIO_AF_PC0_EVENTOUT             GPIO_AF15
//PC1
#define GPIO_AF_PC1_ETH_MDC              GPIO_AF11
#define GPIO_AF_PC1_EVENTOUT             GPIO_AF15
//PC2
#define GPIO_AF_PC2_SPI2_MISO            GPIO_AF5
#define GPIO_AF_PC2_I2S2ext_SD           GPIO_AF5
#define GPIO_AF_PC2_OTG_HS_ULPI_DIR      GPIO_AF10
#define GPIO_AF_PC2_ETH_MII_TXD2         GPIO_AF11
#define GPIO_AF_PC2_EVENTOUT             GPIO_AF15
//PC3
#define GPIO_AF_PC3_SPI2_MOSI            GPIO_AF5
#define GPIO_AF_PC3_I2S2_SD              GPIO_AF5
#define GPIO_AF_PC3_OTG_HS_ULPI_NXT      GPIO_AF10
#define GPIO_AF_PC3_ETH_MII_TX_CLK       GPIO_AF11
#define GPIO_AF_PC3_EVENTOUT             GPIO_AF15
//PC4
#define GPIO_AF_PC4_ETH_MII_RXD0         GPIO_AF11
#define GPIO_AF_PC4_ETH_RMII_RXD0        GPIO_AF11
#define GPIO_AF_PC4_EVENTOUT             GPIO_AF15
//PC5
#define GPIO_AF_PC5_ETH_MII_RXD1         GPIO_AF11
#define GPIO_AF_PC5_ETH_RMII_RXD1        GPIO_AF11
#define GPIO_AF_PC5_EVENTOUT             GPIO_AF15
//PC6
#define GPIO_AF_PC6_TIM3_CH1             GPIO_AF2
#define GPIO_AF_PC6_TIM8_CH1             GPIO_AF3
#define GPIO_AF_PC6_I2S2_MCK             GPIO_AF6
#define GPIO_AF_PC6_USART6_TX            GPIO_AF8
#define GPIO_AF_PC6_SDIO_D6              GPIO_AF12
#define GPIO_AF_PC6_DCMI_D0              GPIO_AF13
#define GPIO_AF_PC6_EVENTOUT             GPIO_AF15
//PC7
#define GPIO_AF_PC7_TIM3_CH2             GPIO_AF2
#define GPIO_AF_PC7_TIM8_CH2             GPIO_AF3
#define GPIO_AF_PC7_I2S3_MCK             GPIO_AF6
#define GPIO_AF_PC7_USART6_RX            GPIO_AF8
#define GPIO_AF_PC7_SDIO_D7              GPIO_AF12
#define GPIO_AF_PC7_DCMI_D1              GPIO_AF13
#define GPIO_AF_PC7_EVENTOUT             GPIO_AF15
//PC8
#define GPIO_AF_PC8_TIM3_CH3             GPIO_AF2
#define GPIO_AF_PC8_TIM8_CH3             GPIO_AF3
#define GPIO_AF_PC8_USART6_CK            GPIO_AF8
#define GPIO_AF_PC8_SDIO_D0              GPIO_AF12
#define GPIO_AF_PC8_DCMI_D2              GPIO_AF13
#define GPIO_AF_PC8_EVENTOUT             GPIO_AF15
//PC9
#define GPIO_AF_PC9_MCO2                 GPIO_AF0
#define GPIO_AF_PC9_TIM3_CH4             GPIO_AF2
#define GPIO_AF_PC9_TIM8_CH4             GPIO_AF3
#define GPIO_AF_PC9_I2C3_SDA             GPIO_AF4
#define GPIO_AF_PC9_I2S_CKIN             GPIO_AF6
#define GPIO_AF_PC9_SDIO_D1              GPIO_AF12
#define GPIO_AF_PC9_DCMI_D3              GPIO_AF13
#define GPIO_AF_PC9_EVENTOUT             GPIO_AF15
//PC10
#define GPIO_AF_PC10_SPI3_SCK             GPIO_AF6
#define GPIO_AF_PC10_I2S3_CK              GPIO_AF6
#define GPIO_AF_PC10_USART3_TX            GPIO_AF7
#define GPIO_AF_PC10_UART4_TX             GPIO_AF8
#define GPIO_AF_PC10_SDIO_D2              GPIO_AF12
#define GPIO_AF_PC10_EVENTOUT             GPIO_AF15
//PC11
#define GPIO_AF_PC11_I2S3ext_SD           GPIO_AF6
#define GPIO_AF_PC11_SPI3_MISO            GPIO_AF5
#define GPIO_AF_PC11_USART3_RX            GPIO_AF7
#define GPIO_AF_PC11_UART4_RX             GPIO_AF8
#define GPIO_AF_PC11_SDIO_D3              GPIO_AF12
#define GPIO_AF_PC11_EVENTOUT             GPIO_AF15
//PC12
#define GPIO_AF_PC12_SPI3_MOSI            GPIO_AF6
#define GPIO_AF_PC12_I2S3_SD              GPIO_AF6
#define GPIO_AF_PC12_USART3_CK            GPIO_AF7
#define GPIO_AF_PC12_UART5_TX             GPIO_AF8
#define GPIO_AF_PC12_SDIO_CK              GPIO_AF12
#define GPIO_AF_PC12_EVENTOUT             GPIO_AF15
//PC13
#define GPIO_AF_PC13_EVENTOUT             GPIO_AF15
//PC14
#define GPIO_AF_PC14_EVENTOUT             GPIO_AF15
//PC15
#define GPIO_AF_PC15_EVENTOUT             GPIO_AF15
//PD0
#define GPIO_AF_PD0_CAN1_RX              GPIO_AF9
#define GPIO_AF_PD0_FSMC_D2              GPIO_AF12
#define GPIO_AF_PD0_EVENTOUT             GPIO_AF15
//PD1
#define GPIO_AF_PD1_CAN1_TX              GPIO_AF9
#define GPIO_AF_PD1_FSMC_D3              GPIO_AF12
#define GPIO_AF_PD1_EVENTOUT             GPIO_AF15
//PD2
#define GPIO_AF_PD2_TIM3_ETR             GPIO_AF2
#define GPIO_AF_PD2_UART5_RX             GPIO_AF8
#define GPIO_AF_PD2_SDIO_CMD             GPIO_AF12
#define GPIO_AF_PD2_DCMI_D11             GPIO_AF13
#define GPIO_AF_PD2_EVENTOUT             GPIO_AF15
//PD3
#define GPIO_AF_PD3_USART2_CTS           GPIO_AF7
#define GPIO_AF_PD3_FSMC_CLK             GPIO_AF12
#define GPIO_AF_PD3_EVENTOUT             GPIO_AF15
//PD4
#define GPIO_AF_PD4_USART2_RTS           GPIO_AF7
#define GPIO_AF_PD4_FSMC_NOE             GPIO_AF12
#define GPIO_AF_PD4_EVENTOUT             GPIO_AF15
//PD5
#define GPIO_AF_PD5_USART2_TX            GPIO_AF7
#define GPIO_AF_PD5_FSMC_NWE             GPIO_AF12
#define GPIO_AF_PD5_EVENTOUT             GPIO_AF15
//PD6
#define GPIO_AF_PD6_USART2_RX            GPIO_AF7
#define GPIO_AF_PD6_FSMC_NWAIT           GPIO_AF12
#define GPIO_AF_PD6_EVENTOUT             GPIO_AF15
//PD7
#define GPIO_AF_PD7_USART2_CK            GPIO_AF7
#define GPIO_AF_PD7_FSMC_NE1             GPIO_AF12
#define GPIO_AF_PD7_FSMC_NCE2            GPIO_AF12
#define GPIO_AF_PD7_EVENTOUT             GPIO_AF15
//PD8
#define GPIO_AF_PD8_USART3_TX            GPIO_AF7
#define GPIO_AF_PD8_FSMC_D13             GPIO_AF12
#define GPIO_AF_PD8_EVENTOUT             GPIO_AF15
//PD9
#define GPIO_AF_PD9_USART3_RX            GPIO_AF7
#define GPIO_AF_PD9_FSMC_D14             GPIO_AF12
#define GPIO_AF_PD9_EVENTOUT             GPIO_AF15
//PD10 
#define GPIO_AF_PD10_USART3_CK            GPIO_AF7
#define GPIO_AF_PD10_FSMC_D15             GPIO_AF12
#define GPIO_AF_PD10_EVENTOUT             GPIO_AF15
//PD11
#define GPIO_AF_PD11_USART3_CTS           GPIO_AF7
#define GPIO_AF_PD11_FSMC_A16             GPIO_AF12
#define GPIO_AF_PD11_EVENTOUT             GPIO_AF15
//PD12
#define GPIO_AF_PD12_TIM4_CH1             GPIO_AF1
#define GPIO_AF_PD12_USART3_RTS           GPIO_AF7
#define GPIO_AF_PD12_FSMC_A17             GPIO_AF12
#define GPIO_AF_PD12_EVENTOUT             GPIO_AF15
//PD13
#define GPIO_AF_PD13_TIM4_CH2             GPIO_AF1
#define GPIO_AF_PD13_FSMC_A18             GPIO_AF12
#define GPIO_AF_PD13_EVENTOUT             GPIO_AF15
//PD14
#define GPIO_AF_PD14_TIM4_CH3             GPIO_AF1
#define GPIO_AF_PD14_FSMC_D0              GPIO_AF12
#define GPIO_AF_PD14_EVENTOUT             GPIO_AF15
//PD15
#define GPIO_AF_PD15_TIM4_CH4             GPIO_AF1
#define GPIO_AF_PD15_FSMC_D1              GPIO_AF12
#define GPIO_AF_PD15_EVENTOUT             GPIO_AF15
//PE0
#define GPIO_AF_PE0_TIM4_ETR             GPIO_AF2
#define GPIO_AF_PE0_FSMC_NBL0            GPIO_AF12
#define GPIO_AF_PE0_DCMI_D2              GPIO_AF13
#define GPIO_AF_PE0_EVENTOUT             GPIO_AF15
//PE1
#define GPIO_AF_PE1_FSMC_NBL1            GPIO_AF12
#define GPIO_AF_PE1_DCMI_D3              GPIO_AF13
#define GPIO_AF_PE1_EVENTOUT             GPIO_AF15
//PE2
#define GPIO_AF_PE2_TRACECLK             GPIO_AF0
#define GPIO_AF_PE2_ETH_MII_TXD3         GPIO_AF11
#define GPIO_AF_PE2_FSMC_A23             GPIO_AF12
#define GPIO_AF_PE2_EVENTOUT             GPIO_AF15
//PE3
#define GPIO_AF_PE3_TRACED0              GPIO_AF0
#define GPIO_AF_PE3_FSMC_A19             GPIO_AF12
#define GPIO_AF_PE3_EVENTOUT             GPIO_AF15
//PE4
#define GPIO_AF_PE4_TRACED1              GPIO_AF0
#define GPIO_AF_PE4_FSMC_A20             GPIO_AF12
#define GPIO_AF_PE4_DCMI_D4              GPIO_AF13
#define GPIO_AF_PE4_EVENTOUT             GPIO_AF15
//PE5
#define GPIO_AF_PE5_TRACED2              GPIO_AF0
#define GPIO_AF_PE5_TIM9_CH1             GPIO_AF3
#define GPIO_AF_PE5_FSMC_A21             GPIO_AF12
#define GPIO_AF_PE5_DCMI_D6              GPIO_AF13
#define GPIO_AF_PE5_EVENTOUT             GPIO_AF15
//PE6
#define GPIO_AF_PE6_TRACED3              GPIO_AF0
#define GPIO_AF_PE6_TIM9_CH2             GPIO_AF3
#define GPIO_AF_PE6_FSMC_A22             GPIO_AF12
#define GPIO_AF_PE6_DCMI_D7              GPIO_AF13
#define GPIO_AF_PE6_EVENTOUT             GPIO_AF15
//PE7
#define GPIO_AF_PE7_TIM1_ETR             GPIO_AF1
#define GPIO_AF_PE7_FSMC_D4              GPIO_AF12
#define GPIO_AF_PE7_EVENTOUT             GPIO_AF15
//PE8
#define GPIO_AF_PE8_TIM1_CH1N            GPIO_AF1
#define GPIO_AF_PE8_FSMC_D5              GPIO_AF12
#define GPIO_AF_PE8_EVENTOUT             GPIO_AF15
//PE9
#define GPIO_AF_PE9_TIM1_CH1             GPIO_AF1
#define GPIO_AF_PE9_FSMC_D6              GPIO_AF12
#define GPIO_AF_PE9_EVENTOUT             GPIO_AF15
//PE10
#define GPIO_AF_PE10_TIM1_CH2N            GPIO_AF1
#define GPIO_AF_PE10_FSMC_D7              GPIO_AF12
#define GPIO_AF_PE10_EVENTOUT             GPIO_AF15
//PE11
#define GPIO_AF_PE11_TIM1_CH2             GPIO_AF1
#define GPIO_AF_PE11_FSMC_D8              GPIO_AF12
#define GPIO_AF_PE11_EVENTOUT             GPIO_AF15
//PE12
#define GPIO_AF_PE12_TIM1_CH3N            GPIO_AF1
#define GPIO_AF_PE12_FSMC_D9              GPIO_AF12
#define GPIO_AF_PE12_EVENTOUT             GPIO_AF15
//PE13
#define GPIO_AF_PE13_TIM1_CH3             GPIO_AF1
#define GPIO_AF_PE13_FSMC_D10             GPIO_AF12
#define GPIO_AF_PE13_EVENTOUT             GPIO_AF15
//PE14
#define GPIO_AF_PE14_TIM1_CH4             GPIO_AF1
#define GPIO_AF_PE14_FSMC_D11             GPIO_AF12
#define GPIO_AF_PE14_EVENTOUT             GPIO_AF15
//PE15
#define GPIO_AF_PE15_TIM1_BKIN            GPIO_AF1
#define GPIO_AF_PE15_FSMC_D12             GPIO_AF12
#define GPIO_AF_PE15_EVENTOUT             GPIO_AF15
//PF0
#define GPIO_AF_PF0_I2C2_SDA              GPIO_AF4
#define GPIO_AF_PF0_FSMC_A0               GPIO_AF12
#define GPIO_AF_PF0_EVENTOUT              GPIO_AF15
//PF1
#define GPIO_AF_PF1_I2C2_SCL              GPIO_AF4
#define GPIO_AF_PF1_FSMC_A1               GPIO_AF12
#define GPIO_AF_PF1_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF2_I2C2_SMBA             GPIO_AF4
#define GPIO_AF_PF2_FSMC_A2               GPIO_AF12
#define GPIO_AF_PF2_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF3_FSMC_A3               GPIO_AF12
#define GPIO_AF_PF3_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF4_FSMC_A4               GPIO_AF12
#define GPIO_AF_PF4_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF5_FSMC_A5               GPIO_AF12
#define GPIO_AF_PF5_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF6_TIM10_CH1             GPIO_AF3
#define GPIO_AF_PF6_FSMC_NIORD            GPIO_AF12
#define GPIO_AF_PF6_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF7_TIM11_CH1             GPIO_AF3
#define GPIO_AF_PF7_FSMC_NREG             GPIO_AF12
#define GPIO_AF_PF7_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF8_TIM13_CH1             GPIO_AF9
#define GPIO_AF_PF8_FSMC_NIOWR            GPIO_AF12
#define GPIO_AF_PF8_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF9_TIM14_CH1             GPIO_AF9
#define GPIO_AF_PF9_FSMC_CD               GPIO_AF12
#define GPIO_AF_PF9_EVENTOUT              GPIO_AF15
#define GPIO_AF_PF10_FSMC_INTR            GPIO_AF12
#define GPIO_AF_PF10_EVENTOUT             GPIO_AF15
#define GPIO_AF_PF11_DCMI_D12             GPIO_AF13
#define GPIO_AF_PF11_EVENTOUT             GPIO_AF15
#define GPIO_AF_PF12_FSMC_A6              GPIO_AF12
#define GPIO_AF_PF12_EVENTOUT             GPIO_AF15
#define GPIO_AF_PF13_FSMC_A7              GPIO_AF12
#define GPIO_AF_PF13_EVENTOUT             GPIO_AF15
#define GPIO_AF_PF14_FSMC_A8              GPIO_AF12
#define GPIO_AF_PF14_EVENTOUT             GPIO_AF15
#define GPIO_AF_PF15_FSMC_A9              GPIO_AF12
#define GPIO_AF_PF15_EVENTOUT             GPIO_AF15
#define GPIO_AF_PG0_FSMC_A10              GPIO_AF12
#define GPIO_AF_PG0_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG1_FSMC_A11              GPIO_AF12
#define GPIO_AF_PG1_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG2_FSMC_A12              GPIO_AF12
#define GPIO_AF_PG2_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG3_FSMC_A13              GPIO_AF12
#define GPIO_AF_PG3_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG4_FSMC_A14              GPIO_AF12
#define GPIO_AF_PG4_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG5_FSMC_A15              GPIO_AF12
#define GPIO_AF_PG5_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG6_FSMC_INT2             GPIO_AF12
#define GPIO_AF_PG6_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG7_USART6_CK             GPIO_AF8
#define GPIO_AF_PG7_FSMC_INT3             GPIO_AF12
#define GPIO_AF_PG7_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG8_ETH_PPS_OUT           GPIO_AF11
#define GPIO_AF_PG8_USART6_RTS            GPIO_AF8
#define GPIO_AF_PG8_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG9_USART6_RX             GPIO_AF8
#define GPIO_AF_PG9_FSMC_NE2              GPIO_AF12
#define GPIO_AF_PG9_FSMC_NCE3             GPIO_AF12
#define GPIO_AF_PG9_EVENTOUT              GPIO_AF15
#define GPIO_AF_PG10_FSMC_NCE4_1          GPIO_AF12
#define GPIO_AF_PG10_FSMC_NE3             GPIO_AF12
#define GPIO_AF_PG10_EVENTOUT             GPIO_AF15
#define GPIO_AF_PG11_ETH_MII_TX_EN        GPIO_AF11
#define GPIO_AF_PG11_ETH_RMII_TX_EN       GPIO_AF11
#define GPIO_AF_PG11_FSMC_NCE4_2          GPIO_AF12
#define GPIO_AF_PG11_EVENTOUT             GPIO_AF15
#define GPIO_AF_PG12_USART6_RTS           GPIO_AF8
#define GPIO_AF_PG12_FSMC_NE4             GPIO_AF12
#define GPIO_AF_PG12_EVENTOUT             GPIO_AF15
#define GPIO_AF_PG13_ETH_MII_TXD0         GPIO_AF11
#define GPIO_AF_PG13_ETH_RMII_TXD0        GPIO_AF11
#define GPIO_AF_PG13_USART6_CTS           GPIO_AF8
#define GPIO_AF_PG13_FSMC_A24             GPIO_AF12
#define GPIO_AF_PG13_EVENTOUT             GPIO_AF15
#define GPIO_AF_PG14_ETH_MII_TXD1         GPIO_AF11
#define GPIO_AF_PG14_ETH_RMII_TXD1        GPIO_AF11
#define GPIO_AF_PG14_USART6_TX            GPIO_AF8
#define GPIO_AF_PG14_FSMC_A25             GPIO_AF12
#define GPIO_AF_PG14_EVENTOUT             GPIO_AF15
#define GPIO_AF_PG15_USART6_CTS           GPIO_AF8
#define GPIO_AF_PG15_DCMI_D13             GPIO_AF13
#define GPIO_AF_PG15_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH0_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH1_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH2_ETH_MII_CRS          GPIO_AF11
#define GPIO_AF_PH2_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH3_ETH_MII_COL          GPIO_AF11
#define GPIO_AF_PH3_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH4_I2C2_SCL             GPIO_AF4
#define GPIO_AF_PH4_OTG_HS_ULPI_NXT      GPIO_AF10
#define GPIO_AF_PH4_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH5_I2C2_SDA             GPIO_AF4
#define GPIO_AF_PH5_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH6_I2C2_SMBA            GPIO_AF4
#define GPIO_AF_PH6_TIM12_CH1            GPIO_AF9
#define GPIO_AF_PH6_ETH_MII_RXD2         GPIO_AF11
#define GPIO_AF_PH6_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH7_I2C3_SCL             GPIO_AF4
#define GPIO_AF_PH7_ETH_MII_RXD3         GPIO_AF11
#define GPIO_AF_PH7_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH8_I2C3_SDA             GPIO_AF4
#define GPIO_AF_PH8_DCMI_HSYNC           GPIO_AF13
#define GPIO_AF_PH8_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH9_TIM12_CH2            GPIO_AF9
#define GPIO_AF_PH9_DCMI_D0              GPIO_AF13
#define GPIO_AF_PH9_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH10_TIM5_CH1             GPIO_AF2
#define GPIO_AF_PH10_DCMI_D1              GPIO_AF13
#define GPIO_AF_PH10_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH11_TIM5_CH2             GPIO_AF2
#define GPIO_AF_PH11_DCMI_D2              GPIO_AF13
#define GPIO_AF_PH11_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH12_TIM5_CH3             GPIO_AF2
#define GPIO_AF_PH12_DCMI_D3              GPIO_AF13
#define GPIO_AF_PH12_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH13_CAN1_TX              GPIO_AF9
#define GPIO_AF_PH13_DCMI_D4              GPIO_AF13
#define GPIO_AF_PH13_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH14_TIM8_CH1N            GPIO_AF3
#define GPIO_AF_PH14_DCMI_D4              GPIO_AF13
#define GPIO_AF_PH14_EVENTOUT             GPIO_AF15
#define GPIO_AF_PH15_TIM8_CH2N            GPIO_AF3
#define GPIO_AF_PH15_DCMI_D11             GPIO_AF13
#define GPIO_AF_PH15_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI0_TIM5_CH4             GPIO_AF2
#define GPIO_AF_PI0_SPI2_NSS             GPIO_AF5
#define GPIO_AF_PI0_I2S2_WS              GPIO_AF5
#define GPIO_AF_PI0_DCMI_D13             GPIO_AF13
#define GPIO_AF_PI0_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI1_SPI2_SCK             GPIO_AF5
#define GPIO_AF_PI1_I2S2_CK              GPIO_AF5
#define GPIO_AF_PI1_DCMI_D8              GPIO_AF13
#define GPIO_AF_PI1_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI2_TIM8_CH4             GPIO_AF3
#define GPIO_AF_PI2_SPI2_MISO            GPIO_AF5
#define GPIO_AF_PI2_I2S2ext_SD           GPIO_AF5
#define GPIO_AF_PI2_DCMI_D9              GPIO_AF13
#define GPIO_AF_PI2_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI3_TIM8_ETR             GPIO_AF3
#define GPIO_AF_PI3_SPI2_MOSI            GPIO_AF5
#define GPIO_AF_PI3_I2S2_SD              GPIO_AF5
#define GPIO_AF_PI3_DCMI_D10             GPIO_AF13
#define GPIO_AF_PI3_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI4_TIM8_BKIN            GPIO_AF3
#define GPIO_AF_PI4_DCMI_D5              GPIO_AF13
#define GPIO_AF_PI4_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI5_TIM8_CH1             GPIO_AF3
#define GPIO_AF_PI5_DCMI_VSYNC           GPIO_AF13
#define GPIO_AF_PI5_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI6_TIM8_CH2             GPIO_AF3
#define GPIO_AF_PI6_DCMI_D6              GPIO_AF13
#define GPIO_AF_PI6_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI7_TIM8_CH3             GPIO_AF3
#define GPIO_AF_PI7_DCMI_D7              GPIO_AF13
#define GPIO_AF_PI7_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI8_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI9_CAN1_RX              GPIO_AF9
#define GPIO_AF_PI9_EVENTOUT             GPIO_AF15
#define GPIO_AF_PI10_ETH_MII_RX_ER       GPIO_AF11
#define GPIO_AF_PI10_EVENTOUT            GPIO_AF15
#define GPIO_AF_PI11_EVENTOUT            GPIO_AF15
#define GPIO_AF_PI12_EVENTOUT            GPIO_AF15
#define GPIO_AF_PI13_EVENTOUT            GPIO_AF15
#define GPIO_AF_PI14_EVENTOUT            GPIO_AF15
#define GPIO_AF_PI15_EVENTOUT            GPIO_AF15


/*define GPIO Mode*/
#define GPIO_MODE_INPUT             0U
#define GPIO_MODE_OUTPUT            1U
#define GPIO_MODE_ALTF              2U
#define GPIO_MODE_ANALOG            3U

/*Define GPIO_TYPE */
#define GPIO_TYPE_PUSHPULL          0U
#define GPIO_TYPE_OPEN_DRAIN        1U

/*Define GPIO_Speed*/
#define GPIO_SPEED_LOW              0U
#define GPIO_SPEED_MEDIUM           1U
#define GPIO_SPEED_HIGH             2U
#define GPIO_SPEED_VERY_HIGH        3U

/*Define GPIO Pulllup Pulldown*/
#define GPIO_NO_PULL                0U
#define GPIO_PULL_UP                1U
#define GPIO_PULL_DOWN              2U
/*define GPIO_PIN State*/
typedef enum
{
    GPIO_PIN_RESET = 0U,
    GPIO_PIN_SET
} GPIO_PinState_t;

//typedef enum GPIO_PORT
typedef enum{
    GPIO_PORT_A = 0U,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
    GPIO_PORT_I 
} GPIO_Port_t;

#define GPIO_PORT_NUM   9U // number of ports 

typedef struct
{
    uint16_t Pin;
    GPIO_PinState_t State;
    uint8_t Mode;                  
    uint8_t Type;                  //open drain or push-pull 
    uint8_t Speed;
    uint8_t Pull;                  //pull up - pull down resistor
    uint8_t Alternate;
} GPIO_Config_t;

typedef struct{
    GPIO_Reg_TypeDef_t *Instance;           //poitner to PORTx
    GPIO_Config_t *Config;
} GPIO_Handle_TypeDef_t;

/*
    FUNCTION PROTOTYPE
*/

void GPIO_Init( GPIO_Handle_TypeDef_t *GPIO_Config);

GPIO_PinState_t GPIO_ReadPin(GPIO_Reg_TypeDef_t *GPIOx,uint16_t Pin);

void GPIO_WritePin(GPIO_Reg_TypeDef_t *GPIOx, uint16_t Pin, GPIO_PinState_t State);

void GPIO_TogglePin(GPIO_Reg_TypeDef_t *GPIOx, uint16_t Pin);



#endif

