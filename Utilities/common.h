#ifndef __COMMON_H
#define __COMMON_H

#include <stdint.h>

#define __LATERAL__		ON/*OFF*/	/*采用分支流程时(即与显示规范不符)，置为ON；采用标准显示规范时，置为OFF*/
#define __UNIT_TEST__	ON/*OFF*/	/*单元板测试时置为ON,整机测试是置为OFF*/

#define   	 YES 	     1
#define   	 NO 	     0  

#define   	 ON 	     1
#define   	 OFF	     0  

#define   	 MainStation 1
#define   	 SubStation	 0  

#define      LinkBuild   1  // 建链
#define      LinkRemove  0  // 拆链

#define      PageOne     0
#define      PageTwo     1

#define   	 RTX 	     3
#define   	 RX 	     2
#define   	 TX	         1  
#define   	 WAIT	     0  

#define      BOTTOM	     0
#define      TOP         1

#define      TEXT	     0
#define      PICTURE     1

#define      NORMAL	     0
#define      LARGE       1

#define      SERVICE	 0

#define      SINGLE_MAC	     0
#define      MULTIPLE_MAC    1

#define      PROCMENUKEY_MAXNUM			 (sizeof(t_ProcMenuKey)/sizeof(t_ProcMenuKey[0]))//27
#define      WORD			             40

#define		TOTAL_ITEMS_PER_LINE		4
#define		FIRST_ITEM_IN_2ND_LINE	(TOTAL_ITEMS_PER_LINE+1)


// --------------------------------参数编辑索引宏定义--------------------------------------
//------------ F1-设置参数页----------------
/*电台IP*/
#define      INDEX_EDIT_RADIOIP	   1 
#define      INDEX_EDIT_RADIOMAC   1
/*    */




//------------ F2-链路参数页----------------
/*链路维护*/
#define     INDEX_EDIT_MAC01   1 
#define     INDEX_EDIT_MAC02   2
#define     INDEX_EDIT_MAC03   3 
#define     INDEX_EDIT_MAC04   4
#define     INDEX_EDIT_MAC05   5     
#define     INDEX_EDIT_MAC06   6
#define     INDEX_EDIT_MAC07   7    
#define     INDEX_EDIT_MAC08   8

/*链路间隔*/
#define     INDEX_EDIT_GAP0    0
#define     INDEX_EDIT_GAP1    1
#define     INDEX_EDIT_GAP2    2
#define     INDEX_EDIT_GAP3    3
/*链路查询*/





//------------ F3-监控参数页----------------
/*工作状态*/
#define      INDEX_EDIT_FREQ_TAB	     1   //频率
#define      INDEX_EDIT_WORKMODE	     2	 //模式
#define      INDEX_EDIT_RANK    	     3   //等级
#define      INDEX_EDIT_POWER    	     4 	 //功率
#define      INDEX_EDIT_MAC              5   //站号
#define      INDEX_EDIT_CHANNUM          6   //信道号





//------------ F4-系统参数页----------------
/*背光开关*/

/*日期时间*/
#define      INDEX_EDIT_DATE		 1   
#define      INDEX_EDIT_TIME         2 

#define      INDEX_EDIT_RATE    	 5



// --------------------------------键值宏定义--------------------------------------
#define      KEY_0		    0
#define      KEY_1		    1
#define      KEY_2		    2
#define      KEY_3		    3
#define      KEY_4		    4
#define      KEY_5		    5
#define      KEY_6		    6
#define      KEY_7		    7
#define      KEY_8		    8
#define      KEY_9		    9
#define      KEY_LEFT		0x0A
#define      KEY_RIGHT		0x0B
#define      KEY_UP		 	0x0C
#define      KEY_DOWN		0x0D
#define      KEY_F1		    0x0E
#define      KEY_F2		    0x0F
#define      KEY_F3		    0x10
#define      KEY_F4		    0x11
#define      KEY_F5		    0x12
#define      KEY_F6		    0x13
#define      KEY_ESC		0x14
#define      KEY_ENT		0x15
#define      KEY_VOL_UP		0x16
#define      KEY_VOL_DOWN	0x17
#define      KEY_NULL		0xFF

// --------------------------------行列地址宏定义--------------------------------------
#define      WIDTH_FONT	    3
#define      WIDTH_CHAR	    2
#define      FONT_START	    1

#define      ROW_GAP	    0x18

#define      ROW_TEXT01	    0x05
#define      ROW_TEXT02	    0x1D
#define      ROW_TEXT03	    0x35
#define      ROW_TEXT04	    0x4B
#define      ROW_TEXT05	    0x65
#define      ROW_TEXT06	    0x7D
#define      ROW_TEXT07	    0x95
#define      ROW_TEXT08	    0xAD
#define      ROW_TEXT09	    0xC5
#define      ROW_TEXT10	    0xDD

#define      COL_WORD1	    2
#define      COL_WORD2	    4
#define      COL_WORD3	    6
#define      COL_WORD4	    8
#define      COL_WORD5	    10
#define      COL_WORD6	    12
#define      COL_WORD7	    14
#define      COL_WORD8	    16
#define      COL_WORD9	    18
#define      COL_WORD10	    20
#define      COL_WORD11	    22
#define      COL_WORD12	    24
#define      COL_WORD13	    26
#define      COL_WORD14	    28
#define      COL_WORD15	    30
#define      COL_WORD16	    32
#define      COL_WORD17	    34
#define      COL_WORD18	    36
#define      COL_WORD19	    38

#define      WIDTH_HALF	    1
#define      WIDTH_WORD	    2

// --------------------------------电台模式宏定义--------------------------------------
/*音量等级*/
#define      VOLUME_SILENCE    		 0
#define      VOLUME_LEVEL1    		 1
#define      VOLUME_LEVEL2    		 2
#define      VOLUME_LEVEL3    		 3

/*工作模式*/
#define      WORKMODE_FIX    		 3
#define      WORKMODE_HOP    		 4
#define      WORKMODE_SFIX    		 5
#define      WORKMODE_SHOP    		 6

/*网络模式*/
#define      NETMODE_PRN    		 0
#define      NETMODE_LINK    		 1
#define      NETMODE_QLINK    		 2

#define      POWER_DUTY    		     0
#define      POWER_LOW    		     1
#define      POWER_HIGH    		     3

#define      RANK_SLAVE    		     0
#define      RANK_MASTER   		     1

#define      RATE_64k    		     0
#define      RATE_128k   		     1
#define      RATE_192k   		     2
#define      RATE_256k    		     4
#define      RATE_512k   		     5
#define      RATE_1024k    		     6

#define      STATE_ASYN    		     0
#define      STATE_SYN   		     1
#define      STATE_CONNECT		     2

#define      MODULE_FREQ_GEN	     0
#define      MODULE_CHAN		     1
#define      MODULE_POWER		     2
#define      MODULE_MAIN_CTRL     	 3
#define      MODULE_EXCHANGE     	 4
#define      MODULE_PANEL	     	 5
#define      MODULE_DC   		     6
#define      MODULE_AC    		     7


#define      SECURE_NORMAL 		     0x00
#define      SECURE_ERROR		     0x5F
#define      SECURE_DESTROY		     0xAF
#define      SECURE_EMPTY			 0xFF

//---------------------------- 界面ID宏定义-------------------------------

#define      MENU_POWER_ON   		 0x00
#define      MENU_POWER_OFF		     0x01
#define      MENU_1ST_BITE			 0x02


//主界面
//#define      MENU_MAIN_PAGE          0x10

// F1-F4设置子界面
#define      MENU_SET_F1             0x30
#define      MENU_SET_F2             0x31
#define      MENU_SET_F3             0x32
#define      MENU_SET_F4             0x33

// F1-设置界面
#define      MENU_PARAMRADIOIP         0x40
#define      MENU_PARAMRADIOMASK	   0x41
#define      MENU_PARAMFACTORYSET      0x42
//#define      MENU_PARAMENTFACTORYSET   0x4A

// F2-链路界面
#define      MENU_PARAMLINKBUILD       0x50
#define      MENU_PARAMLINKMAINTAIN    0x51
#define      MENU_PARAMLINKQUERY       0x52


// F3-监控界面
#define      MENU_PARAMWORKSTATE       0x60
#define      MENU_PARAMDIGTRANSTATIS   0x61
#define      MENU_PARAMDIGTRANREPORT   0x62
#define      MENU_PARAMDEBUGINFO       0x63
#define      MENU_PARAMRUNTIME         0x64

// F4-系统界面
#define      MENU_PARAMDATETIME        0x67
#define      MENU_PARAMRADIOTEST       0x68
#define      MENU_PARAMPOWERCHECK      0x69
#define      MENU_PARAMUNLIGHTONOFF    0x6A
#define      MENU_PARAMVERSIONINFO     0x6B
//#define      MENU_PARAMENTPOWERCHECK   0x6C


// 定义表达式
#define  IsCurNetMode_TestMode(ModeId) (ModeId > NETMODE_QLINK)
#define  IsFuncKey(KeyValue)           ((KeyValue >= KEY_F1) && (KeyValue <= KEY_F5))
#define  IsNumberKey(KeyValue)         (KeyValue <= KEY_9)
#define  IsMonth31Days(Month)          ((Month == 1) || (Month == 3) || (Month == 5) || (Month == 7)  \
                                       || (Month == 8) || (Month == 10) || (Month == 12))
#define  IsMonth30Days(Month)          ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11))
#define  IsThirdNumOfAttn(Number)      ((Number == 0) || (Number == 2) || (Number == 5) || (Number == 7))

//--------------------- 通用函数结构体定义--------------------------
typedef struct
{
    uint8_t Mode_ID;
    uint8_t *Mode;
}Mode_TypeDef; 

typedef struct
{
	uint8_t MacNum;           // 链路Mac
	uint8_t NetState;         // 入网状态
	uint8_t Intensity;        // 场强
	uint8_t MaintainGap_ID;   // 
	//uint8_t *MaintainGap;     // 维护间隔显示文本
	uint8_t Quality_Up;       // 上行质量
	uint8_t Quality_Down;     // 下行质量
}LinkInfo_TypeDef;
extern LinkInfo_TypeDef t_EditLinkInfo[8],t_CurLinkInfo[8];

// test
typedef struct
{
	uint8_t  MacNum;
	uint8_t  SendFram[4];    // 发送帧
	uint8_t  ReceiveFram[4]; // 接收帧
	uint8_t  ConfuFram[4];  // 乱码帧
	uint8_t  ErroFram[4];  // 错误帧
}LinkDigInfo_TypeDef;
extern LinkDigInfo_TypeDef t_CurStatisFrame,t_EditStatisFrame;

typedef struct
{
	uint8_t  MacNum;    // 站号
	uint8_t  SNR;      // 信噪比
}LinkQuaInfo_TypeDef;
extern LinkQuaInfo_TypeDef t_CurLinkQuanlity[4];


typedef struct
{
	uint8_t  MacNum[2];    // 站号:为了补齐上报的两个字节，只取低字节
	uint8_t  SNR[2];      // 信噪比
}LinkReportQua_TypeDef;
extern LinkReportQua_TypeDef t_ReportLinkQuan[4];

typedef struct
{
    uint8_t Pos_ID;
    uint8_t Pos_x;
    uint8_t Pos_y;
}Position_TypeDef;
extern Position_TypeDef  Pos_IP[];

//--------------------- 电台参数结构体定义--------------------------
typedef struct
{
	uint8_t Second;       // 秒
	uint8_t Minute;       // 分
	uint8_t Hour;         // 时
	uint8_t WeekDay;      // 星期几
	uint8_t Day;          // 日
	uint8_t Month;        // 月
	uint8_t Year;         // 年
}TOD_TypeDef;
extern TOD_TypeDef t_CurTime, t_EditTime;
extern TOD_TypeDef t_SubRunTime,t_SumRunTime,t_PoweronTime;

typedef struct
{
	uint8_t BoardNum;         // 业务板号:1-信号处理插槽、1-扩展1插槽、2-扩展2插槽
	uint8_t WaveForm;         // 波形:0-173 、1-513
	uint8_t algorithm;        // 密码算法:0-老算法 、1-新算法
	uint8_t AreaNum;          // 区号:00H-FFH
	uint8_t GroupNum1;         // 组号:00H-FFH
	uint8_t GroupNum2;         // 组号:00H-FFH
	
	//uint8_t effect;       //有效性
	uint8_t state;        //自检结果
}SecureParam_TypeDef;
extern SecureParam_TypeDef t_EditSecureState, t_CurSecureState;

typedef struct
{
	uint8_t ChanNum;      // 站号 ChanNum  00信道
	uint8_t WaveMode;     // 波形模式      01高速
	uint8_t WorkMode;     // 工作模式      03定明
	uint8_t Freq[3];      // 频率Freq[0]-100M, Freq[1]-10M、1M, Freq[2]-100K、25K  (255.00MHz)
	uint8_t TableNum;     // 跳频表号      00 
	uint8_t NetNum[2];    // 跳频网号NetNum[0]-百位，NetNum[1]-十位、个位
	//uint8_t Rank;         // 电台主属: 主站 从站 00 
}ChannelParam_TypeDef;
extern ChannelParam_TypeDef t_EditChannelState, t_CurChannelState;

typedef struct
{
	uint8_t RemoteState;  // 遥控状态
	uint8_t Intensity;    // 场强
	uint8_t Indication;   // 指示
	uint8_t SendRate;     // 发方速率
	uint8_t VoiceCode;    // 发方语音编码方式
	uint8_t SyncState;    // 同步状态
	uint8_t NetState;     // 网络状态
	uint8_t SnrRate;      // 信噪比
	uint8_t ParamState;   // 电台参数状态
	uint8_t NC;          // 预留
	uint8_t CallMAC;      // 发方MAC

	uint8_t MAC;                // MAC地址
	uint8_t Rank;         // 电台主属: 主站 从站 00 
	uint8_t Service_IP[4];      // 业务IP地址
	uint8_t Service_MASK[4];    // 业务掩码
	uint8_t Service_GATEWAY[4]; // 业务网关地址
	uint8_t Manage_IP[4];       // 管理IP地址
	uint8_t Manage_MASK[4];     // 管理掩码
	uint8_t Manage_GATEWAY[4];  // 管理网关地址
	uint8_t INC_IP[4];          // 管理IP地址
	uint8_t INC_MASK[4];        // 管理掩码
	uint8_t INC_GATEWAY[4];     // 管理网关地址
	uint8_t Secure_IP[4];       // 密分服务器IP地址
	uint8_t Secure_MASK[4];     // 密分服务器掩码
	uint8_t Secure_GATEWAY[4];  // 密分服务器网关
	uint8_t ID[5];              // 设备ID
	uint8_t UpperNet;           // 上级网号
	uint8_t MaxMac;             // 规划节点

    uint8_t Power;        //功率
    uint8_t SoftVersion[4];  //软件版本
    uint8_t Volume;       //音量等级
}RadiolParam_TypeDef;
extern RadiolParam_TypeDef t_EditRadioState, t_CurRadioState;

typedef enum 
{
	TEST_SINE_WAVE = 0,
	TEST_NAR_CARRIER,
	TEST_WIDE_CARRIER,
	TEST_CLOSED,
	TEST_9VS3		/*CS,20131128,新增9:3测试模式，发宽带调制波形*/
}TEST_MODE_TYPE;


//  按键类外部变量定义
extern uint8_t g_u8KeyPressed;
extern uint8_t g_u8KeyRelesed;
extern uint8_t g_u8KeyValue;
extern uint8_t g_u8NumBuf[20];
extern uint8_t g_u8DispBuf[30];
extern uint8_t g_u8DispBuf_Mac[30];
extern uint8_t g_u8DispBuf_Frame[100];
extern uint8_t g_u8NumIndex;
extern uint8_t g_u8UpdateTime;
extern uint8_t g_u8GetTimeEnd;

//  菜单类外部变量定义
extern uint8_t g_u8CurMenuID;
extern uint8_t g_u8PreMenuID;
extern uint8_t g_u8TimeCout_Cur;
extern uint8_t g_u8TimeCount_All;

extern uint8_t g_u8MenuItem_Bak1;
extern uint8_t g_u8MenuItem_Bak2;
extern uint8_t g_u8MenuItem_Bak3;
extern uint8_t g_u8MenuItem_Bak4;
extern uint8_t g_u8EditMenuItem;
extern uint8_t g_u8CurMenuItem;

extern uint8_t g_u8ParamEditState;
extern uint8_t g_u8ParamEditIndex;

extern uint8_t g_u8CmdSending;
extern uint8_t g_u8LinkBuildCount;

//  参数类外部变量定义
extern uint8_t g_u8SelftestState[2];
extern uint8_t g_u8LinkTestMac;
extern uint8_t g_u8PreSpeakerState;
extern uint8_t g_u8SpeakerState;
extern uint8_t g_u8PreBackLightState;
extern uint8_t g_u8PreLinkOprtState;
extern uint8_t g_u8BackLightState;
extern uint8_t g_u8FilterDirectState;
extern uint8_t g_u8EditNetPortState;
extern uint8_t g_u8EditTestMode;
extern uint8_t g_u8CurTestMode;
extern uint8_t g_u8CurVolume;
extern uint8_t g_u8LinkOprtState[8];
extern uint8_t g_u8LinkBuildState[8];
extern uint8_t g_u8CurAttn[2];
extern uint8_t g_u8EditAttn[2];
extern uint8_t g_u8LinkInfo[60];
extern uint8_t g_u8CurRefVol[2];
extern uint8_t g_u8EditRefVol[2];
extern uint8_t g_u8FilterMode;
extern uint8_t  au8Code[2];


// 其他外部变量定义
extern uint8_t g_u8Temp;
extern uint8_t g_u8FlagStartUp;
extern uint8_t g_u8RadioState;	// 电台状态，开机超时为NO，正常开机为YES

extern uint8_t g_u8RTxTimeFlag;
extern uint8_t g_u8MaskZeroFlag;
extern uint8_t g_u8NoSendFlag;
extern uint8_t g_u8SecureFlag;

extern uint16_t g_u16Timer2Count;
extern uint16_t g_u16SecondCount;
extern uint16_t g_u16RTxTimeTick;
extern uint8_t  g_u8RunTimeUpdate;
extern uint8_t  g_u8RunTimeCount;
extern uint8_t  g_u8PowerOnOffTick;

extern uint8_t g_u8EnterFactory;
extern uint8_t g_u8PowerOn;
#if 0
extern uint8_t g_u8EditTestType;
extern uint8_t g_u8CurTestType;
#endif
extern uint8_t g_u8SelectItemOK;
extern uint8_t g_u8FnKeyOK;
extern uint8_t g_u8ParamStepOK;

extern uint8_t g_u8MaintainOnOff;

extern uint8_t 	g_u8NumBuf1[3]; 
extern uint8_t	g_u8NumBuf2[3];
extern uint8_t	g_u8NumBuf3[3];
extern uint8_t	g_u8NumBuf4[3]; 
extern uint8_t  SelectStation;


// test 
extern uint8_t ReportMac_Bef;  //上一次的Mac
extern uint8_t ReportMac_Now;
// test


extern uint8_t  SetMac; // test

extern uint8_t  SelectPage;
extern uint8_t  SelectState01;
extern uint8_t  SelectState02;
extern uint8_t  SelectState03;
extern uint8_t  SelectState04;
extern uint8_t  SelectState05;
extern uint8_t  SelectState06;
extern uint8_t  SelectState07;
extern uint8_t  SelectState08;




// 参数备份存储变量
extern uint8_t g_u8TempNetMode;
extern uint8_t g_u8TempPower;
extern uint8_t g_au8TempFreq[3];

// 串口缓存外部变量
extern uint8_t g_u8SerialDataRx[200];  // 环形存储器，串口收数据
extern uint8_t g_u8LengthRx;
extern uint8_t g_u8HeadRx;
extern uint8_t g_u8TailRx;

extern uint8_t g_u8SerialDataTx[200];  // 环形存储器，串口发数据
extern uint8_t g_u8LengthTx;

extern uint8_t g_u8RadioCommRx_Len;
extern uint8_t g_u8RadioCommTx_Len;


//延时函数
extern void Delay_nUS(uint16_t count);
extern void Delay_nMS(uint16_t count);
extern void Delay_nS(uint16_t count);


//其他
extern uint8_t ConvertBCDtoDecimal(uint8_t Data_BCD);
extern uint8_t ConvertDecimaltoBCD(uint8_t Data_BCD);
extern uint8_t isSecureOK(void);
#endif
