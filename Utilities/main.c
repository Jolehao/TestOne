#include "all.h"

/*test 20160611  ---  NanJingUniversitity*/
int main(void)
{
    BSP_Init();
	while(1)
	{
		if((g_u16Timer2Count%20) == 0)
		{
			PowerOnOff_Ctrl();
		}

		if(g_u8PowerOn == YES)
		{
			//ReadCode(au8Code);
			PTT_Ctrl();
			Volume_Ctrl();
			RespondKey();
			//ProcTimeOutWarning();
			ProcRealTimeUpdate(); 
			Receive_SerialData();
			ProcTimeOutEvent();
		}
	}
}

/*********************************************************
*��������TIM2_IRQHandler
*����  ����ʱ��2�жϺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void TIM2_IRQHandler(void)
{
    ScanKey();
	g_u16Timer2Count++;

    // ���ڶ�ʱ����ʱ��
    if(g_u16Timer2Count % 5 == 0)
    {
        g_u8UpdateTime = ~g_u8UpdateTime;
        g_u16SecondCount++;
		g_u8PowerOnOffTick++;
    }

	if(g_u16Timer2Count % 25 == 0) // 1sһ�Σ�ǰ��:Timer2/40ms
	{
		g_u8RunTimeUpdate = ~g_u8RunTimeUpdate;
		g_u8RunTimeCount++; //���㱾�ο�������ʱ��
	}
			
    // �����շ��ƶ�ʱ��˸����
    if(g_u8RTxTimeFlag == YES)
    {
        g_u16RTxTimeTick = (g_u16RTxTimeTick + 1)%20;
    }
 
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}


/*********************************************************
*��������USART1_IRQHandler
*����  ������1�жϺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
    {
		// ���жϱ�־λ
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		USART_ClearFlag(USART1, USART_IT_RXNE);

        if((g_u8TailRx+1)%200 != g_u8HeadRx)
        {
            // �����ݼĴ����ж�ȡһ���ֽ����� 
            g_u8SerialDataRx[g_u8TailRx] = (USART_ReceiveData(USART1) & 0xFF);
            g_u8TailRx = (g_u8TailRx + 1)%200;
        }
     }

    if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
    {   
    	g_u8LengthTx %= 200;
        USART_SendData(USART1, (uint8_t)g_u8SerialDataTx[g_u8LengthTx]);
		g_u8LengthTx++;
        if(g_u8LengthTx >= g_u8RadioCommTx_Len)
        {
            // Disable the EVAL_COM1 Transmit interrupt 
            USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
        }
    }
}	

/*********************************************************
*��������USART3_IRQHandler
*����  ������3�жϺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void USART3_IRQHandler(void)
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        if((g_u8TailRx+1)%200 != g_u8HeadRx)
        {
            // �����ݼĴ����ж�ȡһ���ֽ����� 
            g_u8SerialDataRx[g_u8TailRx] = (USART_ReceiveData(USART3) & 0xFF);
            g_u8TailRx = (g_u8TailRx + 1)%200;
            // ���жϱ�־λ
            USART_ClearFlag(USART3, USART_FLAG_RXNE);
            USART_ClearITPendingBit(USART3, USART_IT_RXNE);
        }
     }

    if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET)
    {   
        USART_SendData(USART3, (uint8_t)g_u8SerialDataTx[g_u8LengthTx++]);
        if(g_u8LengthTx >= g_u8RadioCommTx_Len)
        {
            // Disable the EVAL_COM1 Transmit interrupt 
            USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
        }
    }
}

/*********************************************************
*��������I2C1_ER_IRQHandler
*����  ��I2C1�����жϺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void I2C1_ER_IRQHandler(void)
{
    /* Read SR1 register to get I2C error */
    if ((I2C_ReadRegister(I2C1, I2C_Register_SR1) & 0xFF00) != 0x00)
    {
        /* Clears error flags */
        I2C1->SR1 &= 0x00FF;
        
        /* Send STOP condition */
        I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
        g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
        g_u8RTC_Error       = YES;
        //I2C_GenerateSTOP(I2C1, ENABLE);
        //I2C_AcknowledgeConfig(I2C1, DISABLE);

        //ClearTextState2();
        //PrintString(COL_WORD1, ROW_STATE2, "״̬:I2C�жϴ���!", WORD);
    }
}

/*********************************************************
*��������I2C1_EV_IRQHandler
*����  ��I2C1�¼��жϺ���
*����  ����
*���  ����
*����ֵ����
***********************************************************/
void I2C1_EV_IRQHandler(void)
{
    if(g_u8RTC_InterruptEn == NO)
    {
        return;
    }

    if(g_u8RTC_TranMode == RTC_MODE_TRANSMITTER)   // MASTER SEND DATA
    {
        switch (I2C_GetLastEvent(I2C1))                 // Get last EVENT
        {
            /* EV5 */
            case I2C_EVENT_MASTER_MODE_SELECT:
                /* Send slave Address for write */
                //(void)(I2C1->SR1);
                I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Transmitter);
                break;
        
            /* EV6 */
            case I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED:
                /*Clear ADDR Register  */
                //(void)(I2C1->SR1);
                //(void)(I2C1->SR2);
                I2C_SendData(I2C1, g_u8RTC_RegIndex); 
                break;
        
            /* EV8 */
            case I2C_EVENT_MASTER_BYTE_TRANSMITTING:
				if(g_u8RTC_DataBufLen == 0)
				{
					// Send STOP condition 
                    //I2C_GenerateSTOP(I2C1, ENABLE);
					I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
					g_u8RTC_InterruptEn = NO;		// RTC INTERRUPT ENABLE
				}
				else if(g_u8RTC_TxIdx < g_u8RTC_DataBufLen)
                {
                    /* Transmit Data TxBuffer */
                    I2C_SendData(I2C1, g_u8RTC_DataTx[g_u8RTC_TxIdx++]); 
                }
                break;
                
            case I2C_EVENT_MASTER_BYTE_TRANSMITTED: 
				if(g_u8RTC_TxIdx == g_u8RTC_DataBufLen)
                {
                    /* Send STOP condition */
                    I2C_GenerateSTOP(I2C1, ENABLE);
                    I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                    g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT DISABLE
                }
                break;
        
            default:
                    //I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                    //g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT DISABLE
                break;
        }
    }
    else if(g_u8RTC_TranMode == RTC_MODE_RECEIVER)   // MASTER RECEIVE DATA
    {
        // Check on EV5 
        if(I2C_GetITStatus(I2C1, I2C_IT_SB) == SET)
        {
            // Send slave Address for read
            I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Receiver);
            I2C_ITConfig(I2C1, I2C_IT_BUF, ENABLE);
        }
        else if(I2C_GetITStatus(I2C1, I2C_IT_ADDR) == SET)
        {
            /*Clear ADDR Register */
            (void)(I2C1->SR1);
            (void)(I2C1->SR2);
        }
        else if((I2C_GetITStatus(I2C1, I2C_IT_RXNE) == SET)&&(I2C_GetITStatus(I2C1, I2C_IT_BTF) == RESET))
        {
        	g_u8RTC_RxIdx %= 20;
            g_u8RTC_DataRx[g_u8RTC_RxIdx] = I2C_ReceiveData (I2C1);
        	g_u8RTC_RxIdx++;
            
            if(g_u8RTC_RxIdx == g_u8RTC_DataBufLen - 3)
            {
              /* Disable buffer Interrupts */
              I2C_ITConfig(I2C1, I2C_IT_BUF, DISABLE);
            }
            
            if(g_u8RTC_RxIdx == g_u8RTC_DataBufLen)
            {
              /* Disable Error and Buffer Interrupts */
              I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);            
            }
        }
        else if(I2C_GetITStatus(I2C1, I2C_IT_RXNE) == SET)
        {
            if(g_u8RTC_RxIdx == g_u8RTC_DataBufLen - 3)
            {
                I2C_AcknowledgeConfig(I2C1, DISABLE);
				g_u8RTC_RxIdx %= 20;
                g_u8RTC_DataRx[g_u8RTC_RxIdx] = I2C_ReceiveData(I2C1);
				g_u8RTC_RxIdx++;
            }
            else if(g_u8RTC_RxIdx == g_u8RTC_DataBufLen - 2)
            {
                /* Send STOP condition */
                I2C_GenerateSTOP(I2C1, ENABLE);
				g_u8RTC_RxIdx %= 19;
                g_u8RTC_DataRx[g_u8RTC_RxIdx] = I2C_ReceiveData (I2C1);
				g_u8RTC_RxIdx++;
                g_u8RTC_DataRx[g_u8RTC_RxIdx] = I2C_ReceiveData (I2C1);
				g_u8RTC_RxIdx++;
                I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, DISABLE);
                g_u8RTC_InterruptEn = NO;       // RTC INTERRUPT ENABLE
            }
            else
            {
				g_u8RTC_RxIdx %= 20;
                g_u8RTC_DataRx[g_u8RTC_RxIdx] = I2C_ReceiveData (I2C1);
				g_u8RTC_RxIdx++;
            }
        }
    }
}

