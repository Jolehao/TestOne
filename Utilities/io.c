#include "io.h"


GPIO_TypeDef* GPIO_PORT[9] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, 
                                GPIOF, GPIOG, GPIOH, GPIOI};

/*********************************************************
*函数名：ReadGpioBit
*功能  ：读GPIO引脚位电平
*输入  ：引脚宏定义
*输出  ：无
*返回值：引脚电平0/1
***********************************************************/
uint8_t ReadGpioBit(uint8_t pin_name)
{
	uint8_t Port_index = 0;
    uint16_t Pin_bit = 0;
    uint8_t Value = 0;
    
    Port_index = (pin_name >> 4) & 0x0F;
    Pin_bit = (uint16_t)(1 << (pin_name & 0x0F));
    Value = GPIO_ReadInputDataBit(GPIO_PORT[Port_index], Pin_bit);

    return Value;
}

/*********************************************************
*函数名：SetGpioBit
*功能  ：设置GPIO引脚为高电平
*输入  ：引脚宏定义
*输出  ：无
*返回值：无
***********************************************************/
void SetGpioBit(uint8_t pin_name)
{
	uint8_t Port_index = 0;
    uint16_t Pin_bit = 0;
    Port_index = (pin_name >> 4) & 0x0F;
    Pin_bit = (uint16_t)(1 << (pin_name & 0x0F));

    GPIO_SetBits(GPIO_PORT[Port_index], Pin_bit);
}

/*********************************************************
*函数名：ClrGpioBit
*功能  ：设置GPIO引脚为低电平
*输入  ：引脚宏定义
*输出  ：无
*返回值：无
***********************************************************/
void ClrGpioBit(uint8_t pin_name)
{
	uint8_t Port_index = 0;
    uint16_t Pin_bit = 0;
    Port_index = (pin_name >> 4) & 0x0F;
    Pin_bit = (uint16_t)(1 << (pin_name & 0x0F));

    GPIO_ResetBits(GPIO_PORT[Port_index], Pin_bit);
}

