#include "common.h"

//  �������ⲿ��������
uint8_t g_u8KeyPressed  = NO;
uint8_t g_u8KeyRelesed  = YES;
uint8_t g_u8KeyValue    = 0;
uint8_t g_u8NumBuf[20]  = {0};
uint8_t g_u8DispBuf[30] = {0};
uint8_t g_u8DispBuf_Mac[30] = {0};  // ���¶�����������Ϊ����ˢ�£�Ϊ����g_u8DispBuf[]����
uint8_t g_u8DispBuf_Frame[100] = {0};

uint8_t g_u8NumIndex    = 0;

//  �˵�״̬���ⲿ��������
uint8_t g_u8CurMenuID = MENU_POWER_ON;
uint8_t g_u8PreMenuID = MENU_POWER_ON;
uint8_t g_u8TimeCount_Cur = 0;  // ���ο�������ʱ��
uint8_t g_u8Timecount_All = 0;  // ������ʱ��



uint8_t g_u8MenuItem_Bak1 = 0;   // ��һ��˵�ѡ���
uint8_t g_u8MenuItem_Bak2 = 0;   // �ڶ���˵�ѡ���
uint8_t g_u8MenuItem_Bak3 = 0;   // ������˵�ѡ���
uint8_t g_u8MenuItem_Bak4 = 0;   // ������˵�ѡ���

uint8_t g_u8EditMenuItem  = 1;   // ��ǰҳ��һ��ѡ��
uint8_t g_u8CurMenuItem   = 1;   // ��ǰҳ��ǰѡ��
 
uint8_t g_u8ParamEditState = NO;
uint8_t g_u8ParamEditIndex = 0;

uint8_t g_u8CmdSending     = 0;
uint8_t g_u8LinkBuildCount = 0;

//  �������ⲿ��������
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


// �����ⲿ��������
uint8_t g_u8Temp         = 0;
uint8_t g_u8FlagStartUp  = OFF;
uint8_t g_u8UpdateTime   = 0;
uint8_t g_u8GetTimeEnd   = NO;
uint8_t g_u8RadioState   = YES;	// ��̨״̬��������ʱΪNO����������ΪYES
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
uint8_t ReportMac_Bef = 0;  //��һ�ε�Mac
uint8_t ReportMac_Now = 0;
// test


uint8_t SetMac        = NO;  // test
uint8_t SelectPage    = PageOne;
uint8_t SelectState01 = LinkRemove; // ����-��־λ
uint8_t SelectState02 = LinkRemove;
uint8_t SelectState03 = LinkRemove;
uint8_t SelectState04 = LinkRemove;
uint8_t SelectState05 = LinkRemove;
uint8_t SelectState06 = LinkRemove;
uint8_t SelectState07 = LinkRemove;
uint8_t SelectState08 = LinkRemove;



// �������ݴ洢����
uint8_t g_u8TempNetMode  = 0;
uint8_t g_u8TempPower    = 0;
uint8_t g_au8TempFreq[3] = {0};

// ���ڻ����ⲿ����
uint8_t g_u8SerialDataRx[200] = {0};  // ���δ洢��������������
uint8_t g_u8LengthRx = 0;
uint8_t g_u8HeadRx   = 0;
uint8_t g_u8TailRx   = 0;

uint8_t g_u8SerialDataTx[200] = {0};  // ���δ洢�������ڷ�����
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
*��������Delay_nUS
*����  ����ʱn΢��
*����  ����
*���  ����
*����ֵ����
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
*��������DelaynMS
*����  ����ʱn����
*����  ����
*���  ����
*����ֵ����
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
*��������Delay_nS
*����  ����ʱn��
*����  ����
*���  ����
*����ֵ����
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
*��������ConvertBCDtoDecimal
*����  ����BCD��ת��Ϊʮ������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t ConvertBCDtoDecimal(uint8_t Data_BCD)
{
    uint8_t mResult = 0;

    mResult = (Data_BCD >> 4)*10 + (Data_BCD & 0x0F);
    return mResult;
}

/*********************************************************
*��������ConvertBCDtoDecimal
*����  ����ʮ������ת��ΪBCD��
*����  ����
*���  ����
*����ֵ����
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




