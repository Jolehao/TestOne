#include "io.h"


GPIO_TypeDef* GPIO_PORT[9] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, 
                                GPIOF, GPIOG, GPIOH, GPIOI};

/*********************************************************
*��������ReadGpioBit
*����  ����GPIO����λ��ƽ
*����  �����ź궨��
*���  ����
*����ֵ�����ŵ�ƽ0/1
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
*��������SetGpioBit
*����  ������GPIO����Ϊ�ߵ�ƽ
*����  �����ź궨��
*���  ����
*����ֵ����
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
*��������ClrGpioBit
*����  ������GPIO����Ϊ�͵�ƽ
*����  �����ź궨��
*���  ����
*����ֵ����
***********************************************************/
void ClrGpioBit(uint8_t pin_name)
{
	uint8_t Port_index = 0;
    uint16_t Pin_bit = 0;
    Port_index = (pin_name >> 4) & 0x0F;
    Pin_bit = (uint16_t)(1 << (pin_name & 0x0F));

    GPIO_ResetBits(GPIO_PORT[Port_index], Pin_bit);
}

