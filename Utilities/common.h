#ifndef __COMMON_H
#define __COMMON_H

#include <stdint.h>

#define __LATERAL__		ON/*OFF*/	/*���÷�֧����ʱ(������ʾ�淶����)����ΪON�����ñ�׼��ʾ�淶ʱ����ΪOFF*/
#define __UNIT_TEST__	ON/*OFF*/	/*��Ԫ�����ʱ��ΪON,������������ΪOFF*/

#define   	 YES 	     1
#define   	 NO 	     0  

#define   	 ON 	     1
#define   	 OFF	     0  

#define   	 MainStation 1
#define   	 SubStation	 0  

#define      LinkBuild   1  // ����
#define      LinkRemove  0  // ����

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


// --------------------------------�����༭�����궨��--------------------------------------
//------------ F1-���ò���ҳ----------------
/*��̨IP*/
#define      INDEX_EDIT_RADIOIP	   1 
#define      INDEX_EDIT_RADIOMAC   1
/*    */




//------------ F2-��·����ҳ----------------
/*��·ά��*/
#define     INDEX_EDIT_MAC01   1 
#define     INDEX_EDIT_MAC02   2
#define     INDEX_EDIT_MAC03   3 
#define     INDEX_EDIT_MAC04   4
#define     INDEX_EDIT_MAC05   5     
#define     INDEX_EDIT_MAC06   6
#define     INDEX_EDIT_MAC07   7    
#define     INDEX_EDIT_MAC08   8

/*��·���*/
#define     INDEX_EDIT_GAP0    0
#define     INDEX_EDIT_GAP1    1
#define     INDEX_EDIT_GAP2    2
#define     INDEX_EDIT_GAP3    3
/*��·��ѯ*/





//------------ F3-��ز���ҳ----------------
/*����״̬*/
#define      INDEX_EDIT_FREQ_TAB	     1   //Ƶ��
#define      INDEX_EDIT_WORKMODE	     2	 //ģʽ
#define      INDEX_EDIT_RANK    	     3   //�ȼ�
#define      INDEX_EDIT_POWER    	     4 	 //����
#define      INDEX_EDIT_MAC              5   //վ��
#define      INDEX_EDIT_CHANNUM          6   //�ŵ���





//------------ F4-ϵͳ����ҳ----------------
/*���⿪��*/

/*����ʱ��*/
#define      INDEX_EDIT_DATE		 1   
#define      INDEX_EDIT_TIME         2 

#define      INDEX_EDIT_RATE    	 5



// --------------------------------��ֵ�궨��--------------------------------------
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

// --------------------------------���е�ַ�궨��--------------------------------------
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

// --------------------------------��̨ģʽ�궨��--------------------------------------
/*�����ȼ�*/
#define      VOLUME_SILENCE    		 0
#define      VOLUME_LEVEL1    		 1
#define      VOLUME_LEVEL2    		 2
#define      VOLUME_LEVEL3    		 3

/*����ģʽ*/
#define      WORKMODE_FIX    		 3
#define      WORKMODE_HOP    		 4
#define      WORKMODE_SFIX    		 5
#define      WORKMODE_SHOP    		 6

/*����ģʽ*/
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

//---------------------------- ����ID�궨��-------------------------------

#define      MENU_POWER_ON   		 0x00
#define      MENU_POWER_OFF		     0x01
#define      MENU_1ST_BITE			 0x02


//������
//#define      MENU_MAIN_PAGE          0x10

// F1-F4�����ӽ���
#define      MENU_SET_F1             0x30
#define      MENU_SET_F2             0x31
#define      MENU_SET_F3             0x32
#define      MENU_SET_F4             0x33

// F1-���ý���
#define      MENU_PARAMRADIOIP         0x40
#define      MENU_PARAMRADIOMASK	   0x41
#define      MENU_PARAMFACTORYSET      0x42
//#define      MENU_PARAMENTFACTORYSET   0x4A

// F2-��·����
#define      MENU_PARAMLINKBUILD       0x50
#define      MENU_PARAMLINKMAINTAIN    0x51
#define      MENU_PARAMLINKQUERY       0x52


// F3-��ؽ���
#define      MENU_PARAMWORKSTATE       0x60
#define      MENU_PARAMDIGTRANSTATIS   0x61
#define      MENU_PARAMDIGTRANREPORT   0x62
#define      MENU_PARAMDEBUGINFO       0x63
#define      MENU_PARAMRUNTIME         0x64

// F4-ϵͳ����
#define      MENU_PARAMDATETIME        0x67
#define      MENU_PARAMRADIOTEST       0x68
#define      MENU_PARAMPOWERCHECK      0x69
#define      MENU_PARAMUNLIGHTONOFF    0x6A
#define      MENU_PARAMVERSIONINFO     0x6B
//#define      MENU_PARAMENTPOWERCHECK   0x6C


// ������ʽ
#define  IsCurNetMode_TestMode(ModeId) (ModeId > NETMODE_QLINK)
#define  IsFuncKey(KeyValue)           ((KeyValue >= KEY_F1) && (KeyValue <= KEY_F5))
#define  IsNumberKey(KeyValue)         (KeyValue <= KEY_9)
#define  IsMonth31Days(Month)          ((Month == 1) || (Month == 3) || (Month == 5) || (Month == 7)  \
                                       || (Month == 8) || (Month == 10) || (Month == 12))
#define  IsMonth30Days(Month)          ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11))
#define  IsThirdNumOfAttn(Number)      ((Number == 0) || (Number == 2) || (Number == 5) || (Number == 7))

//--------------------- ͨ�ú����ṹ�嶨��--------------------------
typedef struct
{
    uint8_t Mode_ID;
    uint8_t *Mode;
}Mode_TypeDef; 

typedef struct
{
	uint8_t MacNum;           // ��·Mac
	uint8_t NetState;         // ����״̬
	uint8_t Intensity;        // ��ǿ
	uint8_t MaintainGap_ID;   // 
	//uint8_t *MaintainGap;     // ά�������ʾ�ı�
	uint8_t Quality_Up;       // ��������
	uint8_t Quality_Down;     // ��������
}LinkInfo_TypeDef;
extern LinkInfo_TypeDef t_EditLinkInfo[8],t_CurLinkInfo[8];

// test
typedef struct
{
	uint8_t  MacNum;
	uint8_t  SendFram[4];    // ����֡
	uint8_t  ReceiveFram[4]; // ����֡
	uint8_t  ConfuFram[4];  // ����֡
	uint8_t  ErroFram[4];  // ����֡
}LinkDigInfo_TypeDef;
extern LinkDigInfo_TypeDef t_CurStatisFrame,t_EditStatisFrame;

typedef struct
{
	uint8_t  MacNum;    // վ��
	uint8_t  SNR;      // �����
}LinkQuaInfo_TypeDef;
extern LinkQuaInfo_TypeDef t_CurLinkQuanlity[4];


typedef struct
{
	uint8_t  MacNum[2];    // վ��:Ϊ�˲����ϱ��������ֽڣ�ֻȡ���ֽ�
	uint8_t  SNR[2];      // �����
}LinkReportQua_TypeDef;
extern LinkReportQua_TypeDef t_ReportLinkQuan[4];

typedef struct
{
    uint8_t Pos_ID;
    uint8_t Pos_x;
    uint8_t Pos_y;
}Position_TypeDef;
extern Position_TypeDef  Pos_IP[];

//--------------------- ��̨�����ṹ�嶨��--------------------------
typedef struct
{
	uint8_t Second;       // ��
	uint8_t Minute;       // ��
	uint8_t Hour;         // ʱ
	uint8_t WeekDay;      // ���ڼ�
	uint8_t Day;          // ��
	uint8_t Month;        // ��
	uint8_t Year;         // ��
}TOD_TypeDef;
extern TOD_TypeDef t_CurTime, t_EditTime;
extern TOD_TypeDef t_SubRunTime,t_SumRunTime,t_PoweronTime;

typedef struct
{
	uint8_t BoardNum;         // ҵ����:1-�źŴ����ۡ�1-��չ1��ۡ�2-��չ2���
	uint8_t WaveForm;         // ����:0-173 ��1-513
	uint8_t algorithm;        // �����㷨:0-���㷨 ��1-���㷨
	uint8_t AreaNum;          // ����:00H-FFH
	uint8_t GroupNum1;         // ���:00H-FFH
	uint8_t GroupNum2;         // ���:00H-FFH
	
	//uint8_t effect;       //��Ч��
	uint8_t state;        //�Լ���
}SecureParam_TypeDef;
extern SecureParam_TypeDef t_EditSecureState, t_CurSecureState;

typedef struct
{
	uint8_t ChanNum;      // վ�� ChanNum  00�ŵ�
	uint8_t WaveMode;     // ����ģʽ      01����
	uint8_t WorkMode;     // ����ģʽ      03����
	uint8_t Freq[3];      // Ƶ��Freq[0]-100M, Freq[1]-10M��1M, Freq[2]-100K��25K  (255.00MHz)
	uint8_t TableNum;     // ��Ƶ���      00 
	uint8_t NetNum[2];    // ��Ƶ����NetNum[0]-��λ��NetNum[1]-ʮλ����λ
	//uint8_t Rank;         // ��̨����: ��վ ��վ 00 
}ChannelParam_TypeDef;
extern ChannelParam_TypeDef t_EditChannelState, t_CurChannelState;

typedef struct
{
	uint8_t RemoteState;  // ң��״̬
	uint8_t Intensity;    // ��ǿ
	uint8_t Indication;   // ָʾ
	uint8_t SendRate;     // ��������
	uint8_t VoiceCode;    // �����������뷽ʽ
	uint8_t SyncState;    // ͬ��״̬
	uint8_t NetState;     // ����״̬
	uint8_t SnrRate;      // �����
	uint8_t ParamState;   // ��̨����״̬
	uint8_t NC;          // Ԥ��
	uint8_t CallMAC;      // ����MAC

	uint8_t MAC;                // MAC��ַ
	uint8_t Rank;         // ��̨����: ��վ ��վ 00 
	uint8_t Service_IP[4];      // ҵ��IP��ַ
	uint8_t Service_MASK[4];    // ҵ������
	uint8_t Service_GATEWAY[4]; // ҵ�����ص�ַ
	uint8_t Manage_IP[4];       // ����IP��ַ
	uint8_t Manage_MASK[4];     // ��������
	uint8_t Manage_GATEWAY[4];  // �������ص�ַ
	uint8_t INC_IP[4];          // ����IP��ַ
	uint8_t INC_MASK[4];        // ��������
	uint8_t INC_GATEWAY[4];     // �������ص�ַ
	uint8_t Secure_IP[4];       // �ַܷ�����IP��ַ
	uint8_t Secure_MASK[4];     // �ַܷ���������
	uint8_t Secure_GATEWAY[4];  // �ַܷ���������
	uint8_t ID[5];              // �豸ID
	uint8_t UpperNet;           // �ϼ�����
	uint8_t MaxMac;             // �滮�ڵ�

    uint8_t Power;        //����
    uint8_t SoftVersion[4];  //����汾
    uint8_t Volume;       //�����ȼ�
}RadiolParam_TypeDef;
extern RadiolParam_TypeDef t_EditRadioState, t_CurRadioState;

typedef enum 
{
	TEST_SINE_WAVE = 0,
	TEST_NAR_CARRIER,
	TEST_WIDE_CARRIER,
	TEST_CLOSED,
	TEST_9VS3		/*CS,20131128,����9:3����ģʽ����������Ʋ���*/
}TEST_MODE_TYPE;


//  �������ⲿ��������
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

//  �˵����ⲿ��������
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

//  �������ⲿ��������
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


// �����ⲿ��������
extern uint8_t g_u8Temp;
extern uint8_t g_u8FlagStartUp;
extern uint8_t g_u8RadioState;	// ��̨״̬��������ʱΪNO����������ΪYES

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
extern uint8_t ReportMac_Bef;  //��һ�ε�Mac
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




// �������ݴ洢����
extern uint8_t g_u8TempNetMode;
extern uint8_t g_u8TempPower;
extern uint8_t g_au8TempFreq[3];

// ���ڻ����ⲿ����
extern uint8_t g_u8SerialDataRx[200];  // ���δ洢��������������
extern uint8_t g_u8LengthRx;
extern uint8_t g_u8HeadRx;
extern uint8_t g_u8TailRx;

extern uint8_t g_u8SerialDataTx[200];  // ���δ洢�������ڷ�����
extern uint8_t g_u8LengthTx;

extern uint8_t g_u8RadioCommRx_Len;
extern uint8_t g_u8RadioCommTx_Len;


//��ʱ����
extern void Delay_nUS(uint16_t count);
extern void Delay_nMS(uint16_t count);
extern void Delay_nS(uint16_t count);


//����
extern uint8_t ConvertBCDtoDecimal(uint8_t Data_BCD);
extern uint8_t ConvertDecimaltoBCD(uint8_t Data_BCD);
extern uint8_t isSecureOK(void);
#endif
