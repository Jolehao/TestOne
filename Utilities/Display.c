#include "all.h"

/*********************************************************
*��������DispStartUpPage
*����  ��������ʾ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispStartUpPage(void)
{
	LCD_Clear(BOTTOM);  // ����
	LCD_Clear(TOP);

    PrintOneFont24x24(COL_WORD3+WIDTH_HALF, 0x40, Font_chao);
    PrintOneFont24x24(COL_WORD5,              0x40, Font_duan);
    PrintOneFont24x24(COL_WORD6+WIDTH_HALF, 0x40, Font_bo);
    PrintOneFont24x24(COL_WORD8,              0x40, Font_gao);
    PrintOneFont24x24(COL_WORD9+WIDTH_HALF, 0x40, Font_su);
    PrintOneFont24x24(COL_WORD11,             0x40, Font_shu);
    PrintOneFont24x24(COL_WORD12+WIDTH_HALF,0x40, Font_ju);
    PrintOneFont24x24(COL_WORD14,             0x40, Font_dian);
    PrintOneFont24x24(COL_WORD15+WIDTH_HALF,0x40, Font_tai);

	PrintString(COL_WORD6, ROW_TEXT06, "��Ӫ�������", WORD);
	Delay_nS(2);	// �ӳ�4S
	
	PrintString(COL_WORD6, ROW_TEXT06, "                  ", WORD);
    PrintString(COL_WORD6, ROW_TEXT06, "ϵͳ��ʼ��,���Ժ�...", WORD);
	Delay_nS(3);

	#if 0
	PrintString(COL_WORD6, ROW_TEXT06, "                  ", WORD);
    PrintString(COL_WORD6, ROW_TEXT06, "���ڼ���...", WORD);
    Delay_nS(3);     // �ӳ�4S
	#endif

    PrintString(COL_WORD6, ROW_TEXT06, "                    ", WORD);
    PrintString(COL_WORD6, ROW_TEXT06, "�����Լ�...", WORD);

	// test
	#if 0
	g_u8CurMenuID = MENU_1ST_BITE;	// ��Ϊ�����Լ����ID
	#endif
	// test
	g_u8CurMenuID = MENU_1ST_BITE;	// ��Ϊ�����Լ����ID
	g_u8PowerOnOffTick = 0;		// ��ʼ���㿪��ʱ��

}

/*********************************************************
*��������DispFuncKey_Param
*����  ����ʾ����ҳ���ܼ���־
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispFuncKey_Param(void)
{
    PrintString(WIDTH_HALF, ROW_TEXT01,  "F1-����", WORD);
    PrintString(COL_WORD5,  ROW_TEXT01,  "F2-��·", WORD);
    PrintString(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-���", WORD);
    PrintString(COL_WORD14, ROW_TEXT01,   "F4-ϵͳ", WORD);
}

/*********************************************************
*��������DispParamWorkState
*����  ����ʾ����״̬����ҳ����(��ʾȫ������)
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispParamWorkState(void)
{
	if((g_u8CurMenuID != MENU_1ST_BITE)&&(g_u8CurMenuID != MENU_PARAMLINKQUERY))
	{
		/************* ��ʾ�ŵ�����*************/
		DispChannelNum(0);                       // ��ʾ�ŵ���
		DispWorkMode(0);		                // ��ʾ����ģʽ

		
		if(t_CurChannelState.WorkMode%2 == 1)	// ��Ƶģʽ
		{
			if(g_u8CurMenuItem == INDEX_EDIT_FREQ_TAB)
			{
				PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "Ƶ��", WORD);
			}
			else
			{
				PrintString(WIDTH_HALF, ROW_TEXT04, "Ƶ��", WORD);
			}
			DispFrequency(0);
		}
		else    // ����: �������
		{
			if(g_u8CurMenuItem == INDEX_EDIT_FREQ_TAB)
			{
				PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "����", WORD);
			}
			else
			{
				PrintString(WIDTH_HALF, ROW_TEXT04, "����", WORD);
			}
			DispTableNum(0);		// ��ʾ���
			DispNetNum(0);          // ��ʾ����
		}
		//SelectStation = MainStation;SubStation
		DispRadioRank(0);           // ��ʾ�ȼ�


		/************* ��ʾ��̨����**********/
		DispRadioPower(0);          // ����
		//DispMacAddr(0);             // վ��
		//DispMacAddr1(0);             // վ��
		// test
		//DispMacAddr2(0);             // վ��
		//if(ReportMac == YES)
		{
			//ReportMac = NO; 
			//DispMacAddr2(0);  // test
		}
		//else
		{
			//DispMacNum(0);   // վ��
		}	
		// test
		DispMacAddr2(0);   // վ��
		}
}

/*********************************************************
*��������DispMenuText_PageF1
*����  ����ʾF1����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_PageF1(void)
{
 	g_u8CurMenuID   = MENU_SET_F1;
	DispText_PageF1();
	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-����", WORD);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�-�����ּ�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_PageF2
*����  ����ʾF2����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_PageF2(void)
{
 	g_u8CurMenuID   = MENU_SET_F2;

	DispText_PageF2();
	DispFuncKey_Param();
	
    PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-��·", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�-�����ּ�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_PageF3
*����  ����ʾF3����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_PageF3(void)
{
 	g_u8CurMenuID   = MENU_SET_F3;
	DispText_PageF3();
	DispFuncKey_Param();
    PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-���", WORD);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>ѡ��˵�-�����ּ�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_PageF4
*����  ����ʾF4����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_PageF4(void)
{
 	g_u8CurMenuID   = MENU_SET_F4;
	DispText_PageF4();
	DispFuncKey_Param();
    PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-ϵͳ", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>ѡ��˵�-�����ּ�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamRadioIp
*����  ����ʾ��̨IP����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamRadioIp(void)
{
    g_u8CurMenuID = MENU_PARAMRADIOIP;
	memcpy(&t_EditRadioState.Service_IP[0], &t_CurRadioState.Service_IP[0], 4); // ���Ǹ���
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-����", WORD);
	
    PrintString(COL_WORD1, ROW_TEXT02, "1-��̨IP", WORD);
	PrintString(COL_WORD5, ROW_TEXT04, "��ǰ: 192.168.001.001", WORD);
    PrintString(COL_WORD5, ROW_TEXT05, "����: ", WORD);
	Query_ServiceIp();
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע:�����ּ��������-��<ȡ��>�������� ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT10, "   ��<ȷ��>ȷ������-��<F1-F4>�����˵�", WORD); 
}

/*********************************************************
*��������DispMenuText_ParamRadioMask
*����  ����ʾ��̨�������ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamRadioMask(void)
{
    g_u8CurMenuID    = MENU_PARAMRADIOMASK;
	g_u8MaskZeroFlag = NO;
	memcpy(&t_EditRadioState.Service_MASK[0], &t_CurRadioState.Service_MASK[0], 4);
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-����", WORD);

    PrintString(COL_WORD1, ROW_TEXT02, "2-��̨����", WORD);
    PrintString(COL_WORD5, ROW_TEXT04, "��ǰ: 255.255.255.000", WORD);
	PrintString(COL_WORD5, ROW_TEXT05, "����: ", WORD);
	Query_ServiceMask();

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: �����ּ��������-��<ȡ��>�������� ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<ȷ��>ȷ�ϸ���-��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamFactorySet
*����  ����ʾ�ָ��������ò���ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamFactorySet(void)
{
    g_u8CurMenuID = MENU_PARAMFACTORYSET;
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-����", WORD);
    PrintString(COL_WORD1, ROW_TEXT02,  "3-�ָ���������", WORD);
	PrintString(COL_WORD5, ROW_TEXT05,  "�Ƿ�ȷ���ָ���������? ", WORD);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<ȷ��>ȷ���ָ�-��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_F1_F1EntFactorySet
*����  ����ʾȷ���ָ��������ò���ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
/*
void DispMenuText_ParamEntFactorySet(void)
{
    g_u8CurMenuID = MENU_PARAMENTFACTORYSET;
	LCD_Clear(TOP);
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-����", WORD);

    PrintString(COL_WORD1, ROW_TEXT02,  "3-�ָ���������", WORD);
	PrintString(COL_WORD7, ROW_TEXT05,  "���ڻָ�...   ", WORD);
	Set_DefaultParam();

	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F6>������һ���˵�", WORD);
}
*/

/*********************************************************
*��������DispMenuText_ParamLinkBuild
*����  ����ʾ��·��������ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamLinkBuild(void)
{	
    g_u8CurMenuID = MENU_PARAMLINKBUILD;
	g_u8CurMenuItem = 1;
	//memcpy(&t_EditLinkInfo[0],&t_CurLinkInfo[0],sizeof(t_CurLinkInfo[0]));
	PrintHorizonLine(0,143,0xFF,40);
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-��·", WORD); // ����
    PrintString(COL_WORD1, ROW_TEXT02,  "1-��·����", WORD);
    PrintString(COL_WORD1, ROW_TEXT03,  "ѡ��վ��: ", WORD);
	PrintSubWindow_LinkBuild();
	
    PrintString(COL_WORD1, ROW_TEXT06,  "ѡ�����: ����", WORD);
	PrintStringReverse(COL_WORD6,ROW_TEXT06,"����",4);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<��/��/F5>ѡվ��-��<��/��>ѡ����", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<ȷ��>ȷ������-��<F1-F4>�����˵�", WORD);
	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		DispMac();  // ��ʾ��·�����µ�Mac��
	}
	DispItemReverse_ParamLinkBuild(); //����
}

/*********************************************************
*��������DispMenuText_ParamLinkMaintain
*����  ����ʾ��·ά������ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamLinkMaintain(void)
{
    g_u8CurMenuID = MENU_PARAMLINKMAINTAIN;
	g_u8CurMenuItem = 1; 
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-��·", WORD);
    PrintString(COL_WORD1, ROW_TEXT02,  "2-��·ά��", WORD);
	PrintSubWindow_LinkMaintain();
	PrintString(COL_WORD2, ROW_TEXT03, "վ��", WORD);
	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT03, "ά�����", WORD);
	PrintString(COL_WORD11, ROW_TEXT03, "վ��", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "ά�����", WORD);

	DispMac();
	DispItemReverse_ParamLinkMaintain(); //����
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: �������ѡ��վ��-��0 3ѡ��ά�����", WORD);
	PrintOneChar(COL_WORD12+WIDTH_HALF, ROW_TEXT09, Logo_connect);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<ȷ��>ȷ������-��<F1-F4>�����˵�", WORD);

	DispLinkMaintainGap();   // ��ʾά�����(һ������ʾ)
	Query_LinkMaintainGap(); // ��ѯ��·ά�����
}

/*********************************************************
*��������DispMenuText_ParamLinkQuery
*����  ����ʾ��·��ѯ����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamLinkQuery(void)
{
	g_u8CurMenuID = MENU_PARAMLINKQUERY;
  	DispFuncKey_Param();
	// test 20151230
	PrintSubWindow_LinkQuery_Test();
	//PrintSubWindow_LinkQuery();
	PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-��·", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT02,  "3-��·��ѯ", WORD);
//	memcpy(&t_EditLinkInfo[0],&t_CurLinkInfo[0],sizeof(t_CurLinkInfo[0]));

	PrintString(COL_WORD1,ROW_TEXT04,"վ��",WORD);
	PrintString(COL_WORD1,ROW_TEXT05,"����",WORD);
	PrintString(COL_WORD1,ROW_TEXT06,"����",WORD);

	// Report_LinkInfo(void);
	// Report_LinkMaintainGap(void)
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�", WORD);	

	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		// test 20151229
		//DispMac();
		//DispLinkQuantity(0);  // ��ʾ��·����
		Query_LinkQuality();
	}
}

/*********************************************************
*��������DispMenuText_ParamWorkState
*����  ����ʾ����״̬����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamWorkState(void)
{
    g_u8CurMenuID = MENU_PARAMWORKSTATE;
	PrintMainWindow();
	PrintHorizonLine(0,47,0xFF,40);// 95-23 = 72
	g_u8CurMenuItem = 1;
	
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
 
	if(SelectStation == SubStation)  //ѡ������״̬
	{
		PrintVerticalLine(20,48,0x80,143); //191-48=143,��վ
	} 
	else
	{
		PrintVerticalLine(20,48,0x80,23); //191-48=143,��վ
	}
	
	PrintHorizonLine(0,71,0xFF,40);// 95-23 = 72
	memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState)); // �ŵ�����
   	t_EditRadioState.Power = t_CurRadioState.Power;    // ����
	t_EditRadioState.MAC   = t_CurRadioState.MAC;      // վ��
	t_EditRadioState.Rank  = t_CurRadioState.Rank;     // �ȼ�
	
	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01, "F3-���", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT02, "1-����״̬", WORD);
	PrintString(COL_WORD11, ROW_TEXT02, "15/09/23 00:00:00", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT03,  "��������: ", WORD);
	
	if(t_CurChannelState.WorkMode%2 == 1)   // ��Ƶģʽ[35]
    {
        PrintString(WIDTH_HALF, ROW_TEXT04, "Ƶ��: ", WORD);
    }
    else                                    // ��Ƶģʽ[46]
    {
        PrintString(WIDTH_HALF, ROW_TEXT04, "����: ", WORD);
    } 
	
    PrintString(WIDTH_HALF, ROW_TEXT05, "ģʽ: ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT06, "�ȼ�: ", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT07, "����: ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT08, "վ��: ", WORD);
	PrintString(COL_WORD5,  ROW_TEXT08, "�ŵ�: ", WORD);
	
	PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "Ƶ��", WORD);

	if(SelectStation == SubStation)  //ѡ������״̬
	{
		PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT03, "��·״̬:   ", WORD);
		// test 20151229
		PrintSubWindow_SubWorkState();
		PrintString(COL_WORD11, ROW_TEXT04, "վ��", WORD);
   		PrintString(COL_WORD15, ROW_TEXT04, "SNR ", WORD);
		//PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "����:     ", WORD);
   		//PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT06, "��·����: ", WORD);
   		
   		// test
		// 0x0382��ͬ���Ļ�����ʾ SyncState
		if(t_CurRadioState.SyncState != 0x00) // ͬ��
		{
			DispMac();            // ��ʾMac
			DispIntensityLogo();  // ��ʾ��ǿLogo
		}
	}
	else
	{
		PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT03, "��·״̬:   ", WORD);
		PrintSubWindow_WorkState();
		// test
		// 0x0382��ͬ���Ļ�����ʾ SyncState
		if(t_CurRadioState.SyncState != 0x00) // ͬ��
		{
			DispMac();            // ��ʾMac
			DispIntensityLogo();  // ��ʾ��ǿLogo
		}
	}
	
	// ��̨״̬�Ͳ���״̬����������ʾ����
	// test
	if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{		
		DispParamWorkState();  // ����״̬����
		
		Query_ChanParam();    //  �ŵ�����
		Delay_nMS(20);
		Query_RadioPower();   //  ��ѯ��̨����
		Delay_nMS(20);
		Query_RadioMac();     //  ��ѯ��̨MAC:վ��
		Delay_nMS(20);
		Query_RadioRank();   //  ��ѯ��̨�ȼ�
		 
		if(SelectStation == SubStation)
		{	
			//Delay_nMS(40);
			//Query_LinkQuality();  //  ��ѯ��·����		
		}
		//��ǿ�Զ��ϱ�
	}
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<��/��>ѡ�����-��<ȷ��>����༭", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F5>��ҳ-��<F1-F4>�����˵�      ", WORD);
}

/*********************************************************
*��������DispMenuText_ParamDigTranStatis
*����  ����ʾ����ͳ�Ʋ���ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamDigTranStatis(void)
{
    g_u8CurMenuID = MENU_PARAMDIGTRANSTATIS;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-���", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "2-����ͳ��", WORD);
	PrintSubWindow_DigTranOpert();
	
	PrintString(COL_WORD1, ROW_TEXT03,  "վ��", WORD);
	PrintString(COL_WORD4, ROW_TEXT03,  "����֡", WORD);
	PrintString(COL_WORD8, ROW_TEXT03,  "����֡", WORD);
	PrintString(COL_WORD12, ROW_TEXT03, "����֡", WORD);
	PrintString(COL_WORD16, ROW_TEXT03, "����֡", WORD);
	//DispDigTranInfo_Mac();
	
	//DispMac();
	// test
	if(SelectPage == PageOne)
	{	
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(1/2)", WORD);
	}
	else
	{	
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(2/2)", WORD);
	}
	// test
	//Report_DigTranStatis();
	
	#if 0
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT04, "00", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT05, "03", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT06, "04", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT07, "07", WORD);
	#endif
	// test 20151230
	PrintString(WIDTH_HALF, ROW_TEXT08, "����Mac��:  ", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F5>��ҳ,��<ȷ��>����շ�����", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F1-F4>�����˵�", WORD);

	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		Query_DigTranStatis();
	}
}

/*********************************************************
*��������DispMenuText_ParamDigTranReport
*����  ����ʾ�����㱨����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamDigTranReport(void)
{
    g_u8CurMenuID = MENU_PARAMDIGTRANREPORT;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-���", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "3-�����㱨", WORD);
	PrintSubWindow_DigTranOpert();
	
	PrintString(COL_WORD1, ROW_TEXT03,  "վ��", WORD);
	PrintString(COL_WORD4, ROW_TEXT03,  "����֡", WORD);
	PrintString(COL_WORD8, ROW_TEXT03,  "����֡", WORD);
	PrintString(COL_WORD12, ROW_TEXT03, "����֡", WORD);
	PrintString(COL_WORD16, ROW_TEXT03, "����֡", WORD);
	//DispDigTranInfo_Mac();
	//DispMac();
	
	// test
	if(SelectPage == PageOne)
	{	
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(1/2)", WORD);
	}
	else
	{	
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(2/2)", WORD);
	}
	// test
	
	//Report_DigTranStatis();
	
	PrintString(WIDTH_HALF, ROW_TEXT08, "����Mac��:  ", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F5>��ҳ,��<ȷ��>����շ�����", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F1-F4>�����˵�", WORD);

	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		Query_DigTranReport();
	}
}

/*********************************************************
*��������DispMenuText_ParamDebugInfo
*����  ����ʾ������Ϣ����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamDebugInfo(void)
{
    g_u8CurMenuID = MENU_PARAMDEBUGINFO;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-���", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "4-������Ϣ", WORD);

	PrintString(COL_WORD1+WIDTH_HALF, ROW_TEXT03, "���ʼ��", WORD);

	Query_DebugInfo();  
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamRunTime
*����  ����ʾ����ʱ�����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamRunTime(void)
{
    g_u8CurMenuID = MENU_PARAMRUNTIME;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-���", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "5-����ʱ��", WORD);
	PrintString(COL_WORD5, ROW_TEXT05,  "������ʱ��: 0027Сʱ47��", WORD);
	PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT06,  "��������ʱ��:  00Сʱ00��00��", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamDateTime
*����  ����ʾ����ʱ�����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamDateTime(void)
{
    g_u8CurMenuID = MENU_PARAMDATETIME;
	g_u8ParamEditIndex = 0;
	g_u8ParamEditState = OFF;
	g_u8CurMenuItem = 1;
	memcpy(&t_EditTime, &t_CurTime, sizeof(t_CurTime));
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-ϵͳ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "1-����ʱ��", WORD);
	PrintString(COL_WORD5, ROW_TEXT05,  "����: 15/09/02", WORD);
	PrintString(COL_WORD5, ROW_TEXT06,  "ʱ��: 00:00:00", WORD);

	DispItemReverse_ParamDateTime();
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<��/��>ѡ�����-��<ȷ��>����༭", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F1-F4>�����˵�                 ", WORD);
}

/*********************************************************
*��������DispMenuText_ParamRadioTest
*����  ����ʾ��̨�Լ����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamRadioTest(void)
{
    g_u8CurMenuID = MENU_PARAMRADIOTEST;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-ϵͳ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02, "2-��̨�Լ�", WORD);
	#if 0
    PrintString(COL_WORD2, ROW_TEXT03,  "����ģ��:...", WORD);
    PrintString(COL_WORD2, ROW_TEXT04,  "ֱ��ģ��:...", WORD);
    PrintString(COL_WORD2, ROW_TEXT05,  "Ƶ�ϵ�Ԫ:...", WORD);
    PrintString(COL_WORD2, ROW_TEXT06,  "�ŵ���Ԫ:...", WORD);
	PrintString(COL_WORD2, ROW_TEXT07,  "����ģ��:...", WORD);
    PrintString(COL_WORD10, ROW_TEXT03, "���ģ��:...", WORD);
    PrintString(COL_WORD10, ROW_TEXT04, "����ģ��:...", WORD);
	PrintString(COL_WORD10, ROW_TEXT05, "4���ź�:...", WORD);
	#endif
	// test 20151229
	PrintString(COL_WORD2, ROW_TEXT03,  "����ģ��: ��", WORD);
    PrintString(COL_WORD2, ROW_TEXT04,  "ֱ��ģ��: ��", WORD);
    PrintString(COL_WORD2, ROW_TEXT05,  "Ƶ�ϵ�Ԫ: ��", WORD);
    PrintString(COL_WORD2, ROW_TEXT06,  "�ŵ���Ԫ: ��", WORD);
	PrintString(COL_WORD2, ROW_TEXT07,  "����ģ��: ��", WORD);
    PrintString(COL_WORD10, ROW_TEXT03, "���ģ��: ��", WORD);
    PrintString(COL_WORD10, ROW_TEXT04, "����ģ��: ��", WORD);
	PrintString(COL_WORD10, ROW_TEXT05, "4���ź�:  ��", WORD);
	// test 20151229
    //PrintString(COL_WORD10, ROW_TEXT05, "����ģ��:...", WORD);
	//Set_RadioTest();

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamPowerCheck
*����  ����ʾ���ʼ�����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamPowerCheck(void)
{
    g_u8CurMenuID = MENU_PARAMPOWERCHECK;
	g_u8ParamEditState = NO;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-ϵͳ", WORD);
    PrintString(COL_WORD1, ROW_TEXT02,  "3-���ʼ��", WORD);
	PrintString(COL_WORD3, ROW_TEXT05,  "��ȷ�����߿������Ӹ��ػ�����!", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<ȷ��>��ʼ��� ", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamUnlightOnOff
*����  ����ʾ���⿪�ز���ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamUnlightOnOff(void)
{
    g_u8CurMenuID = MENU_PARAMUNLIGHTONOFF;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-ϵͳ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "4-����״̬", WORD);
	PrintString(COL_WORD4, ROW_TEXT04,  "0-�����", WORD);
	PrintString(COL_WORD4, ROW_TEXT05,  "1-���⿪", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��0 1ѡ�񱳹�״̬ ", WORD);
	PrintOneChar(COL_WORD4,ROW_TEXT09,Logo_connect);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispMenuText_ParamVersionInfo
*����  ����ʾ�汾��Ϣ����ҳ�˵�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMenuText_ParamVersionInfo(void)
{
	//uint8_t i = 0;
	//uint8_t u8_Code[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};
    g_u8CurMenuID = MENU_PARAMVERSIONINFO;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,	 "F4-ϵͳ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "5-�汾��Ϣ", WORD);
	PrintSubWindow_VersionInfo();
	PrintString(COL_WORD2+WIDTH_HALF,  ROW_TEXT03, "��Ԫ", WORD);
	PrintString(COL_WORD6+WIDTH_HALF,  ROW_TEXT03, "�汾", WORD);
	PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT03, "��Ԫ", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "�汾", WORD);

	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT04,  "���", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT05,  "����", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT06,  "�ź�", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT07,  "ģ��", WORD);

	PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT04,  "�ŵ�", WORD);
	PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05,  "����", WORD);

	// ��ʾ
	PrintString(COL_WORD6+WIDTH_HALF,	ROW_TEXT04,  "V1.0", WORD);
	PrintString(COL_WORD6+WIDTH_HALF,	ROW_TEXT05,  "V1.0", WORD);
	PrintString(COL_WORD6+WIDTH_HALF,	ROW_TEXT06,  "V1.0", WORD);
	PrintString(COL_WORD6+WIDTH_HALF,	ROW_TEXT07,  "V1.0", WORD);
	PrintString(COL_WORD14+WIDTH_HALF,	ROW_TEXT04,  "V1.0", WORD);
	PrintString(COL_WORD14+WIDTH_HALF,	ROW_TEXT05,  "V1.0", WORD);

	PrintString(COL_WORD10+WIDTH_HALF,	ROW_TEXT06,  "xx  ", WORD);
	PrintString(COL_WORD10+WIDTH_HALF,	ROW_TEXT07,  "xx  ", WORD);
	PrintString(COL_WORD14+WIDTH_HALF,	ROW_TEXT06,  "xx  ", WORD);
	PrintString(COL_WORD14+WIDTH_HALF,	ROW_TEXT07,  "xx  ", WORD);

	// test 20151229
	#if 0
	for(i=0;i<4;i++)
	{
		PrintString(COL_WORD6+WIDTH_HALF,   u8_Code[i],  "V1.0", WORD);
		PrintString(COL_WORD10+WIDTH_HALF,  u8_Code[i],  "xx  ", WORD);
		PrintString(COL_WORD14+WIDTH_HALF,  u8_Code[i],  "V1.0", WORD);
	}
	#endif
	
	// test 20151229
	//Query_SoftVersion();
	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�", WORD);
}

#define  IsCurMenu_ItemOption(MenuId)    () 
/*((MenuId == MENU_OPRT)         || (MenuId == MENU_SUPERIOR) \
                                       || (MenuId == MENU_RADIOPARAM) || (MenuId == MENU_SECURE) \
                                       || (MenuId == MENU_FACTORY)    || (MenuId == MENU_NETPARAM)\
                                       || (MenuId == MENU_ALL_NETPARAM))*/
#define  IsCurMenu_ParamOption(MenuId)   (MenuId == MENU_PARAMDATETIME) 
/*((MenuId == MENU_PARAM1)          || (MenuId == MENU_PARAM3) \
                                       || (MenuId == MENU_SECURE_CONFIG) || (MenuId == MENU_WB_NOISE)\
                                       || (MenuId == MENU_LOCAL)         || (MenuId == MENU_SERVICE_IP)\
                                       || (MenuId == MENU_MANAGE_IP)     || (MenuId == MENU_INC_IP))*/

/*********************************************************
*��������DispItemReverse
*����  ������ҳѡ����ʾ������ʾ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse(void)
{
	switch(g_u8CurMenuID)
	{
		case MENU_PARAMWORKSTATE:
			DispItemReverse_ParamWorkState();
			break;

   		case MENU_PARAMDATETIME:
        	DispItemReverse_ParamDateTime();
        	break;

		case MENU_PARAMLINKBUILD:
			DispItemReverse_ParamLinkBuild();
			break;

		case MENU_PARAMLINKMAINTAIN:
	       // DispItemReverse_ParamLink();
	        DispItemReverse_ParamLinkMaintain();
	        break;

		/*case MENU_PARAMUNLIGHTONOFF:
	        DispItemReverse_ParamUnlightOnOff();
	        break;*/

		default:
			break;
	}

}

/*********************************************************
*��������DispDateTimeReverse
*����  ����ʾ����ʱ�����������ʾ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispDateTimeReverse(uint8_t rev)
{
    if(g_u8ParamEditIndex == INDEX_EDIT_DATE)
    {
        DispDateNum(rev);
    }
    else if(g_u8ParamEditIndex == INDEX_EDIT_TIME)
    {
        DispTimeNum(rev);
    }
}

/*********************************************************
*��������DispWorkStateReverse
*����  ����ʾ����״̬����ҳ����������ʾ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispWorkStateReverse(uint8_t rev)
{
    switch(g_u8ParamEditIndex)
    {
        case INDEX_EDIT_WORKMODE:
            DispWorkMode(rev);
            break;
        
        case INDEX_EDIT_FREQ_TAB:
            if(t_CurChannelState.WorkMode%2 == 1)   // ��Ƶģʽ
            {
                DispFrequency(rev);
                break;
            }
            DispTableNum(rev);
            break;
       
        case INDEX_EDIT_RANK:
            DispRadioRank(rev);
            break;

        case INDEX_EDIT_POWER:
            DispRadioPower(rev);
            break;

		case INDEX_EDIT_MAC:
            DispMacNum(rev);
            break;

		case INDEX_EDIT_CHANNUM:
            DispChannelNum(rev);
            break;

        default:
            break;
    }
}

// test
void DispWorkStateReverse1(uint8_t rev)
{
    switch(g_u8ParamEditIndex)
    {
        case INDEX_EDIT_WORKMODE:
            DispWorkMode(rev);
            break;
        
        case INDEX_EDIT_FREQ_TAB:
            if(t_CurChannelState.WorkMode%2 == 1)   // ��Ƶģʽ
            {
                DispFrequency(rev);
                break;
            }
            DispTableNum(rev);
            break;
       
        case INDEX_EDIT_RANK:
            DispRadioRank(rev);
            break;

        case INDEX_EDIT_POWER:
            DispRadioPower(rev);
            break;

		case INDEX_EDIT_MAC:
            DispMacAddr2(rev);
            break;

		case INDEX_EDIT_CHANNUM:
            DispChannelNum(rev);
            break;

        default:
            break;
    }
}

/*********************************************************
*��������DispItemRecover
*����  �����Թ���״̬�˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover(void)
{
    switch(g_u8CurMenuID)
    {
		case MENU_PARAMWORKSTATE:
    	 	DispItemRecover_ParamWorkState();
   			break;

	    case MENU_PARAMDATETIME:
	        DispItemRecover_ParamDateTime();
	        break;

		case MENU_PARAMLINKBUILD:
			DispItemRecover_ParamLinkBuild();
			break;

		case MENU_PARAMLINKMAINTAIN:
	        //DispItemRecover_ParamLink();
	        DispItemRecover_ParamLinkMaintain();
	        break;

		/* case MENU_PARAMUNLIGHTONOFF:
	        DispItemRecover_ParamUnlightOnOff();
	        break;*/
			
		default:
			break;
	}
}

/*********************************************************
*��������DispItemRecover_ParamLinkBuild
*����  ��������·�����˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamLinkBuild(void)
{
    switch(g_u8EditMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintString(COL_WORD2, ROW_TEXT04,&g_u8DispBuf_Mac[0], 2);
            break;

        case INDEX_EDIT_MAC02:
            PrintString(COL_WORD4, ROW_TEXT04,&g_u8DispBuf_Mac[2], 2);
            break;

		case INDEX_EDIT_MAC03:
            PrintString(COL_WORD6, ROW_TEXT04,&g_u8DispBuf_Mac[4], 2);
            break;

        case INDEX_EDIT_MAC04:
            PrintString(COL_WORD8, ROW_TEXT04,&g_u8DispBuf_Mac[6], 2);
            break;

		case INDEX_EDIT_MAC05:
            PrintString(COL_WORD10, ROW_TEXT04,&g_u8DispBuf_Mac[8], 2);
            break;

        case INDEX_EDIT_MAC06:
            PrintString(COL_WORD12, ROW_TEXT04,&g_u8DispBuf_Mac[10], 2);
            break;

		case INDEX_EDIT_MAC07:
            PrintString(COL_WORD14, ROW_TEXT04,&g_u8DispBuf_Mac[12], 2);
            break;

        case INDEX_EDIT_MAC08:
            PrintString(COL_WORD16, ROW_TEXT04,&g_u8DispBuf_Mac[14], 2);
            break;

        default:
            break;
	}
}

/*********************************************************
*��������DispItemRecover_ParamLinkMaintain
*����  ��������·ά��ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamLinkMaintain(void)
{
    switch(g_u8EditMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT04,&g_u8DispBuf_Mac[0], 2);
            break;

        case INDEX_EDIT_MAC02:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT05,&g_u8DispBuf_Mac[2], 2);
            break;

		case INDEX_EDIT_MAC03:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT06,&g_u8DispBuf_Mac[4], 2);
            break;

        case INDEX_EDIT_MAC04:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT07,&g_u8DispBuf_Mac[6], 2);
            break;
		
		case INDEX_EDIT_MAC05:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT04,&g_u8DispBuf_Mac[8], 2);
            break;

        case INDEX_EDIT_MAC06:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT05,&g_u8DispBuf_Mac[10], 2);
            break;

		case INDEX_EDIT_MAC07:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT06,&g_u8DispBuf_Mac[12], 2);
            break;

        case INDEX_EDIT_MAC08:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT07,&g_u8DispBuf_Mac[14], 2);
            break;

        default:
            break;
	}
}

/*********************************************************
*��������DispItemRecover_ParamLink
*����  ��������·�˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamLink(void)
{
    switch(g_u8EditMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT04,&t_CurLinkInfo[0].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC02:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT05,&t_CurLinkInfo[1].MacNum, WORD);
            break;

		case INDEX_EDIT_MAC03:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT06,&t_CurLinkInfo[2].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC04:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT07,&t_CurLinkInfo[3].MacNum, WORD);
            break;

		case INDEX_EDIT_MAC05:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT04,&t_CurLinkInfo[4].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC06:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT05,&t_CurLinkInfo[5].MacNum, WORD);
            break;

		case INDEX_EDIT_MAC07:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT06,&t_CurLinkInfo[6].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC08:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT07,&t_CurLinkInfo[7].MacNum, WORD);
            break;

        default:
            break;
	}
}

#if 0
/*********************************************************
*��������DispItemRecover_ParamLinkMaintain
*����  ��������·ά���˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamLinkMaintain(void)
{
    switch(g_u8EditMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT04,  "00", WORD);
            break;

        case INDEX_EDIT_MAC02:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT05,  "03", WORD);
            break;

		case INDEX_EDIT_MAC03:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT06,  "04", WORD);
            break;

        case INDEX_EDIT_MAC04:
            PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT07,  "07", WORD);
            break;

		case INDEX_EDIT_MAC05:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT04,  "08", WORD);
            break;

        case INDEX_EDIT_MAC06:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT05,  "11", WORD);
            break;

		case INDEX_EDIT_MAC07:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT06,  "23", WORD);
            break;

        case INDEX_EDIT_MAC08:
            PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT07,  "24", WORD);
            break;

        default:
            break;
	}
}
#endif

/*********************************************************
*��������DispItemRecover_ParamWorkState
*����  �����Թ���״̬�˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamWorkState(void)
{
	switch(g_u8EditMenuItem)
	{
        case INDEX_EDIT_FREQ_TAB:
			if(t_CurChannelState.WorkMode%2 == 1)   // ��Ƶģʽ
	        {
	            PrintString(WIDTH_HALF, ROW_TEXT04, "Ƶ��", WORD);
	            break;
	        }
	        PrintString(WIDTH_HALF, ROW_TEXT04, "����", WORD);
	        break;
    
        case INDEX_EDIT_WORKMODE:
            PrintString(WIDTH_HALF, ROW_TEXT05, "ģʽ", WORD);
            break;
    
        case INDEX_EDIT_RANK:   // �ȼ�
            PrintString(WIDTH_HALF, ROW_TEXT06, "�ȼ�", WORD);
            break;
    
        case INDEX_EDIT_POWER:
            PrintString(WIDTH_HALF, ROW_TEXT07, "����", WORD);
            break;
    
        case INDEX_EDIT_MAC:   //վ��
            PrintString(WIDTH_HALF, ROW_TEXT08, "վ��", WORD);
            break;

		case INDEX_EDIT_CHANNUM:
            PrintString(COL_WORD5,  ROW_TEXT08, "�ŵ�", WORD);
            break;
    
        default:
            break;
    }
}

/*********************************************************
*��������DispItemRecover_ParamDateTime
*����  ����������ʱ��˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamDateTime(void)
{				
	switch(g_u8EditMenuItem)
	{
		case 1:
			PrintString(COL_WORD5, ROW_TEXT05,	"����", COL_WORD2+WIDTH_HALF);
			break;
	
		case 2:
			PrintString(COL_WORD5, ROW_TEXT06,	"ʱ��", COL_WORD2+WIDTH_HALF);
			break;
			
		default:
			break;
	}
}
#if 0
/*********************************************************
*��������DispItemRecover_ParamUnlightOnOff
*����  �����Ա��⿪�ز˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemRecover_ParamUnlightOnOff(void)
{
	switch(g_u8EditMenuItem)
	{
		case 1:
			PrintString(COL_WORD4, ROW_TEXT04,  "0", WORD);
			ClrGpioBit(LED_BAK_PIN);
			break;

		case 2:
			PrintString(COL_WORD4, ROW_TEXT05,  "1", WORD);
			ClrGpioBit(LED_BAK_PIN);
			break;

		default:
			break;
	}
}
#endif

/*********************************************************
*��������DispItemReverse_ParamLinkBuild
*����  ��������·�����˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamLinkBuild(void)
{
    switch(g_u8CurMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintStringReverse(COL_WORD2, ROW_TEXT04,&g_u8DispBuf_Mac[0], 2);
            break;

        case INDEX_EDIT_MAC02:
            PrintStringReverse(COL_WORD4, ROW_TEXT04,&g_u8DispBuf_Mac[2], 2);
            break;

		case INDEX_EDIT_MAC03:
            PrintStringReverse(COL_WORD6, ROW_TEXT04,&g_u8DispBuf_Mac[4], 2);
            break;

        case INDEX_EDIT_MAC04:
            PrintStringReverse(COL_WORD8, ROW_TEXT04,&g_u8DispBuf_Mac[6], 2);
            break;

		case INDEX_EDIT_MAC05:
            PrintStringReverse(COL_WORD10, ROW_TEXT04,&g_u8DispBuf_Mac[8], 2);
            break;

        case INDEX_EDIT_MAC06:
            PrintStringReverse(COL_WORD12, ROW_TEXT04,&g_u8DispBuf_Mac[10], 2);
            break;

		case INDEX_EDIT_MAC07:
            PrintStringReverse(COL_WORD14, ROW_TEXT04,&g_u8DispBuf_Mac[12], 2);
            break;

        case INDEX_EDIT_MAC08:
            PrintStringReverse(COL_WORD16, ROW_TEXT04,&g_u8DispBuf_Mac[14], 2);
            break;

        default:
            break;
	}
}

/*********************************************************
*��������DispItemReverse_ParamLinkMaintain
*����  ��������·ά��ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamLinkMaintain(void)
{
    switch(g_u8CurMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT04,&g_u8DispBuf_Mac[0], 2);
            break;

        case INDEX_EDIT_MAC02:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT05,&g_u8DispBuf_Mac[2], 2);
            break;

		case INDEX_EDIT_MAC03:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT06,&g_u8DispBuf_Mac[4], 2);
            break;

        case INDEX_EDIT_MAC04:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT07,&g_u8DispBuf_Mac[6], 2);
            break;

		case INDEX_EDIT_MAC05:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT04,&g_u8DispBuf_Mac[8], 2);
            break;

        case INDEX_EDIT_MAC06:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT05,&g_u8DispBuf_Mac[10], 2);
            break;

		case INDEX_EDIT_MAC07:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT06,&g_u8DispBuf_Mac[12], 2);
            break;

        case INDEX_EDIT_MAC08:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT07,&g_u8DispBuf_Mac[14], 2);
            break;
			
        default:
            break;
	}
}

/*********************************************************
*��������DispItemReverse_ParamLink
*����  ��������·�˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamLink(void)
{
    switch(g_u8EditMenuItem)
    {
        case INDEX_EDIT_MAC01:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT05,&g_u8DispBuf[0], 2);
            break;

        case INDEX_EDIT_MAC02:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT05,&t_CurLinkInfo[1].MacNum, WORD);
            break;

		case INDEX_EDIT_MAC03:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT06,&t_CurLinkInfo[2].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC04:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT07,&t_CurLinkInfo[3].MacNum, WORD);
            break;

		case INDEX_EDIT_MAC05:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT04,&t_CurLinkInfo[4].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC06:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT05,&t_CurLinkInfo[5].MacNum, WORD);
            break;

		case INDEX_EDIT_MAC07:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT06,&t_CurLinkInfo[6].MacNum, WORD);
            break;

        case INDEX_EDIT_MAC08:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT07,&t_CurLinkInfo[7].MacNum, WORD);
            break;
			
        default:
            break;
	}
}

#if 0
/*********************************************************
*��������DispItemReverse_ParamLinkMaintain
*����  ��������·ά��ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamLinkMaintain(void)
{
    switch(g_u8CurMenuItem)
    {
        case 1:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT04,  "00", WORD);
            break;

        case 2:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT05,  "03", WORD);
            break;

		case 3:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT06,  "04", WORD);
            break;

        case 4:
            PrintStringReverse(COL_WORD2+WIDTH_HALF, ROW_TEXT07,  "07", WORD);
            break;

		case 5:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT04,  "08", WORD);
            break;

        case 6:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT05,  "11", WORD);
            break;

		case 7:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT06,  "23", WORD);
            break;

        case 8:
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT07,  "24", WORD);
            break;
			
        default:
            break;
	}
}
#endif

/*********************************************************
*��������DispItemReverse_ParamWorkState
*����  �����Թ���״̬�˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamWorkState(void)
{				
	switch(g_u8CurMenuItem)
	 {	
        case INDEX_EDIT_FREQ_TAB:
			if(t_CurChannelState.WorkMode%2 == 1)   // ��Ƶģʽ
	        {
	            PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "Ƶ��", WORD);
	            break;
	        }
	        PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "����", WORD);
	        break;
    
        case INDEX_EDIT_WORKMODE:
            PrintStringReverse(WIDTH_HALF, ROW_TEXT05, "ģʽ", WORD);
            break;
    
        case INDEX_EDIT_RANK:   // �ȼ�
            PrintStringReverse(WIDTH_HALF, ROW_TEXT06, "�ȼ�", WORD);
            break;
    
        case INDEX_EDIT_POWER:
            PrintStringReverse(WIDTH_HALF, ROW_TEXT07, "����", WORD);
            break;
    
        case INDEX_EDIT_MAC: //վ��
            PrintStringReverse(WIDTH_HALF, ROW_TEXT08, "վ��", WORD);
            break;

		case INDEX_EDIT_CHANNUM:// �ŵ���
            PrintStringReverse(COL_WORD5,  ROW_TEXT08, "�ŵ�", WORD);
            break;
    
        default:
            break;
    }
}

/*********************************************************
*��������DispItemReverse_ParamDateTime
*����  ����������ʱ��˵�ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamDateTime(void)
{				
	switch(g_u8CurMenuItem)
	{
		case 1:
			PrintStringReverse(COL_WORD5, ROW_TEXT05,	"����", COL_WORD2+WIDTH_HALF);
			break;
	
		case 2:
			PrintStringReverse(COL_WORD5, ROW_TEXT06,	"ʱ��", COL_WORD2+WIDTH_HALF);
			break;
			
		default:
			break;
	}
}
#if 0
/*********************************************************
*��������DispItemReverse_ParamUnlightOnOff
*����  �����Ա��⿪��ҳѡ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemReverse_ParamUnlightOnOff(void)
{
    switch(g_u8CurMenuItem)
    {
        case 1:
            PrintStringReverse(COL_WORD4, ROW_TEXT04,  "0", WORD);
			ClrGpioBit(LED_BAK_PIN);
            break;

        case 2:
            PrintStringReverse(COL_WORD4, ROW_TEXT05,  "1", WORD);
			SetGpioBit(LED_BAK_PIN);
            break;

        default:
            break;
	}
}
#endif

/*********************************************************
*��������DispItemSelectResult
*����  ����ʾ�˵�ѡ��ѡ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispItemSelectResult(void)
{
	if(g_u8SelectItemOK == YES) 	// �л�ѡ��ɹ�  
	{
		g_u8SelectItemOK = NO;
		//DispItemRecover();		 // ������һ������ѡ��
		DispItemRecover();
		//DispItemReverse();		 // ���Ե�ǰѡ��
		DispItemReverse();
	}
}

/*********************************************************
*��������DispRealTimeWorkState
*����  ����ʾʵʱ����״̬
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRealTimeWorkState(void)
{
	//DispSNR();
	Rx_Tx_Led_Ctrl(t_CurRadioState.Indication);
	// ��ʾ״̬1����Ϣ
	//DispText_State1();
	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		// test
		// 0x0382��ͬ���Ļ�����ʾ SyncState
		if(t_CurRadioState.SyncState != 0x00) // ͬ��
		{
			// �����δ������ʾ����
			PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "      ", 3);
			// SNR=0		
			PrintString(COL_WORD15, ROW_TEXT05, "  ", 1);

			
			DispMac();            // ��ʾMac
			DispIntensityLogo();  // ��ʾ��ǿLogo
		}
		else
		{	
			if(SelectStation == SubStation)
			{
				// δ���������
				PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "        ", 4);
				PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "δͬ��", 6);
				// SNR=0		
				PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "        ", 4);
				PrintOneFont16x16(COL_WORD15, ROW_TEXT05, Logo_zeroState);
			}
		}
	}

	#if 0
	// ��ʾʵʱ����    
	if(t_CurRadioState.ParamState == YES)
	{
		DispRealTimeRate();
	}
	#endif
}

/*********************************************************
*��������DispRealTimeRate
*����  ����ʾʵʱ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRealTimeRate(void)
{
	DispRate(0);
}

/*********************************************************
*��������DispDateNum
*����  ����ʾ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispDateNum(uint8_t rev)
{
	uint8_t x = 0,y = 0;
	if(g_u8CurMenuID == MENU_PARAMDATETIME)
	{
		x = ROW_TEXT05;
		y = COL_WORD8;
	}
	else if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		x = ROW_TEXT02;
		y = COL_WORD11;
	}
	
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurTime.Year >> 4) + '0';
        g_u8DispBuf[1] = (t_CurTime.Year & 0x0F) + '0';
        g_u8DispBuf[2] = '/';
        g_u8DispBuf[3] = (t_CurTime.Month >> 4) + '0';
        g_u8DispBuf[4] = (t_CurTime.Month & 0x0F) + '0';
        g_u8DispBuf[5] = '/';
        g_u8DispBuf[6] = (t_CurTime.Day >> 4) + '0';
        g_u8DispBuf[7] = (t_CurTime.Day & 0x0F) + '0';
        
        PrintString(y, x, g_u8DispBuf, 8);
    }
    else if(rev == 1)
    {
        g_u8DispBuf[0] = (t_EditTime.Year >> 4) + '0';
        g_u8DispBuf[1] = (t_EditTime.Year & 0x0F) + '0';
        g_u8DispBuf[2] = (t_EditTime.Month >> 4) + '0';
        g_u8DispBuf[3] = (t_EditTime.Month & 0x0F) + '0';
        g_u8DispBuf[4] = (t_EditTime.Day >> 4) + '0';
        g_u8DispBuf[5] = (t_EditTime.Day & 0x0F) + '0';
	
        PrintStringReverse(y, x, g_u8DispBuf, 2);
        PrintStringReverse(y+3*WIDTH_HALF, x, &g_u8DispBuf[2], 2);
        PrintStringReverse(y+COL_WORD3,    x, &g_u8DispBuf[4], 2);
    }
}

/*********************************************************
*��������DispTimeNum
*����  ����ʾʱ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispTimeNum(uint8_t rev)
{
	uint8_t x = 0,y = 0;
	if(g_u8CurMenuID == MENU_PARAMDATETIME)
	{
		x = ROW_TEXT06;
		y = COL_WORD8;
	}
	else if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		x = ROW_TEXT02;
		y = COL_WORD15+WIDTH_HALF;
	}
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurTime.Hour >> 4) + '0';
        g_u8DispBuf[1] = (t_CurTime.Hour & 0x0F) + '0';
        g_u8DispBuf[2] = ':';
        g_u8DispBuf[3] = (t_CurTime.Minute >> 4) + '0';
        g_u8DispBuf[4] = (t_CurTime.Minute & 0x0F) + '0';
        g_u8DispBuf[5] = ':';
        g_u8DispBuf[6] = (t_CurTime.Second >> 4) + '0';
        g_u8DispBuf[7] = (t_CurTime.Second & 0x0F) + '0';
       
        PrintString(y, x, g_u8DispBuf, 8);
    }
    else if(rev == 1)
    {
        g_u8DispBuf[0] = (t_EditTime.Hour >> 4) + '0';
        g_u8DispBuf[1] = (t_EditTime.Hour & 0x0F) + '0';
        g_u8DispBuf[2] = (t_EditTime.Minute >> 4) + '0';
        g_u8DispBuf[3] = (t_EditTime.Minute & 0x0F) + '0';
        g_u8DispBuf[4] = (t_EditTime.Second >> 4) + '0';
        g_u8DispBuf[5] = (t_EditTime.Second & 0x0F) + '0';
        
        PrintStringReverse(y, x, g_u8DispBuf, 2);
        PrintStringReverse(y+3*WIDTH_HALF, x, &g_u8DispBuf[2], 2);
        PrintStringReverse(y+3*WIDTH_WORD, x, &g_u8DispBuf[4], 2);
    }
}

/*********************************************************
*��������DispTimeNum
*����  ����ʾ��������ʱ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRunTimeNum(void)
{
	uint8_t u8Hour = 0,u8Minute = 0;
	//t_SumRunTime.Minute = au8Code[0];//��ȡ����E2PROM��������ʱ��	
	//t_SumRunTime.Hour   = au8Code[1];
	t_SumRunTime.Hour   = t_SubRunTime.Hour   + t_SumRunTime.Hour;
	t_SumRunTime.Minute = t_SubRunTime.Minute + t_SumRunTime.Minute;
	if((t_SumRunTime.Minute) == 60)
	{
		(t_SumRunTime.Hour)++;
		t_SumRunTime.Minute = 0;
	}
	// ��ʾ��������ʱ��
	g_u8DispBuf[0] = (t_SubRunTime.Hour/10) + '0'; // ��λ
	g_u8DispBuf[1] = (t_SubRunTime.Hour%10) + '0'; // ��λ
	g_u8DispBuf[2] = (t_SubRunTime.Minute/10) + '0'; // ��λ
	g_u8DispBuf[3] = (t_SubRunTime.Minute%10) + '0'; // ��λ
	g_u8DispBuf[4] = (t_SubRunTime.Second/10) + '0'; // ��λ
	g_u8DispBuf[5] = (t_SubRunTime.Second%10) + '0'; // ��λ
	// ��ʾ������ʱ��
	g_u8DispBuf[6] = (t_SumRunTime.Hour/10) + '0'; // ��λ
	g_u8DispBuf[7] = (t_SumRunTime.Hour%10) + '0'; // ��λ
	g_u8DispBuf[8] = (t_SumRunTime.Minute/10) + '0'; // ��λ
	g_u8DispBuf[9] = (t_SumRunTime.Minute%10) + '0'; // ��λ
	
	PrintString(COL_WORD12, ROW_TEXT06,&g_u8DispBuf[0], 2);
	PrintString(COL_WORD15, ROW_TEXT06,&g_u8DispBuf[2], 2);
	PrintString(COL_WORD17, ROW_TEXT06,&g_u8DispBuf[4], 2);

	PrintString(COL_WORD12, ROW_TEXT05,&g_u8DispBuf[6], 2);
	PrintString(COL_WORD15, ROW_TEXT05,&g_u8DispBuf[8], 2);
}

/*********************************************************
*��������DispMacAddr
*����  ����ʾMAC��ַ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMacAddr(uint8_t rev)
{
	if(rev == 0)
	{   //Report_LinkInfo(void)
		g_u8DispBuf_Mac[0] = (t_CurLinkInfo[0].MacNum/10) + '0';
    	g_u8DispBuf_Mac[1] = (t_CurLinkInfo[0].MacNum%10) + '0';
		PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, g_u8DispBuf_Mac, 2);
	}
	else
	{
		g_u8DispBuf_Mac[0] = (t_CurLinkInfo[0].MacNum/10) + '0';
    	g_u8DispBuf_Mac[1] = (t_CurLinkInfo[0].MacNum%10) + '0';
		PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, g_u8DispBuf_Mac, 2);
	}
}

/*********************************************************
*��������DispMacAddr1
*����  ����ʾMAC��ַ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMacAddr1(uint8_t rev)
{
	if(rev == 0)
	{   //Report_LinkInfo(void)
		g_u8DispBuf[0] = ((t_CurRadioState.MAC >> 4) & 0x0F) + '0';
    	g_u8DispBuf[1] = ( t_CurRadioState.MAC & 0x0F) + '0';
		PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, "    ", 2);
		PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
	}
	else
	{
		g_u8DispBuf[0] = ((t_EditRadioState.MAC >> 4) & 0x0F) + '0';
    	g_u8DispBuf[1] = ( t_EditRadioState.MAC & 0x0F) + '0';
		PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, "    ", 2);
		PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
	}
}

//test
void DispMacAddr2(uint8_t rev)
{
	if(rev == 0)
	{   //Report_LinkInfo(void)
		g_u8DispBuf[0] = (t_CurRadioState.MAC/10) + '0';
    	g_u8DispBuf[1] = (t_CurRadioState.MAC%10) + '0';
		PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, "    ", 2);
		PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
	}
	else
	{
		g_u8DispBuf[0] = (t_EditRadioState.MAC/10) + '0';
    	g_u8DispBuf[1] = (t_EditRadioState.MAC%10) + '0';
		PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, "    ", 2);
		PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
	}
}

//test

/*********************************************************
*��������DispRadioTest
*����  ����ʾ��̨�Լ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRadioTest(void)
{
    uint8_t i = 0, j = 0;
	uint8_t u8Code = 0;
    uint8_t u8Count = 0;
    uint8_t *pu8Font;
    uint8_t x = COL_WORD10;
	Position_TypeDef tPosArray[8] = 
	{{MODULE_AC,       COL_WORD6+WIDTH_HALF, ROW_TEXT03},{MODULE_PANEL,      COL_WORD14+WIDTH_HALF, ROW_TEXT03},
	 {MODULE_DC,       COL_WORD6+WIDTH_HALF, ROW_TEXT04},{MODULE_MAIN_CTRL,  COL_WORD14+WIDTH_HALF, ROW_TEXT04},
	 {MODULE_FREQ_GEN, COL_WORD6+WIDTH_HALF, ROW_TEXT05},{MODULE_EXCHANGE,   COL_WORD14+WIDTH_HALF, ROW_TEXT05},
	 {MODULE_CHAN,     COL_WORD6+WIDTH_HALF, ROW_TEXT06},
	 {MODULE_POWER,    COL_WORD6+WIDTH_HALF, ROW_TEXT07}
	};
	
    PrintString(COL_WORD6+WIDTH_HALF, ROW_TEXT03,  "   ", 3);
    PrintString(COL_WORD6+WIDTH_HALF, ROW_TEXT04,  "   ", 3);
    PrintString(COL_WORD6+WIDTH_HALF, ROW_TEXT05,  "   ", 3);
    PrintString(COL_WORD6+WIDTH_HALF, ROW_TEXT06,  "   ", 3);
	PrintString(COL_WORD6+WIDTH_HALF, ROW_TEXT07,  "   ", 3);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "   ", 3);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT04, "   ", 3);
    PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "   ", 3);
	
    for(i=0; i<8; i++)
    {
    	if((g_u8SelftestState[0]>>i)&0x01)
    	{
    		pu8Font = "��";
		}
		else
		{
    		pu8Font = "��";
		}
		
		for(j=0; j<8; j++)
		{
			if(i == tPosArray[j].Pos_ID)
			{
				PrintString(tPosArray[j].Pos_x, tPosArray[j].Pos_y, pu8Font, 2);
				break;
			}
		}
    }
	//�����״̬
	if(g_u8SecureFlag == SECURE_NORMAL)
	{
		PrintString(COL_WORD10, ROW_TEXT07,"�����:��", WORD);
	}
	else if(g_u8SecureFlag != SECURE_EMPTY)
	{
		PrintString(COL_WORD10, ROW_TEXT07,"�����:��", WORD);
	}
	
	//  2/3/4�źŲ�λ״̬
	for(i=0; i<3; i++)
	{
		if(((g_u8SelftestState[1]>>i)&0x01) == 0)
		{
			if(u8Count > 0)
			{
				PrintString(x, ROW_TEXT06, "/", 1);
				x++;
			}
			u8Code = i+'2';
			PrintString(x, ROW_TEXT06, &u8Code, 1);
			x++;
			u8Count++;
		}
	}
	if(u8Count > 0)
	{
		PrintString(x, ROW_TEXT06, "���ź�:", 12);
		x += 7;
		for(i=0; i<u8Count; i++)
		{
			PrintString(x, ROW_TEXT06, "��", 2);
			x += 2;
			if(i != u8Count-1)
			{
				PrintString(x, ROW_TEXT06, "/", 1);
				x += 1;
			}
		}
	}
	else
	{
		PrintString(COL_WORD10, ROW_TEXT06, "�źŵ�Ԫ:��", 11);
	}

	PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵�", WORD);
}

/*********************************************************
*��������DispLinkBuildOprt
*����  ����ʾ��·��������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispLinkBuildOprt(void)
{
	uint8_t u8Index = 0,SelectState = LinkRemove;
	switch(g_u8CurMenuItem)
	{	
		case INDEX_EDIT_MAC01: 
			u8Index = INDEX_EDIT_MAC01;
			SelectState = SelectState01;
			DispLinkBuildState(SelectState,u8Index); // ����������
			SelectState01 = ~SelectState01;          // ��־λ
			g_u8LinkOprtState[0] = SelectState01;
			break;
			
		case INDEX_EDIT_MAC02:
			u8Index = INDEX_EDIT_MAC02;
			SelectState = SelectState02;
			DispLinkBuildState(SelectState,u8Index);
			SelectState02 = ~SelectState02;
			g_u8LinkOprtState[1] = SelectState02;
			break;

		case INDEX_EDIT_MAC03:
			u8Index = INDEX_EDIT_MAC03;
			SelectState = SelectState03;
			DispLinkBuildState(SelectState,u8Index);
			SelectState03 = ~SelectState03;
			g_u8LinkOprtState[2] = SelectState03;
			break;

		case INDEX_EDIT_MAC04:
			u8Index = INDEX_EDIT_MAC04;
			SelectState = SelectState04;
			DispLinkBuildState(SelectState,u8Index);
			SelectState04 = ~SelectState04;
			g_u8LinkOprtState[3] = SelectState04;
			break;

		case INDEX_EDIT_MAC05:
			u8Index = INDEX_EDIT_MAC05;
			SelectState = SelectState05;
			DispLinkBuildState(SelectState,u8Index);
			SelectState05 = ~SelectState05;	
			g_u8LinkOprtState[4] = SelectState05;
			break;

		case INDEX_EDIT_MAC06:
			u8Index = INDEX_EDIT_MAC06;
			SelectState = SelectState06;
			DispLinkBuildState(SelectState,u8Index);
			SelectState06 = ~SelectState06;
			g_u8LinkOprtState[5] = SelectState06;
			break;

		case INDEX_EDIT_MAC07:
			u8Index = INDEX_EDIT_MAC07;
			SelectState = SelectState07;
			DispLinkBuildState(SelectState,u8Index);
			SelectState07 = ~SelectState07;	
			g_u8LinkOprtState[6] = SelectState07;
			break;

		case INDEX_EDIT_MAC08:
			u8Index = INDEX_EDIT_MAC08;
			SelectState = SelectState08;
			DispLinkBuildState(SelectState,u8Index);
			SelectState08 = ~SelectState08;
			g_u8LinkOprtState[7] = SelectState08;
			break;

		default:
			break;
	}
}

/*********************************************************
*��������DispMac
*����  ��ͳ�ƽ������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispResult_StatisLinkBuild(void)
{
	uint8_t i = 0;	
	for(i=0;i<8;i++)
	{
		if(g_u8LinkOprtState[i] == LinkBuild) 
		{
			g_u8LinkBuildState[g_u8LinkBuildCount++] = i;
			t_EditLinkInfo[i].NetState = 1;
		}	
	}
}

/*********************************************************
*��������DispMac
*����  ����ʾMac��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMac(void)
{
	uint8_t i = 0,u8Col_Mac = 0,u8Col_State = 0;
	uint8_t u8Row_Mac[4] = {ROW_TEXT04, ROW_TEXT05, ROW_TEXT06, ROW_TEXT07};

	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		if(SelectStation == SubStation)  // ��վ
		{
			// test 20151229
			g_u8DispBuf[0] = (t_CurLinkQuanlity[0].MacNum/10) + '0';
	    	g_u8DispBuf[1] = (t_CurLinkQuanlity[0].MacNum%10) + '0';
			PrintString(COL_WORD11, ROW_TEXT05, "          ", 5);
			PrintString(COL_WORD11+WIDTH_HALF, ROW_TEXT05, g_u8DispBuf, 2);
		}
		else
		{
			#if 0
			for(i=0;i<8;i++)
			{
				if(i<5)
				{	
					u8Col_Mac = COL_WORD10  + i*COL_WORD2;
					PrintString(u8Col_Mac+WIDTH_HALF,ROW_TEXT04,&g_u8DispBuf_Mac[2*i],2);
				}
				else
				{	
					u8Col_Mac = COL_WORD10  + (i%5)*COL_WORD2;
					PrintString(u8Col_Mac+WIDTH_HALF,ROW_TEXT06,&g_u8DispBuf_Mac[2*i],2);	
				}	
			}
			#endif
			// test 20151229
			
			g_u8DispBuf[0] = (t_CurLinkQuanlity[0].MacNum/10) + '0';
	    	g_u8DispBuf[1] = (t_CurLinkQuanlity[0].MacNum%10) + '0';
			PrintString(COL_WORD10 + WIDTH_HALF, ROW_TEXT04, "    ", 2);
			PrintString(COL_WORD10 + WIDTH_HALF, ROW_TEXT04, g_u8DispBuf, 2);
			
			//DispMacAddr2(0);
		}
	}
	else if(g_u8CurMenuID == MENU_PARAMLINKBUILD)
	{	
		for(i=0;i<8;i++)
		{
			u8Col_Mac   = COL_WORD2  + i*COL_WORD2;
			u8Col_State = WIDTH_HALF + (i%4)*(COL_WORD5);
			PrintString(u8Col_Mac,ROW_TEXT04,&g_u8DispBuf_Mac[2*i],2); // ��ʾRow_Text04�е�Mac��
			if(i<4)
			{	
				PrintString(u8Col_State,ROW_TEXT07,&g_u8DispBuf_Mac[2*i],2); // ��ʾRow_Text07��Mac��
				DispLinkNetState(u8Col_State+COL_WORD1,ROW_TEXT07,i);	     // ��ʾRow_Text07������״̬
			}
			else
			{			
				PrintString(u8Col_State,ROW_TEXT08,&g_u8DispBuf_Mac[2*i],2);	
				DispLinkNetState(u8Col_State+COL_WORD1,ROW_TEXT08,i);
			}	
		}		
	}
	else if(g_u8CurMenuID == MENU_PARAMLINKMAINTAIN)
	{
		for(i=0;i<8;i++)
		{
			if(i<4)
			{	
				PrintString(COL_WORD2+WIDTH_HALF,u8Row_Mac[i],&g_u8DispBuf_Mac[2*i],2);
			}
			else
			{		
				PrintString(COL_WORD11+WIDTH_HALF,u8Row_Mac[i%4],&g_u8DispBuf_Mac[2*i],2);	
			}	
		}
	}
	else if(g_u8CurMenuID == MENU_PARAMLINKQUERY)
	{
		#if 0
		for(i=0;i<8;i++)
		{
			u8Col_Mac = COL_WORD4 + i*COL_WORD2;
			PrintString(u8Col_Mac,ROW_TEXT04,&g_u8DispBuf_Mac[2*i],2);
		}
		#endif
		
		// test 20151229
		g_u8DispBuf[0] = (t_ReportLinkQuan[0].MacNum[1]/10) + '0';
		g_u8DispBuf[1] = (t_ReportLinkQuan[0].MacNum[1]%10) + '0';
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT04, "    ", 2);
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT04, g_u8DispBuf, 2);
	}
	else if((g_u8CurMenuID == MENU_PARAMDIGTRANSTATIS) || (g_u8CurMenuID == MENU_PARAMDIGTRANREPORT))
	{
		if(SelectPage == PageOne)
		{	
			for(i=0;i<4;i++)
			{	
				PrintString(COL_WORD1+WIDTH_HALF, u8Row_Mac[i], "  ", 2);
				PrintString(COL_WORD1+WIDTH_HALF, u8Row_Mac[i], &g_u8DispBuf_Mac[2*i], 2);
			}	
			PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(1/2)", WORD);
		}
		else
		{
			for(i=0;i<4;i++)
			{
				PrintString(COL_WORD1+WIDTH_HALF, u8Row_Mac[i], "  ", 2);
				PrintString(COL_WORD1+WIDTH_HALF, u8Row_Mac[i], &g_u8DispBuf_Mac[2*(i+4)], 2);
			}
			PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(2/2)", WORD);
		}
	}
	else 
	{
		return;
	}
}

/*********************************************************
*��������DispIntensityLogo
*����  ����ʾ��ǿͼ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispIntensityLogo(void)
{
	uint8_t COL_X = 0,ROW_Y = 0;
	#if 0
	uint8_t i = 0,u8Inten[8] = {0};
	uint8_t x = 0,y = 0;
	for(i=0;i<8;i++)
	{
		u8Inten[i] = t_CurLinkInfo[i].Intensity;
		if(i<5)
		{
			x = i*COL_WORD2 + (COL_WORD10+WIDTH_HALF);
			y = ROW_TEXT05;
		}
		else
		{
			x = (i-5)*COL_WORD2 + (COL_WORD10+WIDTH_HALF);
			y = ROW_TEXT07;
		}
	
	    if(u8Inten[i] >= 128)
	    {
			u8Inten[i] &= 0x7F;
			if(u8Inten[i] < 70)
			{
				PrintOneFont16x16(x, y, Logo_intense5);
			}
			else if(u8Inten[i] < 80)
			{
				PrintOneFont16x16(x, y, Logo_intense4);
			}
			else if(u8Inten[i] < 90)
			{
				PrintOneFont16x16(x, y, Logo_intense3);
			}
			else if(u8Inten[i] < 100)
			{
				PrintOneFont16x16(x, y, Logo_intense2);
			}
			else if(u8Inten[i] < 110)
			{
				PrintOneFont16x16(x, y, Logo_intense1);
			}
			else
			{
				PrintOneFont16x16(x, y, Logo_intense0);
			}
	    }
	    else
	    {
			PrintOneFont16x16(x, y, Logo_intense5);
	    }
	}
	#endif
	if(SelectStation == SubStation)
	{
		COL_X = COL_WORD15;
		ROW_Y = ROW_TEXT05;
	}
	else
	{
		COL_X = COL_WORD10+WIDTH_HALF;
		ROW_Y = ROW_TEXT05;
	}

	PrintString(COL_X, ROW_TEXT06, "    ", 2);

	// test 20151229
	switch(t_CurLinkQuanlity[0].SNR)
	{
		case 0x00:			
			PrintOneFont16x16(COL_X, ROW_Y, Logo_zeroState);
			break;
			
		case 0x01:		
			PrintOneFont16x16(COL_X, ROW_Y, Logo_oneState);
			break;

		case 0x02:			
			PrintOneFont16x16(COL_X, ROW_Y, Logo_twoState);
			break;

		case 0x03:		
			PrintOneFont16x16(COL_X, ROW_Y, Logo_threeState);
			break;

		case 0x04:		
			PrintOneFont16x16(COL_X, ROW_Y, Logo_fourState);
			break;

		default:
			break;
	}
	#if 0
	PrintOneFont16x16(COL_WORD10+WIDTH_HALF, ROW_TEXT05, Logo_fourState);
	PrintOneFont16x16(COL_WORD12+WIDTH_HALF, ROW_TEXT05, Logo_threeState);
	PrintOneFont16x16(COL_WORD14+WIDTH_HALF, ROW_TEXT05, Logo_twoState);
	PrintOneFont16x16(COL_WORD16+WIDTH_HALF, ROW_TEXT05, Logo_zeroState);
	PrintOneFont16x16(COL_WORD18+WIDTH_HALF, ROW_TEXT05, Logo_twoState);
	PrintOneFont16x16(COL_WORD10+WIDTH_HALF, ROW_TEXT07, Logo_threeState);
	PrintOneFont16x16(COL_WORD12+WIDTH_HALF, ROW_TEXT07, Logo_twoState);
	PrintOneFont16x16(COL_WORD14+WIDTH_HALF, ROW_TEXT07, Logo_oneState);
	#endif
}

/*********************************************************
*��������DispLinkQuantity
*����  ����ʾ��·����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispLinkQuantity(uint8_t rev)
{
	uint8_t i = 0,Col_Quality = 0;
    if(rev == 0)
    {
		for(i=0;i<8;i++)
		{
			Col_Quality = COL_WORD4 +i*(COL_WORD2);
			g_u8DispBuf[2*i]   = (t_CurLinkInfo[i].Quality_Up   & 0x0f) + '0'; // ��λ�� 0����
			g_u8DispBuf[2*i+1] = (t_CurLinkInfo[i].Quality_Down & 0x0f) + '0'; 

			PrintString(Col_Quality, ROW_TEXT05, &g_u8DispBuf[2*i+0], 1);
			PrintString(Col_Quality, ROW_TEXT06, &g_u8DispBuf[2*i+1], 1);
		}
    }
    else
    {
 		for(i=0;i<8;i++)
		{
			Col_Quality = COL_WORD4 +i*(COL_WORD2);
			g_u8DispBuf[i]   = (t_CurLinkInfo[i].Quality_Up   & 0x0f) + '0'; // ��λ�� 0����
			g_u8DispBuf[i+1] = (t_CurLinkInfo[i].Quality_Down & 0x0f) + '0'; 

			PrintString(Col_Quality, ROW_TEXT05, &g_u8DispBuf[2*i+0], 1);
			PrintString(Col_Quality, ROW_TEXT06, &g_u8DispBuf[2*i+1], 1);
		}
    }
}

/*********************************************************
*��������DispLinkQuantity_Test
*����  ����ʾ��·����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
// test 20151229
void DispLinkQuantity_Test(uint8_t rev)
{
	//DispSNR(void);
	if(rev == 0) // ��ͬ��
	{
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT05, "	   ", 4);		// ��������
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT05, " �� ", 4);
		
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT06, "	   ", 4);		// ��������
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT06, " �� ", 4);
	}
	else
	{
		#if 0
		g_u8DispBuf[0] = (t_ReportLinkQuan[0].SNR/10) + '0';
		g_u8DispBuf[1] = (t_ReportLinkQuan[0].SNR%10) + '0';
		PrintString(COL_WORD4, ROW_TEXT05, "	", 2);		// ��������
		PrintString(COL_WORD4, ROW_TEXT05, g_u8DispBuf, 2);
		
		PrintString(COL_WORD4, ROW_TEXT06, "	", 2);		// ��������
		PrintString(COL_WORD4, ROW_TEXT06, g_u8DispBuf, 2);
		#endif
		PrintString(COL_WORD4, ROW_TEXT05, "	      ", 8);		// ��������
		PrintString(COL_WORD4, ROW_TEXT05, &g_u8DispBuf[2], 7);
		
		PrintString(COL_WORD4, ROW_TEXT06, "	      ", 8);		// ��������
		PrintString(COL_WORD4, ROW_TEXT06, &g_u8DispBuf[2], 7);
	}
}

/*********************************************************
*��������DispLinkMaintainGap
*����  ����ʾ��·ά�����(һ����ȫ��ʾ)
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispLinkMaintainGap(void)
{
	 uint8_t i = 0,x = 0,y = 0;
	 for(i=0;i<8;i++)
	 {
		 if(i < 4)
		 {
			 x = COL_WORD5;
			 y = ROW_TEXT04 + i*ROW_GAP;
		 }
		 else
		 {
			 x = COL_WORD14;
			 y = ROW_TEXT04 + (i-4)*ROW_GAP;
		 }
		 DispGap(x, y, t_CurLinkInfo[i].MaintainGap_ID, 0);
	 }
}

/*********************************************************
*��������ProcLinkBuildParamKey_UpDown
*����  ��������·��������ҳ�µ����ϡ����¼�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcLinkBuildParamKey_UpDown(void)
{   
    g_u8PreLinkOprtState = (g_u8PreLinkOprtState+1)%2;
    DispLinkOprtParamReverse();
}

/*********************************************************
*��������DispLinkOprtParamReverse
*����  ��������·��������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispLinkOprtParamReverse(void)
{
	if(g_u8PreLinkOprtState == LinkRemove)
	{
		PrintStringReverse(COL_WORD6, ROW_TEXT06,	"����", WORD);
	}
	else
	{	
		PrintStringReverse(COL_WORD6, ROW_TEXT06,	"����", WORD);
	}
}

/*********************************************************
*��������DispLinkBuildState
*����  ����ʾ��·����״̬
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispLinkBuildState(uint8_t state,uint8_t rev)
{
	if(state == LinkRemove)  // ����
	{
		PrintString(COL_WORD2+(rev-1)*(COL_WORD2),ROW_TEXT05,"��",2);
	}
	else
	{
		PrintString(COL_WORD2+(rev-1)*(COL_WORD2),ROW_TEXT05,"- ",2);
	}
}

#if 0
void DispLinkMaintainGap_Mac(uint8_t rev)
{
	uint8_t i = 0,y_Mac[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};
	if(rev == 0)
	{
		if(g_u8CurMenuID == MENU_PARAMLINKMAINTAIN)
		{	
			for(i=0;i<8;i++)
			{
				if(i<4)
				{			
					PrintString(COL_WORD5, y_Mac[i],mMaintainGap_Cur[i].Mode_ID, WORD);
					PrintString(COL_WORD8+WIDTH_HALF, y_Mac[i], mMaintainGap_Cur[i].Mode, WORD);
				}
				else
				{	
					PrintString(COL_WORD11+WIDTH_HALF, y_Mac[i%4],mMaintainGap_Cur[i].Mode_ID, WORD);
					PrintString(COL_WORD15, y_Mac[i%4], mMaintainGap_Cur[i].Mode, WORD);
				}
				break;
			}
		}	
	}
	else
	{
		if(g_u8CurMenuID == MENU_PARAMLINKMAINTAIN)
		{	
			for(i=0;i<8;i++)
			{
				if(i<4)
				{			
					PrintStringReverse(COL_WORD5, y_Mac[i],mMaintainGap_Cur[i].Mode_ID, WORD);
					PrintString(COL_WORD8+WIDTH_HALF, y_Mac[i], mMaintainGap_Cur[i].Mode, WORD);
				}
				else
				{	
					PrintString(COL_WORD11+WIDTH_HALF, y_Mac[i%4],mMaintainGap_Cur[i].Mode_ID, WORD);
					PrintString(COL_WORD15, y_Mac[i%4], mMaintainGap_Cur[i].Mode, WORD);
				}
				break;
			}
		}	
	}
}
#endif

/*********************************************************
*��������DispReverseGap
*����  ������Mac��Ӧ����·ά�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispGap(uint8_t x, uint8_t y, uint8_t u8Gap, uint8_t rev)
{
	uint8_t i = 0;
	Mode_TypeDef mMaintainGap[4]  = {{INDEX_EDIT_GAP0,"0-��ս<00s>"},{INDEX_EDIT_GAP1,"1-��ս<10s>"},
	                                 {INDEX_EDIT_GAP2,"2-��ս<20s>"},{INDEX_EDIT_GAP3,"3-��ս<30s>"}};

	for(i=0; i<4; i++)
	{
		if(u8Gap == mMaintainGap[i].Mode_ID)
		{
			if(rev == 0)
			{
				PrintString(x, y, mMaintainGap[i].Mode, 11);
			}
			else
			{
				PrintStringReverse(x, y, mMaintainGap[i].Mode, 11);
			}
			break;
		}
	}
}

/*********************************************************
*��������DispReverseGap
*����  ������Mac��Ӧ����·ά�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispReverseGap(void)
{
	uint8_t x = 0, y = 0;
	
	if(g_u8CurMenuItem <= 4)
	{
		x = COL_WORD5;
		y = ROW_TEXT04 + (g_u8CurMenuItem-1)*ROW_GAP;
	}
	else
	{
		x = COL_WORD14;
		y = ROW_TEXT04 + (g_u8CurMenuItem-5)*ROW_GAP;
	}
	DispGap(x, y, t_EditLinkInfo[g_u8CurMenuItem-1].MaintainGap_ID, 1);// 1 ����
}

/*********************************************************
*��������DispRecoverGap
*����  ������Mac��Ӧ����·ά�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRecoverGap(void)
{
	switch(g_u8CurMenuItem)
	{
		case INDEX_EDIT_MAC01:
			DispGap(COL_WORD5, ROW_TEXT04, t_CurLinkInfo[0].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC02:
			DispGap(COL_WORD5, ROW_TEXT05, t_CurLinkInfo[1].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC03:
			DispGap(COL_WORD5, ROW_TEXT06, t_CurLinkInfo[2].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC04:
			DispGap(COL_WORD5, ROW_TEXT07, t_CurLinkInfo[3].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC05:
			DispGap(COL_WORD14, ROW_TEXT04, t_CurLinkInfo[4].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC06:
			DispGap(COL_WORD14, ROW_TEXT05, t_CurLinkInfo[5].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC07:
			DispGap(COL_WORD14, ROW_TEXT06, t_CurLinkInfo[6].MaintainGap_ID, 1);
			break;

		case INDEX_EDIT_MAC08:
			DispGap(COL_WORD14, ROW_TEXT07, t_CurLinkInfo[7].MaintainGap_ID, 1);
			break;

		default:
			break;	
	}
}

#if 0
/*********************************************************
*��������DispDigTranInfo_Mac
*����  ������������ϢMac��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispDigTranInfo_Mac()
{
	int i = 0,Row_X[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};
	if(SelectPage == PageOne)
	{	
		for(i=0;i<4;i++)
		{	
			g_u8DispBuf[2*i+0] = (LinkInfo_Cur[i].MacNum >> 4) + '0';	// ��λ
			g_u8DispBuf[2*i+1] = (LinkInfo_Cur[i].MacNum & 0x0F) + '0'; // ��λ
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], "  ", 2);
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], &g_u8DispBuf[2*i], 2);
		}	
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(1/2)", WORD);
	}
	else
	{
		for(i=0;i<4;i++)
		{
			
			g_u8DispBuf[2*i+0] = (LinkInfo_Cur[i+4].MacNum >> 4) + '0';	// ��λ
			g_u8DispBuf[2*i+1] = (LinkInfo_Cur[i+4].MacNum & 0x0F) + '0'; // ��λ
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], "  ", 2);
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], &g_u8DispBuf[2*i], 2);
		}
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(2/2)", WORD);
	}
}
#endif

/*********************************************************
*��������DispDigTranInfo_FrameInfo
*����  �����������յ���֡��Ϣ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispDigTranInfo_FrameInfo(void)
{	
	uint8_t i = 0,Row_X[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};
	for(i=0;i<8;i++)
	{	
		if((g_u8CurMenuID == MENU_PARAMDIGTRANREPORT)||(g_u8CurMenuID == MENU_PARAMDIGTRANSTATIS))
		{
			PrintString(COL_WORD3, Row_X[i%4], "  ",2);
			PrintString(COL_WORD7, Row_X[i%4], "  ",2);
			PrintString(COL_WORD11,Row_X[i%4], "  ",2);
			PrintString(COL_WORD3, Row_X[i%4], &g_u8DispBuf_Frame[12*i+0],4);
			PrintString(COL_WORD7, Row_X[i%4], &g_u8DispBuf_Frame[12*i+4],4);
			PrintString(COL_WORD11,Row_X[i%4], &g_u8DispBuf_Frame[12*i+8],4);
		}		
	}
}

/*********************************************************
*��������DispLinkNetState
*����  ����ʾ��·����״̬
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispLinkNetState(uint8_t x,uint8_t y,uint8_t rev)
{
	uint8_t u8Col_Mac	= COL_WORD2  + rev*COL_WORD2;
	
	if(0 == t_CurLinkInfo[rev].NetState)
	{
		PrintString(u8Col_Mac,ROW_TEXT05,"- ",2); // ��ʾRow_Text05�е�����״̬
		PrintString(x, y,":δ����",7);	          // ��ʾRow_Text07��Row_Text08�е�����״̬
	}
	else
	{	
		PrintString(u8Col_Mac,ROW_TEXT05,"��",2);
		PrintString(x, y,":������",7);	
	}
}

/*********************************************************
*��������DispRadioRank
*����  ����ʾ��̨�ȼ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRadioRank(uint8_t rev)
{
    if(rev == 0)
    {
		#if 0
		// Test  mainStation:00 �� 20151223
		if(t_CurRadioState.MAC == 00)
		{			
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
			SelectStation = MainStation;
		}
		else
		{			
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
			SelectStation = SubStation;
		}
		// Test  mainStation:00 �� 20151223
		#endif
		
		//test
		if(SelectStation == SubStation)
		{			
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
		}
		else
		{		
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
		}
		//test
		
		#if 0
		if (t_CurRadioState.Rank == 0) // ��վ 
        {			
			if(SelectStation == SubStation)
			{			
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
			}
			else
			{		
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
			}
        }
        else 
        {
			if(SelectStation == SubStation)
			{			
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
			}
			else
			{		
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
			}
        }
		#endif
		
    }
    else
    {
        if(t_EditRadioState.Rank == 0)
        {
            PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
        }
        else 
        {
            PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "��վ", WORD);
        }
    }
}

/*********************************************************
*��������DispRadioPower
*����  ����ʾ��̨����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRadioPower(uint8_t rev)
{
    uint8_t i = 0, x = 0, y = 0;
    Mode_TypeDef mPower[3] = {{0, "ֵ��"}, {1, "С����"}, {3, "����"}};
	
    /*
	if(t_CurRadioState.ParamState == NO)
	{
		return;
	}*/
	
    x = COL_WORD3 + WIDTH_HALF;
   	y = ROW_TEXT07;
	
    //PrintString(x, y, "          ", WORD);
    if(rev == 0)
    {
        for(i=0; i<3; i++)
        {
            if(mPower[i].Mode_ID == t_CurRadioState.Power)
            {
				PrintString(x, y, "          ", WORD);
                PrintString(x, y, mPower[i].Mode, WORD);
                break;
            }
        }
    }
    else
    {
        for(i=0; i<3; i++)
        {
            if(mPower[i].Mode_ID == t_EditRadioState.Power)
            {
				PrintStringReverse(x, y, "      ", WORD);
                PrintStringReverse(x, y, mPower[i].Mode, WORD);
                break;
            }
        }
    }
}

/*********************************************************
*��������DispIpAddr
*����  ����ʾIP��ַ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispIpAddr(uint8_t x, uint8_t y, uint8_t rev)
{
    uint8_t i = 0; 

	for(i=0; i<4; i++)
	{
		g_u8DispBuf[4*i+0] = t_CurRadioState.Service_IP[i]/100   + '0';
		g_u8DispBuf[4*i+1] = t_CurRadioState.Service_IP[i]/10%10 + '0';
		g_u8DispBuf[4*i+2] = t_CurRadioState.Service_IP[i]%10    + '0';
		if(i != 3)
		{
			g_u8DispBuf[4*i+3] = '.';
		}
	}

    if(rev == 0)
    {
		PrintString(x, y, g_u8DispBuf, 15);
	}
	else 
	{
		PrintStringReverse(x, y, g_u8DispBuf, 15);
	}
}

/*********************************************************
*��������DispMaskAddr
*����  ����ʾ�����ַ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMaskAddr(uint8_t x, uint8_t y, uint8_t Type, uint8_t rev)
{
    uint8_t i = 0; 

	for(i=0; i<4; i++)
	{
		g_u8DispBuf[4*i]   = t_CurRadioState.Service_MASK[i]/100 + '0';
		g_u8DispBuf[4*i+1] = t_CurRadioState.Service_MASK[i]/10%10	+ '0';
		g_u8DispBuf[4*i+2] = t_CurRadioState.Service_MASK[i]%10  + '0';
		if(i != 3)
		{
			g_u8DispBuf[4*i+3] = '.';
		}
	}

    if(rev == 0)
    {
		PrintString(x, y, g_u8DispBuf, 15);
	}
	else 
	{
		PrintStringReverse(x, y, g_u8DispBuf, 15);
	}
}

/*********************************************************
*��������DispMask_CountOne
*����  �����������1�ĸ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMask_CountOne(uint8_t j,uint8_t k )
{
	switch(k)
	{
		case 1:
			t_CurRadioState.Service_MASK[j] = 0x80;
			break;
			
		case 2:
			t_CurRadioState.Service_MASK[j] = 0xC0;
			break;
			
		case 3:
			t_CurRadioState.Service_MASK[j] = 0xE0;
			break;
			
		case 4:
			t_CurRadioState.Service_MASK[j] = 0xF0;
			break;
			
		case 5:
			t_CurRadioState.Service_MASK[j] = 0xF8;
			break;
			
		case 6:
			t_CurRadioState.Service_MASK[j] = 0xFC;
			break;
			
		case 7:
			t_CurRadioState.Service_MASK[j] = 0xFE;
			break;
			
		default:
			break;
	}
}

/*********************************************************
*��������DispSendRate
*����  ����ʾʵ�ʷ�������
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispSendRate(void)
{
    uint8_t i = 0;
    Mode_TypeDef mRateMode[] = {{0, "64kbps��"}, {1, "128kbps��"}, {2, "192kbps��"}, {3, "256kbps��"},
								{4, "256kbps��"}, {5, "512kbps��"}, {6, "1024kbps��"}};

    PrintString(COL_WORD5, ROW_TEXT05, "      ", WORD);
    for(i=0; i<7; i++)
    {
        if(mRateMode[i].Mode_ID == t_CurRadioState.SendRate)
        {
           // PrintString(COL_WORD5, ROW_TEXT05,   mRateMode[i].Mode, WORD);
            break;
        }
    }
}

/*********************************************************
*��������DispRate
*����  ����ʾ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispRate(uint8_t rev)
{
    ;
}

/*********************************************************
*��������DispSNR
*����  ����ʾSNR
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispSNR(void)
{
    //uint8_t u8Mac = 0;
	uint8_t u8DataSnr = 0, u8Rate = 0;


	
    /*u8Mac = t_CurRadioState.CallMAC;

    if(u8Mac >= 32)
    {
        t_CurRadioState.CallMAC = t_CurRadioState.MAC;
    }
    g_u8DispBuf[0] = (u8Mac/10) + '0';
    g_u8DispBuf[1] = (u8Mac%10) + '0';
    g_u8DispBuf[2] = ',';*/
	
    u8Rate = t_CurRadioState.SnrRate;
    if(u8Rate < 128)
    {//����.ʵ�ʾ�Ϊ����
        g_u8DispBuf[0] = '+';
        u8DataSnr = u8Rate + 60;
    }
    else if(u8Rate <= 188)
    {
        g_u8DispBuf[0] = '+';
		u8DataSnr = 188 - u8Rate;        // 60-(ucIntensity & 0x7f);
    }
    else
    {
        g_u8DispBuf[0] = '-';
		u8DataSnr = u8Rate - 188;        // (ucIntensity & 0x7f) - 60;
    }

    g_u8DispBuf[1] = u8DataSnr/100 + '0';
    g_u8DispBuf[2] = u8DataSnr/10%10 + '0';
    g_u8DispBuf[3] = '.';
    g_u8DispBuf[4] = u8DataSnr%10 + '0';
	//DispMenuText_ParamDateTime(void);
    PrintString(COL_WORD12+WIDTH_HALF, ROW_TEXT06, g_u8DispBuf, 5);
}


