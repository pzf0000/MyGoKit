/**
  ******************************************************************************
  * @file    stm32f4_discovery.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    28-October-2011
  * @brief   This file provides set of firmware functions to manage Leds and
  *          push-button available on STM32F4-Discovery Kit from STMicroelectronics.
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

/** @addtogroup Utilities
  * @{
  */ 

/** @addtogroup STM32F4_DISCOVERY
  * @{
  */   
    
/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL 
  * @brief This file provides set of firmware functions to manage Leds and push-button
  *        available on STM32F4-Discovery Kit from STMicroelectronics.
  * @{
  */ 

/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Private_Defines
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Private_Macros
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Private_Variables
  * @{
  */ 
GPIO_TypeDef* GPIO_PORT[LEDn] = {LED4_GPIO_PORT, LED3_GPIO_PORT, LED5_GPIO_PORT,
                                 LED6_GPIO_PORT};
const uint16_t GPIO_PIN[LEDn] = {LED4_PIN, LED3_PIN, LED5_PIN,
                                 LED6_PIN};
const uint32_t GPIO_CLK[LEDn] = {LED4_GPIO_CLK, LED3_GPIO_CLK, LED5_GPIO_CLK,
                                 LED6_GPIO_CLK};

GPIO_TypeDef* BUTTON_PORT[BUTTONn] = {USER_BUTTON_GPIO_PORT }; 

const uint16_t BUTTON_PIN[BUTTONn] = {USER_BUTTON_PIN }; 

const uint32_t BUTTON_CLK[BUTTONn] = {USER_BUTTON_GPIO_CLK };

const uint16_t BUTTON_EXTI_LINE[BUTTONn] = {USER_BUTTON_EXTI_LINE };

const uint8_t BUTTON_PORT_SOURCE[BUTTONn] = {USER_BUTTON_EXTI_PORT_SOURCE};
								 
const uint8_t BUTTON_PIN_SOURCE[BUTTONn] = {USER_BUTTON_EXTI_PIN_SOURCE }; 
const uint8_t BUTTON_IRQn[BUTTONn] = {USER_BUTTON_EXTI_IRQn };


//串口数组
USART_TypeDef *USART_x[] = { S_Port_USART1, S_Port_USART2, S_Port_USART3, S_Port_UART4, S_Port_UART5, S_Port_USART6};
//串口子优先级
int Priority_Val[]={1,2,3,4,5,6};
//串口GPIO
GPIO_TypeDef *USARTx_TX_GPIO_Port[] = { S_Port_USART1_TX_GPIO_PORT, 
																				S_Port_USART2_TX_GPIO_PORT, 
																				S_Port_USART3_TX_GPIO_PORT, 
																				S_Port_UART4_TX_GPIO_PORT, 
																				S_Port_UART5_TX_GPIO_PORT,
																				S_Port_USART6_TX_GPIO_PORT
																				 };

GPIO_TypeDef *USARTx_RX_GPIO_Port[] = { S_Port_USART1_RX_GPIO_PORT, 
																				S_Port_USART2_RX_GPIO_PORT, 
																				S_Port_USART3_RX_GPIO_PORT, 
																				S_Port_UART4_RX_GPIO_PORT, 
																				S_Port_UART5_RX_GPIO_PORT,
																				S_Port_USART6_RX_GPIO_PORT
																				 };

const uint32_t USARTx_TX_GPIO_CLK[] = { S_Port_USART1_TX_GPIO_CLK,
																				S_Port_USART2_TX_GPIO_CLK,
																				S_Port_USART3_TX_GPIO_CLK,
																				S_Port_UART4_TX_GPIO_CLK,
																				S_Port_UART5_TX_GPIO_CLK,
																				S_Port_USART6_TX_GPIO_CLK
																				 };

const uint32_t USARTx_RX_GPIO_CLK[] = { S_Port_USART1_RX_GPIO_CLK,
																				S_Port_USART2_RX_GPIO_CLK,
																				S_Port_USART3_RX_GPIO_CLK,
																				S_Port_UART4_RX_GPIO_CLK,
																				S_Port_UART5_RX_GPIO_CLK,
																				S_Port_USART6_RX_GPIO_CLK
																				 };

const uint32_t USARTx_Tx_Pin[] = { 	S_Port_USART1_TX_PIN, 
																		S_Port_USART2_TX_PIN,
																		S_Port_USART3_TX_PIN, 
																		S_Port_UART4_TX_PIN, 
																		S_Port_UART5_TX_PIN, 
																		S_Port_USART6_TX_PIN
																		 };

const uint32_t USARTx_Rx_Pin[] = { 	S_Port_USART1_RX_PIN, 
																		S_Port_USART2_RX_PIN,
																		S_Port_USART3_RX_PIN, 
																		S_Port_UART4_RX_PIN, 
																		S_Port_UART5_RX_PIN,
																		S_Port_USART6_RX_PIN

																		 };

const uint16_t USARTx_TX_SOURCE[] = { S_Port_USART1_TX_SOURCE,
																			S_Port_USART2_TX_SOURCE,
																			S_Port_USART3_TX_SOURCE,
																			S_Port_UART4_TX_SOURCE,
																			S_Port_UART5_TX_SOURCE,
																			S_Port_USART6_TX_SOURCE
																			 };

const uint16_t USARTx_RX_SOURCE[] = { S_Port_USART1_RX_SOURCE,
																			S_Port_USART2_RX_SOURCE,
																			S_Port_USART3_RX_SOURCE,
																			S_Port_UART4_RX_SOURCE,
																			S_Port_UART5_RX_SOURCE,
																			S_Port_USART6_RX_SOURCE

																			 };
//引脚复用
const uint8_t USARTx_AF[] = { S_Port_USART1_AF, 
															S_Port_USART2_AF, 
															S_Port_USART3_AF, 
															S_Port_UART4_AF, 
															S_Port_UART5_AF,
															S_Port_USART6_AF
															 };

//串口时钟
const uint32_t USARTx_CLK[] = { S_Port_USART1_CLK,	//APB2
																S_Port_USART2_CLK,	//APB1
																S_Port_USART3_CLK,
																S_Port_UART4_CLK,
																S_Port_UART5_CLK,
																S_Port_USART6_CLK
																};	//APB2
//串口中断向量
const uint8_t USARTx_IRQn[] = { S_Port_USART1_IRQn, 
																S_Port_USART2_IRQn, 
																S_Port_USART3_IRQn, 
																S_Port_UART4_IRQn, 
																S_Port_UART5_IRQn,
																S_Port_USART6_IRQn, 	
																};

																

NVIC_InitTypeDef   NVIC_InitStructure;

/**
  * @}
  */ 


/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Private_FunctionPrototypes
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Private_Functions
  * @{
  */ 

/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *     @arg LED4
  *     @arg LED3
  *     @arg LED5
  *     @arg LED6
  * @retval None
  */
void STM_EVAL_LEDInit(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Enable the GPIO_LED Clock */
  RCC_AHB1PeriphClockCmd(GPIO_CLK[Led], ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN[Led];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIO_PORT[Led], &GPIO_InitStructure);
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *     @arg LED4
  *     @arg LED3
  *     @arg LED5
  *     @arg LED6  
  * @retval None
  */
void STM_EVAL_LEDOn(Led_TypeDef Led)
{
  GPIO_PORT[Led]->BSRRL = GPIO_PIN[Led];
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *     @arg LED4
  *     @arg LED3
  *     @arg LED5
  *     @arg LED6 
  * @retval None
  */
void STM_EVAL_LEDOff(Led_TypeDef Led)
{
  GPIO_PORT[Led]->BSRRH = GPIO_PIN[Led];  
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *     @arg LED4
  *     @arg LED3
  *     @arg LED5
  *     @arg LED6  
  * @retval None
  */
void STM_EVAL_LEDToggle(Led_TypeDef Led)
{
  GPIO_PORT[Led]->ODR ^= GPIO_PIN[Led];
}

/**
  * @brief  Configures Button GPIO and EXTI Line.
  * @param  Button: Specifies the Button to be configured.
  *   This parameter should be: BUTTON_USER
  * @param  Button_Mode: Specifies Button mode.
  *   This parameter can be one of following parameters:   
  *     @arg BUTTON_MODE_GPIO: Button will be used as simple IO 
  *     @arg BUTTON_MODE_EXTI: Button will be connected to EXTI line with interrupt
  *                            generation capability  
  * @retval None
  */
void STM_EVAL_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the BUTTON Clock */
  RCC_AHB1PeriphClockCmd(BUTTON_CLK[Button], ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure Button pin as input */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = BUTTON_PIN[Button];
  GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStructure);

  if (Button_Mode == BUTTON_MODE_EXTI)
  {
    /* Connect Button EXTI Line to Button GPIO Pin */
    SYSCFG_EXTILineConfig(BUTTON_PORT_SOURCE[Button], BUTTON_PIN_SOURCE[Button]);

    /* Configure Button EXTI line */
    EXTI_InitStructure.EXTI_Line = BUTTON_EXTI_LINE[Button];
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set Button EXTI Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = BUTTON_IRQn[Button];
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure); 
  }
}

/**
  * @brief  Returns the selected Button state.
  * @param  Button: Specifies the Button to be checked.
  *   This parameter should be: BUTTON_USER  
  * @retval The Button GPIO pin value.
  */
uint32_t STM_EVAL_PBGetState(Button_TypeDef Button)
{
  return GPIO_ReadInputDataBit(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

/**
  * @}
  */ 

void USART_Configuration(usart_TypeDef usartx)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 
	
	//时钟配置
  RCC_AHB1PeriphClockCmd(USARTx_TX_GPIO_CLK[usartx] | USARTx_RX_GPIO_CLK[usartx], ENABLE);
	if(usartx == usart1|| usartx==usart6)	//usart1、usart6
	{
		RCC_APB2PeriphClockCmd(USARTx_CLK[usartx], ENABLE);
	}
	else
	{
		RCC_APB1PeriphClockCmd(USARTx_CLK[usartx], ENABLE);
	}
	//引脚复用配置
  GPIO_PinAFConfig(USARTx_TX_GPIO_Port[usartx], USARTx_TX_SOURCE[usartx], USARTx_AF[usartx]);
  GPIO_PinAFConfig(USARTx_RX_GPIO_Port[usartx], USARTx_RX_SOURCE[usartx], USARTx_AF[usartx]);

  //USARTx 端口配置
  GPIO_InitStructure.GPIO_Pin = USARTx_Tx_Pin[usartx];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(USARTx_TX_GPIO_Port[usartx], &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = USARTx_Rx_Pin[usartx];
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//接收引脚上拉，避免重复进入中断
  GPIO_Init(USARTx_RX_GPIO_Port[usartx], &GPIO_InitStructure);

	//USARTx 初始化配置
	USART_InitStructure.USART_BaudRate = 115200;
	
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART_x[usartx], &USART_InitStructure);
	
	//开启接收中断
  USART_ITConfig(USART_x[usartx],USART_IT_RXNE,ENABLE);
	
	//串口使能
  USART_Cmd(USART_x[usartx], ENABLE);
	USART_ClearFlag(USART_x[usartx], USART_FLAG_TC);
	//串口中断配置
}

void TIM3_Init(u16 arr,u16 psc) 
{  
	TIM_TimeBaseInitTypeDef 	TIM_TimeBaseInitStructure; 
 
	//使能TIM3时钟  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  
	//定时器分频
 	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  				
	//向上计数
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 
	//自动装载值
	TIM_TimeBaseInitStructure.TIM_Period = arr;  
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;    
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//初始化TIM3
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
}

void TIM3_Start(void)
{
	TIM_Cmd(TIM3,ENABLE); //使能定时器
}



void NVIC_SysInit(void)
{
	int i;
	NVIC_InitTypeDef NVIC_InitStructure;    
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);						//设置系统中断有限级分组0
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; 						//定时器中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; 	//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=10; 				//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
	NVIC_Init(&NVIC_InitStructure);  

	
	for(i=0;i<6;i++)
	{
		NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn[i];
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = Priority_Val[i];
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	}
}

void USART_Cfg(void)
{
	USART_Configuration(usart1);
	USART_Configuration(usart2);
	USART_Configuration(usart3);
	USART_Configuration(uart4);
	USART_Configuration(uart5);
	USART_Configuration(usart6);
	TIM3_Init(1000-1,8400-1);	//100ms定时中断
	NVIC_SysInit();
	TIM3_Start();
}

int fputc(int ch, FILE *f)
{
  /* e.g. write a character to the USART */
  USART_SendData(USART6, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET)
  {}

  return ch;
}

/**
  * @}
  */ 

/**
  * @}
  */   

/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
