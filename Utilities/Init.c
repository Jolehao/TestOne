#include "init.h"
#include "io.h"
 

extern void LCD_Clear(uint8_t Level);
extern void WriteVolDataTo5402(uint8_t VolData);

/*********************************************************
*��������BSP_Init
*���ܣ���ʼ��STM32F207(��ϵͳʱ�ӡ�ͨ��IO���жϳ�ʼ��)
*���룺	��
*�����	��
*����ֵ�� ��
***********************************************************/
void BSP_Init(void)
{
    NVIC_Configuration();
	GPIO_Configuration();
    Timx_Configuration();
    COMx_Configuration();
	I2C1_Configuration();
    FSMC_Configuration();
	RadioState_Init();
}

/*********************************************************
*��������GPIO_Configuration
*���ܣ�GPIO��ʼ������
*���룺	��
*�����	��
*����ֵ�� ��
***********************************************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
    
//*********ʹ�ܶ˿�ʱ�� ***************//
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | 
	                       RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG, ENABLE);

//********* ����������� ***************//
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    // ����GPIOA�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 |
	                                GPIO_Pin_3 | GPIO_Pin_11 | GPIO_Pin_12;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    // ����GPIOB�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_12 
	                              | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

    // ����GPIOD�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_10;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

    // ����GPIOG�˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_11 | GPIO_Pin_15;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

    // ����GPIOF�˿�����
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 
    								| GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
    GPIO_Init(GPIOF, &GPIO_InitStructure);


/* ʹ�ܰ����˿�ʱ�� */
/******   KEY_X1--PC6       KEY_Y2--PC2   *********************/
/******   KEY_X2--PC7       KEY_Y3--PC3   *********************/
/******   KEY_X3--PC8       KEY_Y4--PC4   *********************/
/******   KEY_X4--PC9       KEY_Y5--PC5   *********************/
/******   KEY_Y1--PC1       KEY_Y6--PC10  *********************/
	/* ���� KEY����x ���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

//********* ������������ ***************//
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;

    // ssl20131022�޸� ��������GPIOA�˿�PTT����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	/* ���� KEY����y ���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 
                                  | GPIO_Pin_5 | GPIO_Pin_10 | GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* ���� ��Կ���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

/*********************************************************
*��������FSMC_Configuration
*���ܣ�Һ�����ʶ˿ڳ�ʼ������
*���룺	��
*�����	��
*����ֵ�� ��
***********************************************************/
void FSMC_Configuration(void)
{
    FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef  p;
    GPIO_InitTypeDef GPIO_InitStructure; 

    /* Enable GPIOs clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOF |
                         RCC_AHB1Periph_GPIOG, ENABLE);

/******   A0--PF0    *******   D5--PE8    **************/
/******   A1--PF1    *******   D6--PE9    **************/
/******   D0--PD14   *******   D7--PE10   **************/
/******   D1--PD15   *******   NE2--PG9   **************/
/******   D2--PD0    *******   WR--PD5    **************/
/******   D3--PD1    *******   RD--PD4    **************/
/******   D4--PE7    ***********************************/

    /* GPIOD configuration */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 
                                  | GPIO_Pin_5 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    /* GPIOE configuration */
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource7, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource8, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_FSMC);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8  | GPIO_Pin_9  | GPIO_Pin_10;
    GPIO_Init(GPIOE, &GPIO_InitStructure);


    /* GPIOF configuration */
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource0 , GPIO_AF_FSMC);
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource1 , GPIO_AF_FSMC);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;      
    GPIO_Init(GPIOF, &GPIO_InitStructure);
    
    /* GPIOG configuration */
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource9 , GPIO_AF_FSMC);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;      
    GPIO_Init(GPIOG, &GPIO_InitStructure);

/*-- FSMC Configuration ------------------------------------------------------*/
    /* Enable FSMC clock */
    RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE); 
    
    p.FSMC_AddressSetupTime = 1;
    p.FSMC_AddressHoldTime = 0;
    p.FSMC_DataSetupTime = 9;
    p.FSMC_BusTurnAroundDuration = 0;
    p.FSMC_CLKDivision = 2;
    p.FSMC_DataLatency = 0;
    p.FSMC_AccessMode = FSMC_AccessMode_A;

    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM2;
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 

    /*!< Enable FSMC Bank1_SRAM2 Bank */
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM2, ENABLE); 
}

/*********************************************************
*��������Timx_Configuration
*��  �ܣ���ʱ����ʼ������
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void Timx_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    // ����TIM2ÿ20ms�ж�һ��
    TIM_DeInit(TIM2);
    TIM_TimeBaseStructure.TIM_Period = 1199;
    TIM_TimeBaseStructure.TIM_Prescaler = 1999;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}

/*********************************************************
*��������NVIC_Configuration
*��  �ܣ��жϳ�ʼ������
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);//���ڼ���
    //NVIC_SetVectorTable(NVIC_VectTab_BOOT, 0x0);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* Enable the Tim2 Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Enable the USART3 Interrupt */

    NVIC_InitStructure.NVIC_IRQChannel                   = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_Init(&NVIC_InitStructure);

    /* Enable the USART1 Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
    NVIC_Init(&NVIC_InitStructure);

	/* Enable the I2C1 Interrupt */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel                   = I2C1_EV_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel                   = I2C1_ER_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
	NVIC_Init(&NVIC_InitStructure);
}

/*********************************************************
*��������USART1_Configuration
*��  �ܣ�����1��ʼ������
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void USART1_Configuration(void)
{
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable UART clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* Connect PXx to USARTx_Tx*/
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);        // ����USART1������

    /* Connect PXx to USARTx_Rx*/
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);        // ����USART1������

    /* Configure USART Tx as alternate function  */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 38400;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /* USART configuration */
    USART_Init(USART1, &USART_InitStructure);

    /* Enable USART */
    USART_Cmd(USART1, ENABLE);
    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

/*********************************************************
*��������USART3_Configuration
*��  �ܣ�����3��ʼ������
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void USART3_Configuration(void)
{
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable UART clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    /* Connect PXx to USARTx_Tx*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);       // ����USART3������

    /* Connect PXx to USARTx_Rx*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);        // ����USART3������

    /* Configure USART Tx as alternate function  */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 38400;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /* USART configuration */
    USART_Init(USART3, &USART_InitStructure);

    /* Enable USART */
    USART_Cmd(USART3, ENABLE);
    
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
}

/*********************************************************
*��������I2C1_Configuration
*��  �ܣ�I2C1�ڳ�ʼ������
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void I2C1_Configuration(void)
{
    I2C_InitTypeDef  I2C1_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable I2C1 clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
    
    /* Enable I2C1 clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	/*Reset I2Cx IP*/
	RCC_AHB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);

	/*Release reset signal of I2Cx IP*/
	//RCC_AHB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);

    /* Configure PB6 / PB7 as alternate function  */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /* Connect PB6 to I2C1_SCL*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);        // ����I2C1��SCL����

    /* Connect PB7 to I2C1_SDA*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1);        // ����I2C1��SDA����
    
    /* I2C1 configuration */
	I2C_DeInit(I2C1);

	I2C_StructInit(&I2C1_InitStructure);
    I2C_Init(I2C1, &I2C1_InitStructure);

    /* Enable Error Interrupt */
    I2C_ITConfig(I2C1, I2C_IT_ERR , ENABLE);
    
    /* I2C ENABLE */
    I2C_Cmd(I2C1, ENABLE);
}

/*********************************************************
*��������COMx_Configuration
*��  �ܣ����ڳ�ʼ������
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void COMx_Configuration(void)
{
    USART1_Configuration();
    //USART3_Configuration();
}


/*********************************************************
*��������Init_IO
*��  �ܣ�IO�˿ڳ�ʼ��
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void Init_IO(void)
{
//  ��Դ�����ź���ʼ״̬
    SetGpioBit(CON_POWER_PIN);       // �����ذ����������ƽ
    //ClrGpioBit(CON_POWER_PIN);       // �����ذ����������ƽ

//  LED����ʼ״̬
    ClrGpioBit(LED_ALARM2_PIN);     // ��ʼ���澯�Ʋ���
    ClrGpioBit(LED_ALARM1_PIN);   
    ClrGpioBit(LED_POWER2_PIN);     // ��ʼ��Ϊ��Դ�أ��Ʋ���
    ClrGpioBit(LED_POWER1_PIN);   
    ClrGpioBit(LED_Rx_PIN);          // ��ʼ��Ϊ�غ�(���շ�)���Ʋ���
    ClrGpioBit(LED_Tx_PIN);   

//  ��������ƿ���Ĭ�Ϲ�״̬
    ClrGpioBit(LED_BAK_PIN);

//  ���ȿ��ؿ���Ĭ�Ͽ�״̬
    ClrGpioBit(SEL_PTT3_PIN);

//  ����(5402)�����ź���ʼ״̬
    SetGpioBit(CON_5402CS_PIN);        
    SetGpioBit(CON_5402CLK_PIN);       
    SetGpioBit(CON_5402DIN_PIN);   
    WriteVolDataTo5402(VOLUME_LEVEL1);// ����Ĭ������Ϊ�ȼ�1

//  ��ʼ������Ϊ��״̬
    ClrGpioBit(CON_SPK_PIN);

//  ��ʼ��E2PROMΪ����д״̬�����벻������
    ClrGpioBit(E2PROM_WP_PIN);
	SetGpioBit(E2PROM_SCL_PIN);
	SetGpioBit(E2PROM_SDA_PIN);


//  PTT�����ź���ʼ״̬
    ClrGpioBit(SEL_MIC1_PIN);       // ѡ�����·��Ƶ���
    SetGpioBit(SEL_MIC2_PIN);

    ClrGpioBit(SEL_PTT1_PIN);       // ��Ƶ����Ĭ��ȫͨ
    ClrGpioBit(SEL_PTT2_PIN);
    ClrGpioBit(SEL_PTT3_PIN);

    SetGpioBit(SEL_SPEAKER_PIN);    // ������
    ClrGpioBit(SEL_SP_PIN);         // �ز���
    SetGpioBit(PTT_IN_PIN);         // ssl��ʼΪ��PTT����

//  ���ð���ɨ����ʼ״̬
    ClrGpioBit(KEY_X1_PIN);
    SetGpioBit(KEY_X2_PIN);
    SetGpioBit(KEY_X3_PIN);
    SetGpioBit(KEY_X4_PIN);

    SetGpioBit(KEY_Y1_PIN);
    SetGpioBit(KEY_Y2_PIN);
    SetGpioBit(KEY_Y3_PIN);
    SetGpioBit(KEY_Y4_PIN);
    SetGpioBit(KEY_Y5_PIN);
    SetGpioBit(KEY_Y6_PIN);
}

/*********************************************************
*��������Init_Param
*��  �ܣ�������ʼ��
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void Init_Param(void)
{
	uint8_t i = 0;
//  ����ʱ����ʼ״̬
    t_CurTime.Year = 0x13;
    t_CurTime.Month = 1;
    t_CurTime.Day = 1;
    t_CurTime.WeekDay = 0;
    t_CurTime.Hour = 0;
    t_CurTime.Minute = 0;
    t_CurTime.Second = 0;
    memcpy(&t_EditTime, &t_CurTime, sizeof(t_CurTime));
    
//  �����ŵ�������ʼ״̬
    t_CurChannelState.ChanNum   = 00;
    t_CurChannelState.WaveMode  = 01;
    t_CurChannelState.Freq[0]   = 2;
    t_CurChannelState.Freq[1]   = 0x55;//0x25 ��1128D����һ��
    t_CurChannelState.Freq[2]   = 0;
    t_CurChannelState.NetNum[0] = 0;
    t_CurChannelState.NetNum[1] = 0;
    //t_CurChannelState.Rank      = RANK_SLAVE; // ��̨
    t_CurChannelState.WorkMode  = WORKMODE_FIX;
    memcpy(&t_EditChannelState, &t_CurChannelState, sizeof(t_CurChannelState));

//  ���õ�̨������ʼ״̬
    t_CurRadioState.CallMAC            = 1;
    t_CurRadioState.ID[0]              = 0x83;
    t_CurRadioState.ID[1]              = 0x07;
    t_CurRadioState.ID[2]              = 0x50;
    t_CurRadioState.ID[3]              = 0;
    t_CurRadioState.ID[4]              = 0;
    t_CurRadioState.Indication         = 0;
    t_CurRadioState.Intensity          = 0x7F;
    t_CurRadioState.Service_IP[0]      = 0xC0;
    t_CurRadioState.Service_IP[1]      = 0xA8;
    t_CurRadioState.Service_IP[2]      = 0;
    t_CurRadioState.Service_IP[3]      = 1;
    t_CurRadioState.Service_MASK[0]    = 255;
    t_CurRadioState.Service_MASK[1]    = 255;
    t_CurRadioState.Service_MASK[2]    = 255;
    t_CurRadioState.Service_MASK[3]    = 0;
    t_CurRadioState.Manage_IP[0]      = 0xC0;
    t_CurRadioState.Manage_IP[1]      = 0xA8;
    t_CurRadioState.Manage_IP[2]      = 0;
    t_CurRadioState.Manage_IP[3]      = 1;
    t_CurRadioState.Manage_MASK[0]    = 255;
    t_CurRadioState.Manage_MASK[1]    = 255;
    t_CurRadioState.Manage_MASK[2]    = 255;
    t_CurRadioState.Manage_MASK[3]    = 0;
    t_CurRadioState.MAC               = 00;
	t_CurRadioState.Rank              = RANK_SLAVE; // ��̨
    t_CurRadioState.NetState          = 0;
    t_CurRadioState.ParamState        = NO;
    t_CurRadioState.Power             = POWER_LOW;
    t_CurRadioState.RemoteState       = 0;
    t_CurRadioState.SoftVersion[0]    = 0;
    t_CurRadioState.SoftVersion[1]    = 0;
    t_CurRadioState.SoftVersion[2]    = 0;
    t_CurRadioState.SoftVersion[3]    = 1;
    t_CurRadioState.SyncState         = 0;
    t_CurRadioState.UpperNet          = 0;
    //t_CurRadioState.Volume          = VOLUME_LEVEL2;
    memcpy(&t_EditRadioState, &t_CurRadioState, sizeof(t_CurRadioState));
	
	// ��·��Ϣ��ʼ��:  վ�š���ǿ������״̬
	t_CurLinkInfo[0].MacNum = 0x01;
	t_CurLinkInfo[1].MacNum = 0x02;
	t_CurLinkInfo[2].MacNum = 0x03;
	t_CurLinkInfo[3].MacNum = 0x04;
	t_CurLinkInfo[4].MacNum = 0x05;
	t_CurLinkInfo[5].MacNum = 0x06;
	t_CurLinkInfo[6].MacNum = 0x07;
	t_CurLinkInfo[7].MacNum = 0x08;

	for(i=0;i<4;i++)  
	{
		t_CurLinkInfo[2*i].Intensity   = 0x7f;
		t_CurLinkInfo[2*i+1].Intensity = 0x6f;
	}

	for(i=0;i<4;i++)
	{
		t_CurLinkInfo[2*i].NetState    = 0;
		t_CurLinkInfo[2*i+1].NetState  = 1;
	}

	t_CurLinkInfo[0].MaintainGap_ID = 3;
	t_CurLinkInfo[1].MaintainGap_ID = 3;
	t_CurLinkInfo[2].MaintainGap_ID = 1;
	t_CurLinkInfo[3].MaintainGap_ID = 0;
	t_CurLinkInfo[4].MaintainGap_ID = 3;
	t_CurLinkInfo[5].MaintainGap_ID = 2;
	t_CurLinkInfo[6].MaintainGap_ID = 1;
	t_CurLinkInfo[7].MaintainGap_ID = 3;
	
	t_CurLinkInfo[0].Quality_Up   = 0x08;
	t_CurLinkInfo[0].Quality_Down = 0x08;
	t_CurLinkInfo[1].Quality_Up   = 0x09;
	t_CurLinkInfo[1].Quality_Down = 0x09;
	
	t_CurLinkInfo[2].Quality_Up   = 0x06;
	t_CurLinkInfo[2].Quality_Down = 0x06;
	t_CurLinkInfo[3].Quality_Up   = 0x07;
	t_CurLinkInfo[3].Quality_Down = 0x07;
	
	t_CurLinkInfo[4].Quality_Up   = 0x05;
	t_CurLinkInfo[4].Quality_Down = 0x05;
	t_CurLinkInfo[5].Quality_Up   = 0x03;
	t_CurLinkInfo[5].Quality_Down = 0x03;
	
	t_CurLinkInfo[6].Quality_Up   = 0x09;
	t_CurLinkInfo[6].Quality_Down = 0x09;
	t_CurLinkInfo[7].Quality_Up   = 0x05;
	t_CurLinkInfo[7].Quality_Down = 0x05;
	//for(i=0;i<8;i++)
	{	
		//memcpy(&Linkinfo_Edit[i].MacNum,&LinkInfo_Cur[i].MacNum,sizeof(LinkInfo_Cur[i]));
	}
	

//	��ʼ�����ܻ�����
	t_CurSecureState.BoardNum 	   = 0;
	t_CurSecureState.WaveForm      = 0;
	t_CurSecureState.algorithm 	   = 0;
	t_CurSecureState.AreaNum	   = 0;
	t_CurSecureState.GroupNum1     = 0;
	t_CurSecureState.GroupNum2     = 0;
	//t_CurSecureState.effect	   = 0;/*��Ч��1 = OK??���ĵ�ȷ��*/
	t_CurSecureState.state		   = 0xFF;/*0-������0xFF-�������������-�쳣*/
	//t_CurSecureState.state		   = 0x01;/*0-������0xFF-�������������-�쳣*/
//  �����շ�����������ʼ״̬
    memset(g_u8SerialDataRx, 0, 200);  
    memset(g_u8SerialDataTx, 0, 200);  

	g_u8UpdateTime       = 0;
	g_u16SecondCount     = 0;
	g_u16RTxTimeTick     = 0;
	g_u8PowerOnOffTick   = 0;

	g_u8SelftestState[0] = 0x00;
	g_u8SelftestState[1] = 0x00;

	g_u8SecureFlag    = SECURE_EMPTY;
	g_u8RadioState    = YES;	// Ĭ�ϵ�̨״̬����
	g_u8RTxTimeFlag   = NO;
	g_u8FlagStartUp   = OFF;
	g_u8PowerOn       = NO;
	g_u8SpeakerState  = ON;
	g_u8CurMenuID     = MENU_POWER_ON;

	for(i=0;i<8;i++)
	{
		g_u8DispBuf_Mac[2*i+0]  = ((t_CurLinkInfo[i].MacNum >> 4)& 0x0F )+ '0';	// ��λ
		g_u8DispBuf_Mac[2*i+1]  = (t_CurLinkInfo[i].MacNum & 0x0F) + '0'; // ��λ
	}
}

/*********************************************************
*��������RadioState_Init
*��  �ܣ���̨״̬��ʼ��
*��  �룺��
*��  ������
*����ֵ����
***********************************************************/
void RadioState_Init(void)
{
    Init_IO();
    Init_Param();
}


