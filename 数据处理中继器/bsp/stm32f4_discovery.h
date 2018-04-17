/**
  ******************************************************************************
  * @file    stm32f4_discovery.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    28-October-2011
  * @brief   This file contains definitions for STM32F4-Discovery Kit's Leds and 
  *          push-button hardware resources.
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4_DISCOVERY_H
#define __STM32F4_DISCOVERY_H

#ifdef __cplusplus
 extern "C" {
#endif
                                              
/* Includes ------------------------------------------------------------------*/
 #include "stm32f4xx.h"
 #include <stdio.h>
 #include <string.h>
/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32F4_DISCOVERY
  * @{
  */
      
/** @addtogroup STM32F4_DISCOVERY_LOW_LEVEL
  * @{
  */ 

/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Exported_Types
  * @{
  */
typedef enum 
{
  LED4 = 0,
  LED3 = 1,
  LED5 = 2,
  LED6 = 3
} Led_TypeDef;

typedef enum 
{  
  BUTTON_USER = 0,
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;     
/**
  * @}
  */ 

/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** @addtogroup STM32F4_DISCOVERY_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             4

#define LED4_PIN                         GPIO_Pin_12
#define LED4_GPIO_PORT                   GPIOD
#define LED4_GPIO_CLK                    RCC_AHB1Periph_GPIOD  
  
#define LED3_PIN                         GPIO_Pin_13
#define LED3_GPIO_PORT                   GPIOD
#define LED3_GPIO_CLK                    RCC_AHB1Periph_GPIOD  
  
#define LED5_PIN                         GPIO_Pin_14
#define LED5_GPIO_PORT                   GPIOD
#define LED5_GPIO_CLK                    RCC_AHB1Periph_GPIOD  
  
#define LED6_PIN                         GPIO_Pin_15
#define LED6_GPIO_PORT                   GPIOD
#define LED6_GPIO_CLK                    RCC_AHB1Periph_GPIOD
/**
  * @}
  */ 
  
/** @addtogroup STM32F4_DISCOVERY_LOW_LEVEL_BUTTON
  * @{
  */  
#define BUTTONn                          1  

/**
 * @brief Wakeup push-button
 */
#define USER_BUTTON_PIN                GPIO_Pin_0
#define USER_BUTTON_GPIO_PORT          GPIOA
#define USER_BUTTON_GPIO_CLK           RCC_AHB1Periph_GPIOA
#define USER_BUTTON_EXTI_LINE          EXTI_Line0
#define USER_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOA
#define USER_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource0
#define USER_BUTTON_EXTI_IRQn          EXTI0_IRQn 
/**
  * @}
  */ 

#define UARTn                          	6 
#define S_Port_USART1                		USART1
#define S_Port_USART1_CLK           		RCC_APB2Periph_USART1
#define S_Port_USART1_TX_PIN        		GPIO_Pin_6
#define S_Port_USART1_TX_GPIO_PORT     	GPIOB
#define S_Port_USART1_TX_GPIO_CLK       RCC_AHB1Periph_GPIOB
#define S_Port_USART1_TX_SOURCE         GPIO_PinSource6
#define S_Port_USART1_RX_PIN            GPIO_Pin_7
#define S_Port_USART1_RX_GPIO_PORT      GPIOB
#define S_Port_USART1_RX_GPIO_CLK       RCC_AHB1Periph_GPIOB
#define S_Port_USART1_RX_SOURCE         GPIO_PinSource7
#define S_Port_USART1_AF                GPIO_AF_USART1
#define S_Port_USART1_IRQn              USART1_IRQn

/** USART2 **/
#define S_Port_USART2                   USART2
#define S_Port_USART2_CLK               RCC_APB1Periph_USART2
#define S_Port_USART2_TX_PIN            GPIO_Pin_2
#define S_Port_USART2_TX_GPIO_PORT      GPIOA
#define S_Port_USART2_TX_GPIO_CLK       RCC_AHB1Periph_GPIOA
#define S_Port_USART2_TX_SOURCE         GPIO_PinSource2
#define S_Port_USART2_RX_PIN            GPIO_Pin_3
#define S_Port_USART2_RX_GPIO_PORT      GPIOA
#define S_Port_USART2_RX_GPIO_CLK       RCC_AHB1Periph_GPIOA
#define S_Port_USART2_RX_SOURCE         GPIO_PinSource3
#define S_Port_USART2_AF                GPIO_AF_USART2
#define S_Port_USART2_IRQn              USART2_IRQn

/** USART3 **/
#define S_Port_USART3                   USART3
#define S_Port_USART3_CLK               RCC_APB1Periph_USART3
#define S_Port_USART3_TX_PIN            GPIO_Pin_10
#define S_Port_USART3_TX_GPIO_PORT      GPIOB
#define S_Port_USART3_TX_GPIO_CLK       RCC_AHB1Periph_GPIOB
#define S_Port_USART3_TX_SOURCE         GPIO_PinSource10
#define S_Port_USART3_RX_PIN            GPIO_Pin_11
#define S_Port_USART3_RX_GPIO_PORT      GPIOB
#define S_Port_USART3_RX_GPIO_CLK       RCC_AHB1Periph_GPIOB
#define S_Port_USART3_RX_SOURCE         GPIO_PinSource11
#define S_Port_USART3_AF                GPIO_AF_USART3
#define S_Port_USART3_IRQn              USART3_IRQn

/** UART4 **/
#define S_Port_UART4                    UART4
#define S_Port_UART4_CLK                RCC_APB1Periph_UART4
#define S_Port_UART4_TX_PIN             GPIO_Pin_10
#define S_Port_UART4_TX_GPIO_PORT       GPIOC
#define S_Port_UART4_TX_GPIO_CLK        RCC_AHB1Periph_GPIOC
#define S_Port_UART4_TX_SOURCE          GPIO_PinSource10
#define S_Port_UART4_RX_PIN             GPIO_Pin_11
#define S_Port_UART4_RX_GPIO_PORT       GPIOC
#define S_Port_UART4_RX_GPIO_CLK        RCC_AHB1Periph_GPIOC
#define S_Port_UART4_RX_SOURCE          GPIO_PinSource11
#define S_Port_UART4_AF                 GPIO_AF_UART4
#define S_Port_UART4_IRQn               UART4_IRQn

/** UART5 **/
#define S_Port_UART5                    UART5
#define S_Port_UART5_CLK                RCC_APB1Periph_UART5
#define S_Port_UART5_TX_PIN             GPIO_Pin_12
#define S_Port_UART5_TX_GPIO_PORT       GPIOC
#define S_Port_UART5_TX_GPIO_CLK        RCC_AHB1Periph_GPIOC
#define S_Port_UART5_TX_SOURCE          GPIO_PinSource12
#define S_Port_UART5_RX_PIN             GPIO_Pin_2
#define S_Port_UART5_RX_GPIO_PORT       GPIOD
#define S_Port_UART5_RX_GPIO_CLK        RCC_AHB1Periph_GPIOD
#define S_Port_UART5_RX_SOURCE          GPIO_PinSource2
#define S_Port_UART5_AF                 GPIO_AF_UART5
#define S_Port_UART5_IRQn               UART5_IRQn

/** USART6 **/
#define S_Port_USART6                   USART6
#define S_Port_USART6_CLK               RCC_APB2Periph_USART6
#define S_Port_USART6_TX_PIN            GPIO_Pin_6
#define S_Port_USART6_TX_GPIO_PORT      GPIOC
#define S_Port_USART6_TX_GPIO_CLK       RCC_AHB1Periph_GPIOC
#define S_Port_USART6_TX_SOURCE         GPIO_PinSource6
#define S_Port_USART6_RX_PIN            GPIO_Pin_7
#define S_Port_USART6_RX_GPIO_PORT      GPIOC
#define S_Port_USART6_RX_GPIO_CLK       RCC_AHB1Periph_GPIOC
#define S_Port_USART6_RX_SOURCE         GPIO_PinSource7
#define S_Port_USART6_AF                GPIO_AF_USART6
#define S_Port_USART6_IRQn              USART6_IRQn


typedef enum
{
	usart1 = 0,
	usart2 = 1,
	usart3 = 2,
	uart4  = 3,
	uart5  = 4,
	usart6  = 5
}usart_TypeDef;


/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Exported_Macros
  * @{
  */  
/**
  * @}
  */ 


/** @defgroup STM32F4_DISCOVERY_LOW_LEVEL_Exported_Functions
  * @{
  */
void STM_EVAL_LEDInit(Led_TypeDef Led);
void STM_EVAL_LEDOn(Led_TypeDef Led);
void STM_EVAL_LEDOff(Led_TypeDef Led);
void STM_EVAL_LEDToggle(Led_TypeDef Led);
void STM_EVAL_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t STM_EVAL_PBGetState(Button_TypeDef Button);
void USART_Cfg(void);
/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_DISCOVERY_H */
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
