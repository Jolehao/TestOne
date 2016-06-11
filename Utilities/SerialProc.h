#ifndef __SERIALPROC_H
#define __SERIALPROC_H


void Report_ACK(void);
void Report_NACK(void);
void Report_SecureIp(void);
void Report_RadioPower(void);
void Report_RadioRank(void);
void Report_RadioMac(void);
void Report_RadioId(void);









//-------------------------串口指令宏定义----------------------------
#define    REPORT_SOFT_VERSION           0x0080      
#define    REPORT_TIME                   0x0041
#define    REPORT_RADIO_MAC              0x0083  
#define    REPORT_RADIO_IP               0x0084      
#define    REPORT_RADIO_MASK             0x0085
#define    REPORT_RADIO_POWER            0x0086  
#define    REPORT_RADIO_RANK             0x0087      
#define    REPORT_RADIO_ID               0x008D      
#define    REPORT_UPPER_NETNUM           0x008F
#define    REPORT_MAX_MAC		         0x0090
#define    REPORT_MANAGE_IP     		 0x1384
#define    REPORT_INC_IP        		 0x1385
#define    REPORT_SECURE_IP   		 	 0x1386
#define    REPORT_SPU_SOFT_VERSION		 0x0098

#define    REPORT_CHAN_PARAM             0x0181 
#define    REPORT_LINK_MAINTAINGAP       0x0288
#define    REPORT_LINK_QUALITY           0x0289
#define    REPORT_LINK_DIGTRANSTATIS     0x08a8
#define    REPORT_LINK_DIGTRANREPORT     0x08a9

#define    REPORT_POWER_OFF       		 0x0308 
#define    REPORT_ACK                    0x0380 
#define    REPORT_NACK                   0x0381 
#define    REPORT_WORK_INFO              0x0382
#define    REPORT_RADIO_TEST             0x0383
#define    REPORT_LINK_STATE             0x0384
#define    REPORT_LINK_TEST              0x0388
#define    REPORT_NETPORT_STATE          0x0394

#define    REPORT_SCAN_PARAM             0x03B2
#define    REPORT_POWER_SCAN             0x03B3
#define    REPORT_SCAN_STOP              0x03B4
#define    REPORT_POWER_TEST             0x03B5

#define    REPORT_RADIO_INFO             0x03F0
#define    REPORT_STARTUP_REMOTE         0x03F1
#define    REPORT_TIPS_INFO              0x03F3

#define    REPORT_WAVE_MODE              0x6600

#define    REPORT_SECURE_QUERY           0xA199
#define    REPORT_SECURE_CONFIG          0xA190
#define    REPORT_SECURE_CONFIG1         0xA191
#define    REPORT_SECURE_DESTROY         0xA19A
#define    REPORT_SECURE_TIME            0xA19C
#define    REPORT_SECURE_TEST            0xA198
#define    REPORT_SECURE_STATE           0xA196
#define    REPORT_SECURE_INJECT          0xA19D

#define    NUM_OF_CMD                    (sizeof(t_ReportCommand)/sizeof(t_ReportCommand[0]))

typedef struct
{
    uint16_t Fuction_ID;
    void (*ProcessFuction)(void);
}SerialFunction_TypeDef;

//-----------------------------函数定义----------------------------
void Set_DateOfTime(void);
void Set_ChanNum(void);
void Set_ClrRFDigtal(void);
void Set_RadioMac(void);
void Set_ServiceIp(void);
void Set_ServiceMask(void);
void Set_RadioPower(void);
void Set_RadioRank(void);
void Set_RadioId(void);
void Set_UpperNet(void);

void Set_ChanParam(void);
void Set_RadioTest(void);
void Set_LinkTest(void);
void Set_LinkOprt(void);
void Set_LinkMaintainGap(void);
void Set_DestroyParam(void);
void Set_DefaultParam(void);
void Set_NetPortState(void);
void Set_PowerScan(void);
void Set_PowerScanStop(void);
void Set_SecureTest(void);
void Set_SecureSwitch(void);

void Set_PowerOff(void);
void Set_RefVol(void);
void Set_PowerAttn(void);
void Set_FilterMode(void);
void Set_WaveMode(void);


void Query_SoftVersion(void);
void Query_LinkTest(void);
void Query_DigTranStatis(void);
void Query_DigTranReport(void);
void Query_DebugInfo(void);
void Query_LinkMaintainGap(void);
void Query_DateOfTime(void);
void Query_RadioMac(void);
void Query_RadioRank(void);
void Query_LinkQuality(void);
void Query_ServiceIp(void);
void Query_ServiceMask(void);
void Query_RadioPower(void);
void Query_RadioId(void);
void Query_MaxMac(void);
void Query_UpperNet(void);
void Query_ChanNum(void);
void Query_ChanParam(void);
void Query_NetPortState(void);
void Query_PowerTest(void);
void Query_SecureVersion(void);
void Query_PowerAttn(void);


void Report_SecureTest(void);
void Set_SecureQuery(void);
void Set_SecureConfig(void);
void Set_SecureDestroy(void);
void Set_SecureTime(void);
void Query_SecureConfig(void);
void Query_SoftVersion(void);
void Send_SerialData(void);
void Receive_SerialData(void);
void ProcSerialRxCommand(void);
/*
void Report_SoftVersion(void);
void Report_DateOfTime(void);
void Report_RadioMac(void);
void Report_RadioIp(void);
void Report_RadioMask(void);
void Report_RadioPower(void);
void Report_RadioId(void);
void Report_UpperNet(void);
void Report_ChanParam(void);
void Report_ACK(void);
void Report_NACK(void);
void Report_WorkInfo(void);
void Report_RadioTest(void);
void Report_LinkTest(void);
void Report_NetPortState(void);
void Report_PowerScan(void);
void Report_ScanStop(void);
void Report_PowerTest(void);
void Report_RadioInfo(void);
void Report_StartUpAndRemote(void);
void Report_TipsInfo(void);
void Report_SecureTest(void);
void Report_SecureWkey(void);
void Report_SecureVersion(void);
void Report_SecureSwitch(void);






*/
void mockReportWorkInfo(void);

void Report_LinkMaintainGap(void);
void Report_LinkQuality(void);
void Report_LinkInfo(void);
void Report_DigTranStatis(void);
void Report_DigTranReport(void);



#endif
