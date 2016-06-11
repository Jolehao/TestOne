#ifndef __RTC_H
#define __RTC_H

#include <stdint.h>

#define SLAVE_ADDRESS           0x64

#define RTC_MODE_TRANSMITTER    0x01
#define RTC_MODE_RECEIVER       0x00

#define RTC_STATE_TX            0x01
#define RTC_STATE_RX            0x00

extern uint8_t g_u8RTC_TranMode;
extern uint8_t g_u8RTC_TranState;
extern uint8_t g_u8RTC_InterruptEn;
extern uint8_t g_u8RTC_Error;

extern uint8_t g_u8RTC_RegIndex;
extern uint8_t g_u8RTC_TxIdx;
extern uint8_t g_u8RTC_RxIdx;

extern uint8_t g_u8RTC_DataBufLen;
extern uint8_t g_u8RTC_DataTx[20];
extern uint8_t g_u8RTC_DataRx[20];

void LCD_WriteRtcON(void);
void LCD_WriteRtcOFF(void);
void RTC_WriteTime(void);
void RTC_ReadTime(void);
void WriteCode(uint8_t *Code);
void ReadCode(uint8_t *Code);

#endif

