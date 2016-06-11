#include "all.h"


//-----------------------------������ر�������----------------------------
 uint8_t g_u8RadioCommRx_Buf[200];   // ��̨��ָ��
 uint8_t g_u8RadioCommTx_Buf[200];   // ��̨��ָ��

/*********************************************************
*��������Set_DateOfTime
*����  ������������������ʱ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_DateOfTime(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x81;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x07;

    g_u8RadioCommTx_Buf[4] = 0x20;
    g_u8RadioCommTx_Buf[5] = t_CurTime.Year;
    g_u8RadioCommTx_Buf[6] = t_CurTime.Month;
    g_u8RadioCommTx_Buf[7] = t_CurTime.Day;
    g_u8RadioCommTx_Buf[8] = t_CurTime.Hour;
    g_u8RadioCommTx_Buf[9] = t_CurTime.Minute;
    g_u8RadioCommTx_Buf[10] = t_CurTime.Second;
    
    g_u8RadioCommTx_Len = 11;

    Send_SerialData();
}

/*********************************************************
*��������Set_ChanNum
*����  �����������ŵ���ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_ChanNum(void)
{
    g_u8RadioCommTx_Buf[0] = 0x01;
    g_u8RadioCommTx_Buf[1] = 0x00;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;
	
    g_u8RadioCommTx_Buf[4] = t_EditChannelState.ChanNum;
	
	g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Set_ClrRFDigtal
*����  ����������շ�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_ClrRFDigtal(void)
{
    g_u8RadioCommTx_Buf[0] = 0x09;
    g_u8RadioCommTx_Buf[1] = 0x01;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = t_EditRadioState.MAC;
    
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Set_RadioMac
*����  ���������õ�̨MACָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_RadioMac(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x03;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = t_EditRadioState.MAC;
    
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Set_ServiceIp
*����  ���������õ�̨IPָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_ServiceIp(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x04;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x04;

    memcpy(&g_u8RadioCommTx_Buf[4], &t_EditRadioState.Service_IP[0], 4);
    g_u8RadioCommTx_Len = 8;

    Send_SerialData();
}

/*********************************************************
*��������Set_ServiceMask
*����  ���������õ�̨����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_ServiceMask(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x05;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x04;

    memcpy(&g_u8RadioCommTx_Buf[4], &t_EditRadioState.Service_MASK[0], 4);
    g_u8RadioCommTx_Len = 8;

    Send_SerialData();
}

/*********************************************************
*��������SetRadioPower
*����  ���������õ�̨����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_RadioPower(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x06;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = t_EditRadioState.Power;
    
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Set_RadioRank
*����  ���������õ�̨�ȼ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_RadioRank(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x07;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = t_EditRadioState.Rank;
    
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������SetRadioId
*����  ���������õ�̨IDָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_RadioId(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x0D;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x05;

    g_u8RadioCommTx_Buf[4] = t_EditRadioState.ID[0];
    g_u8RadioCommTx_Buf[5] = t_EditRadioState.ID[1];
    g_u8RadioCommTx_Buf[6] = t_EditRadioState.ID[2];
    g_u8RadioCommTx_Buf[7] = t_EditRadioState.ID[3];
    g_u8RadioCommTx_Buf[8] = t_EditRadioState.ID[4];

    g_u8RadioCommTx_Len = 9;

    Send_SerialData();
}

/*********************************************************
*��������Set_UpperNet
*����  �����������ϼ�����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_UpperNet(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x0F;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = t_EditRadioState.UpperNet;

    g_u8RadioCommTx_Len = 5;
    Send_SerialData();
}

/*********************************************************
*��������SetChanParam
*����  �����������ŵ�����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_ChanParam(void)
{
    g_u8RadioCommTx_Buf[0] = 0x01;
    g_u8RadioCommTx_Buf[1] = 0x01;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x09;

    memcpy(&g_u8RadioCommTx_Buf[4], &t_EditChannelState, sizeof(t_EditChannelState));
	if((g_u8RadioCommTx_Buf[9]&0x0F) == 5)	// Ƶ��С����λ2��ʾ5
	{
		g_u8RadioCommTx_Buf[9] &= 0xF0; 
		g_u8RadioCommTx_Buf[9] += 2;
	}
    g_u8RadioCommTx_Len = 13;

    Send_SerialData();
}

/*********************************************************
*��������SetRadioTest
*����  �����͵�̨�Լ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_RadioTest(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x00;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}


/*********************************************************
*��������Set_LinkTest
*����  ��������·����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_LinkTest(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x04;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = g_u8LinkTestMac;
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Set_LinkOprt
*����  �����ͽ�������ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_LinkOprt(void)
{
	uint8_t i = 0,u8Count;
    g_u8RadioCommTx_Buf[0] = 0x02;
    g_u8RadioCommTx_Buf[1] = 0x48;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;
	if(g_u8PreLinkOprtState == LinkBuild) 
	{
		g_u8RadioCommTx_Buf[4] = 0x01;   //����
	}
	else
	{	
		g_u8RadioCommTx_Buf[4] = 0x00;   //����
	}
	for(i=0;i<g_u8LinkBuildCount;i++)
	{
		u8Count = g_u8LinkBuildState[i];
		g_u8RadioCommTx_Buf[5+i] = t_CurLinkInfo[u8Count].MacNum;
	}
    g_u8RadioCommTx_Len = 5 + g_u8LinkBuildCount;
	
    Send_SerialData();
}

/*********************************************************
*��������Set_LinkMaintainGap
*����  ������������·ά�����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_LinkMaintainGap(void)
{
	//uint8_t uCount;
    g_u8RadioCommTx_Buf[0] = 0x02;
    g_u8RadioCommTx_Buf[1] = 0x09;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x02;

	g_u8RadioCommTx_Buf[4] = t_EditLinkInfo[g_u8CurMenuItem-1].MacNum;
	g_u8RadioCommTx_Buf[5] = t_EditLinkInfo[g_u8CurMenuItem-1].MaintainGap_ID;
    g_u8RadioCommTx_Len = 6;
	
    Send_SerialData();
}

/*********************************************************
*��������Set_DestroyParam
*����  �����ͻ�Կ����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_DestroyParam(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x06;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;
    
    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������SetDefaultParam
*����  �����ͻָ���������ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_DefaultParam(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x07;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;
    
    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������SetPowerScan
*����  �����͹���ɨ������ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_PowerScan(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x2D;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x08;

// ��225.00MHzɨ��512.00MHz
    g_u8RadioCommTx_Buf[4] = 0;
    g_u8RadioCommTx_Buf[5] = 0x03;
    g_u8RadioCommTx_Buf[6] = 0x6E;
    g_u8RadioCommTx_Buf[7] = 0xE8;

    g_u8RadioCommTx_Buf[8]  = 0;
    g_u8RadioCommTx_Buf[9]  = 0x07;
    g_u8RadioCommTx_Buf[10] = 0xD0;
    g_u8RadioCommTx_Buf[11] = 0;

    g_u8RadioCommTx_Len = 12;

    Send_SerialData();
}

/*********************************************************
*��������SetPowerScanStop
*����  �����͹���ɨ��ֹͣ����ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_PowerScanStop(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x2E;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Set_PowerOff
*����  �����͹ػ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_PowerOff(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x08;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Set_PowerAttn
*����  ���������ù���˥��ֵָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_PowerAttn(void)
{
    uint16_t u16Data = 0;

    // ATT_value = ab.cd * 4��������ֵ�洢Ϊʮ��������abcd����ATT_value = abcd * 4 / 100 = abcd / 25
    // g_u8EditAttn[] = {0xab, 0xcd}
    u16Data = ConvertBCDtoDecimal(g_u8EditAttn[0])*100 + ConvertBCDtoDecimal(g_u8EditAttn[1]);
    u16Data = u16Data/25;
    
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x2B;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x02;

    g_u8RadioCommTx_Buf[4] = 0x00;
    g_u8RadioCommTx_Buf[5] = (uint8_t)u16Data;
    g_u8RadioCommTx_Len = 6;

    Send_SerialData();
}

/*********************************************************
*��������Set_RefVol
*����  ���������òο���ѹֵָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_RefVol(void)
{
    uint32_t u32Data = 0;

    // Ref_Vol = a.bcd / 3.3 * 1024��������ֵ�洢Ϊʮ��������abcd����ATT_value = abcd / 3300 * 1024 = 0xefgh
    // g_u8EditRefVol[] = {0xab, 0xcd}
    u32Data = ConvertBCDtoDecimal(g_u8EditRefVol[0])*100 + ConvertBCDtoDecimal(g_u8EditRefVol[1]);
    u32Data = u32Data*1024/3300;

    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0xFF;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x02;

    g_u8RadioCommTx_Buf[4] = (uint8_t)(u32Data >> 8);
    g_u8RadioCommTx_Buf[5] = (uint8_t)(u32Data & 0xFF);

    g_u8RadioCommTx_Len = 6;

    Send_SerialData();
}

/*********************************************************
*��������Set_PowerOff
*����  �����͹ػ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_WaveMode(void)
{
    g_u8RadioCommTx_Buf[0] = 0x66;
    g_u8RadioCommTx_Buf[1] = 0x00;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Buf[4] = 0x01;
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Set_FilterMode
*����  ���������ù�ֱַͨģʽָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_FilterMode(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0xFC;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x02;

    g_u8RadioCommTx_Buf[4] = 0x00;
    g_u8RadioCommTx_Buf[5] = g_u8FilterMode;
    g_u8RadioCommTx_Len = 6;

    Send_SerialData();
}

/*********************************************************
*��������Report_ACK
*����  ������ȷ��Ӧ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_ACK(void)
{
	uint8_t i = 0;
// �������óɹ����Ƚ���ǰ��������Ϊ�༭������������ʾ��ǰ����
    switch(g_u8CurMenuID)
    {
		case MENU_PARAMRADIOIP:
			if(g_u8NumIndex == 12)
			{
	            g_u8NumIndex = 0;
				memcpy(&t_CurRadioState.Service_IP[0], &t_EditRadioState.Service_IP[0], 4);
				DispIpAddr(COL_WORD8, ROW_TEXT04,0);
	            PrintString(COL_WORD8, ROW_TEXT05, "               ", 15);
			}
            break;

		case MENU_PARAMRADIOMASK:
			if(g_u8NumIndex == 12)
			{
				g_u8NumIndex = 0;
				g_u8MaskZeroFlag = NO;
				memcpy(&t_CurRadioState.Service_MASK[0], &t_EditRadioState.Service_MASK[0], 4);
				DispMaskAddr(COL_WORD8, ROW_TEXT04, SERVICE, 0);
				PrintString(COL_WORD8, ROW_TEXT05, "               ", 15);
			}
			break;
			
		case MENU_PARAMFACTORYSET://test ���Ż�
			PrintString(WIDTH_HALF, ROW_TEXT04,  "                               ", WORD);
  			PrintString(WIDTH_HALF, ROW_TEXT05,  "                               ", WORD);
			PrintString(WIDTH_HALF, ROW_TEXT06,  "                               ", WORD);
  			PrintString(WIDTH_HALF, ROW_TEXT07,  "                               ", WORD);
			PrintString(WIDTH_HALF, ROW_TEXT08,  "                               ", WORD);
			PrintString(COL_WORD7, ROW_TEXT05,  "�����ָ��ɹ�!             ", WORD);
			ClrGpioBit(LED_ALARM1_PIN);   
			ClrGpioBit(LED_ALARM2_PIN);
            break;

		case MENU_PARAMLINKBUILD:
			g_u8LinkBuildCount = 0;
			for(i=0;i<8;i++)
			{			
				t_CurLinkInfo[i].NetState = t_EditLinkInfo[i].NetState;
			}
			DispMac();
			break;

		case MENU_PARAMLINKMAINTAIN:
			g_u8ParamEditIndex = 0;
			break;

		case MENU_PARAMWORKSTATE:
			g_u8CmdSending = NO;
            t_CurRadioState.Power = t_EditRadioState.Power;
			t_CurRadioState.Rank  = t_EditRadioState.Rank;
			t_CurRadioState.MAC   = t_EditRadioState.MAC;
            memcpy(&t_CurChannelState, &t_EditChannelState, sizeof(t_CurChannelState));
			
			// test
			if(t_CurRadioState.MAC == 00)
			{
				SelectStation = MainStation;
				//DispMenuText_ParamWorkState();// test
			}
			else
			{
				SelectStation = SubStation;
				//DispMenuText_ParamWorkState();// test
			}
	
			// test
			// test
			
			//DispMenuText_ParamWorkState();
			// test
			if(SetMac == YES) // test
			{	
				SetMac = NO;
				DispMenuText_ParamWorkState();
			}
			DispWorkStateReverse(0);
			DispParamWorkState();  // test
			
			//DispRadioPower(0);
			//DispMacAddr1(0);
            g_u8ParamStepOK    = NO;
            g_u8ParamEditIndex = 0;
            g_u8NumIndex       = 0;

			// test
			//DispMenuText_ParamWorkState();
			// test
            break;

		case MENU_PARAMDIGTRANSTATIS:
			PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08,"  ",2);
			PrintString(COL_WORD1,ROW_TEXT04,"    ",4);    //���Mac
			PrintString(COL_WORD4,ROW_TEXT04,"       ",7); //���RF
			PrintString(COL_WORD8,ROW_TEXT04,"       ",7); //���SF
			PrintString(COL_WORD7, ROW_TEXT08, "��ճɹ�!", WORD);
			g_u8ParamEditIndex = 0;
			break;

		case MENU_PARAMDIGTRANREPORT:
			PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08,"  ",2);
			PrintString(COL_WORD1,ROW_TEXT04,"    ",4);    //���Mac
			PrintString(COL_WORD4,ROW_TEXT04,"       ",7); //���RF
			PrintString(COL_WORD8,ROW_TEXT04,"       ",7); //���SF
			PrintString(COL_WORD7, ROW_TEXT08, "��ճɹ�!", WORD);
			g_u8ParamEditIndex = 0;
			break;
			 
        default:
            break;
    }
}

/*********************************************************
*��������Report_NACK
*����  ���������Ӧ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_NACK(void)
{
	uint8_t i = 0;
	// ��������ʧ�ܣ���ǰ����������ֱ����ʾ
	switch(g_u8CurMenuID)
	{
		case MENU_PARAMRADIOIP:
			g_u8NumIndex = 0;
			memcpy(&t_EditRadioState.Service_IP[0], &t_CurRadioState.Service_IP[0], 4);
			PrintString(COL_WORD8, ROW_TEXT05, "               ", 15);
			break;

		case MENU_PARAMRADIOMASK:
			g_u8NumIndex = 0;
			memcpy(&t_EditRadioState.Service_MASK[0], &t_CurRadioState.Service_MASK[0], 4);
			PrintString(COL_WORD8, ROW_TEXT05, "               ", 15);
			break;
			
		case MENU_PARAMFACTORYSET:
  			PrintString(COL_WORD5, ROW_TEXT05,  "                      ", WORD);
			PrintString(COL_WORD7, ROW_TEXT05,  "�����ָ�ʧ��!             ", WORD);
	        break;

		case MENU_PARAMLINKBUILD:
			for(i=0;i<8;i++)
			{			
				t_EditLinkInfo[i].NetState = t_CurLinkInfo[i].NetState;
			}
			DispMac();
			break;

		case MENU_PARAMLINKMAINTAIN:
			break;

		case MENU_PARAMWORKSTATE:
			g_u8CmdSending = 0;
			SetMac = NO; // test
	        t_EditRadioState.Power = t_CurRadioState.Power;
			t_EditRadioState.Rank  = t_CurRadioState.Rank;
			t_EditRadioState.MAC   = t_CurRadioState.MAC;
	        memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState));
	        DispWorkStateReverse(0);  // ����ʧ�ܵĻ�Power �� Mac ��ʾ��ֵ
	        g_u8ParamStepOK    = NO;
		    g_u8ParamEditIndex = 0;
	        g_u8NumIndex       = 0;
	        break;

		case MENU_PARAMDIGTRANSTATIS:
			PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08, "               ", WORD);	
			PrintString(COL_WORD7, ROW_TEXT08, "���ʧ��!", WORD);
			PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08, "  ", 2);	
			g_u8ParamEditIndex = 0;
			break;

		case MENU_PARAMDIGTRANREPORT:
			PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08, "               ", WORD);	
			PrintString(COL_WORD7, ROW_TEXT08, "���ʧ��!", WORD);
			PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08, "  ", 2);	
			g_u8ParamEditIndex = 0;
			break;
			
		case MENU_PARAMPOWERCHECK:
			if(g_u8ParamEditState == YES)
			{	
				PrintString(COL_WORD9, ROW_TEXT04, "���ʧ��!", WORD);
			}
	        break;

		default:
			break;
	}
}

/*********************************************************
*��������Query_SoftVersion
*����  ����������汾��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_SoftVersion(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x40;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_LinkTest
*����  �����͹��ʼ���ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_LinkTest(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x62;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_DigTranStatis
*����  ����������ͳ�Ʋ�ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_DigTranStatis(void)
{
    g_u8RadioCommTx_Buf[0] = 0x04;
    g_u8RadioCommTx_Buf[1] = 0xa6;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_DigTranReport
*����  �����������㱨��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_DigTranReport(void)
{
    g_u8RadioCommTx_Buf[0] = 0x04;
    g_u8RadioCommTx_Buf[1] = 0xa7;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_DebugInfo
*����  �����͵�����Ϣ��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_DebugInfo(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x08;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_LinkMaintainGap
*����  ��������·ά�������ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_LinkMaintainGap(void)
{
    g_u8RadioCommTx_Buf[0] = 0x02;
    g_u8RadioCommTx_Buf[1] = 0x38;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_RadioMac
*����  ������MAC��ַ��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_RadioMac(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x43;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_RadioRank
*����  �����͵�̨�ȼ���ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_RadioRank(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x47;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_LinkQuality
*����  ��������·������ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_LinkQuality(void)
{
    g_u8RadioCommTx_Buf[0] = 0x02;
    g_u8RadioCommTx_Buf[1] = 0x39;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_ServiceIp
*����  �����͵�̨IP��ַ��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_ServiceIp(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x44;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_ServiceMask
*����  �����͵�̨�����ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_ServiceMask(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x45;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_RadioPower
*����  �����͹��ʲ�ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_RadioPower(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x46;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_RadioId
*����  �������豸ID��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_RadioId(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x4D;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_MaxMac
*����  �����͹滮�ڵ��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_MaxMac(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x50;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_UpperNet
*����  �������ϼ����Ų�ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_UpperNet(void)
{
    g_u8RadioCommTx_Buf[0] = 0x00;
    g_u8RadioCommTx_Buf[1] = 0x4F;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_ChanNum
*����  �������ŵ��Ų�ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_ChanNum(void)
{
    g_u8RadioCommTx_Buf[0] = 0x01;
    g_u8RadioCommTx_Buf[1] = 0x40;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}
/*********************************************************
*��������Query_ChanParam
*����  �������ŵ�������ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_ChanParam(void)
{
    g_u8RadioCommTx_Buf[0] = 0x01;
    g_u8RadioCommTx_Buf[1] = 0x41;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_NetPortState
*����  �������������ݴ���״̬��ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_NetPortState(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x51;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_PowerTest
*����  �����͹��ʼ���ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_PowerTest(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x62;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Query_PowerAttn
*����  ������ɨ�������ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_PowerAttn(void)
{
    g_u8RadioCommTx_Buf[0] = 0x03;
    g_u8RadioCommTx_Buf[1] = 0x61;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Report_SoftVersion
*����  ����������汾�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_SoftVersion(void)
{
	u8 ucaSpuSoftVersion[66] = {0};
	//u8 ucaSpuVersionStr[20] = {0};
	//u32 i = 0;
	uint8_t i = 0,u8_Code[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};

	memcpy(ucaSpuSoftVersion, &g_u8RadioCommRx_Buf[4], 66);
	
	if(g_u8CurMenuID == MENU_PARAMVERSIONINFO)
	{
		for(i=0;i<4;i++)
		{
			PrintString(COL_WORD6+WIDTH_HALF,   u8_Code[i],  "V1.5", WORD);
			PrintString(COL_WORD14+WIDTH_HALF,  u8_Code[i],  "V2.6", WORD);
		}
		#if 0
		snprintf((char*)ucaSpuVersionStr, 20, "vx: %02x-%02x %02x:%02x ",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD1, ROW_TEXT04, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "rn: %02x-%02x %02x:%02x ",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD1, ROW_TEXT05, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "mc: %02x-%02x %02x:%02x ",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD1, ROW_TEXT06, ucaSpuVersionStr, 20);

		i += 12;
		snprintf((char*)ucaSpuVersionStr, 20, "wa: %02x-%02x %02x:%02x ",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD1, ROW_TEXT07, ucaSpuVersionStr, 20);

		i += 12;
		snprintf((char*)ucaSpuVersionStr, 20, "64: %02x-%02x %02x:%02x ",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD1, ROW_TEXT04, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, " fg: %02x-%02x %02x:%02x",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD9, ROW_TEXT05, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, " dt: %02x-%02x %02x:%02x",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD9, ROW_TEXT06, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "inf: %02x-%02x %02x:%02x",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD9, ROW_TEXT07, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "app: %02x-%02x %02x:%02x",
				/*ucaSpuSoftVersion[i],*/ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]/*,ucaSpuSoftVersion[i+5]*/);
		PrintString(COL_WORD9, ROW_TEXT08, ucaSpuVersionStr, 20);	
		#endif
	}
}

#if 0
/*********************************************************
*��������Report_SpuSoftVersion
*����  �������źŰ�����汾�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_SpuSoftVersion(void)
{
	u8 ucaSpuSoftVersion[66] = {0};
	u8 ucaSpuVersionStr[20] = {0};
	u32 i = 0;

	memcpy(ucaSpuSoftVersion, &g_u8RadioCommRx_Buf[4], 66);
	
	if(g_u8CurMenuID == MENU_PARAMVERSIONINFO)
	{
		//snprintf: ���ɱ���ַ������ƶ��ĸ�ʽд�뵽�ַ���
		//%02x ����Ϊ2 ʮ��������ʽ
		snprintf((char*)ucaSpuVersionStr, 20, "vx: %02x-%02x %02x:%02x ",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD1, ROW_TEXT01, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "rn: %02x-%02x %02x:%02x ",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD1, ROW_TEXT02, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "mc: %02x-%02x %02x:%02x ",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD1, ROW_TEXT03, ucaSpuVersionStr, 20);

		i += 12;
		snprintf((char*)ucaSpuVersionStr, 20, "wa: %02x-%02x %02x:%02x ",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD1, ROW_TEXT04, ucaSpuVersionStr, 20);

		i += 12;
		snprintf((char*)ucaSpuVersionStr, 20, "64: %02x-%02x %02x:%02x ",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD1, ROW_TEXT05, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, " fg: %02x-%02x %02x:%02x",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD9, ROW_TEXT01, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, " dt: %02x-%02x %02x:%02x",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD9, ROW_TEXT02, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "inf: %02x-%02x %02x:%02x",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD9, ROW_TEXT03, ucaSpuVersionStr, 20);

		i += 6;
		snprintf((char*)ucaSpuVersionStr, 20, "app: %02x-%02x %02x:%02x",
				ucaSpuSoftVersion[i+1],ucaSpuSoftVersion[i+2],
				ucaSpuSoftVersion[i+3],ucaSpuSoftVersion[i+4]);
		PrintString(COL_WORD9, ROW_TEXT04, ucaSpuVersionStr, 20);		
	}
}
#endif

/*********************************************************
*��������Report_QueryTime
*����  ������������ѯ�Կ�ʱ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_QueryTime(void)
{
	uint16_t u32TimeOut = 2000;

    g_u8GetTimeEnd = NO;  
    while((u32TimeOut > 0) && (g_u8GetTimeEnd == NO))
    {
    	u32TimeOut--;
        RTC_ReadTime();
        Delay_nMS(30);
    }
    Set_DateOfTime();
}

/*********************************************************
*��������Report_RadioIp
*����  �������̨IP�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioIp(void)
{
	uint8_t x = 0;
	memcpy(&t_CurRadioState.Service_IP[0],  &g_u8RadioCommRx_Buf[4], 4);
	memcpy(&t_EditRadioState.Service_IP[0], &g_u8RadioCommRx_Buf[4], 4);

	if(g_u8CurMenuID == MENU_PARAMRADIOIP)
	{
    	x = COL_WORD8;
        DispIpAddr(x, ROW_TEXT04, 0);
    }
}

/*********************************************************
*��������Report_RadioMask
*����  �������̨�����ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioMask(void)
{
	uint8_t x = 0;
	#if 0
	uint8_t x = 0,i = 0,j = 0,k = 0,u8Mask = 0;
	u8Mask = g_u8RadioCommRx_Buf[4];
    i = ((u8Mask >> 4) & 0x0F)*16 + (u8Mask & 0x0F); // 1�ĸ���
    j = i/8; // j���ֽ� 0xFF
    k = i%8; // ʣ��1�ĸ���
    if(j == 0)
    {
		DispMask_CountOne(j,k);
		t_CurRadioState.Service_MASK[1] = 0x00;
		t_CurRadioState.Service_MASK[2] = 0x00;
		t_CurRadioState.Service_MASK[3] = 0x00;
	}
	else if(j == 1)
	{	
		DispMask_CountOne(j,k);
		t_CurRadioState.Service_MASK[0] = 0xFF;
		t_CurRadioState.Service_MASK[2] = 0x00;
		t_CurRadioState.Service_MASK[3] = 0x00;
	}
	else if(j == 2)
	{
		DispMask_CountOne(j,k);
		t_CurRadioState.Service_MASK[0] = 0xFF;
		t_CurRadioState.Service_MASK[1] = 0xFF;
		t_CurRadioState.Service_MASK[3] = 0x00;
	}
	else if(j == 3)
	{
		DispMask_CountOne(j,k);
		t_CurRadioState.Service_MASK[0] = 0xFF;
		t_CurRadioState.Service_MASK[1] = 0xFF;
		t_CurRadioState.Service_MASK[2] = 0xFF;
	}
	else if(j == 4)
	{
		DispMask_CountOne(j,k);
		t_CurRadioState.Service_MASK[0] = 0xFF;
		t_CurRadioState.Service_MASK[1] = 0xFF;
		t_CurRadioState.Service_MASK[2] = 0xFF;
		t_CurRadioState.Service_MASK[3] = 0xFF;
	}
	#endif 
	t_CurRadioState.Service_MASK[0] = 0xFF;
	t_CurRadioState.Service_MASK[1] = 0xFF;
	t_CurRadioState.Service_MASK[2] = g_u8RadioCommRx_Buf[4];
	t_CurRadioState.Service_MASK[3] = 0x00;

	#if 0
	memcpy(&t_CurRadioState.Service_MASK[0],  &g_u8RadioCommRx_Buf[4], 4);
	//memcpy(&t_EditRadioState.Service_MASK[0], &g_u8RadioCommRx_Buf[4], 4);
	#endif
	
	if(g_u8CurMenuID == MENU_PARAMRADIOMASK)
	{
    	x = COL_WORD8;
        DispMaskAddr(x, ROW_TEXT04, SERVICE, 0);
    }
}

/*********************************************************
*��������Report_ManageIp
*����  ���������ܿ�IP�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_ManageIp(void)
{
	memcpy(&t_CurRadioState.Manage_IP[0],  &g_u8RadioCommRx_Buf[4], 12);
	memcpy(&t_EditRadioState.Manage_IP[0], &g_u8RadioCommRx_Buf[4], 12);

}

/*********************************************************
*��������Report_IncIp
*����  ������INC����IP�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_IncIp(void)
{
	memcpy(&t_CurRadioState.INC_IP[0],  &g_u8RadioCommRx_Buf[4], 12);
	memcpy(&t_EditRadioState.INC_IP[0], &g_u8RadioCommRx_Buf[4], 12);
}

/*********************************************************
*��������Report_SecureIp
*����  �������ַܷ�����IP�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_SecureIp(void)
{
	memcpy(&t_CurRadioState.Secure_IP[0],  &g_u8RadioCommRx_Buf[4], 12);
	memcpy(&t_EditRadioState.Secure_IP[0], &g_u8RadioCommRx_Buf[4], 12);

}

/*********************************************************
*��������Report_RadioPower
*����  �������̨�����ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioPower(void)
{
    t_CurRadioState.Power  = g_u8RadioCommRx_Buf[4];
    t_EditRadioState.Power = g_u8RadioCommRx_Buf[4];
	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		DispRadioPower(0);
	} 
}

/*********************************************************
*��������Report_RadioRank
*����  �������̨�ȼ��ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioRank(void)
{
	// Test,then all is useless 20151223
	#if 0
    t_CurRadioState.Rank  = g_u8RadioCommRx_Buf[4];
    t_EditRadioState.Rank = g_u8RadioCommRx_Buf[4];
	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		DispRadioRank(0);// ?????????
	} 
	#endif
}

/*********************************************************
*��������Report_RadioMac
*����  �������̨վ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioMac(void)
{
	g_u8DispBuf[0] = g_u8RadioCommRx_Buf[4] ;

	
	//test
//	 g_u8NumBuf[0] = ((g_u8RadioCommRx_Buf[4] >> 4) & 0x0F) + '0';
//	 g_u8NumBuf[1] = (g_u8RadioCommRx_Buf[4] & 0x0F) + '0';
//	 g_u8DispBuf[0] = (g_u8NumBuf[0])*10 + g_u8NumBuf[1];

	 #if 0
	 ReportMac_Bef = ReportMac_Now;
	 ReportMac_Now = ConvertDecimaltoBCD(g_u8DispBuf[0]);
	 
	 
	 t_CurRadioState.MAC  = ConvertDecimaltoBCD(g_u8DispBuf[0]);
     t_EditRadioState.MAC = ConvertDecimaltoBCD(g_u8DispBuf[0]);
	 #endif

	  ReportMac_Bef = ReportMac_Now;
	  ReportMac_Now = g_u8DispBuf[0];
	 
	 
	 t_CurRadioState.MAC  = g_u8DispBuf[0];
     t_EditRadioState.MAC = g_u8DispBuf[0];
	 
	//test
	

	#if 0
    t_CurRadioState.MAC  = g_u8RadioCommRx_Buf[4];
    t_EditRadioState.MAC = g_u8RadioCommRx_Buf[4];
	#endif
	
	//ReportMac = YES;  // test
	// test
	if(t_CurRadioState.MAC == 00)
	{
		SelectStation = MainStation;
	}
	else
	{
		SelectStation = SubStation;
	}
	//test
	#if 0
	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		DispMacAddr2(0);  // ��ʾMac��ַ
		// test
		//DispMacNum(0);
		// test
	} 
	#endif
	
	//else if(g_u8CurMenuID == MENU_PARAMLINKBUILD)
	//{
	//}
	
	// test
	if(ReportMac_Bef != ReportMac_Now) // ֻ�к���һ�β�һ���ſ���ˢ��
	{
		//DispMenuText_ParamWorkState();
	}

	// test
	#if 0
	if(t_CurChannelState.ChanNum <= 19)  // ���Ƴ�����Χ���ŵ��ű���ʾ
	{				
		DispParamWorkState(); //20151130�ݶ�??????
	}
	#endif
}

/*********************************************************
*��������Report_RadioId
*����  �������̨ID�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioId(void)
{
    memcpy(&t_CurRadioState.ID[0], &g_u8RadioCommRx_Buf[4], 5);
}

/*********************************************************
*��������Report_MaxMac
*����  ������滮�ڵ��ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_MaxMac(void)
{
    t_CurRadioState.MaxMac = g_u8RadioCommRx_Buf[4];
}

/*********************************************************
*��������Report_UpperNet
*����  �������̨�ϼ������ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_UpperNet(void)
{
    t_CurRadioState.UpperNet = g_u8RadioCommRx_Buf[4];
}

/*********************************************************
*��������Report_ChanParam
*����  �������ŵ������ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_ChanParam(void)
{
	uint8_t ucData = 0;
	memcpy(&t_CurChannelState,	&g_u8RadioCommRx_Buf[4], sizeof(t_CurChannelState));
	
	ucData = t_CurChannelState.Freq[2] & 0x0F;
	if(ucData == 2)
	{
		t_CurChannelState.Freq[2] = (t_CurChannelState.Freq[2] & 0xF0) + 5;
	}
	else
	{
		t_CurChannelState.Freq[2] = t_CurChannelState.Freq[2] & 0xF0;
	}
	memcpy(&t_EditChannelState, &g_u8RadioCommRx_Buf[4], sizeof(t_CurChannelState));
	
	ucData = t_CurChannelState.WorkMode;
	if((ucData < WORKMODE_FIX) || (ucData > WORKMODE_SHOP))
	{
		t_CurChannelState.WorkMode = WORKMODE_FIX;
	}

	if((g_u8CurMenuID <= MENU_PARAMWORKSTATE))
	{
		//DispParamWorkState();
		if(g_u8ParamEditIndex <= INDEX_EDIT_CHANNUM) // �ŵ���
		{
			if(t_CurChannelState.ChanNum <= 25)  // ���Ƴ�����Χ���ŵ��ű���ʾ 0x25 = 19
			{				
				DispParamWorkState();
			}
		}
    	else
    	{		
			if(g_u8ParamEditIndex == INDEX_EDIT_WORKMODE)
			{
				if(t_CurChannelState.WorkMode%2 == 1)	// ��Ƶģʽ
				{
					PrintString(WIDTH_HALF, ROW_TEXT04, "Ƶ��: ", WORD);
					DispFrequency(0);
				}
				else
				{
					PrintString(WIDTH_HALF, ROW_TEXT04, "����: ", WORD);
					DispTableNum(0);
					DispNetNum(0);
				}
			}
		}			
		DispWorkStateReverse(0);
	}
	g_u8ParamEditIndex = 0;
	g_u8NumIndex = 0;
}


#define STARTUP_COUNTDOWN	8	//ssl20140706���̿�������ʱ��,���ܵ���0

/*********************************************************
*��������Report_WorkInfo
*����  �������̨����״̬�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_WorkInfo(void)
{
	memcpy(&t_CurRadioState, &g_u8RadioCommRx_Buf[4], 11);
	memcpy(&t_CurLinkQuanlity[0], &g_u8RadioCommRx_Buf[15],4*sizeof(t_CurLinkQuanlity[0]));
	#if 0
	// ������
	for(i=0;i<15;i++)
	{	
		g_u8DispBuf[i] = g_u8RadioCommRx_Buf[i] + '0';
	}

	PrintString(WIDTH_HALF,ROW_TEXT09,g_u8DispBuf,15);
	#endif

	// test
	if(t_CurRadioState.MAC == 00)
	{
		SelectStation = MainStation;
	}
	else
	{
		SelectStation = SubStation;
	}
	// test

	// ����̨��״̬������ʱ�յ�382����,���ָ̻�����
	// test
	
	if(g_u8RadioState == NO)
	{
		#if 0
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,��վ
		#endif
		g_u8RadioState = YES;
		// test
		DispMenuText_ParamWorkState();
	}
	
	// ����״̬�½����Լ����
	// test
	
	if(g_u8FlagStartUp == ON)
	{
		g_u8FlagStartUp = OFF;
		g_u8RTxTimeFlag = NO;
		//DispRadioTest();      // ��ʾ��̨ģ���Լ���
		Delay_nS(8);
		//DispMenuText_ParamWorkState();       // ��ʾ������һҳ����
	}

	DispRealTimeWorkState();
}

/*********************************************************
*��������Report_RadioTest
*����  �������̨�Լ��ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioTest(void)
{
    g_u8SelftestState[0] = g_u8RadioCommRx_Buf[4];
    g_u8SelftestState[1] = g_u8RadioCommRx_Buf[5];
	
	if(g_u8CurMenuID == MENU_1ST_BITE)
	{
		// test
		if(t_CurRadioState.MAC == 00)
		{
			SelectStation = MainStation;
		}
		else
		{
			SelectStation = SubStation;
		}
		// test
		
        g_u8FlagStartUp = ON;
	}

	// test
	#if 0
	if(g_u8CurMenuID > MENU_1ST_BITE)
	{
		AlarmLed_Ctrl(g_u8SelftestState);		// ���ϵƿ���
	}
	#endif
	
    if(g_u8CurMenuID == MENU_PARAMRADIOTEST)
    {	
		// test 20151229
		//AlarmLed_Ctrl(g_u8SelftestState);		// ���ϵƿ���
        //DispRadioTest();
    }
}

/*********************************************************
*��������Report_LinkMaintainGap
*����  ��������·ά������ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_LinkMaintainGap(void)
{ 
	uint8_t i = 0;
	memcpy(&g_u8LinkInfo[0],&g_u8RadioCommRx_Buf[4],16);
	for(i=0;i<8;i++)
	{
		t_CurLinkInfo[i].MaintainGap_ID = g_u8LinkInfo[2*i+1];  // ��·ά�����
		t_CurLinkInfo[i].MaintainGap_ID = g_u8LinkInfo[2*i+0];
	}
	DispLinkMaintainGap();
}

/*********************************************************
*��������Report_LinkQuality
*����  ��������·�����ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_LinkQuality(void)
{
	uint16_t u16_LinkQuanTemp = 0;
	#if 0
	memcpy(&g_u8LinkInfo[0],&g_u8RadioCommRx_Buf[4],21);
	for(i=0;i<8;i++)
	{
		t_CurLinkInfo[i].Quality_Up   = g_u8LinkInfo[3*i+1];  // ��·��������
		t_CurLinkInfo[i].Quality_Down = g_u8LinkInfo[3*i+0];  // ��·��������
	}
	DispLinkQuantity(0);	
	#endif 
	//DispSNR(void);
	// test 20151229
	// ֻ��������·����,���е�Ĭ�ϸ����е�һ��
	memcpy(&t_ReportLinkQuan[0], &g_u8RadioCommRx_Buf[4],4*sizeof(t_ReportLinkQuan[0]));
	// ����
	//if((t_ReportLinkQuan[0].SNR[0])&(0x80) == 0)  //16λ�����λ�Ƿ���λ
	if(t_ReportLinkQuan[0].SNR[0] <= 0x7F)  //16λ�����λ�Ƿ���λ
	{	
		u16_LinkQuanTemp =	((t_ReportLinkQuan[0].SNR[0]) << 8) + (t_ReportLinkQuan[0].SNR[1]);
		g_u8DispBuf[2] = '+';
	}
	else
	{	
		u16_LinkQuanTemp =	(((t_ReportLinkQuan[0].SNR[0])&(0x7F)) << 8) + (t_ReportLinkQuan[0].SNR[1]);
		g_u8DispBuf[2] = '-';
	}
	g_u8DispBuf[3] = (u16_LinkQuanTemp/10000%10) + '0'; // ��λ
	g_u8DispBuf[4] = (u16_LinkQuanTemp/1000%10) + '0';
	g_u8DispBuf[5] = '.';
	g_u8DispBuf[6] = (u16_LinkQuanTemp/100%10) + '0'; 
	g_u8DispBuf[7] = (u16_LinkQuanTemp/10%10) + '0';
	g_u8DispBuf[8] = (u16_LinkQuanTemp%10) + '0'; 

	if(g_u8CurMenuID == MENU_PARAMLINKQUERY)
	{
		if(t_CurRadioState.SyncState != 0x00) // ͬ��
		{
			DispMac();                // ��ʾMac
			DispLinkQuantity_Test(1); // ��ʾ��������·����
		}
		else
		{
			// test 20151229
			PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT04, "    ", 4);
			PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT04, " �� ", 4);
			DispLinkQuantity_Test(0); // ��ͬ����ʾ �� 
		}
	}
}

/*********************************************************
*��������Report_LinkInfo
*����  ��������·��Ϣ�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_LinkInfo(void)
{
	uint8_t i = 0;
	memcpy(&g_u8LinkInfo[0],&g_u8RadioCommRx_Buf[4],24);
	for(i=0;i<8;i++)
	{
		t_CurLinkInfo[i].MacNum      = g_u8LinkInfo[3*i+0]; // Mac��
		t_CurLinkInfo[i].NetState    = g_u8LinkInfo[3*i+1]; // ����״̬
		t_CurLinkInfo[i].Intensity   = g_u8LinkInfo[3*i+2]; // ��ǿ

		t_EditLinkInfo[i].MacNum     = g_u8LinkInfo[3*i+0];
		t_EditLinkInfo[i].NetState   = g_u8LinkInfo[3*i+1];
		t_EditLinkInfo[i].Intensity  = g_u8LinkInfo[3*i+2];
	}
}

/*********************************************************
*��������Report_LinkTest
*����  ��������·�����ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_LinkTest(void)
{

}

/*********************************************************
*��������Report_DigTranStatis
*����  ����������ͳ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_DigTranStatis(void)
{	
	uint32_t u32_SfTemp = 0,u32_RfTemp = 0;
	uint8_t i = 0,u8Index_SF = 0,u8Index_RF = 0;
	#if 0
	// before
	uint8_t i = 0;
	for(i=0;i<96;i++)
	{
		g_u8RadioCommRx_Buf[i] = 0x33;
	}
	for(i=0;i<8;i++)
	{	
		g_u8DispBuf_Frame[12*i+0] = (g_u8RadioCommRx_Buf[12*i+5] >> 4)   + '0'; //��ȷ֡(��λ)
		g_u8DispBuf_Frame[12*i+1] = (g_u8RadioCommRx_Buf[12*i+5] & 0x0f) + '0';
		g_u8DispBuf_Frame[12*i+2] = (g_u8RadioCommRx_Buf[12*i+6] >> 4)   + '0';
		g_u8DispBuf_Frame[12*i+3] = (g_u8RadioCommRx_Buf[12*i+6] & 0x0f) + '0';
		
		g_u8DispBuf_Frame[12*i+4] = (g_u8RadioCommRx_Buf[12*i+7] >> 4)   + '0'; //����֡(��λ)
		g_u8DispBuf_Frame[12*i+5] = (g_u8RadioCommRx_Buf[12*i+7] & 0x0f) + '0';
		g_u8DispBuf_Frame[12*i+6] = (g_u8RadioCommRx_Buf[12*i+8] >> 4)   + '0';
		g_u8DispBuf_Frame[12*i+7] = (g_u8RadioCommRx_Buf[12*i+8] & 0x0f) + '0';

		g_u8DispBuf_Frame[12*i+8]  = (g_u8RadioCommRx_Buf[12*i+9] >> 4)   + '0'; //����֡(��λ)
		g_u8DispBuf_Frame[12*i+9]  = (g_u8RadioCommRx_Buf[12*i+9] & 0x0f) + '0';
		g_u8DispBuf_Frame[12*i+10] = (g_u8RadioCommRx_Buf[12*i+10] >> 4)   + '0';
		g_u8DispBuf_Frame[12*i+11] = (g_u8RadioCommRx_Buf[12*i+10] & 0x0f) + '0';
	}
	DispDigTranInfo_FrameInfo();
	#endif

	// test 20151228
	// Mac�š�����֡������֡������֡������֡
	memcpy(&t_CurStatisFrame.MacNum,&g_u8RadioCommRx_Buf[4],9);
	
	// Mac��
	g_u8DispBuf[0] = (t_CurStatisFrame.MacNum/10) + '0';
	g_u8DispBuf[1] = (t_CurStatisFrame.MacNum%10) + '0';
	// ����֡
	u32_SfTemp = (t_CurStatisFrame.SendFram[0] << 24) + (t_CurStatisFrame.SendFram[1] << 16)
					+ (t_CurStatisFrame.SendFram[2] << 8)
					+  t_CurStatisFrame.SendFram[3];
	// ����֡
	u32_RfTemp = (t_CurStatisFrame.ReceiveFram[0] << 24) + (t_CurStatisFrame.ReceiveFram[1] << 16)
					+ (t_CurStatisFrame.ReceiveFram[2] << 8)
					+  t_CurStatisFrame.ReceiveFram[3];

	// ����֡
	g_u8DispBuf[2] =  (u32_SfTemp/1000000000%10) + '0'; // ��λ
	g_u8DispBuf[3] =  (u32_SfTemp/100000000%10) + '0';
	g_u8DispBuf[4] =  (u32_SfTemp/10000000%10) + '0';
	g_u8DispBuf[5] =  (u32_SfTemp/1000000%10) + '0';
	g_u8DispBuf[6] =  (u32_SfTemp/100000%10) + '0';
	g_u8DispBuf[7] =  (u32_SfTemp/10000%10) + '0';
	g_u8DispBuf[8] =  (u32_SfTemp/1000%10) + '0';
	g_u8DispBuf[9] =  (u32_SfTemp/100%10) + '0';
	g_u8DispBuf[10] = (u32_SfTemp/10%10) + '0';
	g_u8DispBuf[11] = (u32_SfTemp%10) + '0';

	// ����֡
	g_u8DispBuf[12] =  (u32_RfTemp/1000000000%10) + '0'; // ��λ
	g_u8DispBuf[13] =  (u32_RfTemp/100000000%10) + '0';
	g_u8DispBuf[14] =  (u32_RfTemp/10000000%10) + '0';
	g_u8DispBuf[15] =  (u32_RfTemp/1000000%10) + '0';
	g_u8DispBuf[16] =  (u32_RfTemp/100000%10) + '0';
	g_u8DispBuf[17] =  (u32_RfTemp/10000%10) + '0';
	g_u8DispBuf[18] =  (u32_RfTemp/1000%10) + '0';
	g_u8DispBuf[19] =  (u32_RfTemp/100%10) + '0';
	g_u8DispBuf[20] =  (u32_RfTemp/10%10) + '0';
	g_u8DispBuf[21] =  (u32_RfTemp%10) + '0';

	for(i=0;i<10;i++)
	{
		if(g_u8DispBuf[i+2] != '0')
		{
			u8Index_SF = i+2;
			break;
		}
	}
	
	for(i=0;i<10;i++)
	{
		if(g_u8DispBuf[i+12] != '0')
		{
			u8Index_RF = i+12;
			break;
		}
	}

	if(g_u8CurMenuID == MENU_PARAMDIGTRANSTATIS) 
	{
		if(SelectPage == PageOne)  // test 20151230
		{
			// test 20151230����ճɹ���־���
			//PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08, "          ", WORD);
			
			// ��ʾվ��
			PrintString(COL_WORD1+WIDTH_HALF, ROW_TEXT04, g_u8DispBuf, 2);
			
			// ��ʾ����֡
			if((t_CurStatisFrame.SendFram[1] > 0x8F) || (t_CurStatisFrame.SendFram[0] > 0x00))	// �ݶ�ֵ: ��Ļ��ֻ����ʾ7λֵ
			{	
				
				PrintString(COL_WORD4, ROW_TEXT04, "		   ",6);
				PrintString(COL_WORD4, ROW_TEXT04, "֡��� ", WORD);
			}
			else
			{	
				PrintString(COL_WORD4, ROW_TEXT04, "       ",WORD);
				if(u8Index_SF == 0x00)
				{	
					//PrintString(COL_WORD4, ROW_TEXT04, "       ",7);
					PrintString(COL_WORD5, ROW_TEXT04, "0",1);
				}
				else
				{		
					PrintString(COL_WORD4, ROW_TEXT04, &g_u8DispBuf[u8Index_SF], 12-u8Index_SF);
				}
			}
			
			// ��ʾ����֡
			if((t_CurStatisFrame.ReceiveFram[1] > 0x8F) || (t_CurStatisFrame.ReceiveFram[0] > 0x00))  // �ݶ�ֵ: ��Ļ��ֻ����ʾ7λֵ
			{			
				PrintString(COL_WORD8, ROW_TEXT04, "		   ",6);
				PrintString(COL_WORD8, ROW_TEXT04, "֡��� ", WORD);
			}
			else
			{	
				PrintString(COL_WORD8, ROW_TEXT04, "       ",WORD);
				if(u8Index_RF == 0x00)
				{			
					//PrintString(COL_WORD8, ROW_TEXT04, "	    ",7);
					PrintString(COL_WORD9, ROW_TEXT04, "0",1);
				}
				else
				{			
					PrintString(COL_WORD8, ROW_TEXT04, &g_u8DispBuf[u8Index_RF], 22-u8Index_RF);
				}
			}
		}
	}
}

/*********************************************************
*��������Report_DigTranReport
*����  �����������㱨�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_DigTranReport(void)
{
	#if 0
	uint8_t i = 0;
	for(i=0;i<8;i++)
	{
		g_u8DispBuf[6*i+0] = g_u8RadioCommRx_Buf[6*i+5]  + '0'; //��ȷ֡
		g_u8DispBuf[6*i+1] = g_u8RadioCommRx_Buf[6*i+6]  + '0';
		g_u8DispBuf[6*i+2] = g_u8RadioCommRx_Buf[6*i+7]  + '0'; //����֡
		g_u8DispBuf[6*i+3] = g_u8RadioCommRx_Buf[6*i+8]  + '0';
		g_u8DispBuf[6*i+4] = g_u8RadioCommRx_Buf[6*i+9]  + '0'; //����֡
		g_u8DispBuf[6*i+5] = g_u8RadioCommRx_Buf[6*i+10] + '0';
	}
	DispDigTranInfo_FrameInfo();
	#if 0
	LinkDigInfo_TypeDef LinkDigInfo[8];
	LinkDigInfo[0].RigFram[0]   = g_u8RadioCommRx_Buf[5]; //��ȷ֡
	LinkDigInfo[0].RigFram[1]   = g_u8RadioCommRx_Buf[6];
	LinkDigInfo[0].ErrFram[0]   = g_u8RadioCommRx_Buf[7]; //����֡
	LinkDigInfo[0].ErrFram[1]   = g_u8RadioCommRx_Buf[8];
	LinkDigInfo[0].ConfuFram[0] = g_u8RadioCommRx_Buf[9]; //����֡
	LinkDigInfo[0].ConfuFram[1] = g_u8RadioCommRx_Buf[10];
	PrintString(COL_WORD5, ROW_TEXT03,LinkDigInfo[0].RigFram,2);
	PrintString(COL_WORD9, ROW_TEXT03,LinkDigInfo[0].ErrFram,2);
	PrintString(COL_WORD13,ROW_TEXT03,LinkDigInfo[0].ConfuFram,2);
	for(i=0;i<8;i++)
	{
		memcpy(&g_u8LinkInfo[0],&g_u8RadioCommRx_Buf[4],56);
	}
	#endif
	#endif	
	uint32_t u32_SfTemp = 0,u32_RfTemp = 0;
	uint8_t i = 0,u8Index_SF = 0,u8Index_RF = 0;
	#if 0
	// before
	uint8_t i = 0;
	for(i=0;i<96;i++)
	{
		g_u8RadioCommRx_Buf[i] = 0x33;
	}
	for(i=0;i<8;i++)
	{	
		g_u8DispBuf_Frame[12*i+0] = (g_u8RadioCommRx_Buf[12*i+5] >> 4)   + '0'; //��ȷ֡(��λ)
		g_u8DispBuf_Frame[12*i+1] = (g_u8RadioCommRx_Buf[12*i+5] & 0x0f) + '0';
		g_u8DispBuf_Frame[12*i+2] = (g_u8RadioCommRx_Buf[12*i+6] >> 4)   + '0';
		g_u8DispBuf_Frame[12*i+3] = (g_u8RadioCommRx_Buf[12*i+6] & 0x0f) + '0';
		
		g_u8DispBuf_Frame[12*i+4] = (g_u8RadioCommRx_Buf[12*i+7] >> 4)   + '0'; //����֡(��λ)
		g_u8DispBuf_Frame[12*i+5] = (g_u8RadioCommRx_Buf[12*i+7] & 0x0f) + '0';
		g_u8DispBuf_Frame[12*i+6] = (g_u8RadioCommRx_Buf[12*i+8] >> 4)   + '0';
		g_u8DispBuf_Frame[12*i+7] = (g_u8RadioCommRx_Buf[12*i+8] & 0x0f) + '0';

		g_u8DispBuf_Frame[12*i+8]  = (g_u8RadioCommRx_Buf[12*i+9] >> 4)   + '0'; //����֡(��λ)
		g_u8DispBuf_Frame[12*i+9]  = (g_u8RadioCommRx_Buf[12*i+9] & 0x0f) + '0';
		g_u8DispBuf_Frame[12*i+10] = (g_u8RadioCommRx_Buf[12*i+10] >> 4)   + '0';
		g_u8DispBuf_Frame[12*i+11] = (g_u8RadioCommRx_Buf[12*i+10] & 0x0f) + '0';
	}
	DispDigTranInfo_FrameInfo();
	#endif

	// test 20151228
	// Mac�š�����֡������֡������֡������֡
	memcpy(&t_CurStatisFrame.MacNum,&g_u8RadioCommRx_Buf[4],9);
	
	// Mac��
	g_u8DispBuf[0] = (t_CurStatisFrame.MacNum/10) + '0';
	g_u8DispBuf[1] = (t_CurStatisFrame.MacNum%10) + '0';
	// ����֡
	u32_SfTemp = (t_CurStatisFrame.SendFram[0] << 24) + (t_CurStatisFrame.SendFram[1] << 16)
					+ (t_CurStatisFrame.SendFram[2] << 8)
					+  t_CurStatisFrame.SendFram[3];
	// ����֡
	u32_RfTemp = (t_CurStatisFrame.ReceiveFram[0] << 24) + (t_CurStatisFrame.ReceiveFram[1] << 16)
					+ (t_CurStatisFrame.ReceiveFram[2] << 8)
					+  t_CurStatisFrame.ReceiveFram[3];

	// ����֡
	g_u8DispBuf[2] =  (u32_SfTemp/1000000000%10) + '0'; // ��λ
	g_u8DispBuf[3] =  (u32_SfTemp/100000000%10) + '0';
	g_u8DispBuf[4] =  (u32_SfTemp/10000000%10) + '0';
	g_u8DispBuf[5] =  (u32_SfTemp/1000000%10) + '0';
	g_u8DispBuf[6] =  (u32_SfTemp/100000%10) + '0';
	g_u8DispBuf[7] =  (u32_SfTemp/10000%10) + '0';
	g_u8DispBuf[8] =  (u32_SfTemp/1000%10) + '0';
	g_u8DispBuf[9] =  (u32_SfTemp/100%10) + '0';
	g_u8DispBuf[10] = (u32_SfTemp/10%10) + '0';
	g_u8DispBuf[11] = (u32_SfTemp%10) + '0';

	// ����֡
	g_u8DispBuf[12] =  (u32_RfTemp/1000000000%10) + '0'; // ��λ
	g_u8DispBuf[13] =  (u32_RfTemp/100000000%10) + '0';
	g_u8DispBuf[14] =  (u32_RfTemp/10000000%10) + '0';
	g_u8DispBuf[15] =  (u32_RfTemp/1000000%10) + '0';
	g_u8DispBuf[16] =  (u32_RfTemp/100000%10) + '0';
	g_u8DispBuf[17] =  (u32_RfTemp/10000%10) + '0';
	g_u8DispBuf[18] =  (u32_RfTemp/1000%10) + '0';
	g_u8DispBuf[19] =  (u32_RfTemp/100%10) + '0';
	g_u8DispBuf[20] =  (u32_RfTemp/10%10) + '0';
	g_u8DispBuf[21] =  (u32_RfTemp%10) + '0';

	for(i=0;i<10;i++)
	{
		if(g_u8DispBuf[i+2] != '0')
		{
			u8Index_SF = i+2;
			break;
		}
	}
	
	for(i=0;i<10;i++)
	{
		if(g_u8DispBuf[i+12] != '0')
		{
			u8Index_RF = i+12;
			break;
		}
	}

	if(g_u8CurMenuID == MENU_PARAMDIGTRANREPORT) 
	{
		if(SelectPage == PageOne)  // test 20151230
		{
			// test 20151230����ճɹ���־���
			//PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT08, "          ", WORD);
			
			// ��ʾվ��
			PrintString(COL_WORD1+WIDTH_HALF, ROW_TEXT04, g_u8DispBuf, 2);
			
			// ��ʾ����֡
			if((t_CurStatisFrame.SendFram[1] > 0x8F) || (t_CurStatisFrame.SendFram[0] > 0x00))	// �ݶ�ֵ: ��Ļ��ֻ����ʾ7λֵ
			{	
				
				PrintString(COL_WORD4, ROW_TEXT04, "		   ",6);
				PrintString(COL_WORD4, ROW_TEXT04, "֡��� ", WORD);
			}
			else
			{	
				PrintString(COL_WORD4, ROW_TEXT04, "       ",WORD);
				if(u8Index_SF == 0x00)
				{	
					//PrintString(COL_WORD4, ROW_TEXT04, "       ",7);
					PrintString(COL_WORD5, ROW_TEXT04, "0",1);
				}
				else
				{		
					PrintString(COL_WORD4, ROW_TEXT04, &g_u8DispBuf[u8Index_SF], 12-u8Index_SF);
				}
			}
			
			// ��ʾ����֡
			if((t_CurStatisFrame.ReceiveFram[1] > 0x8F) || (t_CurStatisFrame.ReceiveFram[0] > 0x00))  // �ݶ�ֵ: ��Ļ��ֻ����ʾ7λֵ
			{			
				PrintString(COL_WORD8, ROW_TEXT04, "		   ",6);
				PrintString(COL_WORD8, ROW_TEXT04, "֡��� ", WORD);
			}
			else
			{	
				PrintString(COL_WORD8, ROW_TEXT04, "       ",WORD);
				if(u8Index_RF == 0x00)
				{			
					//PrintString(COL_WORD8, ROW_TEXT04, "	    ",7);
					PrintString(COL_WORD9, ROW_TEXT04, "0",1);
				}
				else
				{			
					PrintString(COL_WORD8, ROW_TEXT04, &g_u8DispBuf[u8Index_RF], 22-u8Index_RF);
				}
			}
		}
	}
}

/*********************************************************
*��������Report_PowerScan
*����  ��������ɨ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_PowerScan(void)
{

}

/*********************************************************
*��������Report_ScanStop
*����  ������ֹͣ����ɨ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_ScanStop(void)
{

}

/*********************************************************
*��������Report_PowerTest
*����  �������ʼ���ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_PowerTest(void)
{
	if((g_u8ParamEditState == YES) && (g_u8CurMenuID == MENU_PARAMPOWERCHECK))
	{
		g_u8DispBuf[0] = (g_u8RadioCommRx_Buf[4]/10) + '0';
		g_u8DispBuf[1] = (g_u8RadioCommRx_Buf[4]%10) + '0';
		g_u8DispBuf[2] = 'd';
		g_u8DispBuf[3] = 'B';
		g_u8DispBuf[4] = 'm';
		
		PrintString(COL_WORD9, ROW_TEXT04, "         ", WORD);
		PrintString(COL_WORD9, ROW_TEXT04, g_u8DispBuf, 5);
	}
}

void Report_SpuSoftVersion(void)
{
}

/*********************************************************
*��������Report_RadioInfo
*����  �������̨��Ϣ�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_RadioInfo(void)
{

}

/*********************************************************
*��������Report_StartUpAndRemote
*����  �������ػ�״̬��ң��״̬�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_StartUpAndRemote(void)
{
    //g_u8SelftestState[0] = g_u8RadioCommRx_Buf[64];
    //g_u8SelftestState[1] = g_u8RadioCommRx_Buf[65];
    
    memcpy(&t_CurChannelState,  &g_u8RadioCommRx_Buf[66], sizeof(t_CurChannelState));
    memcpy(&t_EditChannelState, &g_u8RadioCommRx_Buf[66], sizeof(t_EditChannelState));

    memcpy(&t_CurRadioState, &g_u8RadioCommRx_Buf[80], 11);

    t_CurRadioState.Power  = g_u8RadioCommRx_Buf[100];
    t_EditRadioState.Power = g_u8RadioCommRx_Buf[100];
    
    memcpy(&t_CurRadioState.Service_IP[0],  &g_u8RadioCommRx_Buf[105], 4);
    memcpy(&t_EditRadioState.Service_IP[0], &g_u8RadioCommRx_Buf[105], 4);

    t_CurRadioState.MAC  = g_u8RadioCommRx_Buf[110];
    t_EditRadioState.MAC = g_u8RadioCommRx_Buf[110];

	// test
	if(t_CurRadioState.MAC == 00)
	{
		SelectStation = MainStation;
	}
	else
	{
		SelectStation = SubStation;
	}
	// test
	
	g_u8CurMenuItem = 1;
	g_u8ParamEditIndex = 0;

	if(g_u8CurMenuID != MENU_1ST_BITE)
	{
		DispMenuText_ParamWorkState(); // test
	}
	//DispParam1();
	//DispItemReverse_Param1();
}

/*********************************************************
*��������Report_TipsInfo
*����  ��������ʾ��Ϣ�ϱ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_TipsInfo(void)
{
}

/*********************************************************
*��������Report_PowerAttn
*����  �������ϱ��Ĺ��ʲ���ֵ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_PowerAttn(void)
{

}

/*********************************************************
*��������Report_WaveMode
*����  ���ϱ�����ģʽ
*����  ����
*���  ����
*����ֵ����
*��ע  ��1:���Ʋ���  2:�������
***********************************************************/
void Report_WaveMode(void)
{

}

/*********************************************************
*��������Report_PowerOff
*����  ���ϱ��ػ�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Report_PowerOff(void)
{
	SetGpioBit(CON_POWER_PIN);
	//ClrGpioBit(CON_POWER_PIN);
}

/*********************************************************
*��������Set_SecureTest
*����  �����ͱ��ܻ��Լ�ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_SecureTest(void)
{
    g_u8RadioCommTx_Buf[0] = 0xa1;
    g_u8RadioCommTx_Buf[1] = 0x98;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Set_SecureQuery
*����  �����ͱ��ܻ���ѯָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_SecureQuery(void)
{
    g_u8RadioCommTx_Buf[0] = 0xa1;
    g_u8RadioCommTx_Buf[1] = 0x99;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x00;

    g_u8RadioCommTx_Len = 4;

    Send_SerialData();
}

/*********************************************************
*��������Set_SecureConfig
*����  �����ͱ��ܻ���������ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_SecureConfig(void)
{
    g_u8RadioCommTx_Buf[0] = 0xa1;
    g_u8RadioCommTx_Buf[1] = 0x90;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x06;

    memcpy(&g_u8RadioCommTx_Buf[4], &t_EditSecureState, 6);
    
    g_u8RadioCommTx_Len = 10;

    Send_SerialData();
}

/*********************************************************
*��������Set_SecureDestroy
*����  ���������ٱ��ܻ���Դָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_SecureDestroy(void)
{
    uint8_t aDestroyCode[4] = {0x29, 0x45, 0x32, 0x90};

    g_u8RadioCommTx_Buf[0] = 0xa1;
    g_u8RadioCommTx_Buf[1] = 0x9A;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x04;

    memcpy(&g_u8RadioCommTx_Buf[4], aDestroyCode, 4);
    
    g_u8RadioCommTx_Len = 8;

    Send_SerialData();
}

/*********************************************************
*��������Set_SecureTime
*����  �����ͱ��ܻ�Уʱָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Set_SecureTime(void)
{
    g_u8RadioCommTx_Buf[0] = 0xa1;
    g_u8RadioCommTx_Buf[1] = 0x9C;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x08;

	g_u8RadioCommTx_Buf[4] = 2;
	g_u8RadioCommTx_Buf[5] = 0;
    g_u8RadioCommTx_Buf[6] = t_CurTime.Year >> 4;
    g_u8RadioCommTx_Buf[7] = t_CurTime.Year & 0x0F;
    g_u8RadioCommTx_Buf[8] = ConvertBCDtoDecimal(t_CurTime.Month);
    g_u8RadioCommTx_Buf[9] = ConvertBCDtoDecimal(t_CurTime.Day);
    g_u8RadioCommTx_Buf[10] = ConvertBCDtoDecimal(t_CurTime.Hour);
    g_u8RadioCommTx_Buf[11] = ConvertBCDtoDecimal(t_CurTime.Minute);
	
    g_u8RadioCommTx_Len = 12;

    Send_SerialData();
}

/*********************************************************
*��������Query_SecureConfig
*����  ����ѯ�������������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Query_SecureConfig(void)
{
    g_u8RadioCommTx_Buf[0] = 0xa1;
    g_u8RadioCommTx_Buf[1] = 0x91;
    g_u8RadioCommTx_Buf[2] = 0x00;
    g_u8RadioCommTx_Buf[3] = 0x01;

    g_u8RadioCommTx_Buf[4] = 0;
    g_u8RadioCommTx_Len = 5;

    Send_SerialData();
}

/*********************************************************
*��������Encode_SlipData
*����  ��Slip���ݷ�װ����
*����  ����̨�������ں�CRC������������ʼ��ַ�����鳤��
*���  ����
*����ֵ����װ��������ܳ���
***********************************************************/
unsigned char Encode_SlipData(unsigned char* mDataBuf, unsigned char mLen)
{
    unsigned char i = 0, j = 0;
    unsigned char ucLength = 0;
    ucLength = mLen;
    
    for(i=0; i<ucLength; i++)
    {
        if((mDataBuf[i] != 0xC0) && (mDataBuf[i] != 0xDB))
        {
            continue;
        }

        ucLength++;
        for(j=ucLength-2; j>i; j--)
        {
            mDataBuf[j+1] = mDataBuf[j];
        }

        if(mDataBuf[i] == 0xC0)
        {
            mDataBuf[i+1] = 0xDC;
        }
        else if(mDataBuf[i] == 0xDB)
        {
            mDataBuf[i+1] = 0xDD;
        }

        mDataBuf[i] = 0xDB;
    }
    return ucLength;
}

/*********************************************************
*��������Decode_SlipData
*����  ��Slip���ݽ��װ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t Decode_SlipData(uint8_t *array, uint8_t len)
{
    uint8_t i = 0, j = 0, u8Length;
    u8Length = len;

    for(i=0; i<len; i++)
    {
        if(array[i] != 0xDB)
        {
            continue;
        }

        if(i == (len-1))        // ���һ��ֵΪ0xDB
        {
            continue;
        }
        
        if((array[i+1] != 0xDC) && (array[i+1] != 0xDD))
        {
            continue;
        }

        if(array[i+1] == 0xDC)
        {
            array[i] = 0xC0;
        }
        else if(array[i+1] == 0xDD)
        {
            array[i] = 0xDB;
        }
        
        for(j=i+1; j<len-1; j++)
        {
            array[j] = array[j+1];
        }
        u8Length--;
    }
	return u8Length;
}

/*********************************************************
*��������Calculate_Crc
*����  ������CRCУ��ֵ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint16_t Calculate_Crc(uint8_t *Buf, uint8_t len)
{
    uint8_t i = 0,j = 0;
    uint16_t crc = 0,flag = 0;

    for(i=0; i<len; i++)
    {
        crc ^= (unsigned int)(Buf[i] << 8);

        for(j=0; j<8; j++)
        {
            flag = crc&0x8000;
            crc <<= 1;

            if(flag)
            {
                crc &= 0xfffe;
                crc ^= 0x8005;
            }
        }
    }

    return crc;
}

/*********************************************************
*��������Receve_SerialData
*����  �����մ�������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Receive_SerialData(void)
{
    uint16_t u16Crc = 0;
    static uint8_t u8Array[2] = {0,0};
    static uint8_t u8ReceivingFlag = NO;
    //uint16_t u16Command = 0;
    
    if(g_u8HeadRx == g_u8TailRx)
    {
        return;
    }

    u8Array[0] = u8Array[1];
    u8Array[1] = g_u8SerialDataRx[g_u8HeadRx];
    g_u8HeadRx = (g_u8HeadRx + 1)%200;

    if(u8ReceivingFlag == NO)
    {
// -----------------�յ�֡ͷ--------------------------//
        if((u8Array[0] == 0xC0) && (u8Array[1] != 0xC0))
        {
            u8ReceivingFlag = YES;
            g_u8RadioCommRx_Buf[g_u8LengthRx] = u8Array[1];
            g_u8LengthRx = (g_u8LengthRx + 1)%200;
        }
    }
    else
    {
// -----------------�յ�֡β--------------------------//
        if((u8Array[0] != 0xC0) && (u8Array[1] == 0xC0))
        {
            u8ReceivingFlag = NO;
            g_u8RadioCommRx_Len = Decode_SlipData(g_u8RadioCommRx_Buf, g_u8LengthRx);
			g_u8RadioCommRx_Len %= 201;

			g_u8LengthRx = 0;
            g_u8RadioCommRx_Len -= 2;
            u16Crc = g_u8RadioCommRx_Buf[g_u8RadioCommRx_Len] << 8;
            u16Crc += g_u8RadioCommRx_Buf[g_u8RadioCommRx_Len+1];


            /*u16Command = g_u8RadioCommRx_Buf[0] << 8;
            u16Command += g_u8RadioCommRx_Buf[1];
            if(u16Command == REPORT_SCAN_PARAM)
                u16Command = REPORT_SCAN_PARAM;*/

         if(Calculate_Crc(g_u8RadioCommRx_Buf, g_u8RadioCommRx_Len) == u16Crc)
            {
                ProcSerialRxCommand();
            }
        }
        else
        {
            g_u8RadioCommRx_Buf[g_u8LengthRx] = u8Array[1];
            g_u8LengthRx = (g_u8LengthRx + 1)%200;
        }
    }
}

/*********************************************************
*��������Send_SerialData
*����  �����ʹ�������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Send_SerialData(void)
{
    uint16_t u16Data = 0;
    uint16_t u16TimeOut = 50000;

	// �˴�Ϊ��ֹ��������޶����ͳ��ȣ��ɸ���ʵ���޸�
	if(g_u8RadioCommTx_Len < 120)	
	{
		u16Data = Calculate_Crc(g_u8RadioCommTx_Buf, g_u8RadioCommTx_Len);
		g_u8RadioCommTx_Buf[g_u8RadioCommTx_Len] = (uint8_t)(u16Data >> 8);
		g_u8RadioCommTx_Buf[g_u8RadioCommTx_Len+1] = (uint8_t)(u16Data & 0xFF);
		g_u8RadioCommTx_Len += 2;
		
		g_u8RadioCommTx_Len = Encode_SlipData(g_u8RadioCommTx_Buf, g_u8RadioCommTx_Len);	  // ��slipЭ���װ����
	
		g_u8SerialDataTx[0] = 0xC0;
		memcpy(&g_u8SerialDataTx[1], g_u8RadioCommTx_Buf, g_u8RadioCommTx_Len);
		g_u8RadioCommTx_Len++;
		g_u8SerialDataTx[g_u8RadioCommTx_Len++] = 0xC0;
		g_u8LengthTx = 0;
	 
	// ��ʼ�������ݷ��Ͳ��ȴ����ͽ���	 
		USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
		while((g_u8LengthTx < g_u8RadioCommTx_Len) && (u16TimeOut > 0))
		{
			u16TimeOut--;
			Delay_nUS(1);
		}
		
		u16TimeOut = 50000;
		while((USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) 
			&& (u16TimeOut > 0))
		{
			u16TimeOut--;
		}
		// ���жϱ�־λ
		USART_ClearFlag(USART1, USART_FLAG_TXE);
		USART_ClearITPendingBit(USART1, USART_IT_TXE);
	}
}

/*********************************************************
*��������ProcSerialRxCommand
*����  ����������ָ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
SerialFunction_TypeDef t_ReportCommand[] = 
{
    {REPORT_ACK,                Report_ACK}, 
	{REPORT_NACK,               Report_NACK},
	
	{REPORT_RADIO_IP,           Report_RadioIp},	
	{REPORT_RADIO_MASK,         Report_RadioMask},

	{REPORT_RADIO_MAC,          Report_RadioMac},	
	{REPORT_CHAN_PARAM,         Report_ChanParam},
	{REPORT_RADIO_POWER,        Report_RadioPower},
	{REPORT_RADIO_RANK,         Report_RadioRank},

	{REPORT_RADIO_TEST,         Report_RadioTest},
    {REPORT_LINK_MAINTAINGAP,   Report_LinkMaintainGap},
    {REPORT_LINK_QUALITY,       Report_LinkQuality},
   // {REPORT_LINK_STATE,         Report_LinkInfo},
    {REPORT_LINK_DIGTRANSTATIS, Report_DigTranStatis},
    {REPORT_LINK_DIGTRANREPORT, Report_DigTranReport},
	{REPORT_POWER_TEST,         Report_PowerTest}, 
	{REPORT_SPU_SOFT_VERSION,   Report_SpuSoftVersion},
		






	
    {REPORT_LINK_TEST,     Report_LinkTest},   
    /*{REPORT_NETPORT_STATE, Report_NetPortState},*/{REPORT_POWER_SCAN,   Report_PowerScan},
      {REPORT_RADIO_ID,   Report_RadioId},
    /*{REPORT_RADIO_INFO,    Report_RadioInfo},*/  

	// test
	  {REPORT_WORK_INFO,  Report_WorkInfo},
    

	
	{REPORT_INC_IP,     Report_IncIp},     {REPORT_SECURE_IP, Report_SecureIp},
	{REPORT_MAX_MAC,    Report_MaxMac},

	{REPORT_SCAN_STOP,      Report_ScanStop},

	// test 20151229
	//{REPORT_SOFT_VERSION,  Report_SoftVersion}, 

    {REPORT_STARTUP_REMOTE,Report_StartUpAndRemote},{REPORT_TIME,       Report_QueryTime},
    {REPORT_UPPER_NETNUM,  Report_UpperNet}, 	    {REPORT_SCAN_PARAM, Report_PowerAttn},	  
    {REPORT_TIPS_INFO,     Report_TipsInfo},

	 {REPORT_POWER_OFF, Report_PowerOff}
};
void ProcSerialRxCommand(void)
{
    uint16_t u16Command = 0;
    uint8_t i = 0;

    u16Command = g_u8RadioCommRx_Buf[0] << 8;
    u16Command += g_u8RadioCommRx_Buf[1];

    if(u16Command == REPORT_WORK_INFO)
    {
        Report_WorkInfo();
    }
    else
    {
        //i = NUM_OF_CMD;
        for(i=0; i<NUM_OF_CMD; i++)
        {
            if(u16Command == t_ReportCommand[i].Fuction_ID)
            {
                (*t_ReportCommand[i].ProcessFuction)();
                break;
            }
        }
    }
}

void mockReportWorkInfo(void)
{
	t_EditRadioState.RemoteState 	= 0;
	t_EditRadioState.Intensity 		= 0;
	t_EditRadioState.Indication		= 0;
	t_EditRadioState.SendRate		= 8;
	t_EditRadioState.VoiceCode		= 3;/*VOC_2400*/
	t_EditRadioState.SyncState		= 0;/*δͬ��*/
	t_EditRadioState.NetState		= 0;/*δ����*/
	t_EditRadioState.SnrRate		= 0;
	t_EditRadioState.ParamState		= 1;
	t_EditRadioState.NC				= 0;
	t_EditRadioState.CallMAC		= 1;
	memcpy(&g_u8RadioCommRx_Buf[4], &t_EditRadioState, 11);
	Report_WorkInfo();
}


