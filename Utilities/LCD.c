#include "LCD.h"
#include "io.h"
#include "Font.h"


#define LCD_BASE           (uint32_t)(0x64000002)
#define LCD_BUF            ((LCD_TypeDef *)LCD_BASE)



/*********************************************************
*��������LCD_Reset
*����  ��LCD��λ
*����  ����
*���  ����
*����ֵ����
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
*��������LCD_WriteIndex
*���ܣ�  LCDдָ��
*���룺	 ��
*�����	 ��
*����ֵ����
***********************************************************/
void LCD_WriteIndex(uint8_t LCD_Reg)
{
  /* Write 8-bit Index, then Write Reg */
    LCD_BUF->LCD_REG = LCD_Reg;
    Delay_nUS(30);
}

/*********************************************************
*��������LCD_WriteData
*����  ��LCDд����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void LCD_WriteData(uint8_t LCD_Value)
{
  /* Write 8-bit Reg */
    LCD_BUF->LCD_RAM = LCD_Value;
    Delay_nUS(30);
}

/*********************************************************
*��������LCD_ReadData
*����  ��LCD������
*����  ����
*���  ����
*����ֵ����
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
*��������LCD_WriteReg
*����  ��LCDд�Ĵ���
*����  ����
*���  ����
*����ֵ����
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
*��������LCD_ReadReg
*����  ��LCD���Ĵ���
*����  ����
*���  ����
*����ֵ����
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
*��������LCD_SetTextMode
*����  ��LCD�������ֻ�ͼ��ģʽ
*����  ����
*���  ����
*����ֵ����
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
*��������LCD_DispOn
*����  ��LCD����ʾ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void LCD_DispOn(void)
{
    uint8_t DataRead = 0;
    DataRead = LCD_ReadReg(0x00);
    LCD_WriteReg(0x00, DataRead | 0x04);
}

/*********************************************************
*��������LCD_DispOff
*����  ��LCD����ʾ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void LCD_DispOff(void)
{
    uint8_t DataRead = 0;
    DataRead = LCD_ReadReg(0x00);
    LCD_WriteReg(0x00, DataRead & 0xFB);
}

/*********************************************************
*��������LCD_init
*����  ��LCD��ʼ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void LCD_init(void)
{
    LCD_Reset();
    
    LCD_WriteReg(0x00, 0x0C);
    LCD_WriteReg(0x01, 0x04);       // ϵͳʱ�Ӳ���Ƶ(BIT[3,2]:00-DIV8,01-DIV4,10-DIV2,11-DIV0)
    //LCD_WriteReg(0x03, 0x00);       // �رվ�����
    //LCD_WriteReg(0x0F, 0x00);       // ��ֹ�жϣ����ܰ���Ѷ��
    //LCD_WriteReg(0x10, 0x04);       // �������֡��α�
    LCD_WriteReg(0x11, 0xF3);       // �����α�߶ȡ��м��
    LCD_WriteReg(0x20, 0x27);       // ���ù��������ұ߽�(320)
    LCD_WriteReg(0x21, 0x27);       // ������ʾ���ڿ��(320)
    LCD_WriteReg(0x30, 0xEF);       // ���ù��������±߽�(240)
    LCD_WriteReg(0x31, 0xEF);      // ������ʾ���ڸ߶�(240)
    //LCD_WriteReg(0x40, 0x00);       // ���ù���������߽�(0)
    //LCD_WriteReg(0x50, 0x00);       // ���ù��������ϱ߽�(0)
    //LCD_WriteReg(0x60, 0x00);       // ���ù��λ��(X)
    //LCD_WriteReg(0x61, 0x00);       // ���þ������µĹ����ʼλ��
    //LCD_WriteReg(0x62, 0x00);       // ���þ������µĹ����ֹλ��
    //LCD_WriteReg(0x70, 0x00);       // ���ù��λ��(Y)
    //LCD_WriteReg(0x71, 0x00);       
    //LCD_WriteReg(0x72, 0x00);
    //LCD_WriteReg(0x80, 0x00);
    //LCD_WriteReg(0x90, 0x00);
    //LCD_WriteReg(0xA0, 0x8C);       // ����֡����:FlamRate=SystemFreq/(ITCR+320/4)*240
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
    //LCD_WriteReg(0xF1, 0x00);        // �����ַ���С

    //LCD_WriteReg(0x00, 0x0C);
}

/*********************************************************
*��������LCD_Clear
*����  ������
*����  ����
*���  ����
*����ֵ����
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

    LCD_WriteReg(0xE0, 0x00);        // ����ʱд�������
    LCD_WriteReg(0xF0, 0x08);        // ��������:BIT[3]=1
    Delay_nMS(10);
}

/*********************************************************
*��������PrintString
*����  ����ʾ�ַ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void LCD_SetXY(uint8_t x, uint8_t y)
{
    if((x<=0x27) && (y<=0xEF))
    {
        //LCD_WriteReg(0x12, 0x32);       // ���ˮƽ���ƣ�˫ͼ��OR��ʾ����ȡDDRAM2
        LCD_WriteReg(0x60, x);       // ���ù��λ��(X)
        LCD_WriteReg(0x70, y);       // ���ù��λ��(Y)
    }
}

/*********************************************************
*��������PrintOneFont
*����  ����ʾһ��24x24����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintOneFont(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;

    LCD_SetMode(PICTURE, NORMAL);   // ����ͼ��ģʽ
    LCD_WriteReg(0x10, 0x06);       // ������ʾBIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // ��괹ֱ�ƶ���˫ͼ��OR��ʾ����ȡDDRAM2

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
*��������PrintString
*����  ����ʾ�ַ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintString(uint8_t x, uint8_t y, uint8_t* str, uint8_t len)
{
    uint8_t i = 0;

    LCD_SetMode(TEXT, NORMAL);      // ��������ģʽ
    LCD_WriteReg(0x10, 0x00);       // ������ʾBIT[5]=0
    LCD_WriteReg(0x12, 0x32);       // ���ˮƽ���ƣ�˫ͼ��OR��ʾ����ȡDDRAM2
    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);

    while((str[i] != 0) && (i < len))
    {
        LCD_WriteData(str[i++]);
    }
}

/*********************************************************
*��������PrintString
*����  ����ʾһ������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintNum(uint8_t x, uint8_t y, uint8_t num, uint8_t rev)
{
    uint8_t u8char = 0;
	u8char = num + '0';

    LCD_SetMode(TEXT, NORMAL);      // ��������ģʽ
    if(rev == 0)
    {	
    	LCD_WriteReg(0x10, 0x00);       // ������ʾBIT[5]=0
	}
    else if(rev == 1)
    {
		LCD_WriteReg(0x10, 0x20);       // ������ʾBIT[5]=0
	}
		
    LCD_WriteReg(0x12, 0x32);       // ���ˮƽ���ƣ�˫ͼ��OR��ʾ����ȡDDRAM2
    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    LCD_WriteData(u8char);
}

/*********************************************************
*��������PrintStringReverse
*����  ��������ʾ�ַ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintStringReverse(uint8_t x, uint8_t y, uint8_t* str,  uint8_t len)
{
    uint8_t i = 0;

    LCD_SetMode(TEXT, NORMAL);              // ��������ģʽ
    LCD_WriteReg(0x10, 0x20);       // ������ʾBIT[5]=1
    LCD_WriteReg(0x12, 0x32);       // ���ˮƽ���ƣ�˫ͼ��OR��ʾ����ȡDDRAM2
    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);

    while((str[i] != 0) && (i < len))
    {
        LCD_WriteData(str[i++]);
    }
}

/*********************************************************
*��������PrintMainWindow
*����  ����ʾ�����ڿ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintMainWindow(void)
{
	uint8_t i = 0, j = 0;

	LCD_Clear(BOTTOM);
	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

// �����������
	LCD_WriteReg(0x12, 0xB1);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM1
	// ���������
	LCD_SetXY(39, 0);
	LCD_WriteIndex(0xB0);
	for(i=0; i<240; i++)
	{
		LCD_WriteData(0x03);
	}
	// ���������
	LCD_SetXY(0, 0);
	LCD_WriteIndex(0xB0);
	for(i=0; i<240; i++)
	{
		LCD_WriteData(0xC0);
	}
// ����������
	LCD_WriteReg(0x12, 0x31);		// ���ˮƽ����BIT[7]=0��˫ͼ��OR��ʾ����ȡDDRAM1
	for(i=0; i<2; i++)
	{
	// ����Ϻ���
		LCD_SetXY(0, i);
		LCD_WriteIndex(0xB0);
		for(j=0; j<40; j++)
		{
			LCD_WriteData(0xFF);
		}
		
	// ����º���
		LCD_SetXY(0, i+238);
		LCD_WriteIndex(0xB0);
		for(j=0; j<40; j++)
		{
			LCD_WriteData(0xFF);
		}
	}

// ���ڿ��ں���
	// ���ڳ�����1
	LCD_SetXY(0, 23);
	LCD_WriteIndex(0xB0);
	for(j=0; j<40; j++)
	{
		LCD_WriteData(0xFF);
	}
// ���ڳ�����8
	LCD_SetXY(0, 191);
	LCD_WriteIndex(0xB0);
	for(j=0; j<40; j++)
	{
		LCD_WriteData(0xFF);
	}
}

/*********************************************************
*��������PrintWindow_MakeVerticalLine
*����  �����ڴ�ֱ���ߺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintVerticalLine(uint8_t x, uint8_t y,uint8_t data,uint8_t len)
{
	uint8_t  j = 0;

	//LCD_DispOff();				  // �ر���ʾ
	LCD_Clear(TOP);
	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

// �����������
	LCD_WriteReg(0x12, 0xB1);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM1
	// �������
	LCD_SetXY(x, y);
	LCD_WriteIndex(0xB0);
	for(j=0; j<len; j++)
	{
		LCD_WriteData(data);
	}
	LCD_DispOn();			 // ����ʾ
	/*
	    // ���������
    LCD_SetXY(39, 0);
    LCD_WriteIndex(0xB0);
    for(j=0; j<240; j++)
    {
        LCD_WriteData(0x03);
    }
    // ���������
    LCD_SetXY(0, 0);
    LCD_WriteIndex(0xB0);
    for(j=0; j<240; j++)
    {
        LCD_WriteData(0xC0);
    }
    // �ڿ�����
    LCD_SetXY(34, 0);
    LCD_WriteIndex(0xB0);
    for(j=0; j<240; j++)
    {
        LCD_WriteData(0xC0);
    }
    */
}

/*********************************************************
*��������PrintHorizonLine
*����  ������ˮƽ���ߺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintHorizonLine(uint8_t x, uint8_t y,uint8_t data,uint8_t len)
{
	uint8_t  j = 0;
	//LCD_DispOff();				  // �ر���ʾ
	LCD_Clear(TOP);
	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0
	// ����������
	LCD_WriteReg(0x12, 0x31);		// ���ˮƽ����BIT[7]=0��˫ͼ��OR��ʾ����ȡDDRAM1

	// ����Ϻ���
	LCD_SetXY(x, y);
	LCD_WriteIndex(0xB0);
	for(j=0; j<len; j++)
	{
		LCD_WriteData(data);
	}
	LCD_DispOn();			 // ����ʾ
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
*��������ClearHorizonLine
*����  ���������ˮƽ�ߺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ClearHorizonLine(uint8_t x, uint8_t y,uint8_t data)
{
	uint8_t  j = 0;

	//LCD_DispOff();				  // �ر���ʾ
	//LCD_Clear(TOP);
	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0
	// ����������
	LCD_WriteReg(0x12, 0x31);		// ���ˮƽ����BIT[7]=0��˫ͼ��OR��ʾ����ȡDDRAM1

	// ����Ϻ���
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
	LCD_DispOn();			 // ����ʾ
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
*��������ClearWorkWindow
*����  �������������
*����  ����
*���  ����
*����ֵ����
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
*��������DispText_PageF1
*����  ����ʾF1�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispText_PageF1(void)
{
	PrintHorizonLine(0,95,0xFF,COL_WORD7+WIDTH_HALF);// 95-23 = 72
	PrintVerticalLine(COL_WORD7+WIDTH_HALF,24,0x80,72); // 119-23=96
	
	PrintString(WIDTH_HALF, ROW_TEXT02,   "1-��̨IP      ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT03,   "2-��̨����    ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT04,   "3-�ָ���������", WORD);
}

/*********************************************************
*��������DispText_PageF2
*����  ����ʾF2�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispText_PageF2(void)
{
	PrintHorizonLine(COL_WORD5,95,0xFF,COL_WORD6); 
	PrintVerticalLine(COL_WORD5,24,0x80,71);//95-23=72
	PrintVerticalLine(COL_WORD11,24,0x80,72);//71-23=48

	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT02,   "1-��·����", WORD);
	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT03,   "2-��·ά��", WORD);
    PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT04,   "3-��·��ѯ", WORD);
}

/*********************************************************
*��������DispText_PageF3
*����  ����ʾF3�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispText_PageF3(void)
{
	PrintHorizonLine(COL_WORD9+WIDTH_HALF,143,0xFF,COL_WORD6);
	PrintVerticalLine(COL_WORD9+WIDTH_HALF,24,0x80,119);
	PrintVerticalLine(COL_WORD15+WIDTH_HALF,24,0x80,120);

	PrintString(COL_WORD10, ROW_TEXT02,   "1-����״̬", WORD);
	PrintString(COL_WORD10, ROW_TEXT03,   "2-����ͳ��", WORD);
    PrintString(COL_WORD10, ROW_TEXT04,   "3-�����㱨", WORD);
    PrintString(COL_WORD10, ROW_TEXT05,   "4-������Ϣ", WORD);
    PrintString(COL_WORD10, ROW_TEXT06,   "5-����ʱ��", WORD);
}

/*********************************************************
*��������DispText_PageF4
*����  ����ʾF4�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispText_PageF4(void)
{
	PrintHorizonLine(COL_WORD14,143,0xFF,COL_WORD6);
	PrintVerticalLine(COL_WORD14,24,0x80,119);

	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT02, "1-����ʱ��", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03,"2-��̨�Լ�", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT04, "3-���ʼ��", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "4-���⿪��", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT06, "5-�汾��Ϣ", WORD);
}

/*********************************************************
*��������ClearMainPageLine
*����  ������������µĿ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ClearMainPageLine(void)
{
	PrintString(COL_WORD5, ROW_TEXT03, "                  ", WORD);
	PrintString(COL_WORD6, ROW_TEXT05, "	              ", WORD);		
	PrintString(WIDTH_HALF, ROW_TEXT09,"                  ", WORD);
}

/*********************************************************
*��������ClearText_PageF1
*����  �����F1�����µ����ݡ����߼����֡�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ClearText_PageF1(void)
{
	ClearHorizonLine(0,95,0x00);	//д00�������
	PrintVerticalLine(COL_WORD7+WIDTH_HALF,24,0x00,72); // 119-23=96

	PrintString(WIDTH_HALF, ROW_TEXT02,   "                ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT03,   "                ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT04,   "                ", WORD);
}

/*********************************************************
*��������ClearText_PageF2
*����  �����F2�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ClearText_PageF2(void)
{
	ClearHorizonLine(0,95,0x00);	//д00�������
	PrintVerticalLine(COL_WORD5,24,0x00,71);//95-23=72
	PrintVerticalLine(COL_WORD11,24,0x00,72);//71-23=48

	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT02,   "         ", WORD);
	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT03,   "         ", WORD);
    PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT04,   "         ", WORD);
}

/*********************************************************
*��������ClearText_PageF3
*����  �����F3�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ClearText_PageF3(void)
{
	ClearHorizonLine(0,143,0x00);	//д00�������
	PrintVerticalLine(COL_WORD9+WIDTH_HALF,24,0x00,119);
	PrintVerticalLine(COL_WORD15+WIDTH_HALF,24,0x00,120);

	PrintString(COL_WORD10, ROW_TEXT02,   "             ", WORD);
    PrintString(COL_WORD10, ROW_TEXT03,   "             ", WORD);
    PrintString(COL_WORD10, ROW_TEXT04,   "             ", WORD);
    PrintString(COL_WORD10, ROW_TEXT05,   "             ", WORD);
	PrintString(COL_WORD10, ROW_TEXT06,   "             ", WORD);
}

/*********************************************************
*��������ClearText_PageF4
*����  �����F4�����µ��ı�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ClearText_PageF4(void)
{
	ClearHorizonLine(0,143,0x00);	//д00�������
	PrintVerticalLine(COL_WORD14,24,0x00,119);

	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT02, "          ", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "          ", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT04, "          ", WORD);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "          ", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT06, "          ", WORD);
}

#if 0
/*********************************************************
*��������OperPageLine
*����  ���������ӽ����µĿ���
*����  ����
*���  ����
*����ֵ����
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
*��������PrintSubWindow_LinkBuild
*����  ����ʾ��·�������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_LinkBuild(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2

// ��·�����������
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

// ��·����������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_LinkMaintain
*����  ����ʾ��·ά�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_LinkMaintain(void)
{
	uint8_t i = 0, j = 0;
	uint8_t  y = 0;
	uint8_t u8Code[4] = {9,21,27,39};

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2


// ��·ά���������
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

// ��·ά��������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_LinkQuery
*����  ����ʾ��·��ѯ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_LinkQuery(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2

// ��·��ѯ�������
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

// ��·��ѯ������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_LinkQuery_Test
*����  ����ʾ��·��ѯ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_LinkQuery_Test(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2

// ��·��ѯ�������
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

// ��·��ѯ������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_WorkState
*����  ����ʾ����״̬���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_WorkState(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2


// ��·��ѯ�������
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

// ��·��ѯ������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_SubWorkState
*����  ����ʾ��վ����״̬���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_SubWorkState(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2


// ��·��ѯ�������
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

// ��·��ѯ������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_DigTranOpert
*����  ����ʾ�����������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_DigTranOpert(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2


// ��·��ѯ�������
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

// ��·��ѯ������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintSubWindow_VersionInfo
*����  ����ʾ�汾��Ϣ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintSubWindow_VersionInfo(void)
{
	uint8_t i = 0, j = 0;
	uint8_t x = 0, y = 0;

	LCD_SetMode(PICTURE, NORMAL);	// ͼ��ģʽ
	LCD_WriteReg(0x10, 0x00);		// ������ʾBIT[5]=0

	LCD_WriteReg(0x12, 0xB2);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2


// ��·��ѯ�������
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

// ��·��ѯ������
	LCD_WriteReg(0x12, 0x32);		// ��괹ֱ����BIT[7]=1��˫ͼ��OR��ʾ����ȡDDRAM2
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
*��������PrintOneChar
*����  ����ʾһ��8x16�ַ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintOneChar(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;
        
    LCD_SetMode(PICTURE, NORMAL);   // ����ͼ��ģʽ
    LCD_WriteReg(0x10, 0x06);       // ������ʾBIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // ��괹ֱ�ƶ���˫ͼ��OR��ʾ����ȡDDRAM2

    LCD_SetXY(x, y);
    LCD_WriteIndex(0xB0);
    for(i=0; i<16; i++)
    {
        LCD_WriteData(str[i]);
    }
}

/*********************************************************
*��������PrintOneFont16x16
*����  ����ʾһ��16x16����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintOneFont16x16(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;

    LCD_SetMode(PICTURE, NORMAL);   // ����ͼ��ģʽ
    LCD_WriteReg(0x10, 0x00);       // ������ʾBIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // ��괹ֱ�ƶ���˫ͼ��OR��ʾ����ȡDDRAM2

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
*��������PrintOneFont24x24
*����  ���Ŵ�������ʾ�ַ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PrintOneFont24x24(uint8_t x, uint8_t y, uint8_t* str)
{
    uint8_t i = 0;

    LCD_SetMode(PICTURE, NORMAL);   // ����ͼ��ģʽ
    //LCD_WriteReg(0x10, 0x06);       // ������ʾBIT[5]=0
    LCD_WriteReg(0x10, 0);       // ������ʾBIT[5]=0
    LCD_WriteReg(0x12, 0xB2);       // ��괹ֱ�ƶ���˫ͼ��OR��ʾ����ȡDDRAM2

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


