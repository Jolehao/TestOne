#include "all.h"

/*********************************************************
*函数名：DispStartUpPage
*功能  ：开机显示
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispStartUpPage(void)
{
	LCD_Clear(BOTTOM);  // 清屏
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

	PrintString(COL_WORD6, ROW_TEXT06, "国营第七五○厂", WORD);
	Delay_nS(2);	// 延迟4S
	
	PrintString(COL_WORD6, ROW_TEXT06, "                  ", WORD);
    PrintString(COL_WORD6, ROW_TEXT06, "系统初始化,请稍后...", WORD);
	Delay_nS(3);

	#if 0
	PrintString(COL_WORD6, ROW_TEXT06, "                  ", WORD);
    PrintString(COL_WORD6, ROW_TEXT06, "正在加载...", WORD);
    Delay_nS(3);     // 延迟4S
	#endif

    PrintString(COL_WORD6, ROW_TEXT06, "                    ", WORD);
    PrintString(COL_WORD6, ROW_TEXT06, "正在自检...", WORD);

	// test
	#if 0
	g_u8CurMenuID = MENU_1ST_BITE;	// 置为开机自检界面ID
	#endif
	// test
	g_u8CurMenuID = MENU_1ST_BITE;	// 置为开机自检界面ID
	g_u8PowerOnOffTick = 0;		// 开始计算开机时间

}

/*********************************************************
*函数名：DispFuncKey_Param
*功能  ：显示参数页功能键标志
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispFuncKey_Param(void)
{
    PrintString(WIDTH_HALF, ROW_TEXT01,  "F1-设置", WORD);
    PrintString(COL_WORD5,  ROW_TEXT01,  "F2-链路", WORD);
    PrintString(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-监控", WORD);
    PrintString(COL_WORD14, ROW_TEXT01,   "F4-系统", WORD);
}

/*********************************************************
*函数名：DispParamWorkState
*功能  ：显示工作状态参数页参数(显示全部参数)
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispParamWorkState(void)
{
	if((g_u8CurMenuID != MENU_1ST_BITE)&&(g_u8CurMenuID != MENU_PARAMLINKQUERY))
	{
		/************* 显示信道参数*************/
		DispChannelNum(0);                       // 显示信道号
		DispWorkMode(0);		                // 显示工作模式

		
		if(t_CurChannelState.WorkMode%2 == 1)	// 定频模式
		{
			if(g_u8CurMenuItem == INDEX_EDIT_FREQ_TAB)
			{
				PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "频率", WORD);
			}
			else
			{
				PrintString(WIDTH_HALF, ROW_TEXT04, "频率", WORD);
			}
			DispFrequency(0);
		}
		else    // 表网: 表号网号
		{
			if(g_u8CurMenuItem == INDEX_EDIT_FREQ_TAB)
			{
				PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "表网", WORD);
			}
			else
			{
				PrintString(WIDTH_HALF, ROW_TEXT04, "表网", WORD);
			}
			DispTableNum(0);		// 显示表号
			DispNetNum(0);          // 显示网号
		}
		//SelectStation = MainStation;SubStation
		DispRadioRank(0);           // 显示等级


		/************* 显示电台参数**********/
		DispRadioPower(0);          // 功率
		//DispMacAddr(0);             // 站号
		//DispMacAddr1(0);             // 站号
		// test
		//DispMacAddr2(0);             // 站号
		//if(ReportMac == YES)
		{
			//ReportMac = NO; 
			//DispMacAddr2(0);  // test
		}
		//else
		{
			//DispMacNum(0);   // 站号
		}	
		// test
		DispMacAddr2(0);   // 站号
		}
}

/*********************************************************
*函数名：DispMenuText_PageF1
*功能  ：显示F1参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_PageF1(void)
{
 	g_u8CurMenuID   = MENU_SET_F1;
	DispText_PageF1();
	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-设置", WORD);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单-按数字键进入菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_PageF2
*功能  ：显示F2参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_PageF2(void)
{
 	g_u8CurMenuID   = MENU_SET_F2;

	DispText_PageF2();
	DispFuncKey_Param();
	
    PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-链路", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单-按数字键进入菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_PageF3
*功能  ：显示F3参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_PageF3(void)
{
 	g_u8CurMenuID   = MENU_SET_F3;
	DispText_PageF3();
	DispFuncKey_Param();
    PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-监控", WORD);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>选择菜单-按数字键进入菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_PageF4
*功能  ：显示F4参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_PageF4(void)
{
 	g_u8CurMenuID   = MENU_SET_F4;
	DispText_PageF4();
	DispFuncKey_Param();
    PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-系统", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>选择菜单-按数字键进入菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamRadioIp
*功能  ：显示电台IP参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamRadioIp(void)
{
    g_u8CurMenuID = MENU_PARAMRADIOIP;
	memcpy(&t_EditRadioState.Service_IP[0], &t_CurRadioState.Service_IP[0], 4); // 覆盖更新
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-设置", WORD);
	
    PrintString(COL_WORD1, ROW_TEXT02, "1-电台IP", WORD);
	PrintString(COL_WORD5, ROW_TEXT04, "当前: 192.168.001.001", WORD);
    PrintString(COL_WORD5, ROW_TEXT05, "输入: ", WORD);
	Query_ServiceIp();
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注:按数字键输入参数-按<取消>重新输入 ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT10, "   按<确定>确定更改-按<F1-F4>下拉菜单", WORD); 
}

/*********************************************************
*函数名：DispMenuText_ParamRadioMask
*功能  ：显示电台掩码参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamRadioMask(void)
{
    g_u8CurMenuID    = MENU_PARAMRADIOMASK;
	g_u8MaskZeroFlag = NO;
	memcpy(&t_EditRadioState.Service_MASK[0], &t_CurRadioState.Service_MASK[0], 4);
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-设置", WORD);

    PrintString(COL_WORD1, ROW_TEXT02, "2-电台掩码", WORD);
    PrintString(COL_WORD5, ROW_TEXT04, "当前: 255.255.255.000", WORD);
	PrintString(COL_WORD5, ROW_TEXT05, "输入: ", WORD);
	Query_ServiceMask();

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按数字键输入参数-按<取消>重新输入 ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT10, "    按<确定>确认更改-按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamFactorySet
*功能  ：显示恢复出厂设置参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamFactorySet(void)
{
    g_u8CurMenuID = MENU_PARAMFACTORYSET;
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-设置", WORD);
    PrintString(COL_WORD1, ROW_TEXT02,  "3-恢复出厂设置", WORD);
	PrintString(COL_WORD5, ROW_TEXT05,  "是否确定恢复出厂设置? ", WORD);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<确定>确定恢复-按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_F1_F1EntFactorySet
*功能  ：显示确定恢复出厂设置参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
/*
void DispMenuText_ParamEntFactorySet(void)
{
    g_u8CurMenuID = MENU_PARAMENTFACTORYSET;
	LCD_Clear(TOP);
  	DispFuncKey_Param();
	PrintStringReverse(WIDTH_HALF, ROW_TEXT01,  "F1-设置", WORD);

    PrintString(COL_WORD1, ROW_TEXT02,  "3-恢复出厂设置", WORD);
	PrintString(COL_WORD7, ROW_TEXT05,  "正在恢复...   ", WORD);
	Set_DefaultParam();

	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F6>返回上一级菜单", WORD);
}
*/

/*********************************************************
*函数名：DispMenuText_ParamLinkBuild
*功能  ：显示链路建立参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamLinkBuild(void)
{	
    g_u8CurMenuID = MENU_PARAMLINKBUILD;
	g_u8CurMenuItem = 1;
	//memcpy(&t_EditLinkInfo[0],&t_CurLinkInfo[0],sizeof(t_CurLinkInfo[0]));
	PrintHorizonLine(0,143,0xFF,40);
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-链路", WORD); // 反显
    PrintString(COL_WORD1, ROW_TEXT02,  "1-链路建立", WORD);
    PrintString(COL_WORD1, ROW_TEXT03,  "选择站号: ", WORD);
	PrintSubWindow_LinkBuild();
	
    PrintString(COL_WORD1, ROW_TEXT06,  "选择操作: 建链", WORD);
	PrintStringReverse(COL_WORD6,ROW_TEXT06,"建链",4);
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<左/右/F5>选站号-按<上/下>选操作", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<确定>确认设置-按<F1-F4>下拉菜单", WORD);
	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		DispMac();  // 显示链路建立下的Mac号
	}
	DispItemReverse_ParamLinkBuild(); //反显
}

/*********************************************************
*函数名：DispMenuText_ParamLinkMaintain
*功能  ：显示链路维护参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamLinkMaintain(void)
{
    g_u8CurMenuID = MENU_PARAMLINKMAINTAIN;
	g_u8CurMenuItem = 1; 
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-链路", WORD);
    PrintString(COL_WORD1, ROW_TEXT02,  "2-链路维护", WORD);
	PrintSubWindow_LinkMaintain();
	PrintString(COL_WORD2, ROW_TEXT03, "站号", WORD);
	PrintString(COL_WORD5+WIDTH_HALF, ROW_TEXT03, "维护间隔", WORD);
	PrintString(COL_WORD11, ROW_TEXT03, "站号", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "维护间隔", WORD);

	DispMac();
	DispItemReverse_ParamLinkMaintain(); //反显
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按方向键选择站号-按0 3选择维护间隔", WORD);
	PrintOneChar(COL_WORD12+WIDTH_HALF, ROW_TEXT09, Logo_connect);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<确定>确认设置-按<F1-F4>下拉菜单", WORD);

	DispLinkMaintainGap();   // 显示维护间隔(一次性显示)
	Query_LinkMaintainGap(); // 查询链路维护间隔
}

/*********************************************************
*函数名：DispMenuText_ParamLinkQuery
*功能  ：显示链路查询参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamLinkQuery(void)
{
	g_u8CurMenuID = MENU_PARAMLINKQUERY;
  	DispFuncKey_Param();
	// test 20151230
	PrintSubWindow_LinkQuery_Test();
	//PrintSubWindow_LinkQuery();
	PrintStringReverse(COL_WORD5,  ROW_TEXT01,  "F2-链路", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT02,  "3-链路查询", WORD);
//	memcpy(&t_EditLinkInfo[0],&t_CurLinkInfo[0],sizeof(t_CurLinkInfo[0]));

	PrintString(COL_WORD1,ROW_TEXT04,"站号",WORD);
	PrintString(COL_WORD1,ROW_TEXT05,"上行",WORD);
	PrintString(COL_WORD1,ROW_TEXT06,"下行",WORD);

	// Report_LinkInfo(void);
	// Report_LinkMaintainGap(void)
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单", WORD);	

	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		// test 20151229
		//DispMac();
		//DispLinkQuantity(0);  // 显示链路质量
		Query_LinkQuality();
	}
}

/*********************************************************
*函数名：DispMenuText_ParamWorkState
*功能  ：显示工作状态参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
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
 
	if(SelectStation == SubStation)  //选择主从状态
	{
		PrintVerticalLine(20,48,0x80,143); //191-48=143,从站
	} 
	else
	{
		PrintVerticalLine(20,48,0x80,23); //191-48=143,主站
	}
	
	PrintHorizonLine(0,71,0xFF,40);// 95-23 = 72
	memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState)); // 信道参数
   	t_EditRadioState.Power = t_CurRadioState.Power;    // 功率
	t_EditRadioState.MAC   = t_CurRadioState.MAC;      // 站号
	t_EditRadioState.Rank  = t_CurRadioState.Rank;     // 等级
	
	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01, "F3-监控", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT02, "1-工作状态", WORD);
	PrintString(COL_WORD11, ROW_TEXT02, "15/09/23 00:00:00", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT03,  "参数配置: ", WORD);
	
	if(t_CurChannelState.WorkMode%2 == 1)   // 定频模式[35]
    {
        PrintString(WIDTH_HALF, ROW_TEXT04, "频率: ", WORD);
    }
    else                                    // 跳频模式[46]
    {
        PrintString(WIDTH_HALF, ROW_TEXT04, "表网: ", WORD);
    } 
	
    PrintString(WIDTH_HALF, ROW_TEXT05, "模式: ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT06, "等级: ", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT07, "功率: ", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT08, "站号: ", WORD);
	PrintString(COL_WORD5,  ROW_TEXT08, "信道: ", WORD);
	
	PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "频率", WORD);

	if(SelectStation == SubStation)  //选择主从状态
	{
		PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT03, "链路状态:   ", WORD);
		// test 20151229
		PrintSubWindow_SubWorkState();
		PrintString(COL_WORD11, ROW_TEXT04, "站号", WORD);
   		PrintString(COL_WORD15, ROW_TEXT04, "SNR ", WORD);
		//PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "无线:     ", WORD);
   		//PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT06, "链路质量: ", WORD);
   		
   		// test
		// 0x0382中同步的话才显示 SyncState
		if(t_CurRadioState.SyncState != 0x00) // 同步
		{
			DispMac();            // 显示Mac
			DispIntensityLogo();  // 显示场强Logo
		}
	}
	else
	{
		PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT03, "链路状态:   ", WORD);
		PrintSubWindow_WorkState();
		// test
		// 0x0382中同步的话才显示 SyncState
		if(t_CurRadioState.SyncState != 0x00) // 同步
		{
			DispMac();            // 显示Mac
			DispIntensityLogo();  // 显示场强Logo
		}
	}
	
	// 电台状态和参数状态均正常才显示参数
	// test
	if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{		
		DispParamWorkState();  // 工作状态参数
		
		Query_ChanParam();    //  信道参数
		Delay_nMS(20);
		Query_RadioPower();   //  查询电台功率
		Delay_nMS(20);
		Query_RadioMac();     //  查询电台MAC:站号
		Delay_nMS(20);
		Query_RadioRank();   //  查询电台等级
		 
		if(SelectStation == SubStation)
		{	
			//Delay_nMS(40);
			//Query_LinkQuality();  //  查询链路质量		
		}
		//场强自动上报
	}
	
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<上/下>选择参数-按<确定>进入编辑", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F5>翻页-按<F1-F4>下拉菜单      ", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamDigTranStatis
*功能  ：显示数传统计参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamDigTranStatis(void)
{
    g_u8CurMenuID = MENU_PARAMDIGTRANSTATIS;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-监控", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "2-数传统计", WORD);
	PrintSubWindow_DigTranOpert();
	
	PrintString(COL_WORD1, ROW_TEXT03,  "站号", WORD);
	PrintString(COL_WORD4, ROW_TEXT03,  "发送帧", WORD);
	PrintString(COL_WORD8, ROW_TEXT03,  "接收帧", WORD);
	PrintString(COL_WORD12, ROW_TEXT03, "乱码帧", WORD);
	PrintString(COL_WORD16, ROW_TEXT03, "错误帧", WORD);
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
	PrintString(WIDTH_HALF, ROW_TEXT08, "输入Mac号:  ", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F5>翻页,按<确定>清空收发数据", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F1-F4>下拉菜单", WORD);

	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		Query_DigTranStatis();
	}
}

/*********************************************************
*函数名：DispMenuText_ParamDigTranReport
*功能  ：显示数传汇报参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamDigTranReport(void)
{
    g_u8CurMenuID = MENU_PARAMDIGTRANREPORT;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-监控", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "3-数传汇报", WORD);
	PrintSubWindow_DigTranOpert();
	
	PrintString(COL_WORD1, ROW_TEXT03,  "站号", WORD);
	PrintString(COL_WORD4, ROW_TEXT03,  "发送帧", WORD);
	PrintString(COL_WORD8, ROW_TEXT03,  "接收帧", WORD);
	PrintString(COL_WORD12, ROW_TEXT03, "乱码帧", WORD);
	PrintString(COL_WORD16, ROW_TEXT03, "错误帧", WORD);
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
	
	PrintString(WIDTH_HALF, ROW_TEXT08, "输入Mac号:  ", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F5>翻页,按<确定>清空收发数据", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F1-F4>下拉菜单", WORD);

	//if((g_u8RadioState == YES) && (t_CurRadioState.ParamState == YES))
	{
		Query_DigTranReport();
	}
}

/*********************************************************
*函数名：DispMenuText_ParamDebugInfo
*功能  ：显示调试信息参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamDebugInfo(void)
{
    g_u8CurMenuID = MENU_PARAMDEBUGINFO;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-监控", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "4-调试信息", WORD);

	PrintString(COL_WORD1+WIDTH_HALF, ROW_TEXT03, "功率检测", WORD);

	Query_DebugInfo();  
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamRunTime
*功能  ：显示运行时间参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamRunTime(void)
{
    g_u8CurMenuID = MENU_PARAMRUNTIME;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD9+WIDTH_HALF, ROW_TEXT01,   "F3-监控", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "5-运行时间", WORD);
	PrintString(COL_WORD5, ROW_TEXT05,  "总运行时间: 0027小时47分", WORD);
	PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT06,  "本次运行时间:  00小时00分00秒", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamDateTime
*功能  ：显示日期时间参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamDateTime(void)
{
    g_u8CurMenuID = MENU_PARAMDATETIME;
	g_u8ParamEditIndex = 0;
	g_u8ParamEditState = OFF;
	g_u8CurMenuItem = 1;
	memcpy(&t_EditTime, &t_CurTime, sizeof(t_CurTime));
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-系统", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "1-日期时间", WORD);
	PrintString(COL_WORD5, ROW_TEXT05,  "日期: 15/09/02", WORD);
	PrintString(COL_WORD5, ROW_TEXT06,  "时间: 00:00:00", WORD);

	DispItemReverse_ParamDateTime();
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<上/下>选择参数-按<确定>进入编辑", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F1-F4>下拉菜单                 ", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamRadioTest
*功能  ：显示电台自检参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamRadioTest(void)
{
    g_u8CurMenuID = MENU_PARAMRADIOTEST;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-系统", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02, "2-电台自检", WORD);
	#if 0
    PrintString(COL_WORD2, ROW_TEXT03,  "交流模块:...", WORD);
    PrintString(COL_WORD2, ROW_TEXT04,  "直流模块:...", WORD);
    PrintString(COL_WORD2, ROW_TEXT05,  "频合单元:...", WORD);
    PrintString(COL_WORD2, ROW_TEXT06,  "信道单元:...", WORD);
	PrintString(COL_WORD2, ROW_TEXT07,  "功放模块:...", WORD);
    PrintString(COL_WORD10, ROW_TEXT03, "面板模块:...", WORD);
    PrintString(COL_WORD10, ROW_TEXT04, "主控模块:...", WORD);
	PrintString(COL_WORD10, ROW_TEXT05, "4槽信号:...", WORD);
	#endif
	// test 20151229
	PrintString(COL_WORD2, ROW_TEXT03,  "交流模块: √", WORD);
    PrintString(COL_WORD2, ROW_TEXT04,  "直流模块: √", WORD);
    PrintString(COL_WORD2, ROW_TEXT05,  "频合单元: √", WORD);
    PrintString(COL_WORD2, ROW_TEXT06,  "信道单元: √", WORD);
	PrintString(COL_WORD2, ROW_TEXT07,  "功放模块: √", WORD);
    PrintString(COL_WORD10, ROW_TEXT03, "面板模块: √", WORD);
    PrintString(COL_WORD10, ROW_TEXT04, "主控模块: √", WORD);
	PrintString(COL_WORD10, ROW_TEXT05, "4槽信号:  √", WORD);
	// test 20151229
    //PrintString(COL_WORD10, ROW_TEXT05, "交换模块:...", WORD);
	//Set_RadioTest();

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamPowerCheck
*功能  ：显示功率检测参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamPowerCheck(void)
{
    g_u8CurMenuID = MENU_PARAMPOWERCHECK;
	g_u8ParamEditState = NO;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-系统", WORD);
    PrintString(COL_WORD1, ROW_TEXT02,  "3-功率检测", WORD);
	PrintString(COL_WORD3, ROW_TEXT05,  "请确定天线口已连接负载或天线!", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<确定>开始检测 ", WORD);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamUnlightOnOff
*功能  ：显示背光开关参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamUnlightOnOff(void)
{
    g_u8CurMenuID = MENU_PARAMUNLIGHTONOFF;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,   "F4-系统", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "4-背光状态", WORD);
	PrintString(COL_WORD4, ROW_TEXT04,  "0-背光关", WORD);
	PrintString(COL_WORD4, ROW_TEXT05,  "1-背光开", WORD);

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按0 1选择背光状态 ", WORD);
	PrintOneChar(COL_WORD4,ROW_TEXT09,Logo_connect);
	PrintString(WIDTH_HALF, ROW_TEXT10, "    按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispMenuText_ParamVersionInfo
*功能  ：显示版本信息参数页菜单文字
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMenuText_ParamVersionInfo(void)
{
	//uint8_t i = 0;
	//uint8_t u8_Code[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};
    g_u8CurMenuID = MENU_PARAMVERSIONINFO;
  	DispFuncKey_Param();
	PrintStringReverse(COL_WORD14, ROW_TEXT01,	 "F4-系统", WORD);
    PrintString(WIDTH_HALF, ROW_TEXT02,  "5-版本信息", WORD);
	PrintSubWindow_VersionInfo();
	PrintString(COL_WORD2+WIDTH_HALF,  ROW_TEXT03, "单元", WORD);
	PrintString(COL_WORD6+WIDTH_HALF,  ROW_TEXT03, "版本", WORD);
	PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT03, "单元", WORD);
	PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT03, "版本", WORD);

	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT04,  "面板", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT05,  "主控", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT06,  "信号", WORD);
	PrintString(COL_WORD2+WIDTH_HALF, ROW_TEXT07,  "模板", WORD);

	PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT04,  "信道", WORD);
	PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05,  "功放", WORD);

	// 显示
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
	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单", WORD);
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
*函数名：DispItemReverse
*功能  ：参数页选项显示反向显示
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispDateTimeReverse
*功能  ：显示日期时间参数反向显示
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispWorkStateReverse
*功能  ：显示工作状态参数页参数反向显示
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispWorkStateReverse(uint8_t rev)
{
    switch(g_u8ParamEditIndex)
    {
        case INDEX_EDIT_WORKMODE:
            DispWorkMode(rev);
            break;
        
        case INDEX_EDIT_FREQ_TAB:
            if(t_CurChannelState.WorkMode%2 == 1)   // 定频模式
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
            if(t_CurChannelState.WorkMode%2 == 1)   // 定频模式
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
*函数名：DispItemRecover
*功能  ：正显工作状态菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemRecover_ParamLinkBuild
*功能  ：正显链路建立菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemRecover_ParamLinkMaintain
*功能  ：正显链路维护页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemRecover_ParamLink
*功能  ：正显链路菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemRecover_ParamLinkMaintain
*功能  ：正显链路维护菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemRecover_ParamWorkState
*功能  ：正显工作状态菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispItemRecover_ParamWorkState(void)
{
	switch(g_u8EditMenuItem)
	{
        case INDEX_EDIT_FREQ_TAB:
			if(t_CurChannelState.WorkMode%2 == 1)   // 定频模式
	        {
	            PrintString(WIDTH_HALF, ROW_TEXT04, "频率", WORD);
	            break;
	        }
	        PrintString(WIDTH_HALF, ROW_TEXT04, "表网", WORD);
	        break;
    
        case INDEX_EDIT_WORKMODE:
            PrintString(WIDTH_HALF, ROW_TEXT05, "模式", WORD);
            break;
    
        case INDEX_EDIT_RANK:   // 等级
            PrintString(WIDTH_HALF, ROW_TEXT06, "等级", WORD);
            break;
    
        case INDEX_EDIT_POWER:
            PrintString(WIDTH_HALF, ROW_TEXT07, "功率", WORD);
            break;
    
        case INDEX_EDIT_MAC:   //站号
            PrintString(WIDTH_HALF, ROW_TEXT08, "站号", WORD);
            break;

		case INDEX_EDIT_CHANNUM:
            PrintString(COL_WORD5,  ROW_TEXT08, "信道", WORD);
            break;
    
        default:
            break;
    }
}

/*********************************************************
*函数名：DispItemRecover_ParamDateTime
*功能  ：正显日期时间菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispItemRecover_ParamDateTime(void)
{				
	switch(g_u8EditMenuItem)
	{
		case 1:
			PrintString(COL_WORD5, ROW_TEXT05,	"日期", COL_WORD2+WIDTH_HALF);
			break;
	
		case 2:
			PrintString(COL_WORD5, ROW_TEXT06,	"时间", COL_WORD2+WIDTH_HALF);
			break;
			
		default:
			break;
	}
}
#if 0
/*********************************************************
*函数名：DispItemRecover_ParamUnlightOnOff
*功能  ：正显背光开关菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemReverse_ParamLinkBuild
*功能  ：反显链路建立菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemReverse_ParamLinkMaintain
*功能  ：反显链路维护页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemReverse_ParamLink
*功能  ：反显链路菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemReverse_ParamLinkMaintain
*功能  ：反显链路维护页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemReverse_ParamWorkState
*功能  ：反显工作状态菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispItemReverse_ParamWorkState(void)
{				
	switch(g_u8CurMenuItem)
	 {	
        case INDEX_EDIT_FREQ_TAB:
			if(t_CurChannelState.WorkMode%2 == 1)   // 定频模式
	        {
	            PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "频率", WORD);
	            break;
	        }
	        PrintStringReverse(WIDTH_HALF, ROW_TEXT04, "表网", WORD);
	        break;
    
        case INDEX_EDIT_WORKMODE:
            PrintStringReverse(WIDTH_HALF, ROW_TEXT05, "模式", WORD);
            break;
    
        case INDEX_EDIT_RANK:   // 等级
            PrintStringReverse(WIDTH_HALF, ROW_TEXT06, "等级", WORD);
            break;
    
        case INDEX_EDIT_POWER:
            PrintStringReverse(WIDTH_HALF, ROW_TEXT07, "功率", WORD);
            break;
    
        case INDEX_EDIT_MAC: //站号
            PrintStringReverse(WIDTH_HALF, ROW_TEXT08, "站号", WORD);
            break;

		case INDEX_EDIT_CHANNUM:// 信道号
            PrintStringReverse(COL_WORD5,  ROW_TEXT08, "信道", WORD);
            break;
    
        default:
            break;
    }
}

/*********************************************************
*函数名：DispItemReverse_ParamDateTime
*功能  ：反显日期时间菜单页选项
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispItemReverse_ParamDateTime(void)
{				
	switch(g_u8CurMenuItem)
	{
		case 1:
			PrintStringReverse(COL_WORD5, ROW_TEXT05,	"日期", COL_WORD2+WIDTH_HALF);
			break;
	
		case 2:
			PrintStringReverse(COL_WORD5, ROW_TEXT06,	"时间", COL_WORD2+WIDTH_HALF);
			break;
			
		default:
			break;
	}
}
#if 0
/*********************************************************
*函数名：DispItemReverse_ParamUnlightOnOff
*功能  ：反显背光开关页选项
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispItemSelectResult
*功能  ：显示菜单选项选择结果
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispItemSelectResult(void)
{
	if(g_u8SelectItemOK == YES) 	// 切换选项成功  
	{
		g_u8SelectItemOK = NO;
		//DispItemRecover();		 // 正显上一个反显选项
		DispItemRecover();
		//DispItemReverse();		 // 反显当前选项
		DispItemReverse();
	}
}

/*********************************************************
*函数名：DispRealTimeWorkState
*功能  ：显示实时工作状态
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispRealTimeWorkState(void)
{
	//DispSNR();
	Rx_Tx_Led_Ctrl(t_CurRadioState.Indication);
	// 显示状态1栏信息
	//DispText_State1();
	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		// test
		// 0x0382中同步的话才显示 SyncState
		if(t_CurRadioState.SyncState != 0x00) // 同步
		{
			// 先清空未入网显示区域
			PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "      ", 3);
			// SNR=0		
			PrintString(COL_WORD15, ROW_TEXT05, "  ", 1);

			
			DispMac();            // 显示Mac
			DispIntensityLogo();  // 显示场强Logo
		}
		else
		{	
			if(SelectStation == SubStation)
			{
				// 未入网的情况
				PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "        ", 4);
				PrintString(COL_WORD10+WIDTH_HALF, ROW_TEXT05, "未同步", 6);
				// SNR=0		
				PrintString(COL_WORD14+WIDTH_HALF, ROW_TEXT05, "        ", 4);
				PrintOneFont16x16(COL_WORD15, ROW_TEXT05, Logo_zeroState);
			}
		}
	}

	#if 0
	// 显示实时速率    
	if(t_CurRadioState.ParamState == YES)
	{
		DispRealTimeRate();
	}
	#endif
}

/*********************************************************
*函数名：DispRealTimeRate
*功能  ：显示实时速率
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispRealTimeRate(void)
{
	DispRate(0);
}

/*********************************************************
*函数名：DispDateNum
*功能  ：显示日期
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispTimeNum
*功能  ：显示时间
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispTimeNum
*功能  ：显示开机运行时间
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispRunTimeNum(void)
{
	uint8_t u8Hour = 0,u8Minute = 0;
	//t_SumRunTime.Minute = au8Code[0];//读取存在E2PROM的总运行时间	
	//t_SumRunTime.Hour   = au8Code[1];
	t_SumRunTime.Hour   = t_SubRunTime.Hour   + t_SumRunTime.Hour;
	t_SumRunTime.Minute = t_SubRunTime.Minute + t_SumRunTime.Minute;
	if((t_SumRunTime.Minute) == 60)
	{
		(t_SumRunTime.Hour)++;
		t_SumRunTime.Minute = 0;
	}
	// 显示本次运行时间
	g_u8DispBuf[0] = (t_SubRunTime.Hour/10) + '0'; // 高位
	g_u8DispBuf[1] = (t_SubRunTime.Hour%10) + '0'; // 低位
	g_u8DispBuf[2] = (t_SubRunTime.Minute/10) + '0'; // 高位
	g_u8DispBuf[3] = (t_SubRunTime.Minute%10) + '0'; // 低位
	g_u8DispBuf[4] = (t_SubRunTime.Second/10) + '0'; // 高位
	g_u8DispBuf[5] = (t_SubRunTime.Second%10) + '0'; // 低位
	// 显示总运行时间
	g_u8DispBuf[6] = (t_SumRunTime.Hour/10) + '0'; // 高位
	g_u8DispBuf[7] = (t_SumRunTime.Hour%10) + '0'; // 低位
	g_u8DispBuf[8] = (t_SumRunTime.Minute/10) + '0'; // 低位
	g_u8DispBuf[9] = (t_SumRunTime.Minute%10) + '0'; // 低位
	
	PrintString(COL_WORD12, ROW_TEXT06,&g_u8DispBuf[0], 2);
	PrintString(COL_WORD15, ROW_TEXT06,&g_u8DispBuf[2], 2);
	PrintString(COL_WORD17, ROW_TEXT06,&g_u8DispBuf[4], 2);

	PrintString(COL_WORD12, ROW_TEXT05,&g_u8DispBuf[6], 2);
	PrintString(COL_WORD15, ROW_TEXT05,&g_u8DispBuf[8], 2);
}

/*********************************************************
*函数名：DispMacAddr
*功能  ：显示MAC地址
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispMacAddr1
*功能  ：显示MAC地址
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispRadioTest
*功能  ：显示电台自检结果
*输入  ：无
*输出  ：无
*返回值：无
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
    		pu8Font = "×";
		}
		else
		{
    		pu8Font = "√";
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
	//密码机状态
	if(g_u8SecureFlag == SECURE_NORMAL)
	{
		PrintString(COL_WORD10, ROW_TEXT07,"密码机:√", WORD);
	}
	else if(g_u8SecureFlag != SECURE_EMPTY)
	{
		PrintString(COL_WORD10, ROW_TEXT07,"密码机:×", WORD);
	}
	
	//  2/3/4信号槽位状态
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
		PrintString(x, ROW_TEXT06, "槽信号:", 12);
		x += 7;
		for(i=0; i<u8Count; i++)
		{
			PrintString(x, ROW_TEXT06, "√", 2);
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
		PrintString(COL_WORD10, ROW_TEXT06, "信号单元:×", 11);
	}

	PrintString(WIDTH_HALF, ROW_TEXT09, "注: 按<F1-F4>下拉菜单", WORD);
}

/*********************************************************
*函数名：DispLinkBuildOprt
*功能  ：显示链路建立操作
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispLinkBuildOprt(void)
{
	uint8_t u8Index = 0,SelectState = LinkRemove;
	switch(g_u8CurMenuItem)
	{	
		case INDEX_EDIT_MAC01: 
			u8Index = INDEX_EDIT_MAC01;
			SelectState = SelectState01;
			DispLinkBuildState(SelectState,u8Index); // 建链、拆链
			SelectState01 = ~SelectState01;          // 标志位
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
*函数名：DispMac
*功能  ：统计建链结果
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispMac
*功能  ：显示Mac号
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispMac(void)
{
	uint8_t i = 0,u8Col_Mac = 0,u8Col_State = 0;
	uint8_t u8Row_Mac[4] = {ROW_TEXT04, ROW_TEXT05, ROW_TEXT06, ROW_TEXT07};

	if(g_u8CurMenuID == MENU_PARAMWORKSTATE)
	{
		if(SelectStation == SubStation)  // 从站
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
			PrintString(u8Col_Mac,ROW_TEXT04,&g_u8DispBuf_Mac[2*i],2); // 显示Row_Text04行的Mac号
			if(i<4)
			{	
				PrintString(u8Col_State,ROW_TEXT07,&g_u8DispBuf_Mac[2*i],2); // 显示Row_Text07行Mac号
				DispLinkNetState(u8Col_State+COL_WORD1,ROW_TEXT07,i);	     // 显示Row_Text07行入网状态
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
*函数名：DispIntensityLogo
*功能  ：显示场强图标
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispLinkQuantity
*功能  ：显示链路质量
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispLinkQuantity(uint8_t rev)
{
	uint8_t i = 0,Col_Quality = 0;
    if(rev == 0)
    {
		for(i=0;i<8;i++)
		{
			Col_Quality = COL_WORD4 +i*(COL_WORD2);
			g_u8DispBuf[2*i]   = (t_CurLinkInfo[i].Quality_Up   & 0x0f) + '0'; // 高位是 0舍弃
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
			g_u8DispBuf[i]   = (t_CurLinkInfo[i].Quality_Up   & 0x0f) + '0'; // 高位是 0舍弃
			g_u8DispBuf[i+1] = (t_CurLinkInfo[i].Quality_Down & 0x0f) + '0'; 

			PrintString(Col_Quality, ROW_TEXT05, &g_u8DispBuf[2*i+0], 1);
			PrintString(Col_Quality, ROW_TEXT06, &g_u8DispBuf[2*i+1], 1);
		}
    }
}

/*********************************************************
*函数名：DispLinkQuantity_Test
*功能  ：显示链路质量
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
// test 20151229
void DispLinkQuantity_Test(uint8_t rev)
{
	//DispSNR(void);
	if(rev == 0) // 不同步
	{
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT05, "	   ", 4);		// 上行质量
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT05, " × ", 4);
		
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT06, "	   ", 4);		// 下行质量
		PrintString(COL_WORD4+WIDTH_HALF, ROW_TEXT06, " × ", 4);
	}
	else
	{
		#if 0
		g_u8DispBuf[0] = (t_ReportLinkQuan[0].SNR/10) + '0';
		g_u8DispBuf[1] = (t_ReportLinkQuan[0].SNR%10) + '0';
		PrintString(COL_WORD4, ROW_TEXT05, "	", 2);		// 上行质量
		PrintString(COL_WORD4, ROW_TEXT05, g_u8DispBuf, 2);
		
		PrintString(COL_WORD4, ROW_TEXT06, "	", 2);		// 下行质量
		PrintString(COL_WORD4, ROW_TEXT06, g_u8DispBuf, 2);
		#endif
		PrintString(COL_WORD4, ROW_TEXT05, "	      ", 8);		// 上行质量
		PrintString(COL_WORD4, ROW_TEXT05, &g_u8DispBuf[2], 7);
		
		PrintString(COL_WORD4, ROW_TEXT06, "	      ", 8);		// 下行质量
		PrintString(COL_WORD4, ROW_TEXT06, &g_u8DispBuf[2], 7);
	}
}

/*********************************************************
*函数名：DispLinkMaintainGap
*功能  ：显示链路维护间隔(一次性全显示)
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：ProcLinkBuildParamKey_UpDown
*功能  ：处理链路建立参数页下的向上、向下键
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void ProcLinkBuildParamKey_UpDown(void)
{   
    g_u8PreLinkOprtState = (g_u8PreLinkOprtState+1)%2;
    DispLinkOprtParamReverse();
}

/*********************************************************
*函数名：DispLinkOprtParamReverse
*功能  ：反显链路操作参数
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispLinkOprtParamReverse(void)
{
	if(g_u8PreLinkOprtState == LinkRemove)
	{
		PrintStringReverse(COL_WORD6, ROW_TEXT06,	"拆链", WORD);
	}
	else
	{	
		PrintStringReverse(COL_WORD6, ROW_TEXT06,	"建链", WORD);
	}
}

/*********************************************************
*函数名：DispLinkBuildState
*功能  ：显示链路建立状态
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispLinkBuildState(uint8_t state,uint8_t rev)
{
	if(state == LinkRemove)  // 拆链
	{
		PrintString(COL_WORD2+(rev-1)*(COL_WORD2),ROW_TEXT05,"√",2);
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
*函数名：DispReverseGap
*功能  ：反显Mac对应的链路维护间隔
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispGap(uint8_t x, uint8_t y, uint8_t u8Gap, uint8_t rev)
{
	uint8_t i = 0;
	Mode_TypeDef mMaintainGap[4]  = {{INDEX_EDIT_GAP0,"0-作战<00s>"},{INDEX_EDIT_GAP1,"1-作战<10s>"},
	                                 {INDEX_EDIT_GAP2,"2-作战<20s>"},{INDEX_EDIT_GAP3,"3-作战<30s>"}};

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
*函数名：DispReverseGap
*功能  ：反显Mac对应的链路维护间隔
*输入  ：无
*输出  ：无
*返回值：无
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
	DispGap(x, y, t_EditLinkInfo[g_u8CurMenuItem-1].MaintainGap_ID, 1);// 1 反显
}

/*********************************************************
*函数名：DispRecoverGap
*功能  ：正显Mac对应的链路维护间隔
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispDigTranInfo_Mac
*功能  ：正显数传信息Mac号
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispDigTranInfo_Mac()
{
	int i = 0,Row_X[4] = {ROW_TEXT04,ROW_TEXT05,ROW_TEXT06,ROW_TEXT07};
	if(SelectPage == PageOne)
	{	
		for(i=0;i<4;i++)
		{	
			g_u8DispBuf[2*i+0] = (LinkInfo_Cur[i].MacNum >> 4) + '0';	// 高位
			g_u8DispBuf[2*i+1] = (LinkInfo_Cur[i].MacNum & 0x0F) + '0'; // 低位
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], "  ", 2);
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], &g_u8DispBuf[2*i], 2);
		}	
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(1/2)", WORD);
	}
	else
	{
		for(i=0;i<4;i++)
		{
			
			g_u8DispBuf[2*i+0] = (LinkInfo_Cur[i+4].MacNum >> 4) + '0';	// 高位
			g_u8DispBuf[2*i+1] = (LinkInfo_Cur[i+4].MacNum & 0x0F) + '0'; // 低位
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], "  ", 2);
			PrintString(COL_WORD2+WIDTH_HALF, Row_X[i], &g_u8DispBuf[2*i], 2);
		}
		PrintString(COL_WORD16+WIDTH_HALF, ROW_TEXT08, "(2/2)", WORD);
	}
}
#endif

/*********************************************************
*函数名：DispDigTranInfo_FrameInfo
*功能  ：正显数传收到的帧信息
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispLinkNetState
*功能  ：显示链路入网状态
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispLinkNetState(uint8_t x,uint8_t y,uint8_t rev)
{
	uint8_t u8Col_Mac	= COL_WORD2  + rev*COL_WORD2;
	
	if(0 == t_CurLinkInfo[rev].NetState)
	{
		PrintString(u8Col_Mac,ROW_TEXT05,"- ",2); // 显示Row_Text05行的入网状态
		PrintString(x, y,":未入网",7);	          // 显示Row_Text07、Row_Text08行的入网状态
	}
	else
	{	
		PrintString(u8Col_Mac,ROW_TEXT05,"√",2);
		PrintString(x, y,":已入网",7);	
	}
}

/*********************************************************
*函数名：DispRadioRank
*功能  ：显示电台等级
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispRadioRank(uint8_t rev)
{
    if(rev == 0)
    {
		#if 0
		// Test  mainStation:00 下 20151223
		if(t_CurRadioState.MAC == 00)
		{			
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "主站", WORD);
			SelectStation = MainStation;
		}
		else
		{			
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "从站", WORD);
			SelectStation = SubStation;
		}
		// Test  mainStation:00 上 20151223
		#endif
		
		//test
		if(SelectStation == SubStation)
		{			
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "从站", WORD);
		}
		else
		{		
			PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "主站", WORD);
		}
		//test
		
		#if 0
		if (t_CurRadioState.Rank == 0) // 从站 
        {			
			if(SelectStation == SubStation)
			{			
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "从站", WORD);
			}
			else
			{		
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "主站", WORD);
			}
        }
        else 
        {
			if(SelectStation == SubStation)
			{			
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "从站", WORD);
			}
			else
			{		
				PrintString(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "主站", WORD);
			}
        }
		#endif
		
    }
    else
    {
        if(t_EditRadioState.Rank == 0)
        {
            PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "从站", WORD);
        }
        else 
        {
            PrintStringReverse(COL_WORD3 + WIDTH_HALF, ROW_TEXT06, "主站", WORD);
        }
    }
}

/*********************************************************
*函数名：DispRadioPower
*功能  ：显示电台功率
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispRadioPower(uint8_t rev)
{
    uint8_t i = 0, x = 0, y = 0;
    Mode_TypeDef mPower[3] = {{0, "值守"}, {1, "小功率"}, {3, "大功率"}};
	
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
*函数名：DispIpAddr
*功能  ：显示IP地址
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispMaskAddr
*功能  ：显示掩码地址
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispMask_CountOne
*功能  ：计算掩码的1的个数
*输入  ：无
*输出  ：无
*返回值：无
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
*函数名：DispSendRate
*功能  ：显示实际发送速率
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispSendRate(void)
{
    uint8_t i = 0;
    Mode_TypeDef mRateMode[] = {{0, "64kbps↑"}, {1, "128kbps↑"}, {2, "192kbps↑"}, {3, "256kbps↑"},
								{4, "256kbps↑"}, {5, "512kbps↑"}, {6, "1024kbps↑"}};

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
*函数名：DispRate
*功能  ：显示速率
*输入  ：无
*输出  ：无
*返回值：无
***********************************************************/
void DispRate(uint8_t rev)
{
    ;
}

/*********************************************************
*函数名：DispSNR
*功能  ：显示SNR
*输入  ：无
*输出  ：无
*返回值：无
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
    {//传递.实际均为正数
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


