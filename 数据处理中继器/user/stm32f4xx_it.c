/**
  ******************************************************************************
  * @file    IO_Toggle/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "stm32f4xx_it.h"

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup IO_Toggle
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/
extern int  gfTimTrig;
extern unsigned char ucBuff[42];
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
	{
		gfTimTrig = 1;
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
}

extern unsigned char Uart1Buff[3];
extern unsigned char Uart1BuffIndex;
extern int iUart1DataRdy;
void USART1_IRQHandler(void)
{
    char c;
    if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==SET)
    {
				c = USART_ReceiveData(USART1);
				if(Uart1BuffIndex == 3)
				{					
					iUart1DataRdy= 1;									
				}
				else
				{
						Uart1Buff[Uart1BuffIndex++] = c;
				}
    }
}


extern unsigned char Uart2Buff[3];
extern unsigned char Uart2BuffIndex;
extern int iUart2DataRdy;
void USART2_IRQHandler(void)
{
    char c;
    if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE)==SET)
    {
				c = USART_ReceiveData(USART2);
				if(Uart2BuffIndex == 3)
				{
						iUart2DataRdy= 1;	
				}
				else
				{
						Uart2Buff[Uart2BuffIndex++] = c;
				}
    }
}

extern unsigned char Uart3Buff[3];
extern unsigned char Uart3BuffIndex;
extern int iUart3DataRdy;
void USART3_IRQHandler(void)
{
    char c;
    if(USART_GetFlagStatus(USART3,USART_FLAG_RXNE)==SET)
    {
				c = USART_ReceiveData(USART3);
				if(Uart3BuffIndex == 3)
				{
							iUart3DataRdy =1;
				}
				else
				{
						Uart3Buff[Uart3BuffIndex++] = c;
				}
    }
}



extern unsigned char Uart4Buff[3];
extern unsigned char Uart4BuffIndex;
extern int iUart4DataRdy;
void UART4_IRQHandler(void)
{
    char c;
    if(USART_GetFlagStatus(UART4,USART_FLAG_RXNE)==SET)
    {
        c = USART_ReceiveData(UART4);
				if(Uart4BuffIndex == 3)
				{
							iUart4DataRdy =1;
				}
				else
				{
						Uart4Buff[Uart4BuffIndex++] = c;
				}
    }
}

void UART5_IRQHandler(void)
{
    char c;
    if(USART_GetFlagStatus(UART5,USART_FLAG_RXNE)==SET)
    {
        c = USART_ReceiveData(UART5);
				USART_SendData(UART5,0x05);
				while (USART_GetFlagStatus(UART5, USART_FLAG_TXE) == RESET);			
        USART_SendData(UART5,c);
				while (USART_GetFlagStatus(UART5, USART_FLAG_TXE) == RESET);						
    }
}

void USART6_IRQHandler(void)
{
    char c;
    if(USART_GetFlagStatus(USART6,USART_FLAG_RXNE)==SET)
    {
				c = USART_ReceiveData(USART6);
				USART_SendData(USART6,0x06);
				while (USART_GetFlagStatus(USART6, USART_FLAG_TXE) == RESET);			
				USART_SendData(USART6,c);
				while (USART_GetFlagStatus(USART6, USART_FLAG_TXE) == RESET);
    }
}








/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
