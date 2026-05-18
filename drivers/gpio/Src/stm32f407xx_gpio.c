#include "stm32f407xx_gpio.h"
#include "stm32f407xxx_rcc.h"

/*-------------------static function--------------------------*/
static void GPIO_Config_Pin(GPIO_Handle_TypeDef_t *hgpio,uint8_t position)
{
    //Init mode for GPIOx
    uint8_t mode = hgpio->Config->Mode;
    hgpio->Instance->MODER  &= ~(PIN_MASK_2BIT << (position*2));
    hgpio->Instance->MODER |= (mode << (position*2));
    /*Init output type: push pull or open-drain
      0(reset) : push pull
      1 : open drain 
    */
    uint8_t otype = hgpio->Config->Type;
    hgpio->Instance->OTYPER &=  ~(PIN_MASK_1BIT << position);
    hgpio->Instance->OTYPER |=  (otype << position);

    /*init output speeed*/
    uint8_t ospeed = hgpio->Config->Speed;
    hgpio->Instance->OSPEEDR &= ~(PIN_MASK_2BIT << (position*2));
    hgpio->Instance->OSPEEDR |= (ospeed << (position*2));

    /*init pull-up, pull-down*/
    uint8_t pull = hgpio->Config->Pull;
    hgpio->Instance->PUPDR &=  ~(PIN_MASK_2BIT << (position*2));
    hgpio->Instance->PUPDR |= pull << (position*2);

    /*configure alternate function*/
    uint8_t alternate = hgpio->Config->Alternate;
    if(mode == GPIO_MODE_ALTF)
    {
        if(position < 8)
        {
            hgpio->Instance->AFR[0] &= ~(PIN_MASK_4BIT << (position*4));
            hgpio->Instance->AFR[0] |= (alternate << (position*4));
        }
        else
        {
            uint8_t offset = position - 8;
            hgpio->Instance->AFR[1] &= ~(PIN_MASK_4BIT << (offset*4));
            hgpio->Instance->AFR[1] |=  alternate << (offset*4);
        }
    }
        //init state firstly
    GPIO_PinState_t state = hgpio->Config->State;
    if(state == GPIO_PIN_SET)
    {
        //PIN SET
        hgpio->Instance->BSRR = (PIN_MASK_1BIT << position);
    }
    else
    {
        //PIN RESET
        hgpio->Instance->BSRR = (PIN_MASK_1BIT << (position + 16));
    } 

}
/*-------------------static function--------------------------*/

/*Gpio init*/
void GPIO_Init(GPIO_Handle_TypeDef_t *hgpio)
{

    for(uint8_t i = 0 ; i < 16 ; i++){
        if(hgpio->Config->Pin & (1 << i))
        {   
            GPIO_Config_Pin(hgpio,i);
        }
    }
} 

/*Read status pin*/
GPIO_PinState_t GPIO_ReadPin(GPIO_Reg_TypeDef_t *GPIOx,uint16_t Pin)
{
    if(GPIOx->IDR & Pin)
    {
        return GPIO_PIN_SET;
    }
    return GPIO_PIN_RESET;
}
/*Wtite status pin*/
void GPIO_WritePin(GPIO_Reg_TypeDef_t *GPIOx, uint16_t Pin, GPIO_PinState_t State)
{
    if(State == GPIO_PIN_SET)
    {
        GPIOx->BSRR = Pin;
    }
    else
    {
        GPIOx->BSRR = (uint32_t)(Pin << 16U);
    }
}
/*Toggle Pin*/
void GPIO_TogglePin(GPIO_Reg_TypeDef_t *GPIOx,
                    uint16_t Pin)
{
    GPIOx->ODR ^= Pin;
}