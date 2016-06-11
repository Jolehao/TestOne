#include "RTC.h"
#include "io.h"
#include "LCD.h"
#include "Display.h"

#include <string.h>


uint8_t g_u8RTC_TranMode    = RTC_MODE_RECEIVER;
uint8_t g_u8RTC_TranState   = RTC_MODE_RECEIVER;
uint8_t g_u8RTC_InterruptEn = NO;
uint8_t g_u8RTC_Error       = NO;
uint8_t g_u8RTC_RegIndex   = 0;

uint8_t g_u8RTC_TxIdx      = 0;
uint8_t g_u8RTC_RxIdx      = 0;

uint8_t g_u8RTC_DataBufLen = 0;
uint8_t g_u8RTC_DataTx[20] = {0};
uint8_t g_u8RTC_DataRx[20] = {0};

/*********************************************************
*函数名：RTC_WriteON
*功能：  RTC写允许
*输入：	 无
*输出：	 无
*返回值：无
***********************************************************/
void RTC_WriteON(void)
{
	uint32_t u32TimeOut = 360000;

	g_u8RTC_TranMode	 = RTC_MODE_TRANSMITTER;  
	g_u8RTC_RegIndex	 = 0x10;
	g_u8RTC_TxIdx		 = 0;
	g_u8RTC_DataBufLen	 = 1;
	g_u8RTC_DataTx[0]	 = 0x80;
	g_u8RTC_InterruptEn  = YES;
	I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_BUF), ENABLE);	// Enable Event and Buffer Interrupts
	I2C_GenerateSTART(I2C1, ENABLE);						 // Generate the Start condition
	while(g_u8RTC_InterruptEn)
	{
		u32TimeOut--;
		if(u32TimeOut > 0)	  // 定时约30ms
		{
			if(g_u8RTC_Error == YES)
			{
				I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
				g_u8RTC_InterruptEn = NO;		// RTC INTERRUPT ENABLE
				g_u8RTC_Error = NO;
				return;
			}
		}
		else
		{
			g_u8RTC_InterruptEn  = NO;
			//I2C_AcknowledgeConfig(I2C1, DISABLE);
			//I2C_GenerateSTOP(I2C1, ENABLE);
			I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
		}
	}

	g_u8RTC_TranMode	 = RTC_MODE_TRANSMITTER;  
	g_u8RTC_RegIndex	 = 0x0F;
	g_u8RTC_TxIdx		 = 0;
	g_u8RTC_DataBufLen	 = 1;
	g_u8RTC_DataTx[0]	 = 0x84;
	g_u8RTC_InterruptEn  = YES;
	I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_BUF), ENABLE);	// Enable Event and Buffer Interrupts
	I2C_GenerateSTART(I2C1, ENABLE);						 // Generate the Start condition

	u32TimeOut = 360000;
	while(g_u8RTC_InterruptEn)
	{
		u32TimeOut--;
		if(u32TimeOut > 0)	  // 定时约30ms
		{
			if(g_u8RTC_Error == YES)
			{
				I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
				g_u8RTC_InterruptEn = NO;		// RTC INTERRUPT ENABLE
				g_u8RTC_Error = NO;
				return;
			}
		}
		else
		{
			g_u8RTC_InterruptEn  = NO;
			//I2C_AcknowledgeConfig(I2C1, DISABLE);
			//I2C_GenerateSTOP(I2C1, ENABLE);
			I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
			return;
		}
	}
}


/*********************************************************
*函数名：RTC_WriteOFF
*功能：  RTC写禁止
*输入：	 无
*输出：	 无
*返回值：无
***********************************************************/
void RTC_WriteOFF(void)
{
    uint32_t u32TimeOut = 360000;

    g_u8RTC_TxIdx        = 0;
    g_u8RTC_RegIndex     = 0x10;
    g_u8RTC_TranMode     = RTC_MODE_TRANSMITTER;  
    g_u8RTC_DataBufLen   = 2;
    g_u8RTC_DataTx[0]    = 0;
    g_u8RTC_DataTx[1]    = 0;
    g_u8RTC_InterruptEn  = YES;
    I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, ENABLE);  // Enable Event and Buffer Interrupts
    I2C_GenerateSTART(I2C1, ENABLE);                         // Generate the Start condition
    while(g_u8RTC_InterruptEn)
    {
		u32TimeOut--;
        if(u32TimeOut > 0)    // 定时约30ms
        {
            if(g_u8RTC_Error == YES)
            {
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
                g_u8RTC_Error = NO;
                return;
            }
        }
        else
        {
            g_u8RTC_InterruptEn  = NO;
            //I2C_AcknowledgeConfig(I2C1, DISABLE);
            //I2C_GenerateSTOP(I2C1, ENABLE);
            I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
            return;
        }
    }
}

/*********************************************************
*函数名：RTC_WriteTime
*功能  ：发送设置电台时间指令
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void RTC_WriteTime(void)
{
    uint32_t u32TimeOut = 360000;

// WRITE DATE OF TIME
    RTC_WriteON();
    t_EditTime.WeekDay  = t_CurTime.WeekDay;
    memcpy(&g_u8RTC_DataTx[0], &t_EditTime, sizeof(t_EditTime));
	
    g_u8RTC_DataTx[2]  |= 0x80;     // SET 24 HOURS MODE
    g_u8RTC_RegIndex    = 0x00;     // RTC2404 REG INDEX
    g_u8RTC_TxIdx       = 0;                              // TX COUNTER
    g_u8RTC_DataBufLen  = (uint8_t)(sizeof(t_EditTime));             // TX DATA LENGTH
    g_u8RTC_InterruptEn = YES;                            // RTC INTERRUPT ENABLE
    g_u8RTC_TranMode    = RTC_MODE_TRANSMITTER;
    
    I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_BUF), ENABLE);  // Enable Event and Buffer Interrupts
    I2C_GenerateSTART(I2C1, ENABLE);                         // Generate the Start condition

    while(g_u8RTC_InterruptEn)
    {
		u32TimeOut--;
        if(u32TimeOut > 0)    // 定时约30ms
        {
            if(g_u8RTC_Error == YES)
            {
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
                g_u8RTC_Error = NO;
				RTC_WriteOFF();
                return;
            }
        }
        else
        {
            g_u8RTC_InterruptEn  = NO;
            //I2C_AcknowledgeConfig(I2C1, DISABLE);
            //I2C_GenerateSTOP(I2C1, ENABLE);
            I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
			RTC_WriteOFF();
            return;
        }
    }
    RTC_WriteOFF();


    g_u8ParamEditIndex = 0;
	
    memcpy(&t_CurTime, &t_EditTime, sizeof(t_CurTime));
    if(g_u8CurMenuID == MENU_PARAMDATETIME)
    {
        if(g_u8ParamEditIndex == INDEX_EDIT_DATE)
        {
            DispDateNum(0);
        }
        
        if(g_u8ParamEditIndex == INDEX_EDIT_TIME)
        {
            DispTimeNum(0);
        }
    }	
}

/*********************************************************
*函数名：RTC_ReadTime
*功能  ：发送日期时间查询指令
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
//RTC_WriteTime();
void RTC_ReadTime(void)
{
    uint32_t u32TimeOut = 360000;
	//uint8_t au8Code[2] = {0};

// QUERY DATE OF TIME
    g_u8RTC_InterruptEn = YES;
	g_u8RTC_DataBufLen  = 0;
	g_u8RTC_TxIdx       = 0;
    g_u8RTC_RegIndex    = 0x00;     // RTC2404 REG INDEX
    g_u8RTC_TranMode    = RTC_MODE_TRANSMITTER;
	
 
    I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_BUF), ENABLE);  // Enable Event and Buffer Interrupts
    I2C_GenerateSTART(I2C1, ENABLE); 
	


	// Generate the Start condition

    while(g_u8RTC_InterruptEn)
    {
		u32TimeOut--;
        if(u32TimeOut > 0)    // 定时约30ms
        {
            if(g_u8RTC_Error == YES)
            {
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
                g_u8RTC_Error = NO;
				g_u8GetTimeEnd = YES;
                return;
            }
        }
        else
        {
			g_u8GetTimeEnd = YES;
            g_u8RTC_InterruptEn  = NO;
            //I2C_AcknowledgeConfig(I2C1, DISABLE);
            //I2C_GenerateSTOP(I2C1, ENABLE);
            I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
            return;
        }
    }



    g_u8RTC_InterruptEn = YES;
    g_u8RTC_DataBufLen  = 7;
    g_u8RTC_RxIdx       = 0;
    g_u8RTC_TranMode    = RTC_MODE_RECEIVER;
    memset(g_u8RTC_DataRx, 0, sizeof(g_u8RTC_DataRx));
    
    I2C_ITConfig(I2C1, I2C_IT_EVT, ENABLE);     // Enable Event Interrupts
    I2C_AcknowledgeConfig(I2C1, ENABLE);        // Enable Acknowledge
    I2C_GenerateSTART(I2C1, ENABLE);            // Generate the Start condition

    u32TimeOut = 360000; 
    while(g_u8RTC_InterruptEn)
    {
		u32TimeOut--;
        if(u32TimeOut > 0)    // 定时约30ms
        {
            if(g_u8RTC_Error == YES)
            {
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
                g_u8RTC_Error = NO;
				g_u8GetTimeEnd = YES;
                return;
            }
        }
        else
        {
			g_u8GetTimeEnd = YES;
            g_u8RTC_InterruptEn  = NO;
            //I2C_AcknowledgeConfig(I2C1, DISABLE);
            //I2C_GenerateSTOP(I2C1, ENABLE);
            I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
            return;
        }
    }

    memcpy(&t_CurTime, g_u8RTC_DataRx, sizeof(t_CurTime));
    t_CurTime.Hour &= 0x3F;
    g_u8GetTimeEnd = YES;

	if(g_u8CurMenuID == MENU_PARAMDATETIME)
    {
        if(g_u8ParamEditIndex != INDEX_EDIT_TIME)
        {
           DispTimeNum(0);
        }
        
        if(g_u8ParamEditIndex != INDEX_EDIT_DATE)
        {
           DispDateNum(0);
        }
    }

	else if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		DispTimeNum(0);
		DispDateNum(0);
	}
	else if(g_u8CurMenuID == MENU_PARAMRUNTIME)
	{
		//ReadCode(au8Code);	
		//memcpy(&t_SumRunTime.Minute,&au8Code[0],2);
		//memcpy(&t_SumRunTime.Hour,&au8Code[2],2);
		DispRunTimeNum();
	}
}

/*********************************************************
*函数名：WriteCode
*功能  ：把密码写入E2PROM
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void WriteCode(uint8_t *Code)
{
	uint32_t u32TimeOut = 360000;

	RTC_WriteON();
	memcpy(&g_u8RTC_DataTx[0], Code, 3);
	g_u8RTC_RegIndex	= 0x14; 						  // RTC2404 REG INDEX
	g_u8RTC_TxIdx		= 0;							  // TX COUNTER
	g_u8RTC_DataBufLen	= 3;							  // TX DATA LENGTH
	g_u8RTC_InterruptEn = YES;							  // RTC INTERRUPT ENABLE
	g_u8RTC_TranMode	= RTC_MODE_TRANSMITTER;

	I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_BUF), ENABLE);	// Enable Event and Buffer Interrupts
	I2C_GenerateSTART(I2C1, ENABLE);						 // Generate the Start condition

	while(g_u8RTC_InterruptEn)
	{
		u32TimeOut--;
		if(u32TimeOut > 0)	  // 定时约30ms
		{
			if(g_u8RTC_Error == YES)
			{
				I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
				g_u8RTC_InterruptEn = NO;		// RTC INTERRUPT ENABLE
				g_u8RTC_Error = NO;
				RTC_WriteOFF();
				return;
			}
		}
		else
		{
			g_u8RTC_InterruptEn  = NO;
			//I2C_AcknowledgeConfig(I2C1, DISABLE);
			//I2C_GenerateSTOP(I2C1, ENABLE);
			I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
			RTC_WriteOFF();
			return;
		}
	}

	RTC_WriteOFF();
}


/*********************************************************
*函数名：ReadCode
*功能  ：读出存在E2PROM中的密码
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ReadCode(uint8_t *Code)
{
    uint32_t u32TimeOut = 360000;

    g_u8RTC_InterruptEn = YES;
	g_u8RTC_DataBufLen  = 0;
	g_u8RTC_TxIdx       = 0;
	g_u8RTC_RegIndex	= 0x14; 						  // RTC2404 REG INDEX
    g_u8RTC_TranMode    = RTC_MODE_TRANSMITTER;
    
    I2C_ITConfig(I2C1, (I2C_IT_EVT | I2C_IT_BUF), ENABLE);  // Enable Event and Buffer Interrupts
    I2C_GenerateSTART(I2C1, ENABLE);                         // Generate the Start condition

    while(g_u8RTC_InterruptEn)
    {
		u32TimeOut--;
        if(u32TimeOut > 0)    // 定时约30ms
        {
            if(g_u8RTC_Error == YES)
            {
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
                g_u8RTC_Error = NO;
                return;
            }
        }
        else
        {
            g_u8RTC_InterruptEn  = NO;
            //I2C_AcknowledgeConfig(I2C1, DISABLE);
            //I2C_GenerateSTOP(I2C1, ENABLE);
            I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
            return;
        }
    }

	g_u8RTC_InterruptEn = YES;
	g_u8RTC_DataBufLen	= 3;
	g_u8RTC_RxIdx		= 0;
	g_u8RTC_TranMode	= RTC_MODE_RECEIVER;
	memset(g_u8RTC_DataRx, 0, sizeof(g_u8RTC_DataRx));
	
    I2C_ITConfig(I2C1, I2C_IT_EVT, ENABLE);     // Enable Event Interrupts
    I2C_AcknowledgeConfig(I2C1, ENABLE);        // Enable Acknowledge
    I2C_GenerateSTART(I2C1, ENABLE);            // Generate the Start condition

    u32TimeOut = 360000;
	while(g_u8RTC_InterruptEn)
	{
		u32TimeOut--;
        if(u32TimeOut > 0)    // 定时约30ms
        {
            if(g_u8RTC_Error == YES)
            {
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
                g_u8RTC_Error = NO;
                return;
            }
        }
        else
        {
            g_u8RTC_InterruptEn  = NO;
            //I2C_AcknowledgeConfig(I2C1, DISABLE);
            //I2C_GenerateSTOP(I2C1, ENABLE);
            I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
            return;
        }
	}
	memcpy(&Code, g_u8RTC_DataRx, 3);
}

