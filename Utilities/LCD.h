#ifndef __LCD_H
#define __LCD_H

#include <stdint.h>

typedef struct
{
    volatile uint8_t LCD_RAM;
    volatile uint8_t LCD_REG;
} LCD_TypeDef;


void PrintMainWindow(void);
void PrintVerticalLine(uint8_t x, uint8_t y,uint8_t data,uint8_t len);
void PrintHorizonLine(uint8_t x, uint8_t y,uint8_t data,uint8_t len);
void ClearHorizonLine(uint8_t x, uint8_t y,uint8_t data);
void PrintSubWindow_LinkBuild(void);
void PrintSubWindow_LinkMaintain(void);
void PrintSubWindow_LinkQuery(void);
void PrintSubWindow_LinkQuery_Test(void);
void PrintSubWindow_WorkState(void);
void PrintSubWindow_SubWorkState(void);
void PrintSubWindow_DigTranOpert(void);
void PrintSubWindow_VersionInfo(void);



void ClearTextWindow(void);


void DispText_PageF1(void);
void DispText_PageF2(void);
void DispText_PageF3(void);
void DispText_PageF4(void);

void ClearMainPageLine(void);
void ClearText_PageF1(void);
void ClearText_PageF2(void);
void ClearText_PageF3(void);
void ClearText_PageF4(void);













void LCD_Reset(void);
void LCD_WriteIndex(uint8_t LCD_Reg);
void LCD_WriteData(uint8_t LCD_Value);
uint8_t LCD_ReadData(void);
void LCD_WriteReg(uint8_t LCD_Reg,uint8_t LCD_RegValue);
uint8_t LCD_ReadReg(uint8_t LCD_Reg);
void LCD_SetMode(uint8_t Mode, uint8_t Size);
void LCD_DispOn(void);
void LCD_DispOff(void);
void LCD_init(void);
void LCD_Clear(uint8_t Level);
void LCD_SetXY(uint8_t x, uint8_t y);
void PrintOneFont(uint8_t x, uint8_t y, uint8_t* str);
void PrintString(uint8_t x, uint8_t y, uint8_t* str, uint8_t len);
void PrintNum(uint8_t x, uint8_t y, uint8_t num, uint8_t rev);
void PrintStringReverse(uint8_t x, uint8_t y, uint8_t* str, uint8_t len);
void PrintOneChar(uint8_t x, uint8_t y, uint8_t* str);
void PrintOneFont16x16(uint8_t x, uint8_t y, uint8_t* str);
void PrintOneFont24x24(uint8_t x, uint8_t y, uint8_t* str);

#endif

