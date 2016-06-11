
#ifndef  __KEYBOARD_H
#define  __KEYBOARD_H

#include "common.h"


typedef struct
{
    uint8_t Fuction_ID;
    void (*ProcessFuction)(void);
}ProcessFunction_TypeDef;


//����ɨ��״̬
void ScanKey(void);
void ScanKeyState1(uint8_t Index_Y);
void ScanKeyState2(uint8_t Index_Y);
void ScanKeyState3(uint8_t Index_Y);
void ScanKeyState4(uint8_t Index_Y);
uint8_t ReadKeyState(void);


//�����
void SelectItem_UP(uint8_t MAXItem);
void SelectItem_Down(uint8_t MAXItem);
void SelectItem_LR(uint8_t MAXItem);
void SelectItem_LR_LinkBuild(uint8_t MAXItem);
void SelectItem_LR_WorkState(uint8_t MaxItem);
// void SelectItem_LR_LinkMaintain(uint8_t MaxItem);
void SelectMenuItem(uint8_t MAXItem);

#if 0
//�����漰F1-F4����
void ProcMainPageKey_F1(void);
void ProcMainPageKey_F2(void);
void ProcMainPageKey_F3(void);
void ProcMainPageKey_F4(void);
#endif

//F1-F4����
void ProcMenuKey_SetF1(void);
void ProcMenuKey_SetF2(void);
void ProcMenuKey_SetF3(void);
void ProcMenuKey_SetF4(void);


//F1-���ý���
void ProMenuKey_ParamRadioIp(void);
void ProMenuKey_ParamRadioMask(void);
void ProMenuKey_ParamFactorySet(void);
//void ProMenuKey_ParamEntFactorySet(void);


//F2-��·����
void ProMenuKey_ParamLinkBuild(void);
void ProMenuKey_ParamLinkMaintain(void);
void ProMenuKey_ParamLinkQuery(void);


//F3-��ؽ���
void ProMenuKey_ParamWorkState(void);
void ProMenuKey_ParamDigTranStatis(void);
void ProMenuKey_ParamDigTranReport(void);
void ProMenuKey_ParamDebugInfo(void);
void ProMenuKey_ParamRunTime(void);


//F4-ϵͳ����
void ProMenuKey_ParamDateTime(void);
void ProMenuKey_ParamRadioTest(void);
void ProMenuKey_ParamPowerCheck(void);
void ProMenuKey_ParamUnlightOnOff(void);
void ProMenuKey_ParamVersionInfo(void);
//void ProMenuKey_ParamEntPowerCheck(void);


//F1-F4�������µ����ְ���
void ProcNumKey_SetIp(void);
void ProcNumKey_SetMask(void);
void ProcNumKey_InputF1Num(void);
void ProcNumKey_InputF2Num(void);
void ProcNumKey_InputF3Num(void);
void ProcNumKey_InputF4Num(void);
void ProcNumKey_InputMaintainGapNum(uint8_t u8Key);
void ProcNumKey_InputUnlightOnOffNum(void);


//����ʱ���µ����ְ���
void ProcNumKey_Time(void);
void ProcNumKey_Date(void);
void ProcNumKey_Time(void);
void ProcNumKey_Freq(void);
void ProcNumKey_TableNum(void);
//void ProcNumKey_SetMac(uint8_t u8MaxMac);
void ProcNumKey_MacNum(void);
void ProcNumKey_MacNum_Test(void);
void ProcNumKey_ChanNum(void);



// ����������
void ProcEditPower_Add1(void);
void ProcEditMac_Add1(void);
void ProcEditMac_Add2(void);
void ProcEditChanNum_Add1(void);
void ProcEditWorkMode_Add1(void);
void ProcEditFreOrTab_Add1(void);
void ProcEditParamWorkState_Add1(void);

void ProcEditPower_Cut1(void);
void ProcEditMac_Cut1(void);
void ProcEditMac_Cut2(void);
void ProcEditChanNum_Cut1(void);
void ProcEditWorkMode_Cut1(void);
void ProcEditFreOrTab_Cut1(void);
void ProcEditParamWorkState_Cut1(void);


//���������ʵȿ���
void GetPowerOnTime(void);
void PTT_Ctrl(void);
void Volume_Ctrl(void);
void PowerOnOff_Ctrl(void);
void AlarmLed_Ctrl(uint8_t *State);
void Rx_Tx_Led_Ctrl(uint8_t State);


//ȡ����ȷ�ϼ�
void ProcDateTimeKey_ENT(void);
void ProcLinkBuild_ENT(void);
void ProcLinkMaintain_ENT(void);
void ProcParamWorkState_ENT(void);
void ProcLinkMaintain_ESC(void);
void ProcParamWorkState_ESC(void);



void RespondKey(void);

void ProcRealTimeUpdate(void);
void ProcTimeOutEvent(void);
void ProcTimeOutWarning(void);
void ProcTimeOut_PowerOnOff(void);


void ProcEditDateTime_Num(void);
void ProcEditRank_Step1(void);
void ProcEditParamWorkState_Num(void);
void DispChannelNum(uint8_t rev);
void DispMacNum(uint8_t rev);
void DispWorkMode(uint8_t rev);
void DispTableNum(uint8_t rev);
void DispNetNum(uint8_t rev);
void DispFrequency(uint8_t rev);
void GetEditNum_ParamWorkState(void);
void GetEditNum_ParamWorkState_Test(void);

//Ƶ���µ�����λ
uint8_t IsFreqvalid_FirstNum(uint8_t KeyValue);
uint8_t IsFreqvalid_SecondNum(uint8_t KeyValue);
uint8_t IsFreqvalid_ThirdNum(uint8_t KeyValue);
uint8_t IsFreqvalid_ForthNum(uint8_t KeyValue);
uint8_t IsFreqvalid_FifthNum(uint8_t KeyValue);
uint8_t IsFreqNumvalid(uint8_t KeyValue);

void ProTwelveNum(void);


//�����µ�����λ
void GetDate_FirstNum(uint8_t KeyValue);
void GetDate_ThirdNum(uint8_t KeyValue);
void GetDate_ForthNum(uint8_t KeyValue);
void GetDate_FifthNum(uint8_t KeyValue);
void GetDate_SixthNum(uint8_t KeyValue);
void GetDate_SecondNum(uint8_t KeyValue);


uint8_t IsNumCorrect_IP(void);


//MAC��ַ�µ�����λ
uint8_t IsNumCorrect_Mask(void);
uint8_t IsFirstNumCorrect_Mask(void);
uint8_t IsSecondNumCorrect_Mask(void);
uint8_t IsThirdNumCorrect_Mask(void);



































#endif

