#include "LCD.h"
#include "io.h"
#include "Font.h"


#define LCD_BASE           (uint32_t)(0x64000002)
#define LCD_BUF            ((LCD_TypeDef *)LCD_BASE)



/*********************************************************
*函数名：LCD_Reset
*功能  ：LCD复位
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_Reset(void)
{
	Delay_nMS(100);
    SetGpioBit(CON_8806RST_PIN);
	Delay_nMS(10);
    ClrGpioBit(CON_8806RST_PIN);
	Delay_nMS(10);
    SetGpioBit(CON_8806RST_PIN);
	Delay_nMS(5);
}

/*********************************************************
*函数名：LCD_WriteIndex
*功能：  LCD写指令
*输入：	 无
*输出：	 无
*返回值：无
***********************************************************/
void LCD_WriteIndex(uint8_t LCD_Reg)
{
  /* Write 8-bit Index, then Write Reg */
    LCD_BUF->LCD_REG = LCD_Reg;
    Delay_nUS(30);
}

/*********************************************************
*函数名：LCD_WriteData
*功能  ：LCD写数据
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_WriteData(uint8_t LCD_Value)
{
  /* Write 8-bit Reg */
    LCD_BUF->LCD_RAM = LCD_Value;
    Delay_nUS(30);
}

/*********************************************************
*函数名：LCD_ReadData
*功能  ：LCD读数据
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
uint8_t LCD_ReadData(void)
{ 
	/* Read 8-bit Reg */
    uint8_t u8Data = 0;
    u8Data = (LCD_BUF->LCD_RAM);
    Delay_nUS(30);
	return u8Data;
}

/*********************************************************
*函数名：LCD_WriteReg
*功能  ：LCD写寄存器
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_WriteReg(uint8_t LCD_Reg,uint8_t LCD_RegValue)
{ 
  /* Write 8-bit Index, then Write Reg */
  LCD_BUF->LCD_REG = LCD_Reg;
  Delay_nUS(30);
  /* Write 8-bit Reg */
  LCD_BUF->LCD_RAM = LCD_RegValue;
  Delay_nUS(30);
}

/*********************************************************
*函数名：LCD_ReadReg
*功能  ：LCD读寄存器
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
uint8_t LCD_ReadReg(uint8_t LCD_Reg)
{
  /* Write 8-bit Index (then Read Reg) */
  LCD_BUF->LCD_REG = LCD_Reg;
  Delay_nUS(30);
  /* Read 8-bit Reg */
  return (LCD_BUF->LCD_RAM);
}

/*********************************************************
*函数名：LCD_SetTextMode
*功能  ：LCD设置文字或图形模式
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_SetMode(uint8_t Mode, uint8_t Size)
{
    uint8_t DataRead = 0;
    DataRead = LCD_ReadReg(0x00);
    if(Mode == TEXT)
    {
        LCD_WriteReg(0x00, DataRead | 0x08);
        if(Size == NORMAL)
        {
            LCD_WriteReg(0xF1, 0x00);
        }
        else
        {
            LCD_WriteReg(0xF1, 0x50);
        }
    }
    else
    {
        LCD_WriteReg(0x00, DataRead & 0xF7);
    }
}

/*********************************************************
*函数名：LCD_DispOn
*功能  ：LCD开显示
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_DispOn(void)
{
    uint8_t DataRead = 0;
    DataRead = LCD_ReadReg(0x00);
    LCD_WriteReg(0x00, DataRead | 0x04);
}

/*********************************************************
*函数名：LCD_DispOff
*功能  ：LCD关显示
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_DispOff(void)
{
    uint8_t DataRead = 0;
    DataRead = LCD_ReadReg(0x00);
    LCD_WriteReg(0x00, DataRead & 0xFB);
}

/*********************************************************
*函数名：LCD_init
*功能  ：LCD初始化
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_init(void)
{
    LCD_Reset();
    
    LCD_WriteReg(0x00, 0x0C);
    LCD_WriteReg(0x01, 0x04);       // 系统时钟不分频(BIT[3,2]:00-DIV8,01-DIV4,10-DIV2,11-DIV0)
    //LCD_WriteReg(0x03, 0x00);       // 关闭卷动功能
    //LCD_WriteReg(0x0F, 0x00);       // 禁止中断，禁能按键讯号
    //LCD_WriteReg(0x10, 0x04);       // 设置文字、游标
    LCD_WriteReg(0x11, 0xF3);       // 设置游标高度、行间距
    LCD_WriteReg(0x20, 0x27);       // 设置工作窗口右边界(320)
    LCD_WriteReg(0x21, 0x27);       // 设置显示窗口宽度(320)
    LCD_WriteReg(0x30, 0xEF);       // 设置工作窗口下边界(240)
    LCD_WriteReg(0x31, 0xEF);      // 设置显示窗口高度(240)
    //LCD_WriteReg(0x40, 0x00);       // 设置工作窗口左边界(0)
    //LCD_WriteReg(0x50, 0x00);       // 设置工作窗口上边界(0)
    //LCD_WriteReg(0x60, 0x00);       // 设置光标位置(X)
    //LCD_WriteReg(0x61, 0x00);       // 设置卷动功能下的光标起始位置
    //LCD_WriteReg(0x62, 0x00);       // 设置卷动功能下的光标终止位置
    //LCD_WriteReg(0x70, 0x00);       // 设置光标位置(Y)
    //LCD_WriteReg(0x71, 0x00);       
    //LCD_WriteReg(0x72, 0x00);
    //LCD_WriteReg(0x80, 0x00);
    //LCD_WriteReg(0x90, 0x00);
    //LCD_WriteReg(0xA0, 0x8C);       // 设置帧速率:FlamRate=SystemFreq/(ITCR+320/4)*240
    //LCD_WriteReg(0xA1, 0x00);
    //LCD_WriteReg(0xA2, 0x00);
    //LCD_WriteReg(0xA3, 0x00);
    //LCD_WriteReg(0xC0, 0x00);
    //LCD_WriteReg(0xC1, 0x00);
    //LCD_WriteReg(0xC2, 0x00);
    //LCD_WriteReg(0xC3, 0x00);
    //LCD_WriteReg(0xD0, 0x00);
    //LCD_WriteReg(0xD1, 0x00);
    LCD_Clear(BOTTOM);
    LCD_Clear(TOP);
    //LCD_WriteReg(0xF1, 0x00);        // 设置字符大小

    //LCD_WriteReg(0x00, 0x0C);
}

/*********************************************************
*函数名：LCD_Clear
*功能  ：清屏
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_Clear(uint8_t Level)
{
    if(Level == BOTTOM)
    {
        LCD_WriteReg(0x12, 0x31);
    }
    else
    {
        LCD_WriteReg(0x12, 0x32);
    }

    LCD_WriteReg(0xE0, 0x00);        // 清屏时写入的数据
    LCD_WriteReg(0xF0, 0x08);        // 启动清屏:BIT[3]=1
    Delay_nMS(10);
}

/*********************************************************
*函数名：PrintString
*功能  ：显示字符串
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void LCD_SetXY(uint8_t x, uint8_t y)
{
    if((x<=0x27) && (y<=0xEF))
    {
        //LCD_WriteReg(0x12, 0x32);       // 光标水平右移，双图层OR显示，存取DDRAM2
        LCD_WriteReg(0x60, x);       // 设置光标位置(X)
        LCD_WriteReg(0x70, y);       // 设置光标位置(Y)
    }
}

/*********************************************************
*函数名：PrintOneFont
*功能  ：显示一个24x24汉字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintOneFont(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;

    LCD_SetMode(PICTURE, NORMAL);   // 设置图形模式
    LCD_WriteReg(0x10, 0x06);       // 正常显示BIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // 光标垂直移动，双图层OR显示，存取DDRAM2

    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    for(i=0; i<72; i+=3)
    {
        LCD_WriteData(str[i]);
    }
    
    LCD_SetXY(x + WIDTH_HALF, y);
    LCD_WriteIndex(0xB0);
    for(i=1; i<72; i+=3)
    {
        LCD_WriteData(str[i]);
    }

    LCD_SetXY(x + 2*WIDTH_HALF, y);
    LCD_WriteIndex(0xB0);
    for(i=2; i<72; i+=3)
    {
        LCD_WriteData(str[i]);
    }
}

/*********************************************************
*函数名：PrintString
*功能  ：显示字符串
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintString(uint8_t x, uint8_t y, uint8_t* str, uint8_t len)
{
    uint8_t i = 0;

    LCD_SetMode(TEXT, NORMAL);      // 设置文字模式
    LCD_WriteReg(0x10, 0x00);       // 正常显示BIT[5]=0
    LCD_WriteReg(0x12, 0x32);       // 光标水平右移，双图层OR显示，存取DDRAM2
    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);

    while((str[i] != 0) && (i < len))
    {
        LCD_WriteData(str[i++]);
    }
}

/*********************************************************
*函数名：PrintString
*功能  ：显示一串数字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintNum(uint8_t x, uint8_t y, uint8_t num, uint8_t rev)
{
    uint8_t u8char = 0;
	u8char = num + '0';

    LCD_SetMode(TEXT, NORMAL);      // 设置文字模式
    if(rev == 0)
    {	
    	LCD_WriteReg(0x10, 0x00);       // 正常显示BIT[5]=0
	}
    else if(rev == 1)
    {
		LCD_WriteReg(0x10, 0x20);       // 正常显示BIT[5]=0
	}
		
    LCD_WriteReg(0x12, 0x32);       // 光标水平右移，双图层OR显示，存取DDRAM2
    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    LCD_WriteData(u8char);
}

/*********************************************************
*函数名：PrintStringReverse
*功能  ：反向显示字符串
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintStringReverse(uint8_t x, uint8_t y, uint8_t* str,  uint8_t len)
{
    uint8_t i = 0;

    LCD_SetMode(TEXT, NORMAL);              // 设置文字模式
    LCD_WriteReg(0x10, 0x20);       // 反向显示BIT[5]=1
    LCD_WriteReg(0x12, 0x32);       // 光标水平右移，双图层OR显示，存取DDRAM2
    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);

    while((str[i] != 0) && (i < len))
    {
        LCD_WriteData(str[i++]);
    }
}

/*********************************************************
*函数名：PrintMainWindow
*功能  ：显示主窗口框架
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintMainWindow(void)
{
	uint8_t i = 0, j = 0;

	LCD_Clear(BOTTOM);
	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

// 窗口外框纵线
	LCD_WriteReg(0x12, 0xB1);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM1
	// 外框右纵线
	LCD_SetXY(39, 0);
	LCD_WriteIndex(0xB0);
	for(i=0; i<240; i++)
	{
		LCD_WriteData(0x03);
	}
	// 外框左纵线
	LCD_SetXY(0, 0);
	LCD_WriteIndex(0xB0);
	for(i=0; i<240; i++)
	{
		LCD_WriteData(0xC0);
	}
// 窗口外框横线
	LCD_WriteReg(0x12, 0x31);		// 光标水平右移BIT[7]=0，双图层OR显示，存取DDRAM1
	for(i=0; i<2; i++)
	{
	// 外框上横线
		LCD_SetXY(0, i);
		LCD_WriteIndex(0xB0);
		for(j=0; j<40; j++)
		{
			LCD_WriteData(0xFF);
		}
		
	// 外框下横线
		LCD_SetXY(0, i+238);
		LCD_WriteIndex(0xB0);
		for(j=0; j<40; j++)
		{
			LCD_WriteData(0xFF);
		}
	}

// 窗口框内横线
	// 框内长横线1
	LCD_SetXY(0, 23);
	LCD_WriteIndex(0xB0);
	for(j=0; j<40; j++)
	{
		LCD_WriteData(0xFF);
	}
// 框内长横线8
	LCD_SetXY(0, 191);
	LCD_WriteIndex(0xB0);
	for(j=0; j<40; j++)
	{
		LCD_WriteData(0xFF);
	}
}

/*********************************************************
*函数名：PrintWindow_MakeVerticalLine
*功能  ：窗口垂直划线函数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintVerticalLine(uint8_t x, uint8_t y,uint8_t data,uint8_t len)
{
	uint8_t  j = 0;

	//LCD_DispOff();				  // 关闭显示
	LCD_Clear(TOP);
	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

// 窗口外框纵线
	LCD_WriteReg(0x12, 0xB1);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM1
	// 外框纵线
	LCD_SetXY(x, y);
	LCD_WriteIndex(0xB0);
	for(j=0; j<len; j++)
	{
		LCD_WriteData(data);
	}
	LCD_DispOn();			 // 打开显示
	/*
	    // 外框右纵线
    LCD_SetXY(39, 0);
    LCD_WriteIndex(0xB0);
    for(j=0; j<240; j++)
    {
        LCD_WriteData(0x03);
    }
    // 外框左纵线
    LCD_SetXY(0, 0);
    LCD_WriteIndex(0xB0);
    for(j=0; j<240; j++)
    {
        LCD_WriteData(0xC0);
    }
    // 内框长纵线
    LCD_SetXY(34, 0);
    LCD_WriteIndex(0xB0);
    for(j=0; j<240; j++)
    {
        LCD_WriteData(0xC0);
    }
    */
}

/*********************************************************
*函数名：PrintHorizonLine
*功能  ：窗口水平划线函数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintHorizonLine(uint8_t x, uint8_t y,uint8_t data,uint8_t len)
{
	uint8_t  j = 0;
	//LCD_DispOff();				  // 关闭显示
	LCD_Clear(TOP);
	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0
	// 窗口外框横线
	LCD_WriteReg(0x12, 0x31);		// 光标水平右移BIT[7]=0，双图层OR显示，存取DDRAM1

	// 外框上横线
	LCD_SetXY(x, y);
	LCD_WriteIndex(0xB0);
	for(j=0; j<len; j++)
	{
		LCD_WriteData(data);
	}
	LCD_DispOn();			 // 打开显示
	/*
			LCD_SetXY(0, i);
		LCD_WriteIndex(0xB0);
		for(j=0; j<40; j++)
		{
			LCD_WriteData(0xFF);
		}
	*/
}

/*********************************************************
*函数名：ClearHorizonLine
*功能  ：清除窗口水平线函数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearHorizonLine(uint8_t x, uint8_t y,uint8_t data)
{
	uint8_t  j = 0;

	//LCD_DispOff();				  // 关闭显示
	//LCD_Clear(TOP);
	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0
	// 窗口外框横线
	LCD_WriteReg(0x12, 0x31);		// 光标水平右移BIT[7]=0，双图层OR显示，存取DDRAM1

	// 外框上横线
	LCD_SetXY(x, y);
	LCD_WriteIndex(0xB0);
	if(j == 0)
	{
		LCD_WriteData(0xC0);
	}
	for(j=1; j<39; j++)
	{
		LCD_WriteData(data);
	}
	if(j == 39)
	{
		LCD_WriteData(0x03);
	}
	LCD_DispOn();			 // 打开显示
	/*
			LCD_SetXY(0, i);
		LCD_WriteIndex(0xB0);
		for(j=0; j<40; j++)
		{
			LCD_WriteData(0xFF);
		}
	*/
}

/*********************************************************
*函数名：ClearWorkWindow
*功能  ：清除工作窗口
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearTextWindow(void)
{
    uint8_t i = 0;
    for(i=0; i<8; i++)
    {
        PrintString(WIDTH_HALF, ROW_TEXT02 + i*24, "                                 ", WORD);
    }
}

/*********************************************************
*函数名：DispText_PageF1
*功能  ：显示F1界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispText_PageF1(void)
{
	PrintHorizonLine(0,95,0xFF,COL_WORD7+WIDTH_HALF);// 95-23 = 72
	PrintVerticalLine(COL_WORD7+WIDTH_HALF,24,0x80,72); // 119-23=96
	
	PrintString(WIDTH_HALF, ROW_TEXT02,   "1-电台IP      ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT03,   "2-电台掩码    ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT04,   "3-恢复出厂设置", WORD);
}

/*********************************************************
*函数名：DispText_PageF2
*功能  ：显示F2界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispText_PageF2(void)
{
	PrintHorizonLine(COL_WORD5,95,0xFF,COL_WORD6); 
	PrintVerticalLine(COL_WORD5,24,0x80,71);//95-23=72
	PrintVerticalLine(COL_WORD11,24,0x80,72);//71-23=48

	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT02,   "1-链路建立", WORD);
	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT03,   "2-链路维护", WORD);
    PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT04,   "3-链路查询", WORD);
}

/*********************************************************
*函数名：DispText_PageF3
*功能  ：显示F3界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispText_PageF3(void)
{
	PrintHorizonLine(COL_WORD9+WIDTH_HALF,143,0xFF,COL_WORD6);
	PrintVerticalLine(COL_WORD9+WIDTH_HALF,24,0x80,119);
	PrintVerticalLine(COL_WORD15+WIDTH_HALF,24,0x80,120);

	PrintString(COL_WORD10, ROW_TEXT02,   "1-工作状态", WORD);
	PrintString(COL_WORD10, ROW_TEXT03,   "2-数传统计", WORD);
    PrintString(COL_WORD10, ROW_TEXT04,   "3-数传汇报", WORD);
    PrintString(COL_WORD10, ROW_TEXT05,   "4-调试信息", WORD);
    PrintString(COL_WORD10, ROW_TEXT06,   "5-运行时间", WORD);
}

/*********************************************************
*函数名：DispText_PageF4
*功能  ：显示F4界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispText_PageF4(void)
{
	PrintHorizonLine(COL_WORD14,143,0xFF,COL_WORD6);
	PrintVerticalLine(COL_WORD14,24,0x80,119);

	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT02, "1-日期时间", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03,"2-电台自检", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT04, "3-功率检测", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "4-背光开关", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT06, "5-版本信息", WORD);
}

/*********************************************************
*函数名：ClearMainPageLine
*功能  ：清除主界面下的框线
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearMainPageLine(void)
{
	PrintString(COL_WORD5, ROW_TEXT03, "                  ", WORD);
	PrintString(COL_WORD6, ROW_TEXT05, "	              ", WORD);		
	PrintString(WIDTH_HALF, ROW_TEXT09,"                  ", WORD);
}

/*********************************************************
*函数名：ClearText_PageF1
*功能  ：清除F1界面下的内容【框线及文字】
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearText_PageF1(void)
{
	ClearHorizonLine(0,95,0x00);	//写00进行清除
	PrintVerticalLine(COL_WORD7+WIDTH_HALF,24,0x00,72); // 119-23=96

	PrintString(WIDTH_HALF, ROW_TEXT02,   "                ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT03,   "                ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT04,   "                ", WORD);
}

/*********************************************************
*函数名：ClearText_PageF2
*功能  ：清除F2界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearText_PageF2(void)
{
	ClearHorizonLine(0,95,0x00);	//写00进行清除
	PrintVerticalLine(COL_WORD5,24,0x00,71);//95-23=72
	PrintVerticalLine(COL_WORD11,24,0x00,72);//71-23=48

	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT02,   "         ", WORD);
	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT03,   "         ", WORD);
    PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT04,   "         ", WORD);
}

/*********************************************************
*函数名：ClearText_PageF3
*功能  ：清除F3界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearText_PageF3(void)
{
	ClearHorizonLine(0,143,0x00);	//写00进行清除
	PrintVerticalLine(COL_WORD9+WIDTH_HALF,24,0x00,119);
	PrintVerticalLine(COL_WORD15+WIDTH_HALF,24,0x00,120);

	PrintString(COL_WORD10, ROW_TEXT02,   "             ", WORD);
    PrintString(COL_WORD10, ROW_TEXT03,   "             ", WORD);
    PrintString(COL_WORD10, ROW_TEXT04,   "             ", WORD);
    PrintString(COL_WORD10, ROW_TEXT05,   "             ", WORD);
	PrintString(COL_WORD10, ROW_TEXT06,   "             ", WORD);
}

/*********************************************************
*函数名：ClearText_PageF4
*功能  ：清除F4界面下的文本
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ClearText_PageF4(void)
{
	ClearHorizonLine(0,143,0x00);	//写00进行清除
	PrintVerticalLine(COL_WORD14,24,0x00,119);

	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT02, "          ", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "          ", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT04, "          ", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "          ", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT06, "          ", WORD);
}

#if 0
/*********************************************************
*函数名：OperPageLine
*功能  ：清除并添加界面下的框线
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void OperPageLine(void)
{
	switch(g_u8PreMenuID)
	{
		case MENU_SET_F1:
			ClearPageF1Line();
			switch(g_u8CurMenuID)
			{
				case MENU_SET_F2:
					PrintPageF2Line();
					break;
				case MENU_SET_F3:
					PrintPageF3Line();
					break;
				case MENU_SET_F4:
					PrintPageF4Line();
					break;	
				default:
					break;
			}
			break;
			
		case MENU_SET_F2:
			ClearLine_PageF2();
			switch(g_u8CurMenuID)
			{
				case MENU_SET_F1:
					DispPageF1Content();
					break;
				case MENU_SET_F3:
					PrintPageF3Line();
					break;
				case MENU_SET_F4:
					PrintPageF4Line();
					break;
				default:
					break;
			}
			break;	
			
		case MENU_SET_F3:
			ClearText_PageF3();
			switch(g_u8CurMenuID)
			{
				case MENU_SET_F1:
					DispPageF1Content();
					break;
				case MENU_SET_F2:
					PrintPageF2Line();
					break;
				case MENU_SET_F4:
					PrintPageF4Line();
					break;
				default:
					break;
			}
			break;	
			
		case MENU_SET_F4:
			ClearText_PageF4();
			switch(g_u8CurMenuID)
			{
				case MENU_SET_F1:
					DispPageF1Content();
					break;
				case MENU_SET_F2:
					PrintPageF2Line();
					break;
				case MENU_SET_F3:
					PrintPageF3Line();
					break;
				default:
					break;
			}
			break;
		default:
			break;	
	}
}
#endif

/*********************************************************
*函数名：PrintSubWindow_LinkBuild
*功能  ：显示链路建立表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_LinkBuild(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2

// 链路建立表格纵线
	for(i=0; i<9; i++)
	{
		x = 3 + i*4;
		LCD_SetXY(x, 71);
		LCD_WriteIndex(0xB0);
		for(j=0; j<48;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路建立表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<3; i++)
	{
		y = 71 + i*24;//26
		LCD_SetXY(3, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<32; j++)
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_LinkMaintain
*功能  ：显示链路维护表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_LinkMaintain(void)
{
	uint8_t i = 0, j = 0;
	uint8_t  y = 0;
	uint8_t u8Code[4] = {9,21,27,39};

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2


// 链路维护表格纵线
	LCD_SetXY(3, 47);
	LCD_WriteIndex(0xB0);
	for(j=0; j<121;j++)
	{
		LCD_WriteData(0x80);
	}

	for(i=0; i<4; i++)
	{
		LCD_SetXY(u8Code[i], 47);
		LCD_WriteIndex(0xB0);
		for(j=0; j<121;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路维护表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<6; i++)
	{
		y = 47 + i*24;//26
		LCD_SetXY(3, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<36; j++)  // 39-3=36
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_LinkQuery
*功能  ：显示链路查询表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_LinkQuery(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2

// 链路查询表格纵线
	LCD_SetXY(1, 71);
	LCD_WriteIndex(0xB0);
	//WIDTH_HALF=1
	for(j=0; j<72; j++)//52
	{
		LCD_WriteData(0x80);
	}

	for(i=0; i<9; i++)
	{
		x = 7 + i*4;
		LCD_SetXY(x, 71);
		LCD_WriteIndex(0xB0);
		for(j=0; j<72;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路查询表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<4; i++)
	{
		y = 71 + i*24;//26
		LCD_SetXY(1, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<38; j++)
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_LinkQuery_Test
*功能  ：显示链路查询表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_LinkQuery_Test(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2

// 链路查询表格纵线
	LCD_SetXY(1, 71);
	LCD_WriteIndex(0xB0);
	//WIDTH_HALF=1
	for(j=0; j<72; j++)//52
	{
		LCD_WriteData(0x80);
	}

	for(i=0; i<4; i++)
	{
		x = 7 + i*9;
		LCD_SetXY(x, 71);
		LCD_WriteIndex(0xB0);
		for(j=0; j<72;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路查询表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<4; i++)
	{
		y = 71 + i*24;//26
		LCD_SetXY(1, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<33; j++)
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_WorkState
*功能  ：显示工作状态表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_WorkState(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2


// 链路查询表格纵线
	for(i=0; i<5; i++)
	{
		x = 20 + i*4;
		LCD_SetXY(x, 71);
		LCD_WriteIndex(0xB0);
		for(j=0; j<121;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路查询表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<6; i++)
	{
		y = 71 + i*24;//26
		LCD_SetXY(20, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<20; j++)
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_SubWorkState
*功能  ：显示从站工作状态表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_SubWorkState(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2


// 链路查询表格纵线
	for(i=0; i<3; i++)
	{
		x = 20 + i*8;
		LCD_SetXY(x, 71);
		LCD_WriteIndex(0xB0);
		for(j=0; j<49;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路查询表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<3; i++)
	{
		y = 71 + i*24;//26
		LCD_SetXY(20, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<16; j++)
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_DigTranOpert
*功能  ：显示数传操作表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_DigTranOpert(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2


// 链路查询表格纵线
	LCD_SetXY(1, 47);
	LCD_WriteIndex(0xB0);
	for(j=0; j<121;j++)
	{
		LCD_WriteData(0x80);
	}

	for(i=0; i<5; i++)
	{
		x = 7 + i*8;
		LCD_SetXY(x, 47);
		LCD_WriteIndex(0xB0);
		for(j=0; j<121;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路查询表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<6; i++)
	{
		y = 47 + i*24;//26
		LCD_SetXY(1, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<38; j++)
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintSubWindow_VersionInfo
*功能  ：显示版本信息表格
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintSubWindow_VersionInfo(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// 图形模式
	LCD_WriteReg(0x10, 0x00);		// 正常显示BIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2


// 链路查询表格纵线
	LCD_SetXY(3, 47);
	LCD_WriteIndex(0xB0);
	for(j=0; j<121;j++)
	{
		LCD_WriteData(0x80);
	}

	for(i=0; i<4; i++)
	{
		x = 11 + i*8;
		LCD_SetXY(x, 47);
		LCD_WriteIndex(0xB0);
		for(j=0; j<121;j++)
		{
			LCD_WriteData(0x80);
		}
	}

// 链路查询表格横线
	LCD_WriteReg(0x12, 0x32);		// 光标垂直下移BIT[7]=1，双图层OR显示，存取DDRAM2
	for(i=0; i<6; i++)
	{
		y = 47 + i*24;//26
		LCD_SetXY(3, y);
		LCD_WriteIndex(0xB0);
		for(j=0; j<32; j++)  // 27-3=24
		{
			LCD_WriteData(0xFF);
		}
	}
}

/*********************************************************
*函数名：PrintOneChar
*功能  ：显示一个8x16字符
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintOneChar(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;
        
    LCD_SetMode(PICTURE, NORMAL);   // 设置图形模式
    LCD_WriteReg(0x10, 0x06);       // 正常显示BIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // 光标垂直移动，双图层OR显示，存取DDRAM2

    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    for(i=0; i<16; i++)
    {
        LCD_WriteData(str[i]);
    }
}

/*********************************************************
*函数名：PrintOneFont16x16
*功能  ：显示一个16x16汉字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintOneFont16x16(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;

    LCD_SetMode(PICTURE, NORMAL);   // 设置图形模式
    LCD_WriteReg(0x10, 0x00);       // 正常显示BIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // 光标垂直移动，双图层OR显示，存取DDRAM2

    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    for(i=0; i<32; i+=2)
    {
        LCD_WriteData(str[i]);
    }
    
    LCD_SetXY(x + WIDTH_HALF, y);
    LCD_WriteIndex(0xB0);
    for(i=1; i<32; i+=2)
    {
        LCD_WriteData(str[i]);
    }
}

/*********************************************************
*函数名：PrintOneFont24x24
*功能  ：放大两倍显示字符串
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PrintOneFont24x24(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;

    LCD_SetMode(PICTURE, NORMAL);   // 设置图形模式
    //LCD_WriteReg(0x10, 0x06);       // 正常显示BIT[5]=0
    LCD_WriteReg(0x10, 0);       // 正常显示BIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // 光标垂直移动，双图层OR显示，存取DDRAM2

    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    for(i=0; i<72; i+=3)
    {
        LCD_WriteData(str[i]);
    }
    
    LCD_SetXY(x + WIDTH_HALF, y);
    LCD_WriteIndex(0xB0);
    for(i=1; i<72; i+=3)
    {
        LCD_WriteData(str[i]);
    }

    LCD_SetXY(x + WIDTH_WORD, y);
    LCD_WriteIndex(0xB0);
    for(i=2; i<72; i+=3)
    {
        LCD_WriteData(str[i]);
    }
}


