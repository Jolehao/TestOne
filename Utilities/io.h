#ifndef __IO_H
#define __IO_H

#include "libraries.h"

// GPIOA端口引脚(写位带区，根据输入、输出按位操作GPIO.IDR、GPIO.ODR)
#define LED_BAK_PIN          0x00     // PA.0
#define SEL_PTT2_PIN         0x01     // PA.1
#define SEL_PTT3_PIN         0x02     // PA.2
#define SEL_SP_PIN           0x03     // PA.3

#define BDPTT_IN_PIN         0x08     // PA.8
#define SEL_MIC1_PIN         0x0B     // PA.11
#define SEL_MIC2_PIN         0x0C     // PA.12

// GPIOB端口引脚(写位带区，根据输入、输出按位操作GPIO.IDR、GPIO.ODR)
//#define RTC_SDL_PIN          ((volatile uint32_t *) (40408018))     // PB.6 
//#define RTC_SDA_PIN          ((volatile uint32_t *) (4040801C))     // PB.7 
#define E2PROM_SDA_PIN       0x18        // PB.8
#define E2PROM_SCL_PIN       0x19        // PB.9

//#define LED_Tx_PIN       	 0x1C     // PB.12
//#define LED_Rx_PIN       	 0x1D     // PB.13
//正样收发灯和告警灯互换位置
#define LED_ALARM1_PIN       0x1D     // PB.13
#define LED_ALARM2_PIN       0x1C     // PB.12

#define LED_POWER2_PIN       0x1E     // PB.14


// GPIOC端口引脚(写位带区，根据输入、输出按位操作GPIO.IDR、GPIO.ODR)
#define KEY_Y1_PIN           0x21     // PC.1 
#define KEY_Y2_PIN           0x22     // PC.2
#define KEY_Y3_PIN           0x23     // PC.3
#define KEY_Y4_PIN           0x24     // PC.4
#define KEY_Y5_PIN           0x25     // PC.5
#define KEY_X1_PIN           0x26     // PC.6
#define KEY_X2_PIN           0x27     // PC.7
#define KEY_X3_PIN           0x28     // PC.8
#define KEY_X4_PIN           0x29     // PC.9
#define KEY_Y6_PIN           0x2A     // PC.10
#define KEY_POWER_PIN        0x2D     // PC.13

// GPIOD端口引脚(写位带区，根据输入、输出按位操作GPIO.IDR、GPIO.ODR)
#define SEL_PTT1_PIN         0x32     // PD.2
#define PTT_IN_PIN           0x33     // PD.3
#define CON_SPK_PIN          0x36     // PD.6
#define LED_POWER1_PIN       0x3A     // PD.10

#define ZKPTT1_IN_PIN        0x43     // PE.3
#define ZKPTT2_IN_PIN        0x44     // PE.4

// GPIOF端口引脚
#define CON_POWER_PIN        0x56     // PF.6
#define CON_5402CLK_PIN      0x57     // PF.7
#define CON_5402CS_PIN       0x58     // PF.8
#define CON_5402DIN_PIN      0x59     // PF.9
#define SEL_SPEAKER_PIN      0x5A     // PF.10
#define CON_8806RST_PIN      0x5B     // PF.11
#define E2PROM_WP_PIN        0x5C     // PF.12

// GPIOG端口引脚
#define CON_DESTROY_PIN      0x67     // PG.7
#define LED_Power_PIN        0x68     // PG.8
//#define LED_ALARM1_PIN           0x6B     // PG.11
//#define LED_ALARM2_PIN           0x6F     // PG.15

//正样收发灯和告警灯互换位置
#define LED_Rx_PIN           0x6B     // PG.11
#define LED_Tx_PIN       	 0x6F     // PG.15

uint8_t ReadGpioBit(uint8_t pin_name);
void SetGpioBit(uint8_t pin_name);
void ClrGpioBit(uint8_t pin_name);

#endif
