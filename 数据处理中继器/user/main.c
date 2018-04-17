/**
  ******************************************************************************
  * @file    IO_Toggle/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4_discovery.h"

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup IO_Toggle
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/

#define GET_GOKIT_DATA	0x55

unsigned char ucBuff[42];
int gfTimTrig = 0;
int iTimeCnt = 0;
int iUart1DataRdy = 0;
int iUart2DataRdy = 0;
int iUart3DataRdy = 0;
int iUart4DataRdy = 0;
unsigned char Uart1Buff[3];
unsigned char Uart1BuffIndex=0;
unsigned char Uart2Buff[3];
unsigned char Uart2BuffIndex=0;
unsigned char Uart3Buff[3];
unsigned char Uart3BuffIndex=0;
unsigned char Uart4Buff[3];
unsigned char Uart4BuffIndex=0;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);
/* Private functions ---------------------------------------------------------*/

void BuffInit(void)
{
	memset(ucBuff,0,sizeof(ucBuff));
	ucBuff[0] = '#';
	ucBuff[1] = 'D';
	ucBuff[2] = 'T';
	ucBuff[3] = 'U';
	ucBuff[4] = ',';
	///第一路数据红外、温度、湿度
	ucBuff[5] = '0';
	ucBuff[6] = '1';
	ucBuff[7] = ',';
	ucBuff[8] = '0';
	ucBuff[9] = '0';
	ucBuff[10] = ',';
	ucBuff[11] = '0';
	ucBuff[12] = '0';
	ucBuff[13] = ',';
	///第二路数据红外、温度、湿度
	ucBuff[14] = '0';
	ucBuff[15] = '1';
	ucBuff[16] = ',';
	ucBuff[17] = '0';
	ucBuff[18] = '0';
	ucBuff[19] = ',';
	ucBuff[20] = '0';
	ucBuff[21] = '0';
	ucBuff[22] = ',';
	///第三路数据红外、温度、湿度
	ucBuff[23] = '0';
	ucBuff[24] = '1';
	ucBuff[25] = ',';
	ucBuff[26] = '0';
	ucBuff[27] = '0';
	ucBuff[28] = ',';
	ucBuff[29] = '0';
	ucBuff[30] = '0';
	ucBuff[31] = ',';
	//第四路数据红外、温度、湿度
	ucBuff[32] = '0';
	ucBuff[33] = '1';
	ucBuff[34] = ',';
	ucBuff[35] = '0';
	ucBuff[36] = '0';
	ucBuff[37] = ',';
	ucBuff[38] = '0';
	ucBuff[39] = '0';
	ucBuff[40] = 0x0D;
	ucBuff[41] = 0x0A;
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
        system_stm32f4xx.c file
     */
	int i;
	BuffInit();
	USART_Cfg();

  while (1)
  {
		if(gfTimTrig==1)
		{
			gfTimTrig = 0;
			if (iTimeCnt == 120)
				iTimeCnt = 0;
			else
				iTimeCnt++;
			if(iTimeCnt ==20)
			{
				if(iUart1DataRdy==1)
				{
					iUart1DataRdy= 0;
				  Uart1BuffIndex = 0;
					 ///第一路数据红外、温度、湿度
					 ucBuff[6] = Uart1Buff[0]+'0';
					 if (Uart1Buff[1]>=100)
							Uart1Buff[1]=99;
					    ucBuff[8] = Uart1Buff[1]/10+'0';
					    ucBuff[9] = Uart1Buff[1]%10+'0';
					 if (Uart1Buff[2]>=100)
							Uart1Buff[2]=99;						
					    ucBuff[11] = Uart1Buff[2]/10+'0';
					    ucBuff[12] = Uart1Buff[2]%10+'0';;	
				}				   
				
					USART_SendData(USART1,GET_GOKIT_DATA);
					while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
			}
			else if (iTimeCnt ==40)
			{
				if(iUart2DataRdy==1)
				{
					iUart2DataRdy = 0;
				  Uart2BuffIndex = 0;
					///第二路数据红外、温度、湿度
					ucBuff[15] = Uart2Buff[0]+'0';
					if (Uart2Buff[1]>=100)
							Uart2Buff[1]=99;
						  ucBuff[17] = Uart2Buff[1]/10+'0';
						  ucBuff[18] = Uart2Buff[1]%10+'0';
					if (Uart2Buff[2]>=100)
							Uart2Buff[2]=99;
						  ucBuff[20] = Uart2Buff[2]/10+'0';
						  ucBuff[21] = Uart2Buff[2]%10+'0';;		
				}
					USART_SendData(USART2,GET_GOKIT_DATA);
					while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
			}
			else if (iTimeCnt ==60)
			{
				if(iUart3DataRdy ==1)
				{
					iUart3DataRdy =0;
				  Uart3BuffIndex = 0;
					///第三路数据红外、温度、湿度
					ucBuff[24] = Uart3Buff[0]+'0';
					if (Uart3Buff[1]>=100)
						Uart3Buff[1]=99;										
					  ucBuff[26] = Uart3Buff[1]/10+'0';
					  ucBuff[27] = Uart3Buff[1]%10+'0';
					if (Uart3Buff[2]>=100)
						Uart3Buff[2]=99;	
					  ucBuff[29] = Uart3Buff[2]/10+'0';
					  ucBuff[30] = Uart3Buff[2]%10+'0';;	
				}
				
					USART_SendData(USART3,GET_GOKIT_DATA);
					while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
			}
			else if (iTimeCnt ==80)
			{
				if(iUart4DataRdy ==1)
				{
					iUart4DataRdy =0;
				  Uart4BuffIndex = 0;
					///第四路数据红外、温度、湿度
					ucBuff[33] = Uart4Buff[0]+'0';
					if (Uart4Buff[1]>=100)
							Uart4Buff[1]=99;							
						ucBuff[35] = Uart4Buff[1]/10+'0';
						ucBuff[36] = Uart4Buff[1]%10+'0';
					if (Uart4Buff[2]>=100)
							Uart4Buff[2]=99;						
						ucBuff[38] = Uart4Buff[2]/10+'0';
						ucBuff[39] = Uart4Buff[2]%10+'0';;	
				}
				
					USART_SendData(UART4,GET_GOKIT_DATA);
					while (USART_GetFlagStatus(UART4, USART_FLAG_TXE) == RESET);
			}
			else if (iTimeCnt ==100)
			{
					for(i=0;i<42;i++)
					{
						USART_SendData(UART5,ucBuff[i]);
						while (USART_GetFlagStatus(UART5, USART_FLAG_TXE) == RESET);
					}
			}
		}
  }
}

/**
  * @brief  Delay Function.
  * @param  nCount:specifies the Delay time length.
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
