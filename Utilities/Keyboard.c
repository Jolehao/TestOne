#include "all.h"


uint8_t g_u8ScanState    = 1;
uint8_t g_u8Keyline_y[6] = {1,1,1,1,1,1}; 
uint8_t g_u8KeyBuf[2]    = {0}; 


/*********************************************************
*��������ScanKeyState1
*����  ������ɨ��״̬1����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ScanKeyState1(uint8_t Index_Y)
{
    if(Index_Y == 0)
    {
        g_u8KeyValue = KEY_3;
    }
    else if(Index_Y == 1)
    {
        g_u8KeyValue = KEY_6;
    }
    else if(Index_Y == 2)
    {
        g_u8KeyValue = KEY_9;
    }
    else if(Index_Y == 3)
    {
        g_u8KeyValue = KEY_ENT;
    }
    else if(Index_Y == 4)
    {
        g_u8KeyValue = KEY_VOL_UP;
    }
    else if(Index_Y == 5)
    {
        g_u8KeyValue = KEY_UP;
    }
    else
    {
        SetGpioBit(KEY_X1_PIN);
        ClrGpioBit(KEY_X2_PIN);
        SetGpioBit(KEY_X3_PIN);
        SetGpioBit(KEY_X4_PIN);
        g_u8ScanState = 2;
    }
}

/*********************************************************
*��������ScanKeyState2
*����  ������ɨ��״̬2����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ScanKeyState2(uint8_t Index_Y)
{
    if(Index_Y == 0)
    {
        g_u8KeyValue = KEY_2;
    }
    else if(Index_Y == 1)
    {
        g_u8KeyValue = KEY_5;
    }
    else if(Index_Y == 2)
    {
        g_u8KeyValue = KEY_8;
    }
    else if(Index_Y == 3)
    {
        g_u8KeyValue = KEY_0;
    }
    else if(Index_Y == 4)
    {
        g_u8KeyValue = KEY_VOL_DOWN;
    }
    else if(Index_Y == 5)
    {
        g_u8KeyValue = KEY_RIGHT;
    }
    else
    {
        SetGpioBit(KEY_X1_PIN);
        SetGpioBit(KEY_X2_PIN);
        ClrGpioBit(KEY_X3_PIN);
        SetGpioBit(KEY_X4_PIN);
        g_u8ScanState = 3;
    }
}

/*********************************************************
*��������ScanKeyState3
*����  ������ɨ��״̬3����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ScanKeyState3(uint8_t Index_Y)
{
    if(Index_Y == 0)
    {
        g_u8KeyValue = KEY_1;
    }
    else if(Index_Y == 1)
    {
        g_u8KeyValue = KEY_4;
    }
    else if(Index_Y == 2)
    {
        g_u8KeyValue = KEY_7;
    }
    else if(Index_Y == 3)
    {
        g_u8KeyValue = KEY_ESC;
    }
    else if(Index_Y == 4)
    {
        g_u8KeyValue = KEY_F5;
    }
    else if(Index_Y == 5)
    {
        g_u8KeyValue = KEY_LEFT;
    }
    else
    {
        SetGpioBit(KEY_X1_PIN);
        SetGpioBit(KEY_X2_PIN);
        SetGpioBit(KEY_X3_PIN);
        ClrGpioBit(KEY_X4_PIN);
        g_u8ScanState = 4;
    }
}

/*********************************************************
*��������ScanKeyState4
*����  ������ɨ��״̬4����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ScanKeyState4(uint8_t Index_Y)
{
    if(Index_Y == 0)
    {
        g_u8KeyValue = KEY_F1;
    }
    else if(Index_Y == 1)
    {
        g_u8KeyValue = KEY_F2;
    }
    else if(Index_Y == 2)
    {
        g_u8KeyValue = KEY_F3;
    }
    else if(Index_Y == 3)
    {
        g_u8KeyValue = KEY_F4;
    }
    else if(Index_Y == 4)
    {
        g_u8KeyValue = KEY_F6;
    }
    else if(Index_Y == 5)
    {
        g_u8KeyValue = KEY_DOWN;
    }
    else
    {
        ClrGpioBit(KEY_X1_PIN);
        SetGpioBit(KEY_X2_PIN);
        SetGpioBit(KEY_X3_PIN);
        SetGpioBit(KEY_X4_PIN);
        g_u8ScanState = 1;
    }
}

/*********************************************************
*��������ReadKeyState
*����  ����ȡ����״̬
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t ReadKeyState(void)
{
    uint8_t i = 0;

    memset(g_u8Keyline_y, 1, 6);
    g_u8Keyline_y[0] = ReadGpioBit(KEY_Y1_PIN);
    g_u8Keyline_y[1] = ReadGpioBit(KEY_Y2_PIN);
    g_u8Keyline_y[2] = ReadGpioBit(KEY_Y3_PIN);
    g_u8Keyline_y[3] = ReadGpioBit(KEY_Y4_PIN);
    g_u8Keyline_y[4] = ReadGpioBit(KEY_Y5_PIN);
    g_u8Keyline_y[5] = ReadGpioBit(KEY_Y6_PIN);

	for(i=0; i<6; i++)
	{
		if(g_u8Keyline_y[i] == 0)
		{
		    return i;
		}
	}
    return i;
}

/*********************************************************
*��������ScanKey
*����  ������ɨ�躯��
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ScanKey(void)
{
// �ް�������
    g_u8Temp = ReadKeyState();
    if(g_u8Temp >= 6)
    {
        g_u8KeyRelesed = YES;
    }

// ��⵽�м�����ʱ������ǰ����δ�ͷ�������ɨ��
    if(g_u8KeyRelesed == NO)
    {
        return;
    }

    if(g_u8Temp < 6)
    {
        g_u8KeyPressed = YES;
        g_u8KeyRelesed = NO;
    }
    
// �������ͷ�
    switch(g_u8ScanState)
    {
        case 1:
            ScanKeyState1(g_u8Temp);
            break;
    
        case 2:
            ScanKeyState2(g_u8Temp);
            break;
    
        case 3:
            ScanKeyState3(g_u8Temp);
            break;
    
        case 4:
            ScanKeyState4(g_u8Temp);
            break;
    
        default:
            ClrGpioBit(KEY_X1_PIN);
            SetGpioBit(KEY_X2_PIN);
            SetGpioBit(KEY_X3_PIN);
            SetGpioBit(KEY_X4_PIN);
            g_u8ScanState = 1;
            break;
    }
}

/*********************************************************
*��������SelectItem_UP
*����  �������л�ѡ��
*����  �����ѡ����
*���  ����
*����ֵ����
*NOTE  : ����������Ҫ�󣬷���߼���������������,CS
***********************************************************/
void SelectItem_UP(uint8_t MAXItem)
{
    if((g_u8ParamEditIndex > 0)||(g_u8CurMenuID == MENU_PARAMLINKBUILD))
    {
        return;
    }

    g_u8SelectItemOK = YES;
    g_u8EditMenuItem = g_u8CurMenuItem;
	g_u8NumIndex	 = 0;

	if((g_u8CurMenuItem <= 1) || (g_u8CurMenuItem > MAXItem))
    {
        g_u8CurMenuItem = MAXItem;
    }
    else
    {
        g_u8CurMenuItem--;
    }
}

/*********************************************************
*��������SelectItem_DOWN
*����  �������л�ѡ��
*����  �����ѡ����
*���  ����
*����ֵ����
***********************************************************/
void SelectItem_DOWN(uint8_t MAXItem)
{
    if((g_u8ParamEditIndex > 0)||(g_u8CurMenuID == MENU_PARAMLINKBUILD))
    {
        return;
    }

    g_u8SelectItemOK = YES;
    g_u8EditMenuItem = g_u8CurMenuItem;
	g_u8NumIndex	 = 0;
	
    if((g_u8CurMenuItem >= MAXItem) || (g_u8CurMenuItem < 1))
    {
        g_u8CurMenuItem = 1;
    }
    else
    {
        g_u8CurMenuItem++;
    }
}

/*********************************************************
*��������SelectItem_Left
*����  �������л�ѡ��
*����  �����ѡ����
*���  ����
*����ֵ����
***********************************************************/
void SelectItem_LR(uint8_t MAXItem)
{
    if(g_u8ParamEditIndex > 0)
    {
        return;
    }

    if(MAXItem <= TOTAL_ITEMS_PER_LINE)
    {
        return;
    }

    if((g_u8CurMenuItem <= TOTAL_ITEMS_PER_LINE) && (g_u8CurMenuItem > (MAXItem - TOTAL_ITEMS_PER_LINE)))
    {
        return;
    }

    g_u8SelectItemOK = YES;
    g_u8EditMenuItem = g_u8CurMenuItem;
	g_u8NumIndex	 = 0;

    if(g_u8CurMenuItem <= TOTAL_ITEMS_PER_LINE)    
    {
        g_u8CurMenuItem += TOTAL_ITEMS_PER_LINE;
    }
    else
    {
        g_u8CurMenuItem -= TOTAL_ITEMS_PER_LINE;
    }
}

/*********************************************************
*��������SelectItem_LR_LinkBuild
*����  �������л�MAC��
*����  �����ѡ����
*���  ����
*����ֵ����
***********************************************************/
void SelectItem_LR_LinkBuild(uint8_t MaxItem)
{
	/*
	if(g_u8ParamEditIndex > 0)
    {
        return;
    }
	*/
    g_u8SelectItemOK = YES;
    g_u8EditMenuItem = g_u8CurMenuItem;
	g_u8NumIndex	 = 0;

	if(g_u8KeyValue == KEY_LEFT)
	{
	    if(g_u8CurMenuItem <= 1)
	    {
	    	g_u8CurMenuItem = MaxItem;
	    }
	    else if((g_u8CurMenuItem >= 1)&&(g_u8CurMenuItem <= MaxItem))
	    {
	    	g_u8CurMenuItem --;
	    }
	}
	else
	{
		if(g_u8CurMenuItem >= MaxItem)
	    {
	    	g_u8CurMenuItem = 1;
	    }
	    else if((g_u8CurMenuItem >= 1)&&(g_u8CurMenuItem <= MaxItem))
	    {
	    	g_u8CurMenuItem ++;
	    }
	}
}

/*********************************************************
*��������SelectItem_LR_WorkState
*����  �������л�MAC��
*����  �����ѡ����
*���  ����
*����ֵ����
***********************************************************/
void SelectItem_LR_WorkState(uint8_t MaxItem)
{
	
	if(g_u8ParamEditIndex > 0)
    {
        return;
    }

    g_u8SelectItemOK = YES;
    g_u8EditMenuItem = g_u8CurMenuItem;
	g_u8NumIndex	 = 0;

	if(g_u8KeyValue == KEY_LEFT)
	{
	    if(g_u8CurMenuItem == INDEX_EDIT_CHANNUM)
	    {
	    	g_u8CurMenuItem = INDEX_EDIT_MAC;
	    }
	    else if(g_u8CurMenuItem == INDEX_EDIT_MAC)
	    {
	    	g_u8CurMenuItem = INDEX_EDIT_CHANNUM;
	    }
		else 
		{
			return ;
		}
	}
	else
	{
		if(g_u8CurMenuItem == INDEX_EDIT_MAC)
	    {
	    	g_u8CurMenuItem = INDEX_EDIT_CHANNUM;
	    }
	    else if(g_u8CurMenuItem == INDEX_EDIT_CHANNUM)
	    {
	    	g_u8CurMenuItem = INDEX_EDIT_MAC;
	    }
		else 
		{
			return;
		}
	}
}

/*********************************************************
*��������SelectMenuItem
*����  ��������Ӧ����
*����  ��������ֵ�����ѡ����
*���  ����
*����ֵ����
***********************************************************/
void SelectMenuItem(uint8_t MAXItem)
{
    if(g_u8KeyValue == KEY_UP)
    {
        SelectItem_UP(MAXItem);
    }
    else if(g_u8KeyValue == KEY_DOWN)
    {
        SelectItem_DOWN(MAXItem);
    }
	else if((g_u8KeyValue == KEY_LEFT) || (g_u8KeyValue == KEY_RIGHT))
	{
		if(g_u8CurMenuID == MENU_PARAMLINKBUILD)
		{	
			SelectItem_LR_LinkBuild(MAXItem);
		}
		else if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
		{
			SelectItem_LR_WorkState(MAXItem);
		}
		else
		{	
			SelectItem_LR(MAXItem);
		}
		//else if(g_u8CurMenuID == MENU_PARAMLINKMAINTAIN)
		{
			//SelectItem_LR_LinkMaintain(MAXItem);
		}

	}
	/*else if(IsNumberKey(g_u8KeyValue))
	{
		if(g_u8CurMenuID == MENU_PARAMUNLIGHTONOFF)
		{
			ProcNumKey_InputUnlightOnOffNum();
		}
	}*/
	DispItemSelectResult();
}

#if 0
/*********************************************************
*��������ProcMainPageKey_F1
*����  ��F1-���ò˵�����ҳ��Ӧ����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ProcMainPageKey_F1(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // ������һҳ�˵�ѡ��
	ClearMainPageLine();
	DispMenuText_PageF1();
}

/*********************************************************
*��������ProcMainPageKey_F2
*����  ��F2-��·�˵�����ҳ��Ӧ����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ProcMainPageKey_F2(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // ������һҳ�˵�ѡ��
	ClearMainPageLine();
	DispMenuText_PageF2();
}

/*********************************************************
*��������ProcMainPageKey_F3
*����  ��F3-��ز˵�����ҳ��Ӧ����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ProcMainPageKey_F3(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // ������һҳ�˵�ѡ��
	ClearMainPageLine();
	DispMenuText_PageF3();
}

/*********************************************************
*��������ProcMainPageKey_F4
*����  ��F4-ϵͳ�˵�����ҳ��Ӧ����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ProcMainPageKey_F4(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // ������һҳ�˵�ѡ��
	ClearMainPageLine();
	DispMenuText_PageF4();
}
#endif

/*********************************************************
*��������ProcMenuKey_SetF1
*����  ��F1-���ò˵������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcMenuKey_SetF1(void)
{
	if(IsNumberKey(g_u8KeyValue))
    {
        ProcNumKey_InputF1Num();
    }
    else if(g_u8KeyValue == KEY_F2)
    {
		ClearText_PageF1();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearText_PageF1();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearText_PageF1();
		DispMenuText_PageF4();
    }
}

/*********************************************************
*��������ProcMenuKey_SetF2
*����  ��F2-��·�˵������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcMenuKey_SetF2(void)
{
	if(IsNumberKey(g_u8KeyValue))
    {
        ProcNumKey_InputF2Num();
    }
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearText_PageF2();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearText_PageF2();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearText_PageF2();
		DispMenuText_PageF4();
    }
}

/*********************************************************
*��������ProcMenuKey_SetF3
*����  ��F3-��ز˵������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcMenuKey_SetF3(void)
{
	if(IsNumberKey(g_u8KeyValue))
    {
        ProcNumKey_InputF3Num();
    }
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearText_PageF3();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearText_PageF3();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearText_PageF3();
		DispMenuText_PageF4();
    }
	// test
	#if 0
    else if(g_u8KeyValue == KEY_ESC)
    {
      g_u8CurMenuItem = g_u8MenuItem_Bak1;
      LCD_Clear(TOP);
      ClearText_PageF3();
	  DispFuncKey_Param();
	  
	  PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>ѡ��˵�                 ", WORD);
      PrintString(WIDTH_HALF, ROW_TEXT10, "    ��<F6>������һ���˵�              ", WORD);
    }
	#endif
}

/*********************************************************
*��������ProcMenuKey_SetF4
*����  ��F4-ϵͳ�˵������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcMenuKey_SetF4(void)
{
	if(IsNumberKey(g_u8KeyValue))
    {
        ProcNumKey_InputF4Num();
    }
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearText_PageF4();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearText_PageF4();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearText_PageF4();
		DispMenuText_PageF3();
    }
}

/*********************************************************
*��������ProMenuKey_ParamRadioIp
*����  ����̨IP���������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamRadioIp(void)
{
	uint8_t i = 0;
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
	else if(IsNumberKey(g_u8KeyValue))
	{
		ProcNumKey_SetIp();
	}
	else  if(g_u8KeyValue == KEY_ESC)
	{
		g_u8NumIndex = 0;
        PrintString(COL_WORD8, ROW_TEXT05, "               ", 15);
	}
	else  if(g_u8KeyValue == KEY_ENT)
	{
		if(g_u8NumIndex == 12)
		{	
			if(g_u8CurMenuID == MENU_PARAMRADIOIP)
			{
				for(i=0; i<4; i++)
				{
					t_EditRadioState.Service_IP[i] = g_u8NumBuf[3*i]*100 + g_u8NumBuf[3*i+1]*10 + g_u8NumBuf[3*i+2];
				}
				Set_ServiceIp();
			}
		}
	}	
}

/*********************************************************
*��������ProMenuKey_ParamRadioMask
*����  ����̨������������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamRadioMask(void)
{
	uint8_t i = 0;
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
	else if(IsNumberKey(g_u8KeyValue))
	{
		ProcNumKey_SetMask();
	}
	else  if(g_u8KeyValue == KEY_ESC)
	{
		g_u8MaskZeroFlag = NO;
		g_u8NumIndex = 0;
        PrintString(COL_WORD8, ROW_TEXT05, "                   ", 15);
	}
	else  if(g_u8KeyValue == KEY_ENT)
	{
		if(g_u8NumIndex == 12)
		{			
			if(g_u8CurMenuID == MENU_PARAMRADIOMASK)
			{
				for(i=0; i<4; i++)
				{
					t_EditRadioState.Service_MASK[i] = g_u8NumBuf[3*i]*100 + g_u8NumBuf[3*i+1]*10 + g_u8NumBuf[3*i+2];
				}
				Set_ServiceMask();
			}
		}
	}
}

/*********************************************************
*��������ProMenuKey_ParamFactorySet
*����  ���ָ��������ò��������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamFactorySet(void)
{
    if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
	
	if(g_u8ParamEditState == NO)
	{
		if(g_u8KeyValue == KEY_ENT)
		{
			g_u8ParamEditState = YES;
			PrintString(COL_WORD5, ROW_TEXT05,  "                      ", WORD);
			PrintString(COL_WORD5, ROW_TEXT05,  "���ڻָ�...           ", WORD);
			
			PrintString(WIDTH_HALF, ROW_TEXT09, "                                         ", WORD);
			PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵� ", WORD);
			Set_DefaultParam();
		}
	}
}

/*********************************************************
*��������ProMenuKey_ParamLinkBuild 
*����  ����·�������������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamLinkBuild(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		ClearHorizonLine(0,143,0x00);
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		ClearHorizonLine(0,143,0x00);
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		ClearHorizonLine(0,143,0x00);
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		ClearHorizonLine(0,143,0x00);
		DispMenuText_PageF4();
    }
	
	SelectMenuItem(8);
	if(g_u8KeyValue == KEY_F5)
	{
		DispLinkBuildOprt();		
		g_u8ParamEditIndex = YES;  //�ж��Ƿ���Ҫ���н��������ı�־
	}
	else if((g_u8KeyValue == KEY_UP)||(g_u8KeyValue == KEY_DOWN))
	{
		ProcLinkBuildParamKey_UpDown();
	}
	else if(g_u8KeyValue == KEY_ENT)
	{
		ProcLinkBuild_ENT();
	}
}

/*********************************************************
*��������ProMenuKey_ParamLinkMaintain 
*����  ����·ά�����������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamLinkMaintain(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
	
	SelectMenuItem(8);
	if(IsNumberKey(g_u8KeyValue))
	{
		ProcNumKey_InputMaintainGapNum(g_u8KeyValue);
	}
	else if(g_u8KeyValue == KEY_ESC)
	{
		ProcLinkMaintain_ESC();
	}
	else if(g_u8KeyValue == KEY_ENT)
	{
		ProcLinkMaintain_ENT();
	}
}

/*********************************************************
*��������ProMenuKey_ParamLinkQuery 
*����  ����·��ѯ����ҳ�����°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamLinkQuery(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
}

/*********************************************************
*��������ProMenuKey_ParamWorkState 
*����  ������״̬���������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamWorkState(void)
{	
 	if(g_u8KeyValue == KEY_F5)
	{
		//DispLinkInfo_Mac();
 		ClearTextWindow();
		SelectStation = ~SelectStation;
		DispMenuText_ParamWorkState(); 
	}
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,��վ
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,��վ
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,��վ
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,��վ
		DispMenuText_PageF4();
    }
	
	if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		SelectMenuItem(6);				// ѡ��˵�ѡ��
		if(IsNumberKey(g_u8KeyValue))
		{
			ProcEditParamWorkState_Num();
		}
		else if(g_u8KeyValue == KEY_UP)
		{
			ProcEditParamWorkState_Add1();
		}
		else if(g_u8KeyValue == KEY_DOWN)
		{
			ProcEditParamWorkState_Cut1();
		}
		else if(g_u8KeyValue == KEY_ESC)
		{
			ProcParamWorkState_ESC();
		}
		else if(g_u8KeyValue == KEY_ENT)
		{
			ProcParamWorkState_ENT();
		}
	}
}

/*********************************************************
*��������ProMenuKey_ParamDigTranStatis 
*����  ������ͳ�Ʋ��������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamDigTranStatis(void)
{
 	if(g_u8KeyValue == KEY_F5)
	{
		ClearTextWindow();
		SelectPage = ~SelectPage;
		DispMenuText_ParamDigTranStatis(); 
	}
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
	
	// test 20151230
	if(IsNumberKey(g_u8KeyValue)) //����Mac��
	{
		ProcNumKey_MacNum_Test();  // test �汾
	}
	else if(g_u8KeyValue == KEY_ENT) //����շ�����
	{
		//ProcParamWorkState_ENT();
		if(g_u8ParamEditIndex != 0)   // ������Mac  
		{	
			// 
			if(t_EditStatisFrame.MacNum == t_CurStatisFrame.MacNum)
			{
				// ����Mac
				Set_ClrRFDigtal();
			}
			else
			{
				// һֱ����
				PrintString(COL_WORD7, ROW_TEXT08, "����������!", WORD);	
			}
		}
	}
}

/*********************************************************
*��������ProMenuKey_ParamDigTranReport 
*����  �������㱨���������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamDigTranReport(void)
{
 	if(g_u8KeyValue == KEY_F5)
	{
		ClearTextWindow();
		SelectPage = ~SelectPage;
		DispMenuText_ParamDigTranReport(); 
	}
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }

	
	// test 20151230
	if(IsNumberKey(g_u8KeyValue)) //����Mac��
	{
		ProcNumKey_MacNum_Test();  // test �汾
	}
	else if(g_u8KeyValue == KEY_ENT) //����շ�����
	{
		//ProcParamWorkState_ENT();
		if(g_u8ParamEditIndex != 0)   // ������Mac  
		{	
			// 
			if(t_EditStatisFrame.MacNum == t_CurStatisFrame.MacNum)
			{
				// ����Mac
				Set_ClrRFDigtal();
			}
			else
			{
				// һֱ����
				PrintString(COL_WORD7, ROW_TEXT08, "����������!", WORD);	
			}
		}
	}
}

/*********************************************************
*��������ProMenuKey_ParamDebugInfo 
*����  ��������Ϣ���������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamDebugInfo(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
}

/*********************************************************
*��������ProMenuKey_ParamRunTime 
*����  ������ʱ����������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamRunTime(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
}

/*********************************************************
*��������ProMenuKey_ParamDateTime 
*����  ������ʱ����������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamDateTime(void)
{
	SelectMenuItem(2);
	if(IsNumberKey(g_u8KeyValue))
	{
		ProcEditDateTime_Num();
	}
	else if(g_u8KeyValue == KEY_ENT)
	{
		ProcDateTimeKey_ENT();
	}
	else if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
	{
		ClearTextWindow();
		DispMenuText_PageF4();
	}
}

/*********************************************************
*��������ProMenuKey_ParamRadioTest 
*����  ����̨�Լ���������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamRadioTest(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
	{
		ClearTextWindow();
		DispMenuText_PageF4();
	}

}

/*********************************************************
*��������ProMenuKey_ParamPowerCheck 
*����  �����ʼ����������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamPowerCheck(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
	{
		ClearTextWindow();
		DispMenuText_PageF4();
	}
	else  if(g_u8ParamEditState == NO)
	{
		if(g_u8KeyValue == KEY_ENT)
		{
			LCD_Clear(TOP);
			DispFuncKey_Param();
			if(t_CurRadioState.Power == POWER_DUTY)
			{
				
				PrintString(COL_WORD4, ROW_TEXT04, "               ", WORD);
				PrintString(COL_WORD4, ROW_TEXT04, "��ǰΪֵ��״̬!", WORD);
				return;
			}
			g_u8ParamEditState = YES;
			g_u16SecondCount   = 0;
			
		    PrintString(COL_WORD1, ROW_TEXT02,  "3-���ʼ��", WORD);
			PrintString(COL_WORD4, ROW_TEXT04,  "��ǰ����: 37.0dB", WORD);
			PrintString(WIDTH_HALF, ROW_TEXT09, "ע: ��<F1-F4>�����˵� ", WORD);
			Query_PowerTest();
		}
	}
}

/*********************************************************
*��������ProMenuKey_ParamUnlightOnOff 
*����  �����⿪�ز��������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamUnlightOnOff(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
	{
		ClearTextWindow();
		DispMenuText_PageF4();
	}
	
	//SelectMenuItem(2);
	else if(IsNumberKey(g_u8KeyValue))
	{
		ProcNumKey_InputUnlightOnOffNum();
	}
}

/*********************************************************
*��������ProMenuKey_ParamVersionInfo 
*����  ���汾��Ϣ���������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProMenuKey_ParamVersionInfo(void)
{
	if(g_u8KeyValue == KEY_F1)
    {
		ClearTextWindow();
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
	{
		ClearTextWindow();
		DispMenuText_PageF4();
	}
}

/*********************************************************
*��������ProMenuKey_ParamEntFactorySet
*����  ��ȷ���ָ��������ò��������°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
/*
void ProMenuKey_ParamEntFactorySet(void)
{
 	if(g_u8KeyValue == KEY_F6)
	{
		g_u8CurMenuItem = g_u8MenuItem_Bak1;
		LCD_Clear(TOP);
		DispMenuText_MainPage(); 
	}
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		DispMenuText_PageF4();
    }
}
*/

/*********************************************************
*��������ProcNumKey_SetIp
*����  ������IP�������ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_SetIp(void)
{
	uint8_t i = 0,u8Data = 0;
	if(!IsNumCorrect_IP())
    {
        return;
    }
	
   	if(g_u8NumIndex%12 == 0)
    {
		g_u8ParamEditIndex = INDEX_EDIT_RADIOIP;
        g_u8NumIndex       = 0;
		if(g_u8CurMenuID == MENU_PARAMRADIOIP)
		{
			//DispMenuText_ParamRadioIp(void)
			PrintString(COL_WORD8, ROW_TEXT05, "---.---.---.---", 15);
		}
    }
    g_u8NumBuf[g_u8NumIndex] = g_u8KeyValue;
    g_u8NumIndex++;
    u8Data = g_u8KeyValue + '0';
    for(i=0; i<12; i++)
    {
        if(g_u8NumIndex == Pos_IP[i].Pos_ID)
        {
        	if(g_u8CurMenuID == MENU_PARAMRADIOIP)
        	{
				PrintStringReverse(Pos_IP[i].Pos_x, ROW_TEXT05, &u8Data, 1);
			}
            break;
        }
    }
}

/*********************************************************
*��������ProcNumKey_SetMac
*����  ������MAC�������ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_SetMask(void)
{
	uint8_t i	   = 0;
	uint8_t u8Data = 0;
	
	if(g_u8NumIndex >= 12)
	{
		g_u8NumIndex = 0;
		g_u8MaskZeroFlag = NO;
		memset(g_u8NumBuf, 0, 12);
	}

	if(IsNumCorrect_Mask())
	{
		g_u8ParamEditIndex = INDEX_EDIT_RADIOMAC;
		g_u8NumBuf[g_u8NumIndex++] = g_u8KeyValue;
		u8Data = g_u8KeyValue + '0';
		for(i=0; i<12; i++)
		{
			if(Pos_IP[i].Pos_ID == g_u8NumIndex)
			{
				if(g_u8CurMenuID == MENU_PARAMRADIOMASK) 
				{
					PrintStringReverse(Pos_IP[i].Pos_x, ROW_TEXT05, &u8Data, 1);
				}
				break;
			}
		}
	}
}

/*********************************************************
*��������ProcNumKey_MacNum
*����  ������༭վ��״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_MacNum(void)
{
    uint8_t u8Data = 0;

    if(g_u8CmdSending == YES)
    {
        return;
    }

    if((g_u8NumIndex%2 == 0) && (g_u8KeyValue <= 3))
    {
		g_u8ParamStepOK    = NO;
		g_u8ParamEditIndex = g_u8CurMenuItem;
        g_u8NumIndex = 1;
        g_u8NumBuf[0] = g_u8KeyValue;
        g_u8NumBuf[1] = 0;
        u8Data = g_u8KeyValue + '0';
        PrintStringReverse(COL_WORD3+WIDTH_HALF, ROW_TEXT08, &u8Data, 1);
        PrintString(COL_WORD4, ROW_TEXT08, " ", 1);
    }
    else if(g_u8NumIndex == 1)
    {
		if((g_u8NumBuf[0]*10 + g_u8KeyValue) <= 31)
		{
			g_u8NumIndex = 2;
			g_u8NumBuf[1] = g_u8KeyValue;
			u8Data = g_u8KeyValue + '0';
			PrintStringReverse(COL_WORD4, ROW_TEXT08, &u8Data, 1);
		}
        GetEditNum_ParamWorkState();
    }
}

/*********************************************************
*��������ProcNumKey_MacNum_Test
*����  ������༭վ��״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_MacNum_Test(void)
{
    uint8_t u8Data = 0;

	#if 0
    if(g_u8CmdSending == YES)
    {
        return;
    }
	#endif
	PrintString(COL_WORD6+WIDTH_HALF, ROW_TEXT08, "                    ", WORD);
    if((g_u8NumIndex%2 == 0) && (g_u8KeyValue <= 3))
    {
		g_u8ParamStepOK    = NO;
		g_u8ParamEditIndex = g_u8CurMenuItem;
        g_u8NumIndex = 1;
        g_u8NumBuf[0] = g_u8KeyValue;
        g_u8NumBuf[1] = 0;
        u8Data = g_u8KeyValue + '0';
        PrintStringReverse(COL_WORD5+WIDTH_HALF, ROW_TEXT08, &u8Data, 1);
        PrintString(COL_WORD6, ROW_TEXT08, " ", 1);
    }
    else if(g_u8NumIndex == 1)
    {
		if((g_u8NumBuf[0]*10 + g_u8KeyValue) <= 31)
		{
			g_u8NumIndex = 2;
			g_u8NumBuf[1] = g_u8KeyValue;
			u8Data = g_u8KeyValue + '0';
			PrintStringReverse(COL_WORD6, ROW_TEXT08, &u8Data, 1);
		}
        GetEditNum_ParamWorkState_Test();
    }
}

/*********************************************************
*��������ProcNumKey_ChanNum
*����  ������༭�ŵ���״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_ChanNum(void)
{
	uint8_t u8Data = 0;
    
    if((g_u8NumIndex%2 == 0) && (g_u8KeyValue <= 1))
    {
        g_u8ParamStepOK    = NO;
		g_u8ParamEditIndex = g_u8CurMenuItem;
        g_u8NumIndex       = 1;
        g_u8NumBuf[0]      = g_u8KeyValue;
        g_u8NumBuf[1]      = 0;
        u8Data = g_u8KeyValue + '0';
        PrintStringReverse(COL_WORD8 + WIDTH_HALF, ROW_TEXT08, &u8Data, 1);
        PrintString(COL_WORD9, ROW_TEXT08, " ", 1);
    }
    else if(g_u8NumIndex == 1)
    {
        g_u8NumIndex = 2;
        g_u8NumBuf[1] = g_u8KeyValue;
        u8Data = g_u8KeyValue + '0';
        PrintStringReverse(COL_WORD9, ROW_TEXT08, &u8Data, 1);
        GetEditNum_ParamWorkState();
    }
}

/*********************************************************
*��������ProcNumKey_Freq
*����  ������༭Ƶ��״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_Freq(void)
{
	uint8_t i = 0;
	uint8_t u8Data = 0;
	uint8_t x = 0, y = 0;

    if(IsFreqNumvalid(g_u8KeyValue))
    {
		i = g_u8NumIndex%5;
        g_u8NumBuf[i] = g_u8KeyValue;
        g_u8NumIndex  = i + 1;
		
        // ���ó�ʼλ��
        x = COL_WORD3;
        y = ROW_TEXT04;
      
        
        if(g_u8NumIndex == 1)
        {
            g_u8ParamEditIndex = g_u8CurMenuItem;
            memset(&g_u8NumBuf[1], 0, 4);
            if(2 == g_u8KeyValue)
            {
                g_u8NumBuf[1] = 2;
                g_u8NumBuf[2] = 5;
            }
            PrintString(x+WIDTH_WORD, y, "--.--", 5);
        }
        else if(g_u8NumIndex == 2)
        {
			if((g_u8NumBuf[0] == 2) && (g_u8NumBuf[1] > 2))
			{
				g_u8NumBuf[2] = 0;
			}
        }
        u8Data = g_u8KeyValue + '0';
        //ȷ��x���λ��
        x += (g_u8NumIndex/4 + g_u8NumIndex)*WIDTH_HALF;
        PrintStringReverse(x, y, &u8Data, 1);     // ��ʾ�����Ƶ������
    }
}

/*********************************************************
*��������ProcNumKey_TableNum
*����  ������༭���״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_TableNum(void)
{
    uint8_t  u8Data = 0;
    
    if((g_u8NumIndex%2 == 0) && (g_u8KeyValue <= 1))
    {
        g_u8ParamStepOK    = NO;
		g_u8ParamEditIndex = g_u8CurMenuItem;
        g_u8NumIndex       = 1;
        g_u8NumBuf[0]      = g_u8KeyValue;
        g_u8NumBuf[1]      = 0;
        u8Data = g_u8KeyValue + '0';
		//PrintString(COL_WORD3+WIDTH_HALF, ROW_TEXT04, "         ", 9);
        PrintStringReverse(COL_WORD3+WIDTH_HALF, ROW_TEXT04, &u8Data, 1);
        PrintString(COL_WORD4, ROW_TEXT04, " ", 1);
    }
    else if(g_u8NumIndex == 1)
    {
        g_u8NumIndex = 2;
        g_u8NumBuf[1] = g_u8KeyValue;
        u8Data = g_u8KeyValue + '0';
        PrintStringReverse(COL_WORD4, ROW_TEXT04, &u8Data, 1);
        GetEditNum_ParamWorkState();
    }
}

/*********************************************************
*��������ProcNumKey_InputF1Num
*����  ������������������µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_InputF1Num(void)
{
	if(g_u8KeyValue == 1)        // 1
	{
		ClearText_PageF1();
		DispMenuText_ParamRadioIp();
	}
	else if(g_u8KeyValue == 2)  // 2
	{
		ClearText_PageF1();
		DispMenuText_ParamRadioMask();
	}
	else if(g_u8KeyValue == 3)  // 3
	{
		ClearText_PageF1();
		DispMenuText_ParamFactorySet();
	}
}

/*********************************************************
*��������ProcNumKey_InputMaintainGapNum
*����  ������ά�������������µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_InputMaintainGapNum(uint8_t u8Key)
{
	uint8_t u8Index = g_u8CurMenuItem-1;
		
	if(u8Key == KEY_0)
	{
		t_EditLinkInfo[u8Index].MaintainGap_ID = 0;
	}
	else if(u8Key == KEY_1)
	{
		t_EditLinkInfo[u8Index].MaintainGap_ID = 1;
	}
	else if(u8Key == KEY_2)
	{
		t_EditLinkInfo[u8Index].MaintainGap_ID = 2;
	}
	else if(u8Key == KEY_3)
	{
		t_EditLinkInfo[u8Index].MaintainGap_ID = 3;
	}
	DispReverseGap();
}

/*********************************************************
*��������ProcNumKey_InputUnlightOnOffNum
*����  �������⿪����������µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_InputUnlightOnOffNum(void)
{
	if(g_u8ParamEditIndex > 0)
	{
		return;
	}

	if(g_u8KeyValue == 0)   // 0
	{
		ClrGpioBit(LED_BAK_PIN);
	}
	else if(g_u8KeyValue== 1)  // 1
	{
		/*g_u8SelectItemOK = YES;
		g_u8EditMenuItem = 1;
		g_u8CurMenuItem = 2;*/
		SetGpioBit(LED_BAK_PIN);
	}
}

/*********************************************************
*��������ProcNumKey_InputF2Num
*����  ������F2-��·��������µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_InputF2Num(void)
{
	if(g_u8KeyValue == 1)        // 1-��·����
	{
		ClearText_PageF2();
		DispMenuText_ParamLinkBuild();
	}
	else if(g_u8KeyValue == 2)   // 2-��·ά��
	{
		ClearText_PageF2();
		DispMenuText_ParamLinkMaintain();
	}
	else if(g_u8KeyValue == 3)  // 3-��·��ѯ
	{
		ClearText_PageF2();
		DispMenuText_ParamLinkQuery();
	}
}

/*********************************************************
*��������ProcNumKey_InputF3Num
*����  ������F3-�����������µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_InputF3Num(void)
{
		if(g_u8KeyValue == 1)   // 1
		{
			ClearText_PageF3();
			DispMenuText_ParamWorkState();
		}
		else if(g_u8KeyValue == 2)  // 2
		{
			ClearText_PageF3();
			SelectPage = PageOne;
			DispMenuText_ParamDigTranStatis();  
		}
		else if(g_u8KeyValue == 3)  // 3
		{
			ClearText_PageF3();
			SelectPage = PageOne;
			DispMenuText_ParamDigTranReport();
		}
		else if(g_u8KeyValue == 4)  // 4
		{
			ClearText_PageF3();
			DispMenuText_ParamDebugInfo();
		}
		else if(g_u8KeyValue == 5)  // 5
		{
			ClearText_PageF3();
			DispMenuText_ParamRunTime();
		}
}

/*********************************************************
*��������ProcNumKey_InputF4Num
*����  ������F4-ϵͳ�����µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_InputF4Num(void)
{
	if(g_u8KeyValue == 1)	      // 1
	{
		ClearText_PageF4();
		DispMenuText_ParamDateTime();
	}
	else if(g_u8KeyValue == 2)	 // 2
	{
		ClearText_PageF4();
		DispMenuText_ParamRadioTest();
	}
	else if(g_u8KeyValue == 3)	 // 3
	{
		ClearText_PageF4();
		DispMenuText_ParamPowerCheck();
	}
	else if(g_u8KeyValue == 4)	// 4
	{
		ClearText_PageF4();
		DispMenuText_ParamUnlightOnOff();
	}
	else if(g_u8KeyValue == 5)	// 5
	{
		ClearText_PageF4();
		DispMenuText_ParamVersionInfo();
	}
}

/*********************************************************
*��������ProcNumKey_Date
*����  ������༭����״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_Date(void)
{
    switch(g_u8NumIndex)
    {
        case 0:
        case 6:
            GetDate_FirstNum(g_u8KeyValue);
            break;

        case 1:
            GetDate_SecondNum(g_u8KeyValue);
            break;
        
        case 2:
            GetDate_ThirdNum(g_u8KeyValue);
            break;
        
        case 3:
            GetDate_ForthNum(g_u8KeyValue);
            break;
        
        case 4:
            GetDate_FifthNum(g_u8KeyValue);
            break;
        
        case 5:
            GetDate_SixthNum(g_u8KeyValue);
            break;
        
        default:
            break;
    }
}

/*********************************************************
*��������ProcNumKey_Time
*����  ������༭ʱ��״̬�µ����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcNumKey_Time(void)
{
    uint8_t u8Data = 0;
    switch(g_u8NumIndex)
    {
        case 0:
        case 6:
			g_u8ParamEditIndex = g_u8CurMenuItem;
            if(g_u8KeyValue <= 2)
            {
                g_u8NumIndex = 1;
                memset(g_u8NumBuf, 0, 6);
                g_u8NumBuf[0] = g_u8KeyValue;
                g_u8NumBuf[1] = 0;
                u8Data = g_u8KeyValue + '0';
				//DispMenuText_ParamDateTime(void)
                PrintStringReverse(COL_WORD8, ROW_TEXT06, &u8Data, 1);
                PrintString(COL_WORD8+WIDTH_HALF, ROW_TEXT06, "-:--:--", 7);
            }
            break;

        case 1:
            if((g_u8NumBuf[0] == 2) && (g_u8KeyValue > 3))
            {
                return;
            }
            
            g_u8NumIndex = 2;
            g_u8NumBuf[1] = g_u8KeyValue;
            u8Data = g_u8KeyValue + '0';
            PrintStringReverse(COL_WORD8+WIDTH_HALF, ROW_TEXT06,   &u8Data, 1);
            break;

        case 2:
            if(g_u8KeyValue <= 5)
            {
                g_u8NumIndex = 3;
                g_u8NumBuf[2] = g_u8KeyValue;
                u8Data = g_u8KeyValue + '0';
                PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT06,   &u8Data, 1);
            }
            break;

        case 3:
            g_u8NumIndex = 4;
            g_u8NumBuf[3] = g_u8KeyValue;
            u8Data = g_u8KeyValue + '0';
            PrintStringReverse(COL_WORD10, ROW_TEXT06,   &u8Data, 1);
            break;

        case 4:
            if(g_u8KeyValue <= 5)
            {
                g_u8NumIndex = 5;
                g_u8NumBuf[4] = g_u8KeyValue;
                u8Data = g_u8KeyValue + '0';
                PrintStringReverse(COL_WORD11, ROW_TEXT06,   &u8Data, 1);
            }
            break;

        case 5:
            g_u8NumIndex = 6;
            g_u8NumBuf[5] = g_u8KeyValue;
            u8Data = g_u8KeyValue + '0';
            PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT06,   &u8Data, 1);
            break;

        default:
            break;
    }
}

/*********************************************************
*��������IsFirstNumCorrect_Mask
*����  ���ж������MASK�����Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFirstNumCorrect_Mask(void)
{
    if((g_u8KeyValue > 0) && (g_u8MaskZeroFlag == YES))
    {
        return NO;
    }
	
    if(g_u8KeyValue > 2)
    {
        return NO;
    }

    if(g_u8NumIndex == 0)
    {
        if(g_u8KeyValue == 0)
        {
            return NO;
        }
		
		if(g_u8CurMenuID == MENU_PARAMRADIOMASK)
		{
			PrintString(COL_WORD8, ROW_TEXT05, "---.---.---.---", 15);
		}
    }
    
	if(g_u8KeyValue == 0)
	{
		g_u8MaskZeroFlag = YES;
	}
	
    return YES;
}

/*********************************************************
*��������ProTwelveNum
*����  ������12λ�����ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProTwelveNum(void)
{
	uint8_t i = 0;
	for(i=0;i<12;i++)
	{
		if(i < 3)
		{
			g_u8NumBuf1[i] = g_u8NumBuf[i] + '0';
		}
		else if((i>=3) && (i< 6))
		{
			g_u8NumBuf2[i-3] = g_u8NumBuf[i] + '0';
		}
		else if((i>=6) && (i< 9))
		{
			g_u8NumBuf3[i-6] = g_u8NumBuf[i] + '0';
		}
		else if((i>=9) && (i< 12))
		{
			g_u8NumBuf4[i-9] = g_u8NumBuf[i] + '0';
		}		
	}
}

/*********************************************************
*��������IsSecondNumCorrect_Mask
*����  ���ж������MASK�����Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsSecondNumCorrect_Mask(void)
{
	if((g_u8NumIndex > 0) && (g_u8NumIndex < 12))
	{
		if((g_u8KeyValue > 0) && (g_u8MaskZeroFlag == YES))
		{
			return NO;
		}
		
		if(g_u8NumBuf[g_u8NumIndex-1] == 1)
		{
			if((g_u8KeyValue != 2) && (g_u8KeyValue != 9))
			{
				return NO;
			}
		}
		
		if(g_u8NumBuf[g_u8NumIndex-1] == 2)
		{
			if((g_u8KeyValue != 2) && (g_u8KeyValue != 4) && (g_u8KeyValue != 5))
			{
				return NO;
			}
		}
		
		return YES;
	}
	else
	{
		return NO;
	}
}

/*********************************************************
*��������IsThirdNumCorrect_Mask
*����  ���ж������MASK�����Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsThirdNumCorrect_Mask(void)
{
    uint8_t u8Data = 0;

	if((g_u8NumIndex > 1) && (g_u8NumIndex < 12))
	{
		if((g_u8KeyValue > 0) && (g_u8MaskZeroFlag == YES))
		{
			return NO;
		}
		
		u8Data = g_u8NumBuf[g_u8NumIndex-2]*10 + g_u8NumBuf[g_u8NumIndex-1];
		if((u8Data == 12) && (g_u8KeyValue != 8))
		{
			return NO;
		}
		
		if((u8Data == 19) && (g_u8KeyValue != 2))
		{
			return NO;
		}
		
		if((u8Data == 22) && (g_u8KeyValue != 4))
		{
			return NO;
		}
		
		if((u8Data == 24) && (g_u8KeyValue != 0) && (g_u8KeyValue != 8))
		{
			return NO;
		}
		
		if((u8Data == 25) && (g_u8KeyValue != 2) && (g_u8KeyValue != 4) && (g_u8KeyValue != 5))
		{
			return NO;
		}
		
		if((u8Data*10 + g_u8KeyValue) != 255)
		{
			g_u8MaskZeroFlag = YES;
		}
		
		return YES;
	}
	else 
	{
		return NO;
	}
}

/*********************************************************
*��������IsNumCorrect_MAC
*����  ���ж������MASK�����Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsNumCorrect_Mask(void)
{
    if(g_u8NumIndex%3 == 0)
    {
        return IsFirstNumCorrect_Mask();
    }

    else if(g_u8NumIndex%3 == 1)
    {
        return IsSecondNumCorrect_Mask();
    }

    else
    {
        return IsThirdNumCorrect_Mask();
    }
}

/*********************************************************
*��������IsNumCorrect_IP
*����  ���ж������IP�����Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsNumCorrect_IP(void)
{
    uint8_t u8Data = 0;

	if(g_u8NumIndex <= 12)
	{
		if(g_u8NumIndex%3 == 0)
		{
			if(g_u8KeyValue > 2)
			{
				return NO;
			}
		}
		else if(g_u8NumIndex%3 == 1)
		{
			if((g_u8NumBuf[g_u8NumIndex-1] == 2) && (g_u8KeyValue > 5))
			{
				return NO;
			}
		}
		else if(g_u8NumIndex == 2)
		{
			u8Data = g_u8NumBuf[0]*100 + g_u8NumBuf[1]*10 + g_u8KeyValue;
			if(u8Data == 0)
			{
				return NO;
			}
		}
		else if(g_u8NumIndex%3 == 2)
		{
			u8Data = g_u8NumBuf[g_u8NumIndex-2]*10 + g_u8NumBuf[g_u8NumIndex-1];
			if((u8Data == 25) && (g_u8KeyValue > 5))
			{
				return NO;
			}
		}
		return YES;
	}
	else
	{
		return NO;
	}
}

/*********************************************************
*��������ProcNumKey_SetIp
*����  ������IP�������ּ�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
Position_TypeDef Pos_IP[] = {{1, COL_WORD8,  0}, {2, COL_WORD8+WIDTH_HALF, 0},
                              {3, COL_WORD9, 0}, {4, COL_WORD10, 0},
                              {5, COL_WORD10+WIDTH_HALF,           0}, {6, COL_WORD11, 0},
                              {7, COL_WORD12,0}, {8, COL_WORD12+WIDTH_HALF,           0},
                              {9, COL_WORD13,0}, {10,COL_WORD14,0},
                              {11,COL_WORD14+WIDTH_HALF,0}, {12,COL_WORD15,0}};

/*********************************************************
*��������ProcRealTimeUpdate
*����  ������ʵʱʱ�����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcRealTimeUpdate(void)
{
    static uint8_t u8Buf[2] = {0,0},u8Buf_RT[2] = {0,0};
	//uint8_t au8Code[2] = {0};

	u8Buf_RT[0] = u8Buf_RT[1];
	u8Buf_RT[1] = g_u8RunTimeUpdate;  // 1s����һ��
	if(u8Buf_RT[0] != u8Buf_RT[1])
	{		
		// ���㱾�ο���ʱ��
		if(g_u8RunTimeCount % 60 == 0) // minute tick
		{
			t_SubRunTime.Minute++;
            g_u8RunTimeCount = 0;
		}
		if((t_SubRunTime.Minute > 0) && (t_SubRunTime.Minute % 60 == 0)) // hour tick
		{
			t_SubRunTime.Hour++;
			t_SubRunTime.Minute = 0;
		}
		t_SubRunTime.Second = g_u8RunTimeCount; // second tick

        if((t_SubRunTime.Second) % 60 == 0)
        {
            WriteCode(&t_SumRunTime.Second); // ÿ��1min���㲢�洢һ����ʱ��		
        }
	}
    
	//WriteCode(&t_SubRunTime.Minute);
    if((g_u8CurMenuID == MENU_PARAMDATETIME) || (g_u8CurMenuID == MENU_PARAMWORKSTATE)
		|| (g_u8CurMenuID == MENU_PARAMRUNTIME))
    {
        u8Buf[0] = u8Buf[1];
        u8Buf[1] = g_u8UpdateTime; //0.2S����һ��

		//ReadCode(au8Code);	 // Test

        if(u8Buf[0] != u8Buf[1])
        {
         	RTC_ReadTime();
        }
    }
}

/*********************************************************
*��������ProcTimeOutWarning
*����  ������ʱ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcTimeOutWarning(void)
{
    if(g_u8ParamEditState == YES)
    {
        switch(g_u8CurMenuID)
        {
            case MENU_PARAMPOWERCHECK:
                if(g_u16SecondCount >= 50)   // ��ʱ3S
                {
                    g_u8ParamEditState = NO;	
                    PrintString(COL_WORD4, ROW_TEXT04,  "                       ", WORD);
                    PrintString(COL_WORD4, ROW_TEXT04,  "����ʱ,�����¼��!   ", WORD);
				   	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT09, "             ", WORD);                
				   	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT09, "���ʧ��!    ", WORD);               
    			}
                break;
            default:
                break;
        }
    }
}

/*********************************************************
*��������ProcTimeOutEvent
*����  ����Ⲣ����ʱ�¼�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcTimeOutEvent(void)
{  
	ProcTimeOut_PowerOnOff();
}

/*********************************************************
*��������ProcTimeOut_PowerOnOff
*����  �������ػ���ʱ�¼�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcTimeOut_PowerOnOff(void)
{
	// test
	if(g_u8CurMenuID == MENU_1ST_BITE)  
	//if(g_u8CurMenuID == MENU_POWER_ON)
	{
		//if(g_u8PowerOnOffTick >= 5) // test
		if(g_u8PowerOnOffTick >= 150) // ok
		{
		   //LCD_Clear(TOP);
		   g_u8RadioState = NO; 		   // ��ʱδ�յ�382�����Ϊ��̨״̬������
		   // test 20151229
		   // ClrGpioBit(LED_ALARM2_PIN);	   // ������ʾ��ɫ
		   //SetGpioBit(LED_ALARM1_PIN);

		   
		   //DispMenuText_MainPage();
		   Delay_nS(8);
		   DispMenuText_ParamWorkState();	   // ��ʾ����Ĭ�Ͻ���
		   //DispMenuText_ParamLinkBuild();
		}
	}
	// �ػ��ȴ�������Ӧ��ʱ��ֱ�ӹػ�
	if((g_u8CurMenuID == MENU_POWER_OFF) && (g_u8PowerOnOffTick >= 100))
	{
		SetGpioBit(CON_POWER_PIN);
	}
}

/*********************************************************
*��������ProcLinkBuild_ENT
*����  ���������ҳ��·�����µ�ȷ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcLinkBuild_ENT(void)
{
	if(g_u8ParamEditIndex == YES)  // ��������������Ч
	{
		g_u8ParamEditIndex = NO;
		DispResult_StatisLinkBuild();  // ��ʾͳ����·�����Ľ��:��Щ��Ҫ����
		if(g_u8PreLinkOprtState == LinkBuild) //  ѡ�����: ����
		{
			Set_LinkOprt();  // ����
		}
		else
		{
			Set_LinkOprt(); //	����
		}
	}
	else
	{
		return ;
	}
}

/*********************************************************
*��������ProcLinkMaintain_ESC
*����  ���������ҳ��·ά���µ�ȡ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcLinkMaintain_ESC(void)
{
	uint8_t u8Index = g_u8CurMenuItem - 1;

	g_u8ParamEditState = NO;
	t_EditLinkInfo[u8Index].MaintainGap_ID = t_CurLinkInfo[u8Index].MaintainGap_ID;

	DispRecoverGap();
}

/*********************************************************
*��������ProcLinkMaintain_ENT
*����  ���������ҳ��·ά���µ�ȷ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcLinkMaintain_ENT(void)
{
	uint8_t u8Index = g_u8CurMenuItem - 1;
	
	if(g_u8ParamEditState == NO)
	{
		g_u8ParamEditState = YES;
		t_EditLinkInfo[u8Index].MaintainGap_ID = t_CurLinkInfo[u8Index].MaintainGap_ID;
		DispReverseGap();
	}
	else
	{
		Set_LinkMaintainGap();
	}
}

/*********************************************************
*��������ProcDateTimeKey_ENT
*����  ����������ʱ�����ҳ�µ�ȷ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcDateTimeKey_ENT(void)
{
   if(g_u8ParamEditIndex == 0)
    {
        g_u8ParamEditIndex = g_u8CurMenuItem;
		g_u8NumIndex       = 0;
        memcpy(&t_EditTime, &t_CurTime, sizeof(t_CurTime));
        DispDateTimeReverse(1);
    }
    else
    {
        if(g_u8NumIndex == 0)
        {
            DispDateTimeReverse(0);       // ���Բ�����ȡ��ѡ��
            g_u8ParamEditIndex = 0;
        }
        else if(g_u8NumIndex == 6)
        {
            memcpy(&t_EditTime, &t_CurTime, sizeof(t_CurTime));
            if(g_u8ParamEditIndex == INDEX_EDIT_DATE)
            {
                t_EditTime.Year    = (g_u8NumBuf[0]<<4) + g_u8NumBuf[1];
                t_EditTime.Month   = (g_u8NumBuf[2]<<4) + g_u8NumBuf[3];
                t_EditTime.Day     = (g_u8NumBuf[4]<<4) + g_u8NumBuf[5];
            }
            else if(g_u8ParamEditIndex == INDEX_EDIT_TIME)
            {
                t_EditTime.Hour   = (g_u8NumBuf[0]<<4) + g_u8NumBuf[1];
                t_EditTime.Minute = (g_u8NumBuf[2]<<4) + g_u8NumBuf[3];
                t_EditTime.Second = (g_u8NumBuf[4]<<4) + g_u8NumBuf[5];
            }
            RTC_WriteTime(); //����ʱ��
			Set_DateOfTime();
        }
    }
}

/*********************************************************
*��������ProcParamWorkState_ENT
*����  ��������״̬����ҳ�µ�ȷ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcParamWorkState_ENT(void)
{
   	if(g_u8ParamEditIndex == 0) 
    {
		memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState));
		t_EditRadioState.Power = t_CurRadioState.Power; //����
		t_EditRadioState.MAC   = t_CurRadioState.MAC;   //վ��
		t_EditRadioState.Rank  = t_CurRadioState.Rank;  //�ȼ�
		g_u8ParamEditIndex	   = g_u8CurMenuItem;
		DispWorkStateReverse1(1);
		g_u8NumIndex = 0;
	}
    else
    {
		if(g_u8ParamStepOK == NO)  // �����ּ���ʽ���ò���
        {
            if(g_u8NumIndex >= 1)
            {
                GetEditNum_ParamWorkState();
		
            }
            else 
            {
				DispItemReverse_ParamWorkState();
				//g_u8ParamEditIndex = 0;
                g_u8NumIndex       = 0;
                return;
            }
        }
		
		if(g_u8ParamEditIndex == INDEX_EDIT_CHANNUM)
        {
            Set_ChanNum();
        }
		else if(g_u8ParamEditIndex == INDEX_EDIT_MAC)
        {		
			//g_u8NumIndex   = 0;
            //t_EditRadioState.MAC = g_u8NumBuf[0]*10 + g_u8NumBuf[1];
            Set_RadioMac();
			//g_u8CmdSending = YES;// 20151126 �˴��ȵ��ظ�ACK��ʱ��Ÿı�ź���
        }
        else if(g_u8ParamEditIndex == INDEX_EDIT_POWER)
        {
            Set_RadioPower();
        }
		else if(g_u8ParamEditIndex == INDEX_EDIT_RANK)
		{
			Set_RadioRank();
		}
        else
        {
            Set_ChanParam();  //�����ŵ�����
        }
    }
}

/*********************************************************
*��������ProcParamWorkState_ESC
*����  ��������״̬����ҳ�µ�ȡ����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
void ProcParamWorkState_ESC(void)
{
    if(g_u8ParamEditIndex != 0)
    {
        g_u8NumIndex = 0;
        memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState));
		t_EditRadioState.Power = t_CurRadioState.Power;
		t_EditRadioState.MAC   = t_CurRadioState.MAC;
		t_EditRadioState.Rank  = t_CurRadioState.Rank;
		//DispWorkStateReverse(0);       // ���Բ�����ȡ��ѡ��
		// test
		DispWorkStateReverse1(0);       // ���Բ�����ȡ��ѡ��
        g_u8ParamStepOK    = NO;
        g_u8ParamEditIndex = 0;
    }
}

/*********************************************************
*��������ProcEditParamWorkState_Num
*����  ������״̬����ҳ���������봦��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditParamWorkState_Num(void)
{
   switch(g_u8CurMenuItem)
   {
	   case INDEX_EDIT_MAC:
			ProcNumKey_MacNum();
			//ProcNumKey_SetMac();
       		break;

	   case INDEX_EDIT_CHANNUM:
            ProcNumKey_ChanNum();
           break;
   
   
       case INDEX_EDIT_FREQ_TAB:
           if(t_CurChannelState.WorkMode%2 == 1)       // ��Ƶģʽ��
           {
               ProcNumKey_Freq();
               break;
           }
           // ��Ƶģʽ�� 
           ProcNumKey_TableNum();
           break; 
		   
       default:
           break;
   }
}

/*********************************************************
*��������GetEditNum_NetNum
*����  ����ȡ����ҳ����״̬�µĲ���ֵ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetEditNum_ParamWorkState(void)
{
    switch(g_u8ParamEditIndex)
    {
        case INDEX_EDIT_FREQ_TAB:
            if(t_EditChannelState.WorkMode%2 == 1)   // ��Ƶģʽ��
            {
                t_EditChannelState.Freq[0] = g_u8NumBuf[0];
                t_EditChannelState.Freq[1] = (g_u8NumBuf[1] << 4) + g_u8NumBuf[2];
                t_EditChannelState.Freq[2] = (g_u8NumBuf[3] << 4) + g_u8NumBuf[4];
                break;
            }
            // ��Ƶģʽ��
            t_EditChannelState.TableNum = (g_u8NumBuf[0] << 4) + g_u8NumBuf[1];
            break;
			//DispMacNum

		case INDEX_EDIT_CHANNUM:
            t_EditChannelState.ChanNum = (g_u8NumBuf[0] << 4) + g_u8NumBuf[1];
            break;

		case INDEX_EDIT_MAC:
            //t_EditRadioState.MAC = (g_u8NumBuf[0] << 4) + g_u8NumBuf[1];
            t_EditRadioState.MAC = (g_u8NumBuf[0] * 10) + g_u8NumBuf[1];
			SetMac = YES;  // test
            break;

        default:
            break;
    }
}

/*********************************************************
*��������GetEditNum_ParamWorkState_Test
*����  ����ȡ����ҳ����״̬�µĲ���ֵ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetEditNum_ParamWorkState_Test(void)
{
	if(g_u8ParamEditIndex != 0)
	{	
		t_EditStatisFrame.MacNum = (g_u8NumBuf[0] * 10) + g_u8NumBuf[1];
	}
}

/*********************************************************
*��������ProcEditParamWorkState_Add1
*����  ����վ����״̬����ҳ�²�������������1����λ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditParamWorkState_Add1(void)
{
    if(g_u8ParamEditIndex != 0)
    {
        switch(g_u8ParamEditIndex)
        {
			case INDEX_EDIT_CHANNUM:
                ProcEditChanNum_Add1();
                break;
				
            case INDEX_EDIT_WORKMODE:
                ProcEditWorkMode_Add1();
                break;
        
            case INDEX_EDIT_FREQ_TAB:
                ProcEditFreOrTab_Add1();
                break;
        
           // case INDEX_EDIT_RATE:
               // ProcEditRate_Add1();
               // break;

            case INDEX_EDIT_RANK:  
                ProcEditRank_Step1();
                break;

            case INDEX_EDIT_POWER:
                ProcEditPower_Add1();
                break;

           case INDEX_EDIT_MAC:
                ProcEditMac_Add1();
				//ProcEditMac_Add2();
                break;
        
            default:
                break;
        }
    }
}

/*********************************************************
*��������ProcEditFreOrTab_Add1
*����  ��Ƶ�ʲ���50KHz���ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditFreOrTab_Add1(void)
{
    uint8_t u8Data = 0;
    uint16_t u16Data = 0;

    if(t_CurChannelState.WorkMode%2 == 0)       // ��Ƶģʽ
    {
        if(g_u8NumIndex == 1)
        {
            return;
        }
        u8Data = ConvertBCDtoDecimal(t_EditChannelState.TableNum);
        if(u8Data >= 19)
        {
            t_EditChannelState.TableNum = 0;
            g_u8ParamStepOK             = YES;
        }
        else
        {
            t_EditChannelState.TableNum = ConvertDecimaltoBCD(u8Data+1);
            g_u8ParamStepOK             = YES;
        }
        DispTableNum(1);
        return;
    }

    // ��Ƶģʽ
    if((g_u8NumIndex > 0) && (g_u8NumIndex < 5))
    {
        return;
    }
    u16Data = ((uint16_t)(t_EditChannelState.Freq[0] & 0x07)) * 10000;
    
    u8Data = ConvertBCDtoDecimal(t_EditChannelState.Freq[1]);
    u16Data += ((uint16_t)u8Data) * 100; 
    
    u8Data = ConvertBCDtoDecimal(t_EditChannelState.Freq[2]);
    u16Data += (uint16_t)u8Data;
    
    if((u16Data + 5) > 51200)
    {
        t_EditChannelState.Freq[0] = 2;
        t_EditChannelState.Freq[1] = 0x25;
        t_EditChannelState.Freq[2] = 0;
        g_u8ParamStepOK            = YES;
    }
    else
    {
        u16Data += 5;
        t_EditChannelState.Freq[0] = (uint8_t)(u16Data/10000);
        t_EditChannelState.Freq[1] = (uint8_t)((u16Data/1000%10) << 4) + (uint8_t)(u16Data/100%10);
        t_EditChannelState.Freq[2] = (uint8_t)((u16Data/10%10) << 4) + (uint8_t)(u16Data%10);
        g_u8ParamStepOK            = YES;
    }
    DispFrequency(1);
}

/*********************************************************
*��������ProcEditRank_Step1
*����  ����̨�ȼ��л�
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditRank_Step1(void)
{
    t_EditRadioState.Rank = (t_EditRadioState.Rank + 1)%2;
    g_u8ParamStepOK = YES;
    DispRadioRank(1);
}

/*********************************************************
*��������Volume_Add1
*����  ���������ƺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Volume_Add1(void)
{
    if(g_u8CurVolume < VOLUME_LEVEL3)
    {
        g_u8CurVolume++;
    }
}

/*********************************************************
*��������ProcEditPower_Add1
*����  ����̨���ʼ�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditPower_Add1(void)
{
    t_EditRadioState.Power = (t_EditRadioState.Power + 1)%4;
    if(t_EditRadioState.Power == 2)
    {
        t_EditRadioState.Power = 3;
    }
    g_u8ParamStepOK = YES;
    DispRadioPower(1);
}

/*********************************************************
*��������ProcEditMac_Add1
*����  ��վ�ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditMac_Add1(void)
{
    uint8_t u8Data = 0;

    if(g_u8NumIndex == 1)
    {
       return;
    }

    u8Data = ConvertBCDtoDecimal(t_EditRadioState.MAC);
    if(u8Data >= 31)
    {
        t_EditRadioState.MAC = 0;
    }
    else
    {
        u8Data++;
        t_EditRadioState.MAC = ConvertDecimaltoBCD(u8Data);
    }
    g_u8ParamStepOK = YES;
    DispMacNum(1);
}

/*********************************************************
*��������ProcEditChanNum_Add2
*����  ���ŵ��ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditMac_Add2(void)
{
    uint8_t u8Data = 0;

    if(g_u8NumIndex == 1)
    {
        return;
    }

    u8Data = ConvertBCDtoDecimal(t_EditRadioState.MAC);
    if(u8Data >= 19)
    {
        t_EditRadioState.MAC = 0;
    }
    else
    {
        u8Data++;
       t_EditRadioState.MAC = ConvertDecimaltoBCD(u8Data);
    }
    g_u8ParamStepOK = YES;
    DispMacNum(1);
}

/*********************************************************
*��������ProcEditChanNum_Add1
*����  ���ŵ��ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditChanNum_Add1(void)
{
    uint8_t u8Data = 0;

    if(g_u8NumIndex == 1)
    {
        return;
    }

    u8Data = ConvertBCDtoDecimal(t_EditChannelState.ChanNum);
    if(u8Data >= 19)
    {
        t_EditChannelState.ChanNum = 0;
    }
    else
    {
        u8Data++;
        t_EditChannelState.ChanNum = ConvertDecimaltoBCD(u8Data);
    }
    g_u8ParamStepOK = YES;
    DispChannelNum(1);
}

/*********************************************************
*��������ProcEditWorkMode_Add1
*����  ������ģʽ��1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditWorkMode_Add1(void)
{
	uint8_t /*u8State = 0,*/ u8Mode = 0, u8MaxMode = 0;
    //u8State = t_CurSecureState.state;
    u8Mode = t_EditChannelState.WorkMode;

    /*if((u8State == 0xFF) && (u8Mode == WORKMODE_HOP))
    {
    // �澯��ʾ : δ��⵽���ܻ�
        return;
    }*/
	if(isSecureOK())
	{
		u8MaxMode = WORKMODE_SHOP;
	}
	else
	{
		u8MaxMode = WORKMODE_HOP;
	}
	
    if(u8Mode < u8MaxMode)
    {
        u8Mode++;
    }
	else
	{
		u8Mode = WORKMODE_FIX;
	}
    
    t_EditChannelState.WorkMode = u8Mode;
    g_u8ParamStepOK             = YES;
    DispWorkMode(1);
}

/*********************************************************
*��������ProcEditParam1_Cut1
*����  ������״̬����ҳ�²�����������С1����λ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditParamWorkState_Cut1(void)
{
	 if(g_u8ParamEditIndex != 0)
    {
        switch(g_u8ParamEditIndex)
        {
			case INDEX_EDIT_CHANNUM:
                ProcEditChanNum_Cut1();
                break;
				
            case INDEX_EDIT_WORKMODE:
                ProcEditWorkMode_Cut1();
                break;
        
            case INDEX_EDIT_FREQ_TAB:
                ProcEditFreOrTab_Cut1();
                break;
        
            //case INDEX_EDIT_RATE:
               // ProcEditRate_Cut1();
                //break;


            case INDEX_EDIT_RANK:
                ProcEditRank_Step1();
                break;

            case INDEX_EDIT_POWER:
                ProcEditPower_Cut1();
                break;
        
            case INDEX_EDIT_MAC:
                ProcEditMac_Cut1();
                //ProcEditMac_Cut2();
               break;
        
            default:
                break;
        }
    }
}

/*********************************************************
*��������ProcEditChanNum_Cut1
*����  ���ŵ��ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditChanNum_Cut1(void)
{
    uint8_t u8Data = 0;

    if(g_u8NumIndex == 1)
    {
        return;
    }

    u8Data = ConvertBCDtoDecimal(t_EditChannelState.ChanNum);

    if((u8Data == 0) || (u8Data > 19))
    {
        t_EditChannelState.ChanNum = 0x19;
    }
    else if(u8Data <= 19)
    {
        u8Data--;
        t_EditChannelState.ChanNum = ConvertDecimaltoBCD(u8Data);
    }
    g_u8ParamStepOK = YES;
    DispChannelNum(1);
}

/*********************************************************
*��������ProcEditWorkMode_Cut1
*����  ������ģʽ��1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditWorkMode_Cut1(void)
{
	uint8_t u8Mode = 0;
    u8Mode = t_EditChannelState.WorkMode;

  	if(u8Mode > WORKMODE_FIX)
    {
        u8Mode--;   
    }
	else
	{
		if(isSecureOK())
		{
			u8Mode = WORKMODE_SHOP;
		}
		else
		{
			u8Mode = WORKMODE_HOP;
		}
	}
    t_EditChannelState.WorkMode = u8Mode;
    g_u8ParamStepOK             = YES;
    DispWorkMode(1);
}

/*********************************************************
*��������ProcEditFreOrTab_Cut1
*����  ��Ƶ�ʲ���5KHz���ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditFreOrTab_Cut1(void)
{
    uint8_t u8Data = 0;
    uint16_t u16Data = 0;

    if(t_CurChannelState.WorkMode%2 == 0)       // ��Ƶģʽ
    {
        if(g_u8NumIndex == 1)
        {
            return;
        }
        u8Data = ConvertBCDtoDecimal(t_EditChannelState.TableNum);
        if(u8Data == 0)
        {
            t_EditChannelState.TableNum = 0x19;
            g_u8ParamStepOK             = YES;
        }
        else if(u8Data <= 19)
        {
            t_EditChannelState.TableNum = ConvertDecimaltoBCD(u8Data-1);
            g_u8ParamStepOK             = YES;
        }
        DispTableNum(1);
        return;
    }
 
    // ��Ƶģʽ
    if((g_u8NumIndex > 0) && (g_u8NumIndex < 5))
    {
        return;
    }
    
    u16Data = ((uint16_t)(t_EditChannelState.Freq[0] & 0x07)) * 10000;
    
    u8Data = ConvertBCDtoDecimal(t_EditChannelState.Freq[1]);
    u16Data += ((uint16_t)u8Data) * 100; 
    
    u8Data = ConvertBCDtoDecimal(t_EditChannelState.Freq[2]);
    u16Data += (uint16_t)u8Data;
    
    if((u16Data - 5) < 22500)
    {
        t_EditChannelState.Freq[0] = 5;
        t_EditChannelState.Freq[1] = 0x12;
        t_EditChannelState.Freq[2] = 0;
        g_u8ParamStepOK            = YES;
    }
    else
    {
        u16Data -= 5;
        t_EditChannelState.Freq[0] = (uint8_t)(u16Data/10000);
        t_EditChannelState.Freq[1] = (uint8_t)((u16Data/1000%10) << 4) + (uint8_t)(u16Data/100%10);
        t_EditChannelState.Freq[2] = (uint8_t)((u16Data/10%10) << 4) + (uint8_t)(u16Data%10);
        g_u8ParamStepOK            = YES;
    }
    DispFrequency(1);
}

/*********************************************************
*��������ProcEditPower_Cut1
*����  ����̨���ʼ�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditPower_Cut1(void)
{
	switch(t_EditRadioState.Power)
	{
		case 3:
			t_EditRadioState.Power = 1;
			break;
		case 1:
			t_EditRadioState.Power = 0;
			break;
		case 0:
			t_EditRadioState.Power = 3;
			break;
		default:
			t_EditRadioState.Power = 0;
			break;
	}   
    g_u8ParamStepOK = YES;
    DispRadioPower(1);
}

/*********************************************************
*��������ProcEditMac_Cut1
*����  ��վ�ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditMac_Cut1(void)
{
    uint8_t u8Data = 0;

    if(g_u8NumIndex == 1)
    {
        return;
    }

    u8Data = ConvertBCDtoDecimal(t_EditRadioState.MAC);

    if((u8Data == 0) || (u8Data > 31))
    {
        t_EditRadioState.MAC = 0x31;
    }
    else if(u8Data <= 31)
    {
        u8Data--;
        t_EditRadioState.MAC = ConvertDecimaltoBCD(u8Data);
    }
    g_u8ParamStepOK = YES;
    DispMacNum(1);
}

/*********************************************************
*��������ProcEditMac_Cut2
*����  ��վ�ż�1
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditMac_Cut2(void)
{
    uint8_t u8Data = 0;

    if(g_u8NumIndex == 1)
    {
        return;
    }

    u8Data = ConvertBCDtoDecimal(t_EditRadioState.MAC);

    if((u8Data == 0) || (u8Data > 19))
    {
        t_EditRadioState.MAC = 0x19;
    }
    else if(u8Data <= 19)
    {
        u8Data--;
       t_EditRadioState.MAC = ConvertDecimaltoBCD(u8Data);
    }
    g_u8ParamStepOK = YES;
    DispMacNum(1);
}

/*********************************************************
*��������ProcEditDateTime_Num
*����  ������ʱ�����ҳ�²����������봦��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcEditDateTime_Num(void)
{
    switch(g_u8CurMenuItem)
    {
        case INDEX_EDIT_DATE:
            ProcNumKey_Date();
            break;
    
        case INDEX_EDIT_TIME:
            ProcNumKey_Time();
            break;
    
        default:
            break;
    }
}

/*********************************************************
*��������IsFreqNumvalid
*����  ���ж�����Ƶ�������Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFreqNumvalid(uint8_t KeyValue)
{
    uint8_t u8Result = 0;

    switch(g_u8NumIndex)
    {
        case 0:
        case 5:
            u8Result = IsFreqvalid_FirstNum(KeyValue);
            break;

        case 1:
            u8Result = IsFreqvalid_SecondNum(KeyValue);
            break;

        case 2:
            u8Result = IsFreqvalid_ThirdNum(KeyValue);
            break;

        case 3:
             u8Result = IsFreqvalid_ForthNum(KeyValue);
            break;

        case 4:
             u8Result = IsFreqvalid_FifthNum(KeyValue);
            break;

        default:
            u8Result = NO;
            break;
    }
    return u8Result;
}

/*********************************************************
*��������IsFreqvalid_FirstNum
*����  ���ж�����ĵ�һλƵ�������Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFreqvalid_FirstNum(uint8_t KeyValue)
{
    if((KeyValue < 2) || (KeyValue > 5))
    {
        return NO;
    }
    g_u8ParamStepOK = NO;
    return YES;
}

/*********************************************************
*��������IsFreqvalid_SecondNum
*����  ���ж�����ĵڶ�λƵ�������Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFreqvalid_SecondNum(uint8_t KeyValue)
{
    if((g_u8NumBuf[0] == 2) && (KeyValue <= 1))
    {
        return NO;
    }
    else if((g_u8NumBuf[0] == 5) && (KeyValue >= 2))
    {
        return NO;
    }
    return YES;
}

/*********************************************************
*��������IsFreqvalid_ThirdNum
*����  ���ж�����ĵ���λƵ�������Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFreqvalid_ThirdNum(uint8_t KeyValue)
{
    uint16_t u16Data = 0;

    u16Data = (uint16_t)(g_u8NumBuf[0]*10 + g_u8NumBuf[1]);
    if((u16Data == 22) && (KeyValue < 5))
    {
        return NO;
    }
    else if((u16Data == 51) && (KeyValue > 2))
    {
        return NO;
    }
    return YES;
}

/*********************************************************
*��������IsFreqvalid_ForthNum
*����  ���ж�����ĵ���λƵ�������Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFreqvalid_ForthNum(uint8_t KeyValue)
{
    uint16_t u16Data = 0;

    u16Data = (uint16_t)(g_u8NumBuf[0]*100 + g_u8NumBuf[1]*10 + g_u8NumBuf[2]);
    if((u16Data == 512) && (KeyValue > 0))
    {
        return NO;
    }
    return YES;
}

/*********************************************************
*��������IsFreqvalid_FifthNum
*����  ���ж�����ĵ���λƵ�������Ƿ���Ч
*����  ����
*���  ����
*����ֵ����
***********************************************************/
uint8_t IsFreqvalid_FifthNum(uint8_t KeyValue)
{
    uint16_t u16Data = 0;

    u16Data = (uint16_t)(g_u8NumBuf[0]*1000 + g_u8NumBuf[1]*100 + g_u8NumBuf[2]*10 + g_u8NumBuf[3]);
    if(KeyValue != 0)
    {
        if(KeyValue != 5)
        {
            return NO;
        }
        else if(u16Data == 5120)
        {
            return NO;
        }
    }
    return YES;
}

/*********************************************************
*��������DispChannelNum
*����  ����ʾ�ŵ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispChannelNum(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurChannelState.ChanNum >> 4) + '0';// ѹ��BCD�� 0x12
        g_u8DispBuf[1] = (t_CurChannelState.ChanNum & 0x0F) + '0';
        PrintString(COL_WORD8+WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
    }
    else
    {
        g_u8DispBuf[0] = (t_EditChannelState.ChanNum >> 4) + '0';
        g_u8DispBuf[1] = (t_EditChannelState.ChanNum & 0x0F) + '0';
        PrintStringReverse(COL_WORD8+WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
    }
}

/*********************************************************
*��������DispMacNum
*����  ����ʾվ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispMacNum(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurRadioState.MAC >> 4) + '0';// ѹ��BCD�� 0x12
        g_u8DispBuf[1] = (t_CurRadioState.MAC & 0x0F) + '0';
		PrintString(COL_WORD3+WIDTH_HALF, ROW_TEXT08, "    ", 2);
        PrintString(COL_WORD3+WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
    }
    else
    {
        g_u8DispBuf[0] = (t_EditRadioState.MAC >> 4) + '0';
        g_u8DispBuf[1] = (t_EditRadioState.MAC & 0x0F) + '0';
		PrintStringReverse(COL_WORD3+WIDTH_HALF, ROW_TEXT08, "    ", 2);
        PrintStringReverse(COL_WORD3+WIDTH_HALF, ROW_TEXT08, g_u8DispBuf, 2);
    }
}

/*********************************************************
*��������DispWorkMode
*����  ����ʾ����ģʽ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispWorkMode(uint8_t rev)
{
    uint8_t i = 0;
    Mode_TypeDef mWorkMode[4] = {{WORKMODE_FIX, "����"}, {WORKMODE_HOP, "����"},
                                  {WORKMODE_SFIX, "����"}, {WORKMODE_SHOP, "����"}};

    if(rev == 0)
    {
	    i = (t_CurChannelState.WorkMode - WORKMODE_FIX)%4;
		PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT05, mWorkMode[i].Mode, WORD);
	}
	else if(rev == 1)
	{
        i = (t_EditChannelState.WorkMode - WORKMODE_FIX)%4;
        PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT05, mWorkMode[i].Mode, WORD);
    }
}

/*********************************************************
*��������DispFrequency
*����  ����ʾƵ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispFrequency(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurChannelState.Freq[0] & 0x0F) + '0';
        g_u8DispBuf[1] = (t_CurChannelState.Freq[1] >> 4) + '0';
        g_u8DispBuf[2] = (t_CurChannelState.Freq[1] & 0x0F) + '0';
        g_u8DispBuf[3] = '.';
        g_u8DispBuf[4] = (t_CurChannelState.Freq[2] >> 4) + '0';
        g_u8DispBuf[5] = (t_CurChannelState.Freq[2] & 0x0F) + '0';
        g_u8DispBuf[6] = 'M';
        g_u8DispBuf[7] = 'H';
        g_u8DispBuf[8] = 'z';
        PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT04,  g_u8DispBuf, 9);
    }
    else if(rev == 1)
    {
        g_u8DispBuf[0] = (t_EditChannelState.Freq[0] & 0x0F) + '0';
        g_u8DispBuf[1] = (t_EditChannelState.Freq[1] >> 4) + '0';
        g_u8DispBuf[2] = (t_EditChannelState.Freq[1] & 0x0F) + '0';
        g_u8DispBuf[3] = (t_EditChannelState.Freq[2] >> 4) + '0';
        g_u8DispBuf[4] = (t_EditChannelState.Freq[2] & 0x0F) + '0';

        PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT04, g_u8DispBuf, 3);
        PrintStringReverse(COL_WORD5 + WIDTH_HALF, ROW_TEXT04, &g_u8DispBuf[3], 2);
    }
}


/*********************************************************
*��������DispTableNum
*����  ����ʾ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispTableNum(uint8_t rev)
{
    g_u8DispBuf[2] = '-';
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurChannelState.TableNum >> 4) + '0';
        g_u8DispBuf[1] = (t_CurChannelState.TableNum & 0x0F) + '0';
        PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT04,  g_u8DispBuf, 3);
    }
    else
    {
        g_u8DispBuf[0] = (t_EditChannelState.TableNum >> 4) + '0';
        g_u8DispBuf[1] = (t_EditChannelState.TableNum & 0x0F) + '0';
        PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT04,  g_u8DispBuf, 2);
    }
}

/*********************************************************
*��������DispNetNum
*����  ����ʾ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void DispNetNum(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurChannelState.NetNum[0] & 0x03) + '0';
        g_u8DispBuf[1] = (t_CurChannelState.NetNum[1] >> 4)   + '0';
        g_u8DispBuf[2] = (t_CurChannelState.NetNum[1] & 0x0F) + '0';
        PrintString(COL_WORD5, ROW_TEXT04,  g_u8DispBuf, 3);
        PrintString(COL_WORD6 + WIDTH_HALF, ROW_TEXT04,  "   ", 3);   /*�ڸǶ�Ƶ��MHz*/
    }
    else
    {
        g_u8DispBuf[0] = (t_EditChannelState.NetNum[0] & 0x03) + '0';
        g_u8DispBuf[1] = (t_EditChannelState.NetNum[1] >> 4)   + '0';
        g_u8DispBuf[2] = (t_EditChannelState.NetNum[1] & 0x0F) + '0';
        PrintStringReverse(COL_WORD5, ROW_TEXT04,   g_u8DispBuf, 3);
    }
}

#if 0
/*********************************************************
*��������ProcMenuKey_QueryVersion
*����  ����̨��ѯ�źŰ�����汾�����°�����Ӧ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void ProcMenuKey_QueryVersion(void)
{
    if(g_u8KeyValue == KEY_F6)
    {
        GoToSuperiorMenu();        
    }
}
#endif

/*********************************************************
*��������RespondKey
*����  ��������Ӧ����
*����  ����
*���  ��������ֵ
*����ֵ����
***********************************************************/
ProcessFunction_TypeDef t_ProcMenuKey[] = 
{
//	{MENU_MAIN_PAGE,          ProcMenuKey_MainPage},
	{MENU_SET_F1,             ProcMenuKey_SetF1},
	{MENU_SET_F2,             ProcMenuKey_SetF2},
	{MENU_SET_F3,             ProcMenuKey_SetF3},
	{MENU_SET_F4,             ProcMenuKey_SetF4},

	//  F1�²˵�����  
	{MENU_PARAMRADIOIP,       ProMenuKey_ParamRadioIp},
	{MENU_PARAMRADIOMASK,     ProMenuKey_ParamRadioMask},
	{MENU_PARAMFACTORYSET,    ProMenuKey_ParamFactorySet},
//	{MENU_PARAMENTFACTORYSET, ProMenuKey_ParamEntFactorySet},

	//  F2�²˵�����
	{MENU_PARAMLINKBUILD,  	  ProMenuKey_ParamLinkBuild},
	{MENU_PARAMLINKMAINTAIN,  ProMenuKey_ParamLinkMaintain},
	{MENU_PARAMLINKQUERY,  	  ProMenuKey_ParamLinkQuery},
//  {MENU_PARAMLINKQUERYTWO,  ProMenuKey_ParamLinkQueryTwo},

	//  F3�²˵�����		
	{MENU_PARAMWORKSTATE,     ProMenuKey_ParamWorkState},
	{MENU_PARAMDIGTRANSTATIS, ProMenuKey_ParamDigTranStatis},
	{MENU_PARAMDIGTRANREPORT, ProMenuKey_ParamDigTranReport},
	{MENU_PARAMDEBUGINFO,     ProMenuKey_ParamDebugInfo},
	{MENU_PARAMRUNTIME,       ProMenuKey_ParamRunTime},

	//  F4�²˵�����		
	{MENU_PARAMDATETIME,      ProMenuKey_ParamDateTime},
	{MENU_PARAMRADIOTEST, 	  ProMenuKey_ParamRadioTest},
	{MENU_PARAMPOWERCHECK,    ProMenuKey_ParamPowerCheck},
	{MENU_PARAMUNLIGHTONOFF,  ProMenuKey_ParamUnlightOnOff},
	{MENU_PARAMVERSIONINFO,   ProMenuKey_ParamVersionInfo},
	//{MENU_PARAMENTPOWERCHECK, ProMenuKey_ParamEntPowerCheck},
};

void RespondKey(void)
{
    uint8_t i = 0;
	void (*p)(void);

   
    if(g_u8KeyPressed == NO)
    {
        return;
    }

    g_u8KeyPressed = NO;
    for(i=0; i<PROCMENUKEY_MAXNUM; i++)
    {
        if(g_u8CurMenuID == t_ProcMenuKey[i].Fuction_ID)
        {
            p = t_ProcMenuKey[i].ProcessFuction;
            (*p)();
            break;
        }			 
    }
}

/*********************************************************
*��������GetPowerOnTime
*����  ����ȡ����ʱ��
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetPowerOnTime(void)
{
    //uint8_t u8Data = 0;
    //uint8_t u8Month = 0;
    //uint16_t u16Year = 0;

    //RTC_ReadTime();
    ReadCode(&t_SumRunTime.Second);  //��ÿ����洢��ROM����ʷʱ��
    //memcpy(&t_PoweronTime, &t_CurTime, sizeof(TOD_TypeDef));
}


/*********************************************************
*��������PTT_Ctrl
*����  ��PTT���ƺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PTT_Ctrl(void)
{
    //static uint8_t su08PTT_State = NO;
    
    if((g_u8CurMenuID == MENU_POWER_ON) || (g_u8CurMenuID == MENU_POWER_OFF))
    {
		return;
    }

    /*if(ReadGpioBit(ZKPTT1_IN_PIN) == 0)
    {
        ClrGpioBit(SEL_MIC1_PIN);   // ѡͨ��һ·��Ƶ���,CD4052����:[BA]=[00]
        ClrGpioBit(SEL_MIC2_PIN);
        ClrGpioBit(PTT_IN_PIN);     // ֪ͨ������PTT����
        return;
    }

    if(ReadGpioBit(ZKPTT2_IN_PIN) == 0)
    {
        SetGpioBit(SEL_MIC1_PIN);   // ѡͨ�ڶ�·��Ƶ,CD4052����:[BA]=[01]
        ClrGpioBit(SEL_MIC2_PIN);
        ClrGpioBit(PTT_IN_PIN);     // ֪ͨ������PTT����
        return;
    }*/

    if(ReadGpioBit(BDPTT_IN_PIN ) == 0)//lys�޸�
    {
        if(t_CurRadioState.Power == POWER_DUTY)
        {
            g_u8NoSendFlag = YES;
			#if 0
            if(su08PTT_State == NO)
            {
                su08PTT_State = YES;
                if(g_u8CurMenuID == MENU_REMOTE)
                {
                    PrintStringReverse(COL_WORD1, ROW_STATE2, "ң��", WORD);
                    PrintString(COL_WORD3+WIDTH_HALF, ROW_STATE2, "ֵ�ؽ���!", WORD);
                }
                else
                {
                    ClearTextState2();
                    PrintString(COL_WORD1, ROW_STATE2, "״̬:ֵ�ؽ���!", WORD);
                }
            }
			#endif
        }
        else
        {
            g_u8NoSendFlag = NO;
            ClrGpioBit(SEL_MIC1_PIN);   // ѡͨ����·��Ƶ,CD4052����:[BA]=[10]
            SetGpioBit(SEL_MIC2_PIN);
            ClrGpioBit(PTT_IN_PIN);     // ֪ͨ������PTT����
        
        // ����ѡ��
            SetGpioBit(SEL_SP_PIN);
        }
        return;
    }
    //else
    {
        //su08PTT_State = NO;
    }
    g_u8NoSendFlag = NO;
    ClrGpioBit(SEL_SP_PIN);         // ��PTT�ź�ʱ
    SetGpioBit(PTT_IN_PIN);         // ֪ͨ������PTT����
}

/*********************************************************
*��������WriteVolDataTo5402
*����  ��д�������ݵ�MAX5402оƬ
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void WriteVolDataTo5402(uint8_t VolData)
{
    uint8_t i = 0, u8Data = 0;
    uint8_t u8VolLevel[4] = {0x00, 0x40, 0x80, 0xC0};

    //ssl20140521����ʱ���öϿ��������
    if(0 == VolData)
    {
        SetGpioBit(SEL_PTT3_PIN);
        return;
    }
    else
    {
        ClrGpioBit(SEL_PTT3_PIN);
    }

    ClrGpioBit(CON_5402CS_PIN);
    for(i=0; i<8; i++)
    {
        ClrGpioBit(CON_5402CLK_PIN);
        u8Data = (u8VolLevel[VolData] << i) & 0x80;
        if(u8Data)
        {
            SetGpioBit(CON_5402DIN_PIN);
            Delay_nUS(4);
        }
        else
        {
            ClrGpioBit(CON_5402DIN_PIN);
            Delay_nUS(4);
        }
        SetGpioBit(CON_5402CLK_PIN);
        Delay_nUS(4);
    }
    SetGpioBit(CON_5402CS_PIN);
}

/*********************************************************
*��������Volume_Cut1
*����  ���������ƺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Volume_Cut1(void)
{
    if(g_u8CurVolume > VOLUME_SILENCE)
    {
        g_u8CurVolume--;
    }
}
    
/*********************************************************
*��������Volume_Ctrl
*����  ���������ƺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void Volume_Ctrl(void)
{
    if(g_u8KeyPressed == NO)
    {
        return;
    }

    if(g_u8KeyValue == KEY_VOL_UP)
    {
        g_u8KeyPressed = NO;			
        Volume_Add1();
    }
    else if(g_u8KeyValue == KEY_VOL_DOWN)
    {
		g_u8KeyPressed = NO;
        Volume_Cut1();
    }
}

/*********************************************************
*��������PowerOnOff_Ctrl
*����  �����ػ����ƺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void PowerOnOff_Ctrl(void)
{
    uint16_t u8TimeOut = 500;


    g_u8KeyBuf[0] = g_u8KeyBuf[1];
    g_u8KeyBuf[1] = ReadGpioBit(KEY_POWER_PIN);/*�����Կظߵ�ƽΪ����*/
    //g_u8KeyBuf[0] = 0;
	//g_u8KeyBuf[1] = 0;/*��ʱ�޸Ŀ�����������*/
    
    if(g_u8KeyBuf[0] == g_u8KeyBuf[1])
    {
        return;
    }
    
    if((g_u8KeyBuf[0] == 0) && (g_u8KeyBuf[1] == 1))    // ����
    {
		//ReadCode(au8Code);  // ������ȡ������ʱ��
        while(u8TimeOut--)    // HSL.20141128��Ϊ��ֹ��ƽ��������ʱ���ټ��һ�ε�ƽ
        {
            ;
        }    
        if(ReadGpioBit(KEY_POWER_PIN) == 0)
        {
            return;
        }
		
        //ssl20140521��Ԫ˧Ҫ�󿪻��Ȳ�������led��
        ClrGpioBit(LED_POWER2_PIN);     // ��Դ����ʾ��ɫ
        SetGpioBit(LED_POWER1_PIN);  
        ClrGpioBit(LED_Tx_PIN);			// �շ�����ʾ��ɫ
        SetGpioBit(LED_Rx_PIN);         
        ClrGpioBit(LED_ALARM2_PIN);
		SetGpioBit(LED_ALARM1_PIN);     // ���ϵ���ʾ��ɫ

        Delay_nMS(800);/*��������ʱ300ms*/

        ClrGpioBit(LED_POWER2_PIN);     // ��Դ�ƿ���
        ClrGpioBit(LED_POWER1_PIN);
        ClrGpioBit(LED_Rx_PIN);         // �շ��ƿ���
        ClrGpioBit(LED_Tx_PIN);
        ClrGpioBit(LED_ALARM2_PIN);     // ���ϵƿ���
        ClrGpioBit(LED_ALARM1_PIN);

        g_u8PowerOn = YES;
        ClrGpioBit(CON_POWER_PIN);      // �����ذ����������ƽ
        SetGpioBit(LED_POWER2_PIN);     // ��Դ����ʾ��ɫ
        ClrGpioBit(LED_POWER1_PIN);  

		g_u8CurMenuID = MENU_POWER_ON;	// ʶ�𵽿�����������Ϊ��������ID
		//GetPowerOnTime();   //��ȡ����ʱ��
        LCD_init();                     // ��ʾǰ�ȳ�ʼ��8806
        DispStartUpPage();              // ��ʾ��̨��������
    }
    else if((g_u8KeyBuf[0] == 1) && (g_u8KeyBuf[1] == 0))    // �ػ�
    {
		//WriteCode(&t_SubRunTime.Minute); //�ػ�֮ǰ��¼����������ʱ��
        while(u8TimeOut--);     // HSL.20141128��Ϊ��ֹ��ƽ��������ʱ���ټ��һ�ε�ƽ
        if(ReadGpioBit(KEY_POWER_PIN) == 1)
        {
            return;
        }
		
		g_u8PowerOn   = NO;
        g_u8CurMenuID = MENU_POWER_OFF;   // ֻҪ���¿��ؼ����Ͱѽ���ID����ΪMENU_POWER_ONOFF
        LCD_Clear(TOP);
        LCD_Clear(BOTTOM);
		PrintString(COL_WORD6, 0x65, "�������ã����ڹػ�...", WORD);
		Delay_nMS(100);
		ClrGpioBit(CON_POWER_PIN);

		#if 0
        if(t_CurChannelState.NetMode > NETMODE_LINK)
        {
            if(g_u8TempNetMode > NETMODE_LINK)
            {
                g_u8TempNetMode = NETMODE_PRN;
            }
            memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState));
            t_EditChannelState.NetMode = g_u8TempNetMode;
            Set_ChanParam();
        }     
		#endif
        Set_PowerOff();				// �����ذ巢�͹ػ�ָ��
        g_u8PowerOnOffTick = 0;	// ��ʼ����ػ�ʱ��
    }
//#endif
}

/*********************************************************
*��������AlarmLed_Ctrl
*����  ���澯�Ƶƿ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void AlarmLed_Ctrl(uint8_t *pState)
{
    if(t_CurRadioState.ParamState == YES)
    {
        if((pState[0] == 0) && ((pState[1] & 0x07) != 0x07))
        {
            //������ɫ�������
            ClrGpioBit(LED_ALARM2_PIN);
            ClrGpioBit(LED_ALARM1_PIN);
        }
        else
        {
            //������ɫ�������
            ClrGpioBit(LED_ALARM2_PIN);     // ������ʾ��ɫ
            SetGpioBit(LED_ALARM1_PIN);   
        }
    }
    else
    {
        ClrGpioBit(LED_ALARM2_PIN);     // �ػ����ϵ���Ϊ��
        ClrGpioBit(LED_ALARM1_PIN);   
    }
}

/*********************************************************
*��������Rx_Tx_Led_Ctrl
*����  ���շ��ƿ���
*����  ����
*���  ����
*����ֵ����
*NOTE  : CS,20131029,�޸ĳ���ȡ����ʱ��˸��Ϊ��Ҫ��?���ҿ���ʵ����˸?
		 �޸ĵƵ����ȼ���������ߣ�����յƣ����߽�Ϊ����
***********************************************************/
void Rx_Tx_Led_Ctrl(uint8_t State)
{
    uint8_t u8DataState = 0, u8VoiceState = 0, u8LinkTestState = 0;
	static uint8_t su8LastState = 0;
	//static uint8_t  su8RtxState = 0;

    u8DataState     = State & 0x03;
    u8VoiceState    = (State >> 2) & 0x03;
    u8LinkTestState = (State >> 4) & 0x03;

    if((u8DataState | u8VoiceState | u8LinkTestState) == RTX)
    {
        if(su8LastState != State)
        {
            g_u8RTxTimeFlag  = YES;
            g_u16RTxTimeTick = 0;
			su8LastState     = State;
        }
    }
	else if(State != su8LastState)/*����򱣳�ԭ״*/
	{
		if((u8DataState == TX) || (u8VoiceState == TX)
			|| (u8LinkTestState == TX))
	    {
			SetGpioBit(LED_Rx_PIN);     // ����Ϊ��ɫ
			ClrGpioBit(LED_Tx_PIN);   
	    }
		else if((u8DataState == RX) || (u8VoiceState == RX)
			     || (u8LinkTestState == RX))
	    {
			ClrGpioBit(LED_Rx_PIN);     // �յ�Ϊ��ɫ
			SetGpioBit(LED_Tx_PIN);   
	    }
	    else if((u8DataState == WAIT) && (u8VoiceState == WAIT)
                 && (u8LinkTestState == WAIT))
	    {
	        ClrGpioBit(LED_Rx_PIN);   
	        ClrGpioBit(LED_Tx_PIN);   
	    }	   
		
        g_u8RTxTimeFlag = NO;
		su8LastState    = State;
	}	
	else
	{
		;/*������״�������вٿ�*/
	}
}

/*********************************************************
*��������GetDate_FirstNum
*����  ����ȡ���ڵ�һλ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetDate_FirstNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;

    g_u8ParamEditIndex = g_u8CurMenuItem;
    g_u8NumIndex = 1;
    memset(g_u8NumBuf, 0, 6); // g_u8NumBuf�еĺ�6���ֽڸ�ֵΪ0
    g_u8NumBuf[0] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD8, ROW_TEXT05, &u8Data, 1);
    PrintString(COL_WORD8+WIDTH_HALF, ROW_TEXT05, "-/--/--", 7);
}

/*********************************************************
*��������GetDate_SecondNum
*����  ����ȡ���ڵڶ�λ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetDate_SecondNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;

    g_u8NumIndex = 2;
    g_u8NumBuf[1] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD8+WIDTH_HALF, ROW_TEXT05,   &u8Data, 1);
}

/*********************************************************
*��������GetDate_ThirdNum
*����  ����ȡ���ڵ���λ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetDate_ThirdNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;

    if(g_u8KeyValue <= 1)
    {
        g_u8NumIndex = 3;
        g_u8NumBuf[2] = KeyValue;
        u8Data = KeyValue + '0';
        PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT05,   &u8Data, 1);
    }
}

/*********************************************************
*��������GetDate_ForthNum
*����  ����ȡ���ڵ���λ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetDate_ForthNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;

    if((g_u8NumBuf[2] == 0) && (KeyValue == 0))
    {
        return;
    }
    else if((g_u8NumBuf[2] == 1) && (KeyValue > 2))
    {
        return;
    }
    
    g_u8NumIndex = 4;
    g_u8NumBuf[3] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD10, ROW_TEXT05,   &u8Data, 1);
}

/*********************************************************
*��������GetDate_FifthNum
*����  ����ȡ���ڵ���λ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetDate_FifthNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;
    uint8_t u8Month = 0;

    u8Month = g_u8NumBuf[2]*10 + g_u8NumBuf[3];
    if(KeyValue > 3)
    {
        return;
    }
    else if((u8Month == 2) && (KeyValue == 3))  // 2��
    {
        return;
    }

    g_u8NumIndex = 5;
    g_u8NumBuf[4] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD11, ROW_TEXT05, &u8Data, 1);
}

/*********************************************************
*��������GetDate_SixthNum
*����  ����ȡ���ڵ���λ����
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void GetDate_SixthNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;
    uint8_t u8Month = 0;
    uint16_t u16Year = 0;

    u16Year = (uint16_t)(2000 + g_u8NumBuf[0]*10 + g_u8NumBuf[1]);
    u8Month = g_u8NumBuf[2]*10 + g_u8NumBuf[3];

    if(g_u8NumBuf[4] == 0)
    {
        if(KeyValue == 0)
        {
            return;
        }
    }
    else if(g_u8NumBuf[4] == 2)
    {
        if((u16Year%4 != 0) && (u8Month == 2) && (KeyValue == 9))
        {
            return;
        }
    }
    else if(g_u8NumBuf[4] == 3)
    {
        if((IsMonth30Days(u8Month)) && (KeyValue != 0))
        {
            return;
        }
        else if((IsMonth31Days(u8Month)) && (KeyValue > 1))
        {
            return;
        }
    }
    g_u8NumIndex = 6;
    g_u8NumBuf[5] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD11+WIDTH_HALF, ROW_TEXT05,   &u8Data, 1);
}



