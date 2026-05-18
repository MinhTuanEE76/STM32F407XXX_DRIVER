#include "stm32f407xxx_rcc.h"
#include "stm32f407xx_gpio.h"
#include "stm32f407xxx_systick.h"
#include "stm32f407xxx_exti.h"
#include "stm32f407xxx_uart.h"
#include "stm32f407xxx_nvic.h"


GPIO_Handle_TypeDef_t hgpio;
EXTI_Handle_t hexti;
USART_Handle_t huart;

uint8_t rx_buffer[10];

void EXTI_Callback(void)
{
    GPIO_TogglePin(GPIOA,GPIO_PIN_6);
}

static void GPIO_INIT(void);
static void USART_INIT(void);

int main(void)
{
    RCC_SetSystemClockTo168MHz();

    RCC_ENABLE_PORTA_CLK();
    RCC_ENABLE_PORTE_CLK();
    RCC_ENABLE_SYSCFG_CLK();

    GPIO_INIT();
    USART_INIT();

    SYSTICK_Init(168000);

    while(1)
    {
        GPIO_TogglePin(GPIOA, GPIO_PIN_7);
        USART_Transmit_IT(&huart, (uint8_t *)"Hello World\r\n", 13);
        USART_Receive_IT(&huart, rx_buffer, 11);
        SYSTICK_DelayMs(500);
    }
}

static void GPIO_INIT(void)
{
    GPIO_Config_t config;

    config.Pin   = GPIO_PIN_6 | GPIO_PIN_7;
    config.Mode  = GPIO_MODE_OUTPUT;
    config.State = GPIO_PIN_RESET;
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
