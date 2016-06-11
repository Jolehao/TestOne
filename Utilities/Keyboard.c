#include "all.h"


uint8_t g_u8ScanState    = 1;
uint8_t g_u8Keyline_y[6] = {1,1,1,1,1,1}; 
uint8_t g_u8KeyBuf[2]    = {0}; 


/*********************************************************
*函数名：ScanKeyState1
*功能  ：按键扫描状态1函数
*输入  ：无
*输出  ：按键键值
*返回值：无
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
*函数名：ScanKeyState2
*功能  ：按键扫描状态2函数
*输入  ：无
*输出  ：按键键值
*返回值：无
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
*函数名：ScanKeyState3
*功能  ：按键扫描状态3函数
*输入  ：无
*输出  ：按键键值
*返回值：无
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
*函数名：ScanKeyState4
*功能  ：按键扫描状态4函数
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ReadKeyState
*功能  ：读取按键状态
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ScanKey
*功能  ：按键扫描函数
*输入  ：无
*输出  ：按键键值
*返回值：无
***********************************************************/
void ScanKey(void)
{
// 无按键按下
    g_u8Temp = ReadKeyState();
    if(g_u8Temp >= 6)
    {
        g_u8KeyRelesed = YES;
    }

// 检测到有键按下时，若当前按键未释放则跳出扫描
    if(g_u8KeyRelesed == NO)
    {
        return;
    }

    if(g_u8Temp < 6)
    {
        g_u8KeyPressed = YES;
        g_u8KeyRelesed = NO;
    }
    
// 按键已释放
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
*函数名：SelectItem_UP
*功能  ：向上切换选项
*输入  ：最大选项数
*输出  ：无
*返回值：无
*NOTE  : 除非有特殊要求，否则高级设置与其他无异,CS
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
*函数名：SelectItem_DOWN
*功能  ：向下切换选项
*输入  ：最大选项数
*输出  ：无
*返回值：无
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
*函数名：SelectItem_Left
*功能  ：向左切换选项
*输入  ：最大选项数
*输出  ：无
*返回值：无
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
*函数名：SelectItem_LR_LinkBuild
*功能  ：左右切换MAC号
*输入  ：最大选项数
*输出  ：无
*返回值：无
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
*函数名：SelectItem_LR_WorkState
*功能  ：左右切换MAC号
*输入  ：最大选项数
*输出  ：无
*返回值：无
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
*函数名：SelectMenuItem
*功能  ：按键响应函数
*输入  ：按键键值，最大选项数
*输出  ：无
*返回值：无
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
*函数名：ProcMainPageKey_F1
*功能  ：F1-设置菜单参数页响应函数
*输入  ：无
*输出  ：按键键值
*返回值：无
***********************************************************/
void ProcMainPageKey_F1(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // 保存上一页菜单选项
	ClearMainPageLine();
	DispMenuText_PageF1();
}

/*********************************************************
*函数名：ProcMainPageKey_F2
*功能  ：F2-链路菜单参数页响应函数
*输入  ：无
*输出  ：按键键值
*返回值：无
***********************************************************/
void ProcMainPageKey_F2(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // 保存上一页菜单选项
	ClearMainPageLine();
	DispMenuText_PageF2();
}

/*********************************************************
*函数名：ProcMainPageKey_F3
*功能  ：F3-监控菜单参数页响应函数
*输入  ：无
*输出  ：按键键值
*返回值：无
***********************************************************/
void ProcMainPageKey_F3(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // 保存上一页菜单选项
	ClearMainPageLine();
	DispMenuText_PageF3();
}

/*********************************************************
*函数名：ProcMainPageKey_F4
*功能  ：F4-系统菜单参数页响应函数
*输入  ：无
*输出  ：按键键值
*返回值：无
***********************************************************/
void ProcMainPageKey_F4(void)
{
	g_u8ParamEditIndex = 0;
    g_u8ParamStepOK    = NO;
	g_u8ParamEditState = NO;

	g_u8MenuItem_Bak1 = g_u8CurMenuItem;  // 保存上一页菜单选项
	ClearMainPageLine();
	DispMenuText_PageF4();
}
#endif

/*********************************************************
*函数名：ProcMenuKey_SetF1
*功能  ：F1-设置菜单界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcMenuKey_SetF2
*功能  ：F2-链路菜单界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcMenuKey_SetF3
*功能  ：F3-监控菜单界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
	  
	  PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>选择菜单                 ", WORD);
      PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F6>返回上一级菜单              ", WORD);
    }
	#endif
}

/*********************************************************
*函数名：ProcMenuKey_SetF4
*功能  ：F4-系统菜单界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamRadioIp
*功能  ：电台IP参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamRadioMask
*功能  ：电台掩码参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamFactorySet
*功能  ：恢复出厂设置参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
			PrintString(COL_WORD5, ROW_TEXT05,  "正在恢复...           ", WORD);
			
			PrintString(WIDTH_HALF, ROW_TEXT09, "                                         ", WORD);
			PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单 ", WORD);
			Set_DefaultParam();
		}
	}
}

/*********************************************************
*函数名：ProMenuKey_ParamLinkBuild 
*功能  ：链路建立参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
		g_u8ParamEditIndex = YES;  //判断是否需要进行建链操作的标志
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
*函数名：ProMenuKey_ParamLinkMaintain 
*功能  ：链路维护参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamLinkQuery 
*功能  ：链路查询参数页界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamWorkState 
*功能  ：工作状态参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
		PrintVerticalLine(20,48,0x00,143); //191-48=143,从站
		DispMenuText_PageF1();
    }
	else if(g_u8KeyValue == KEY_F2)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,从站
		DispMenuText_PageF2();
    }
	else if(g_u8KeyValue == KEY_F3)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,从站
		DispMenuText_PageF3();
    }
	else if(g_u8KeyValue == KEY_F4)
    {
		ClearTextWindow();
		ClearHorizonLine(0,47,0x00);
		ClearHorizonLine(0,71,0x00);
		PrintVerticalLine(20,48,0x00,23); //70-48=22
		PrintVerticalLine(20,48,0x00,143); //191-48=143,从站
		DispMenuText_PageF4();
    }
	
	if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		SelectMenuItem(6);				// 选择菜单选项
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
*函数名：ProMenuKey_ParamDigTranStatis 
*功能  ：数传统计参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
	if(IsNumberKey(g_u8KeyValue)) //输入Mac号
	{
		ProcNumKey_MacNum_Test();  // test 版本
	}
	else if(g_u8KeyValue == KEY_ENT) //清空收发数据
	{
		//ProcParamWorkState_ENT();
		if(g_u8ParamEditIndex != 0)   // 已输入Mac  
		{	
			// 
			if(t_EditStatisFrame.MacNum == t_CurStatisFrame.MacNum)
			{
				// 正显Mac
				Set_ClrRFDigtal();
			}
			else
			{
				// 一直反显
				PrintString(COL_WORD7, ROW_TEXT08, "请重新输入!", WORD);	
			}
		}
	}
}

/*********************************************************
*函数名：ProMenuKey_ParamDigTranReport 
*功能  ：数传汇报参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
	if(IsNumberKey(g_u8KeyValue)) //输入Mac号
	{
		ProcNumKey_MacNum_Test();  // test 版本
	}
	else if(g_u8KeyValue == KEY_ENT) //清空收发数据
	{
		//ProcParamWorkState_ENT();
		if(g_u8ParamEditIndex != 0)   // 已输入Mac  
		{	
			// 
			if(t_EditStatisFrame.MacNum == t_CurStatisFrame.MacNum)
			{
				// 正显Mac
				Set_ClrRFDigtal();
			}
			else
			{
				// 一直反显
				PrintString(COL_WORD7, ROW_TEXT08, "请重新输入!", WORD);	
			}
		}
	}
}

/*********************************************************
*函数名：ProMenuKey_ParamDebugInfo 
*功能  ：调试信息参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamRunTime 
*功能  ：运行时间参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamDateTime 
*功能  ：日期时间参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamRadioTest 
*功能  ：电台自检参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamPowerCheck 
*功能  ：功率检测参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
				PrintString(COL_WORD4, ROW_TEXT04, "当前为值守状态!", WORD);
				return;
			}
			g_u8ParamEditState = YES;
			g_u16SecondCount   = 0;
			
		    PrintString(COL_WORD1, ROW_TEXT02,  "3-功率检测", WORD);
			PrintString(COL_WORD4, ROW_TEXT04,  "当前功率: 37.0dB", WORD);
			PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单 ", WORD);
			Query_PowerTest();
		}
	}
}

/*********************************************************
*函数名：ProMenuKey_ParamUnlightOnOff 
*功能  ：背光开关参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamVersionInfo 
*功能  ：版本信息参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProMenuKey_ParamEntFactorySet
*功能  ：确定恢复出厂设置参数界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_SetIp
*功能  ：处理IP设置数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_SetMac
*功能  ：处理MAC设置数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_MacNum
*功能  ：处理编辑站号状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_MacNum_Test
*功能  ：处理编辑站号状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_ChanNum
*功能  ：处理编辑信道号状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_Freq
*功能  ：处理编辑频率状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
		
        // 设置初始位置
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
        //确定x光标位置
        x += (g_u8NumIndex/4 + g_u8NumIndex)*WIDTH_HALF;
        PrintStringReverse(x, y, &u8Data, 1);     // 显示输入的频率数字
    }
}

/*********************************************************
*函数名：ProcNumKey_TableNum
*功能  ：处理编辑表号状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_InputF1Num
*功能  ：处理密码输入界面下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_InputMaintainGapNum
*功能  ：处理维护间隔输入界面下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_InputUnlightOnOffNum
*功能  ：处理背光开关输入界面下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_InputF2Num
*功能  ：处理F2-链路输入界面下的数字键
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcNumKey_InputF2Num(void)
{
	if(g_u8KeyValue == 1)        // 1-链路建立
	{
		ClearText_PageF2();
		DispMenuText_ParamLinkBuild();
	}
	else if(g_u8KeyValue == 2)   // 2-链路维护
	{
		ClearText_PageF2();
		DispMenuText_ParamLinkMaintain();
	}
	else if(g_u8KeyValue == 3)  // 3-链路查询
	{
		ClearText_PageF2();
		DispMenuText_ParamLinkQuery();
	}
}

/*********************************************************
*函数名：ProcNumKey_InputF3Num
*功能  ：处理F3-监控输入界面下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_InputF4Num
*功能  ：处理F4-系统界面下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_Date
*功能  ：处理编辑日期状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_Time
*功能  ：处理编辑时间状态下的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFirstNumCorrect_Mask
*功能  ：判断输入的MASK数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProTwelveNum
*功能  ：处理12位的数字键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsSecondNumCorrect_Mask
*功能  ：判断输入的MASK数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsThirdNumCorrect_Mask
*功能  ：判断输入的MASK数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsNumCorrect_MAC
*功能  ：判断输入的MASK数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsNumCorrect_IP
*功能  ：判断输入的IP数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcNumKey_SetIp
*功能  ：处理IP设置数字键
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
Position_TypeDef Pos_IP[] = {{1, COL_WORD8,  0}, {2, COL_WORD8+WIDTH_HALF, 0},
                              {3, COL_WORD9, 0}, {4, COL_WORD10, 0},
                              {5, COL_WORD10+WIDTH_HALF,           0}, {6, COL_WORD11, 0},
                              {7, COL_WORD12,0}, {8, COL_WORD12+WIDTH_HALF,           0},
                              {9, COL_WORD13,0}, {10,COL_WORD14,0},
                              {11,COL_WORD14+WIDTH_HALF,0}, {12,COL_WORD15,0}};

/*********************************************************
*函数名：ProcRealTimeUpdate
*功能  ：处理实时时间更新
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcRealTimeUpdate(void)
{
    static uint8_t u8Buf[2] = {0,0},u8Buf_RT[2] = {0,0};
	//uint8_t au8Code[2] = {0};

	u8Buf_RT[0] = u8Buf_RT[1];
	u8Buf_RT[1] = g_u8RunTimeUpdate;  // 1s更新一次
	if(u8Buf_RT[0] != u8Buf_RT[1])
	{		
		// 计算本次开机时间
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
            WriteCode(&t_SumRunTime.Second); // 每隔1min计算并存储一次总时间		
        }
	}
    
	//WriteCode(&t_SubRunTime.Minute);
    if((g_u8CurMenuID == MENU_PARAMDATETIME) || (g_u8CurMenuID == MENU_PARAMWORKSTATE)
		|| (g_u8CurMenuID == MENU_PARAMRUNTIME))
    {
        u8Buf[0] = u8Buf[1];
        u8Buf[1] = g_u8UpdateTime; //0.2S更新一次

		//ReadCode(au8Code);	 // Test

        if(u8Buf[0] != u8Buf[1])
        {
         	RTC_ReadTime();
        }
    }
}

/*********************************************************
*函数名：ProcTimeOutWarning
*功能  ：处理超时提醒
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcTimeOutWarning(void)
{
    if(g_u8ParamEditState == YES)
    {
        switch(g_u8CurMenuID)
        {
            case MENU_PARAMPOWERCHECK:
                if(g_u16SecondCount >= 50)   // 延时3S
                {
                    g_u8ParamEditState = NO;	
                    PrintString(COL_WORD4, ROW_TEXT04,  "                       ", WORD);
                    PrintString(COL_WORD4, ROW_TEXT04,  "请求超时,请重新检测!   ", WORD);
				   	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT09, "             ", WORD);                
				   	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT09, "检测失败!    ", WORD);               
    			}
                break;
            default:
                break;
        }
    }
}

/*********************************************************
*函数名：ProcTimeOutEvent
*功能  ：检测并处理超时事件
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcTimeOutEvent(void)
{  
	ProcTimeOut_PowerOnOff();
}

/*********************************************************
*函数名：ProcTimeOut_PowerOnOff
*功能  ：处理开关机超时事件
*输入  ：无
*输出  ：无
*返回值：无
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
		   g_u8RadioState = NO; 		   // 超时未收到382信令，认为电台状态不正常
		   // test 20151229
		   // ClrGpioBit(LED_ALARM2_PIN);	   // 故障显示黄色
		   //SetGpioBit(LED_ALARM1_PIN);

		   
		   //DispMenuText_MainPage();
		   Delay_nS(8);
		   DispMenuText_ParamWorkState();	   // 显示开机默认界面
		   //DispMenuText_ParamLinkBuild();
		}
	}
	// 关机等待主控响应超时，直接关机
	if((g_u8CurMenuID == MENU_POWER_OFF) && (g_u8PowerOnOffTick >= 100))
	{
		SetGpioBit(CON_POWER_PIN);
	}
}

/*********************************************************
*函数名：ProcLinkBuild_ENT
*功能  ：处理参数页链路建立下的确定键
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcLinkBuild_ENT(void)
{
	if(g_u8ParamEditIndex == YES)  // 建链拆链操作生效
	{
		g_u8ParamEditIndex = NO;
		DispResult_StatisLinkBuild();  // 显示统计链路建立的结果:哪些需要建链
		if(g_u8PreLinkOprtState == LinkBuild) //  选择操作: 建链
		{
			Set_LinkOprt();  // 建链
		}
		else
		{
			Set_LinkOprt(); //	拆链
		}
	}
	else
	{
		return ;
	}
}

/*********************************************************
*函数名：ProcLinkMaintain_ESC
*功能  ：处理参数页链路维护下的取消键
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcLinkMaintain_ESC(void)
{
	uint8_t u8Index = g_u8CurMenuItem - 1;

	g_u8ParamEditState = NO;
	t_EditLinkInfo[u8Index].MaintainGap_ID = t_CurLinkInfo[u8Index].MaintainGap_ID;

	DispRecoverGap();
}

/*********************************************************
*函数名：ProcLinkMaintain_ENT
*功能  ：处理参数页链路维护下的确定键
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcDateTimeKey_ENT
*功能  ：处理日期时间参数页下的确定键
*输入  ：无
*输出  ：无
*返回值：无
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
            DispDateTimeReverse(0);       // 正显参数，取消选中
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
            RTC_WriteTime(); //设置时间
			Set_DateOfTime();
        }
    }
}

/*********************************************************
*函数名：ProcParamWorkState_ENT
*功能  ：处理工作状态参数页下的确定键
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcParamWorkState_ENT(void)
{
   	if(g_u8ParamEditIndex == 0) 
    {
		memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState));
		t_EditRadioState.Power = t_CurRadioState.Power; //功率
		t_EditRadioState.MAC   = t_CurRadioState.MAC;   //站号
		t_EditRadioState.Rank  = t_CurRadioState.Rank;  //等级
		g_u8ParamEditIndex	   = g_u8CurMenuItem;
		DispWorkStateReverse1(1);
		g_u8NumIndex = 0;
	}
    else
    {
		if(g_u8ParamStepOK == NO)  // 按数字键方式设置参数
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
			//g_u8CmdSending = YES;// 20151126 此处等到回复ACK的时候才改变才合理
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
            Set_ChanParam();  //设置信道参数
        }
    }
}

/*********************************************************
*函数名：ProcParamWorkState_ESC
*功能  ：处理工作状态参数页下的取消键
*输入  ：无
*输出  ：按键键值
*返回值：无
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
		//DispWorkStateReverse(0);       // 正显参数，取消选中
		// test
		DispWorkStateReverse1(0);       // 正显参数，取消选中
        g_u8ParamStepOK    = NO;
        g_u8ParamEditIndex = 0;
    }
}

/*********************************************************
*函数名：ProcEditParamWorkState_Num
*功能  ：工作状态参数页下数字输入处理
*输入  ：无
*输出  ：无
*返回值：无
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
           if(t_CurChannelState.WorkMode%2 == 1)       // 定频模式下
           {
               ProcNumKey_Freq();
               break;
           }
           // 跳频模式下 
           ProcNumKey_TableNum();
           break; 
		   
       default:
           break;
   }
}

/*********************************************************
*函数名：GetEditNum_NetNum
*功能  ：获取参数页工作状态下的参数值
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void GetEditNum_ParamWorkState(void)
{
    switch(g_u8ParamEditIndex)
    {
        case INDEX_EDIT_FREQ_TAB:
            if(t_EditChannelState.WorkMode%2 == 1)   // 定频模式下
            {
                t_EditChannelState.Freq[0] = g_u8NumBuf[0];
                t_EditChannelState.Freq[1] = (g_u8NumBuf[1] << 4) + g_u8NumBuf[2];
                t_EditChannelState.Freq[2] = (g_u8NumBuf[3] << 4) + g_u8NumBuf[4];
                break;
            }
            // 跳频模式下
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
*函数名：GetEditNum_ParamWorkState_Test
*功能  ：获取参数页工作状态下的参数值
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void GetEditNum_ParamWorkState_Test(void)
{
	if(g_u8ParamEditIndex != 0)
	{	
		t_EditStatisFrame.MacNum = (g_u8NumBuf[0] * 10) + g_u8NumBuf[1];
	}
}

/*********************************************************
*函数名：ProcEditParamWorkState_Add1
*功能  ：主站工作状态参数页下参数按步进增加1个单位
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditFreOrTab_Add1
*功能  ：频率步进50KHz或表号加1
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcEditFreOrTab_Add1(void)
{
    uint8_t u8Data = 0;
    uint16_t u16Data = 0;

    if(t_CurChannelState.WorkMode%2 == 0)       // 跳频模式
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

    // 定频模式
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
*函数名：ProcEditRank_Step1
*功能  ：电台等级切换
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcEditRank_Step1(void)
{
    t_EditRadioState.Rank = (t_EditRadioState.Rank + 1)%2;
    g_u8ParamStepOK = YES;
    DispRadioRank(1);
}

/*********************************************************
*函数名：Volume_Add1
*功能  ：音量控制函数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void Volume_Add1(void)
{
    if(g_u8CurVolume < VOLUME_LEVEL3)
    {
        g_u8CurVolume++;
    }
}

/*********************************************************
*函数名：ProcEditPower_Add1
*功能  ：电台功率加1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditMac_Add1
*功能  ：站号加1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditChanNum_Add2
*功能  ：信道号加1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditChanNum_Add1
*功能  ：信道号加1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditWorkMode_Add1
*功能  ：工作模式加1
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcEditWorkMode_Add1(void)
{
	uint8_t /*u8State = 0,*/ u8Mode = 0, u8MaxMode = 0;
    //u8State = t_CurSecureState.state;
    u8Mode = t_EditChannelState.WorkMode;

    /*if((u8State == 0xFF) && (u8Mode == WORKMODE_HOP))
    {
    // 告警显示 : 未检测到保密机
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
*函数名：ProcEditParam1_Cut1
*功能  ：工作状态参数页下参数按步进减小1个单位
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditChanNum_Cut1
*功能  ：信道号减1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditWorkMode_Cut1
*功能  ：工作模式减1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditFreOrTab_Cut1
*功能  ：频率步进5KHz或表号减1
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcEditFreOrTab_Cut1(void)
{
    uint8_t u8Data = 0;
    uint16_t u16Data = 0;

    if(t_CurChannelState.WorkMode%2 == 0)       // 跳频模式
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
 
    // 定频模式
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
*函数名：ProcEditPower_Cut1
*功能  ：电台功率减1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditMac_Cut1
*功能  ：站号减1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditMac_Cut2
*功能  ：站号减1
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcEditDateTime_Num
*功能  ：日期时间参数页下参数数字输入处理
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFreqNumvalid
*功能  ：判断输入频率数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFreqvalid_FirstNum
*功能  ：判断输入的第一位频率数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFreqvalid_SecondNum
*功能  ：判断输入的第二位频率数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFreqvalid_ThirdNum
*功能  ：判断输入的第三位频率数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFreqvalid_ForthNum
*功能  ：判断输入的第四位频率数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：IsFreqvalid_FifthNum
*功能  ：判断输入的第五位频率数字是否有效
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispChannelNum
*功能  ：显示信道号
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispChannelNum(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurChannelState.ChanNum >> 4) + '0';// 压缩BCD码 0x12
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
*函数名：DispMacNum
*功能  ：显示站号
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMacNum(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurRadioState.MAC >> 4) + '0';// 压缩BCD码 0x12
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
*函数名：DispWorkMode
*功能  ：显示工作模式
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispWorkMode(uint8_t rev)
{
    uint8_t i = 0;
    Mode_TypeDef mWorkMode[4] = {{WORKMODE_FIX, "定明"}, {WORKMODE_HOP, "跳明"},
                                  {WORKMODE_SFIX, "定密"}, {WORKMODE_SHOP, "跳密"}};

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
*函数名：DispFrequency
*功能  ：显示频率
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispTableNum
*功能  ：显示表号
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispNetNum
*功能  ：显示网号
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispNetNum(uint8_t rev)
{
    if(rev == 0)
    {
        g_u8DispBuf[0] = (t_CurChannelState.NetNum[0] & 0x03) + '0';
        g_u8DispBuf[1] = (t_CurChannelState.NetNum[1] >> 4)   + '0';
        g_u8DispBuf[2] = (t_CurChannelState.NetNum[1] & 0x0F) + '0';
        PrintString(COL_WORD5, ROW_TEXT04,  g_u8DispBuf, 3);
        PrintString(COL_WORD6 + WIDTH_HALF, ROW_TEXT04,  "   ", 3);   /*掩盖定频的MHz*/
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
*函数名：ProcMenuKey_QueryVersion
*功能  ：电台查询信号板软件版本界面下按键响应
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：RespondKey
*功能  ：按键响应函数
*输入  ：无
*输出  ：按键键值
*返回值：无
***********************************************************/
ProcessFunction_TypeDef t_ProcMenuKey[] = 
{
//	{MENU_MAIN_PAGE,          ProcMenuKey_MainPage},
	{MENU_SET_F1,             ProcMenuKey_SetF1},
	{MENU_SET_F2,             ProcMenuKey_SetF2},
	{MENU_SET_F3,             ProcMenuKey_SetF3},
	{MENU_SET_F4,             ProcMenuKey_SetF4},

	//  F1下菜单设置  
	{MENU_PARAMRADIOIP,       ProMenuKey_ParamRadioIp},
	{MENU_PARAMRADIOMASK,     ProMenuKey_ParamRadioMask},
	{MENU_PARAMFACTORYSET,    ProMenuKey_ParamFactorySet},
//	{MENU_PARAMENTFACTORYSET, ProMenuKey_ParamEntFactorySet},

	//  F2下菜单设置
	{MENU_PARAMLINKBUILD,  	  ProMenuKey_ParamLinkBuild},
	{MENU_PARAMLINKMAINTAIN,  ProMenuKey_ParamLinkMaintain},
	{MENU_PARAMLINKQUERY,  	  ProMenuKey_ParamLinkQuery},
//  {MENU_PARAMLINKQUERYTWO,  ProMenuKey_ParamLinkQueryTwo},

	//  F3下菜单设置		
	{MENU_PARAMWORKSTATE,     ProMenuKey_ParamWorkState},
	{MENU_PARAMDIGTRANSTATIS, ProMenuKey_ParamDigTranStatis},
	{MENU_PARAMDIGTRANREPORT, ProMenuKey_ParamDigTranReport},
	{MENU_PARAMDEBUGINFO,     ProMenuKey_ParamDebugInfo},
	{MENU_PARAMRUNTIME,       ProMenuKey_ParamRunTime},

	//  F4下菜单设置		
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
*函数名：GetPowerOnTime
*功能  ：获取开机时间
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void GetPowerOnTime(void)
{
    //uint8_t u8Data = 0;
    //uint8_t u8Month = 0;
    //uint16_t u16Year = 0;

    //RTC_ReadTime();
    ReadCode(&t_SumRunTime.Second);  //获得开机存储在ROM的历史时间
    //memcpy(&t_PoweronTime, &t_CurTime, sizeof(TOD_TypeDef));
}


/*********************************************************
*函数名：PTT_Ctrl
*功能  ：PTT控制函数
*输入  ：无
*输出  ：无
*返回值：无
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
        ClrGpioBit(SEL_MIC1_PIN);   // 选通第一路音频输出,CD4052控制:[BA]=[00]
        ClrGpioBit(SEL_MIC2_PIN);
        ClrGpioBit(PTT_IN_PIN);     // 通知主控有PTT按下
        return;
    }

    if(ReadGpioBit(ZKPTT2_IN_PIN) == 0)
    {
        SetGpioBit(SEL_MIC1_PIN);   // 选通第二路音频,CD4052控制:[BA]=[01]
        ClrGpioBit(SEL_MIC2_PIN);
        ClrGpioBit(PTT_IN_PIN);     // 通知主控有PTT按下
        return;
    }*/

    if(ReadGpioBit(BDPTT_IN_PIN ) == 0)//lys修改
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
                    PrintStringReverse(COL_WORD1, ROW_STATE2, "遥控", WORD);
                    PrintString(COL_WORD3+WIDTH_HALF, ROW_STATE2, "值守禁发!", WORD);
                }
                else
                {
                    ClearTextState2();
                    PrintString(COL_WORD1, ROW_STATE2, "状态:值守禁发!", WORD);
                }
            }
			#endif
        }
        else
        {
            g_u8NoSendFlag = NO;
            ClrGpioBit(SEL_MIC1_PIN);   // 选通第三路音频,CD4052控制:[BA]=[10]
            SetGpioBit(SEL_MIC2_PIN);
            ClrGpioBit(PTT_IN_PIN);     // 通知主控有PTT按下
        
        // 侧音选择
            SetGpioBit(SEL_SP_PIN);
        }
        return;
    }
    //else
    {
        //su08PTT_State = NO;
    }
    g_u8NoSendFlag = NO;
    ClrGpioBit(SEL_SP_PIN);         // 无PTT信号时
    SetGpioBit(PTT_IN_PIN);         // 通知主控无PTT按下
}

/*********************************************************
*函数名：WriteVolDataTo5402
*功能  ：写音量数据到MAX5402芯片
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void WriteVolDataTo5402(uint8_t VolData)
{
    uint8_t i = 0, u8Data = 0;
    uint8_t u8VolLevel[4] = {0x00, 0x40, 0x80, 0xC0};

    //ssl20140521静音时设置断开声音输出
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
*函数名：Volume_Cut1
*功能  ：音量控制函数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void Volume_Cut1(void)
{
    if(g_u8CurVolume > VOLUME_SILENCE)
    {
        g_u8CurVolume--;
    }
}
    
/*********************************************************
*函数名：Volume_Ctrl
*功能  ：音量控制函数
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：PowerOnOff_Ctrl
*功能  ：开关机控制函数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void PowerOnOff_Ctrl(void)
{
    uint16_t u8TimeOut = 500;


    g_u8KeyBuf[0] = g_u8KeyBuf[1];
    g_u8KeyBuf[1] = ReadGpioBit(KEY_POWER_PIN);/*正样显控高电平为开机*/
    //g_u8KeyBuf[0] = 0;
	//g_u8KeyBuf[1] = 0;/*暂时修改开机处理流程*/
    
    if(g_u8KeyBuf[0] == g_u8KeyBuf[1])
    {
        return;
    }
    
    if((g_u8KeyBuf[0] == 0) && (g_u8KeyBuf[1] == 1))    // 开机
    {
		//ReadCode(au8Code);  // 开机读取总运行时间
        while(u8TimeOut--)    // HSL.20141128，为防止电平抖动，延时后再检测一次电平
        {
            ;
        }    
        if(ReadGpioBit(KEY_POWER_PIN) == 0)
        {
            return;
        }
		
        //ssl20140521李元帅要求开机先测试所有led灯
        ClrGpioBit(LED_POWER2_PIN);     // 电源灯显示黄色
        SetGpioBit(LED_POWER1_PIN);  
        ClrGpioBit(LED_Tx_PIN);			// 收发灯显示黄色
        SetGpioBit(LED_Rx_PIN);         
        ClrGpioBit(LED_ALARM2_PIN);
		SetGpioBit(LED_ALARM1_PIN);     // 故障灯显示黄色

        Delay_nMS(800);/*亮灯需延时300ms*/

        ClrGpioBit(LED_POWER2_PIN);     // 电源灯控灭
        ClrGpioBit(LED_POWER1_PIN);
        ClrGpioBit(LED_Rx_PIN);         // 收发灯控灭
        ClrGpioBit(LED_Tx_PIN);
        ClrGpioBit(LED_ALARM2_PIN);     // 故障灯控灭
        ClrGpioBit(LED_ALARM1_PIN);

        g_u8PowerOn = YES;
        ClrGpioBit(CON_POWER_PIN);      // 向主控板输出开机电平
        SetGpioBit(LED_POWER2_PIN);     // 电源灯显示绿色
        ClrGpioBit(LED_POWER1_PIN);  

		g_u8CurMenuID = MENU_POWER_ON;	// 识别到开机后立刻置为开机界面ID
		//GetPowerOnTime();   //获取开机时间
        LCD_init();                     // 显示前先初始化8806
        DispStartUpPage();              // 显示电台开机界面
    }
    else if((g_u8KeyBuf[0] == 1) && (g_u8KeyBuf[1] == 0))    // 关机
    {
		//WriteCode(&t_SubRunTime.Minute); //关机之前记录本次运行总时间
        while(u8TimeOut--);     // HSL.20141128，为防止电平抖动，延时后再检测一次电平
        if(ReadGpioBit(KEY_POWER_PIN) == 1)
        {
            return;
        }
		
		g_u8PowerOn   = NO;
        g_u8CurMenuID = MENU_POWER_OFF;   // 只要按下开关键，就把界面ID设置为MENU_POWER_ONOFF
        LCD_Clear(TOP);
        LCD_Clear(BOTTOM);
		PrintString(COL_WORD6, 0x65, "保存设置，正在关机...", WORD);
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
        Set_PowerOff();				// 向主控板发送关机指令
        g_u8PowerOnOffTick = 0;	// 开始计算关机时间
    }
//#endif
}

/*********************************************************
*函数名：AlarmLed_Ctrl
*功能  ：告警灯灯控制
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void AlarmLed_Ctrl(uint8_t *pState)
{
    if(t_CurRadioState.ParamState == YES)
    {
        if((pState[0] == 0) && ((pState[1] & 0x07) != 0x07))
        {
            //正样绿色与初样反
            ClrGpioBit(LED_ALARM2_PIN);
            ClrGpioBit(LED_ALARM1_PIN);
        }
        else
        {
            //正样黄色与初样反
            ClrGpioBit(LED_ALARM2_PIN);     // 故障显示黄色
            SetGpioBit(LED_ALARM1_PIN);   
        }
    }
    else
    {
        ClrGpioBit(LED_ALARM2_PIN);     // 关机故障灯置为灭
        ClrGpioBit(LED_ALARM1_PIN);   
    }
}

/*********************************************************
*函数名：Rx_Tx_Led_Ctrl
*功能  ：收发灯控制
*输入  ：无
*输出  ：无
*返回值：无
*NOTE  : CS,20131029,修改程序，取消定时闪烁，为何要闪?而且可以实现闪烁?
		 修改灯的优先级，发灯最高，其次收灯，余者皆为空闲
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
	else if(State != su8LastState)/*相等则保持原状*/
	{
		if((u8DataState == TX) || (u8VoiceState == TX)
			|| (u8LinkTestState == TX))
	    {
			SetGpioBit(LED_Rx_PIN);     // 发灯为黄色
			ClrGpioBit(LED_Tx_PIN);   
	    }
		else if((u8DataState == RX) || (u8VoiceState == RX)
			     || (u8LinkTestState == RX))
	    {
			ClrGpioBit(LED_Rx_PIN);     // 收灯为绿色
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
		;/*保持现状，不进行操控*/
	}
}

/*********************************************************
*函数名：GetDate_FirstNum
*功能  ：获取日期第一位数字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void GetDate_FirstNum(uint8_t KeyValue)
{
    uint8_t u8Data = 0;

    g_u8ParamEditIndex = g_u8CurMenuItem;
    g_u8NumIndex = 1;
    memset(g_u8NumBuf, 0, 6); // g_u8NumBuf中的后6个字节赋值为0
    g_u8NumBuf[0] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD8, ROW_TEXT05, &u8Data, 1);
    PrintString(COL_WORD8+WIDTH_HALF, ROW_TEXT05, "-/--/--", 7);
}

/*********************************************************
*函数名：GetDate_SecondNum
*功能  ：获取日期第二位数字
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：GetDate_ThirdNum
*功能  ：获取日期第三位数字
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：GetDate_ForthNum
*功能  ：获取日期第四位数字
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：GetDate_FifthNum
*功能  ：获取日期第五位数字
*输入  ：无
*输出  ：无
*返回值：无
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
    else if((u8Month == 2) && (KeyValue == 3))  // 2月
    {
        return;
    }

    g_u8NumIndex = 5;
    g_u8NumBuf[4] = KeyValue;
    u8Data = KeyValue + '0';
    PrintStringReverse(COL_WORD11, ROW_TEXT05, &u8Data, 1);
}

/*********************************************************
*函数名：GetDate_SixthNum
*功能  ：获取日期第六位数字
*输入  ：无
*输出  ：无
*返回值：无
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



