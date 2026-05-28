#include "stm32f407xxx_rcc.h"
#include "stm32f407xx_gpio.h"
#include "stm32f407xxx_systick.h"
#include "stm32f407xxx_exti.h"
#include "stm32f407xxx_uart.h"
#include "stm32f407xxx_nvic.h"
#include "stm32f407xxx_can.h"
#include "stm32f407xxx_i2c.h"
#include <string.h>
#include <stdio.h>

#define SLAVE_ADDR 0x50 //example slave address for AT24C25 EEPROM



GPIO_Handle_TypeDef_t hgpio;
EXTI_Handle_t hexti;
USART_Handle_t huart;
extern I2C_Handle_t hi2c1;



void EXTI_Callback(void)
{
    GPIO_TogglePin(GPIOA,GPIO_PIN_6);
}

static void GPIO_INIT(void);
static void USART_INIT(void);
static void I2C_INIT(void);



int main(void)
{
    RCC_SetSystemClockTo168MHz();

    RCC_ENABLE_PORTA_CLK();
    RCC_ENABLE_PORTB_CLK();
    RCC_ENABLE_PORTE_CLK();
    RCC_ENABLE_SYSCFG_CLK();
    RCC_ENABLE_I2C1_CLK();
  

    GPIO_INIT();
    USART_INIT();
    I2C_INIT();
   
    SYSTICK_Init(168000);

    while(1)
    {
        GPIO_TogglePin(GPIOA, GPIO_PIN_7);
        
        I2C_Master_Transmit_IT(&hi2c1, SLAVE_ADDR, (uint8_t*)"Hello", 5U);
        
        // uint8_t data[] = {0x12, 0x34, 'H', 'e', 'l', 'l', 'o'}; //example data to write to AT24C25 starting from memory address 0x0000
        // I2C_Start(&hi2c1);
        // I2C_Master_Transmit(&hi2c1, 0x50 << 1, data, 7U, 1000);
        // I2C_Stop(&hi2c1);

        // SYSTICK_DelayMs(500);

        // I2C_Start(&hi2c1);
        // //send memory address to read
        // I2C_Master_Transmit(&hi2c1, 0x50 << 1, (uint8_t[]){0x12,0x34}, 2U, 1000);
        // I2C_Start(&hi2c1); //repeated start for read
        // I2C_Master_Receive(&hi2c1, (0x50 << 1) | 1, data, 10, 1000);
        // I2C_Stop(&hi2c1);
        SYSTICK_DelayMs(500);
    }
}

static void GPIO_INIT(void)
{
    GPIO_Config_t config;

    config.Pin   = GPIO_PIN_6 | GPIO_PIN_7;
    config.Mode  = GPIO_MODE_OUTPUT;
    config.State = GPIO_PIN_SET;
    config.Type  = GPIO_TYPE_PUSHPULL;
    config.Pull  = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_LOW;

    hgpio.Config   = &config;
    hgpio.Instance = GPIOA;
    GPIO_Init(&hgpio);

    config.Pin   = GPIO_PIN_4;
    config.Mode  = GPIO_MODE_INPUT;
    config.State = GPIO_PIN_SET;
    config.Type  = GPIO_TYPE_PUSHPULL;
    config.Pull  = GPIO_PULL_UP;
    config.Speed = GPIO_SPEED_LOW;

    hgpio.Config   = &config;
    hgpio.Instance = GPIOE;
    GPIO_Init(&hgpio);

    EXTI_Config_t Exti_config;
    Exti_config.Pin = EXTI_LINE_4;
    Exti_config.Port = GPIO_PORT_E;
    Exti_config.Trigger = EXTI_TRIGGER_FALLING;

    hexti.Config = &Exti_config;
    hexti.EXTI_Callback = EXTI_Callback;

    EXTI_Init(&hexti);

    config.Pin   = GPIO_PIN_9;
    config.Mode  = GPIO_MODE_ALTF;
    config.Type  = GPIO_TYPE_PUSHPULL;
    config.Pull  = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_VERY_HIGH;
    config.Alternate = GPIO_AF_PA9_USART1_TX;

    hgpio.Config   = &config;
    hgpio.Instance = GPIOA;
    GPIO_Init(&hgpio);

    config.Pin   = GPIO_PIN_10; 
    config.Mode  = GPIO_MODE_ALTF;
    config.Type  = GPIO_TYPE_PUSHPULL;
    config.Pull  = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_VERY_HIGH;
    config.Alternate = GPIO_AF_PA10_USART1_RX;

    hgpio.Config   = &config;
    hgpio.Instance = GPIOA;
    GPIO_Init(&hgpio);

    config.Pin  = GPIO_PIN_9;
    config.Mode = GPIO_MODE_ALTF;
    config.Type = GPIO_TYPE_PUSHPULL;
    config.Pull = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_VERY_HIGH;
    config.Alternate = GPIO_AF_PB9_CAN1_TX;

    hgpio.Config   = &config;
    hgpio.Instance = GPIOB;
    GPIO_Init(&hgpio);

    config.Pin  = GPIO_PIN_8;
    config.Mode = GPIO_MODE_ALTF;
    config.Type = GPIO_TYPE_PUSHPULL;
    config.Pull = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_VERY_HIGH;
    config.Alternate = GPIO_AF_PB8_CAN1_RX;

    hgpio.Config   = &config;
    hgpio.Instance = GPIOB;
    GPIO_Init(&hgpio);

    hgpio.Instance = GPIOB;
    config.Pin  = GPIO_PIN_6;
    config.Mode = GPIO_MODE_ALTF;
    config.Type = GPIO_TYPE_OPEN_DRAIN;
    config.Pull = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_VERY_HIGH;
    config.Alternate = GPIO_AF_PB6_I2C1_SCL;
    hgpio.Config   = &config;
    GPIO_Init(&hgpio);

    config.Pin  = GPIO_PIN_7;
    config.Mode = GPIO_MODE_ALTF;
    config.Type = GPIO_TYPE_OPEN_DRAIN;
    config.Pull = GPIO_NO_PULL;
    config.Speed = GPIO_SPEED_VERY_HIGH;
    config.Alternate = GPIO_AF_PB7_I2C1_SDA;
    hgpio.Config   = &config;
    GPIO_Init(&hgpio);
}

static void USART_INIT(void)
{
    USART_Config_t config;

    config.Baudrate = USART_BAUDRATE_115200;
    config.Mode = USART_MODE_TX_RX;
    config.Parity = USART_PARITY_NONE;
    config.StopBits = USART_STOPBITS_1;
    config.WordLength = USART_WORD_LENGTH_8BITS;
    config.OverSampling = USART_OVERSAMPLING_16;

    huart.Instance = USART1;
    huart.Config = &config;
    RCC_ENABLE_USART1_CLK();
    USART_Init(&huart);
    NVIC_EnableIRQ(IRQ_NO_USART1);
}

static void I2C_INIT(void)
{
    I2C_Config_t config;

    config.ClockSpeed = I2C_CLOCK_SPEED_100KHz;
    config.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

    config.Mode = I2C_MODE_STANDARD;

    hi2c1.Instance = I2C1;
    hi2c1.Init = config;

    I2C_Init(&hi2c1);
    NVIC_EnableIRQ(IRQ_NO_I2C1_EV);
    NVIC_EnableIRQ(IRQ_NO_I2C1_ER);
}
