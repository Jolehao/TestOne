#include "common.h"

//  按键类外部变量定义
uint8_t g_u8KeyPressed  = NO;
uint8_t g_u8KeyRelesed  = YES;
uint8_t g_u8KeyValue    = 0;
uint8_t g_u8NumBuf[20]  = {0};
uint8_t g_u8DispBuf[30] = {0};
uint8_t g_u8DispBuf_Mac[30] = {0};  // 重新定义数组是因为不断刷新，为防被g_u8DispBuf[]覆盖
uint8_t g_u8DispBuf_Frame[100] = {0};

uint8_t g_u8NumIndex    = 0;

//  菜单状态类外部变量定义
uint8_t g_u8CurMenuID = MENU_POWER_ON;
uint8_t g_u8PreMenuID = MENU_POWER_ON;
uint8_t g_u8TimeCount_Cur = 0;  // 本次开机持续时间
uint8_t g_u8Timecount_All = 0;  // 总运行时间



uint8_t g_u8MenuItem_Bak1 = 0;   // 第一层菜单选项备份
uint8_t g_u8MenuItem_Bak2 = 0;   // 第二层菜单选项备份
uint8_t g_u8MenuItem_Bak3 = 0;   // 第三层菜单选项备份
uint8_t g_u8MenuItem_Bak4 = 0;   // 第三层菜单选项备份

uint8_t g_u8EditMenuItem  = 1;   // 当前页上一条选项
uint8_t g_u8CurMenuItem   = 1;   // 当前页当前选项
 
uint8_t g_u8ParamEditState = NO;
uint8_t g_u8ParamEditIndex = 0;

uint8_t g_u8CmdSending     = 0;
uint8_t g_u8LinkBuildCount = 0;

//  参数类外部变量定义
uint8_t g_u8SelftestState[2]  = {0};
uint8_t g_u8LinkTestMac       = 0;
uint8_t g_u8PreSpeakerState   = OFF;
uint8_t g_u8SpeakerState      = OFF;
uint8_t g_u8PreBackLightState = OFF;
uint8_t g_u8PreLinkOprtState  = LinkBuild;
uint8_t g_u8BackLightState    = OFF;
uint8_t g_u8FilterDirectState = OFF;
uint8_t g_u8EditTestMode      = 0;
uint8_t g_u8CurTestMode       = 0;
uint8_t g_u8CurVolume         = 1;
uint8_t g_u8LinkOprtState[8] = {0};
uint8_t g_u8LinkBuildState[8] = {0};
uint8_t g_u8CurAttn[2]        = {0};
uint8_t g_u8EditAttn[2]       = {0};
uint8_t g_u8LinkInfo[60]      = {0};
uint8_t g_u8CurRefVol[2]      = {1};
uint8_t g_u8EditRefVol[2]     = {1};
uint8_t g_u8FilterMode        = 0;
uint8_t  au8Code[2] = {0,0};


// 其他外部变量定义
uint8_t g_u8Temp         = 0;
uint8_t g_u8FlagStartUp  = OFF;
uint8_t g_u8UpdateTime   = 0;
uint8_t g_u8GetTimeEnd   = NO;
uint8_t g_u8RadioState   = YES;	// 电台状态，开机超时为NO，正常开机为YES
uint8_t g_u8MaintainOnOff = ON;

uint8_t g_u8RTxTimeFlag  = NO;
uint8_t g_u8MaskZeroFlag = NO;
uint8_t g_u8NoSendFlag   = NO;
uint8_t g_u8SecureFlag   = SECURE_EMPTY;

uint16_t g_u16Timer2Count = 0;
uint16_t g_u16SecondCount = 0;
uint16_t g_u16RTxTimeTick = 0;
uint8_t  g_u8RunTimeUpdate = 0;
uint8_t  g_u8RunTimeCount = 0;
uint8_t  g_u8PowerOnOffTick = 0;

uint8_t g_u8EnterFactory = NO;
uint8_t g_u8PowerOn      = NO;
#if 0
uint8_t g_u8EditTestType = TEST_CLOSED;
uint8_t g_u8CurTestType  = TEST_CLOSED;
#endif
uint8_t g_u8SelectItemOK = NO;
uint8_t g_u8FnKeyOK      = NO;
uint8_t g_u8ParamStepOK  = NO;

uint8_t g_u8NumBuf1[3] = {0}; 
uint8_t	g_u8NumBuf2[3] = {0};
uint8_t	g_u8NumBuf3[3] = {0};
uint8_t	g_u8NumBuf4[3] = {0}; 
uint8_t SelectStation = SubStation;


// test 
uint8_t ReportMac_Bef = 0;  //上一次的Mac
uint8_t ReportMac_Now = 0;
// test


uint8_t SetMac        = NO;  // test
uint8_t SelectPage    = PageOne;
uint8_t SelectState01 = LinkRemove; // 拆链-标志位
uint8_t SelectState02 = LinkRemove;
uint8_t SelectState03 = LinkRemove;
uint8_t SelectState04 = LinkRemove;
uint8_t SelectState05 = LinkRemove;
uint8_t SelectState06 = LinkRemove;
uint8_t SelectState07 = LinkRemove;
uint8_t SelectState08 = LinkRemove;



// 参数备份存储变量
uint8_t g_u8TempNetMode  = 0;
uint8_t g_u8TempPower    = 0;
uint8_t g_au8TempFreq[3] = {0};

// 串口缓存外部变量
uint8_t g_u8SerialDataRx[200] = {0};  // 环形存储器，串口收数据
uint8_t g_u8LengthRx = 0;
uint8_t g_u8HeadRx   = 0;
uint8_t g_u8TailRx   = 0;

uint8_t g_u8SerialDataTx[200] = {0};  // 环形存储器，串口发数据
uint8_t g_u8LengthTx = 0;

uint8_t g_u8RadioCommRx_Len = 0;
uint8_t g_u8RadioCommTx_Len = 0;

TOD_TypeDef t_CurTime, t_EditTime;
TOD_TypeDef t_SubRunTime,t_SumRunTime,t_PoweronTime;
SecureParam_TypeDef t_EditSecureState, t_CurSecureState;
RadiolParam_TypeDef t_EditRadioState, t_CurRadioState;
ChannelParam_TypeDef t_EditChannelState, t_CurChannelState;
LinkDigInfo_TypeDef t_CurStatisFrame,t_EditStatisFrame;
LinkQuaInfo_TypeDef t_CurLinkQuanlity[4];
LinkReportQua_TypeDef t_ReportLinkQuan[4];
LinkInfo_TypeDef t_EditLinkInfo[8],t_CurLinkInfo[8];

/*********************************************************
*函数名：Delay_nUS
*功能  ：延时n微秒
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void Delay_nUS(uint16_t count)
{
	uint8_t i = 0;
    uint16_t u16Count = 0;
    u16Count = count;
    
	while(u16Count--)
	{
		i = 12;
		while(i--)
		{}
	}
}

/*********************************************************
*函数名：DelaynMS
*功能  ：延时n毫秒
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void Delay_nMS(uint16_t count)
{
    uint16_t u16Count;
    u16Count = count;
    
	while(u16Count--)
	{
        Delay_nUS(1000);
	}
}

/*********************************************************
*函数名：Delay_nS
*功能  ：延时n秒
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void Delay_nS(uint16_t count)
{
    uint16_t u16Count;
    u16Count = count;
    
	while(u16Count--)
	{
        Delay_nMS(1000);
	}
}

/*********************************************************
*函数名：ConvertBCDtoDecimal
*功能  ：将BCD码转换为十进制数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
uint8_t ConvertBCDtoDecimal(uint8_t Data_BCD)
{
    uint8_t mResult = 0;

    mResult = (Data_BCD >> 4)*10 + (Data_BCD & 0x0F);
    return mResult;
}

/*********************************************************
*函数名：ConvertBCDtoDecimal
*功能  ：将十进制数转换为BCD码
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
uint8_t ConvertDecimaltoBCD(uint8_t Data_DEC)
{
    uint8_t mResult = 0;

    mResult = ((Data_DEC/10%10) << 4) + (Data_DEC%10);
    return mResult;
}

uint8_t isSecureOK(void)
{
	uint8_t mResult = 0;

	if(SECURE_NORMAL == g_u8SecureFlag)
	{
		mResult = YES;
	}
	else
	{
		mResult = NO;
	}
	
	return mResult;
}




