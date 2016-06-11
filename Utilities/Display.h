#ifndef __DISPLAY_H
#define __DISPLAY_H

void DispStartUpPage(void);
void DispFuncKey_Param(void);
void DispParamWorkState(void);

//F1-F4子界面
void DispMenuText_PageF1(void);
void DispMenuText_PageF2(void);
void DispMenuText_PageF3(void);
void DispMenuText_PageF4(void);

/*F1-设置界面下拉选项*/
void DispMenuText_ParamRadioIp(void);
void DispMenuText_ParamRadioMask(void);
void DispMenuText_ParamFactorySet(void);
//void DispMenuText_ParamEntFactorySet(void);


/*F2-链路界面下拉选项*/
void DispMenuText_ParamLinkBuild(void);
void DispMenuText_ParamLinkMaintain(void);
void DispMenuText_ParamLinkQuery(void);


/*F3-监控界面下拉选项*/
void DispMenuText_ParamWorkState(void);
void DispMenuText_ParamDigTranStatis(void);
void DispMenuText_ParamDigTranReport(void);
void DispMenuText_ParamDebugInfo(void);
void DispMenuText_ParamRunTime(void);


/*F4-系统界面下拉选项*/
void DispMenuText_ParamDateTime(void);
void DispMenuText_ParamRadioTest(void);
void DispMenuText_ParamPowerCheck(void);
void DispMenuText_ParamUnlightOnOff(void);
void DispMenuText_ParamVersionInfo(void);
//void DispMenuText_ParamEntPowerCheck(void);


/*反显*/
void DispItemReverse(void);
void DispItemReverse_ParamLinkBuild(void);
void DispItemReverse_ParamLinkMaintain(void);
void DispItemReverse_ParamLink(void);
// void DispItemReverse_ParamLinkMaintain(void);
void DispWorkStateReverse(uint8_t rev);
void DispWorkStateReverse1(uint8_t rev);  // test
void DispItemReverse_ParamWorkState(void);
void DispItemReverse_ParamDateTime(void);
void DispItemReverse_ParamUnlightOnOff(void);
void DispDateTimeReverse(uint8_t rev);

/*正显*/
void DispItemRecover(void);
void DispItemRecover_ParamLinkBuild(void);
void DispItemRecover_ParamLinkMaintain(void);
void DispItemRecover_ParamLink(void);
// void DispItemRecover_ParamLinkMaintain(void);
void DispItemRecover_ParamWorkState(void);
void DispItemRecover_ParamDateTime(void);
void DispItemRecover_ParamUnlightOnOff(void);

//日期时间
void DispDateNum(uint8_t rev);
void DispTimeNum(uint8_t rev);
void DispRunTimeNum(void);
void DispRealTimeWorkState(void);
void DispRealTimeRate(void);

//其余功能函数
void DispItemSelectResult(void);

//串口交互
void DispSendRate(void);
void DispRadioRank(uint8_t rev);
void DispRadioPower(uint8_t rev);
void DispMacAddr(uint8_t rev);
void DispRate(uint8_t rev);
void DispSNR(void);
void DispIpAddr(uint8_t x, uint8_t y, uint8_t rev);
void DispMaskAddr(uint8_t x, uint8_t y, uint8_t Type, uint8_t rev);
void DispMask_CountOne(uint8_t j,uint8_t k );
void DispMacAddr1(uint8_t rev);
void DispMacAddr2(uint8_t rev);
void DispRadioTest(void);
void DispLinkBuildOprt(void);
void DispResult_StatisLinkBuild(void);
void DispMac(void);
void DispIntensityLogo(void);
void DispLinkQuantity(uint8_t rev);
void DispLinkQuantity_Test(uint8_t rev);
void DispLinkMaintainGap(void);
void ProcLinkBuildParamKey_UpDown(void);
void DispLinkOprtParamReverse(void);
void DispLinkBuildState(uint8_t state,uint8_t rev);
void DispGap(uint8_t x, uint8_t y, uint8_t u8Gap, uint8_t rev);
void DispReverseGap(void);
void DispRecoverGap(void);
void DispRecoverLinkMaintainGap_Text(void);
void DispDigTranInfo_Mac(void);
void DispDigTranInfo_FrameInfo(void);
void DispLinkNetState(uint8_t x,uint8_t y,uint8_t rev);






	








	







#endif

