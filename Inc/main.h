/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "stm32f1xx_nucleo.h"

#include "stdio.h"
#include "string.h"


#define DEBUG_INIT(X) 					X


/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Private defines -----------------------------------------------------------*/
#define B1_Pin 							GPIO_PIN_13
#define B1_GPIO_Port 					GPIOC
#define B1_EXTI_IRQn 					EXTI15_10_IRQn
#define LD2_Pin 						GPIO_PIN_5
#define LD2_GPIO_Port 					GPIOA
#define TMS_Pin 						GPIO_PIN_13
#define TMS_GPIO_Port 					GPIOA
#define TCK_Pin 						GPIO_PIN_14
#define TCK_GPIO_Port					GPIOA
#define SWO_Pin 						GPIO_PIN_3
#define SWO_GPIO_Port 					GPIOB



#define LED1_PIN                         GPIO_PIN_5
#define LED1_GPIO_PORT                   GPIOA
#define LED2_PIN                         GPIO_PIN_9
#define LED2_GPIO_PORT                   GPIOC
#define LED3_PIN                         GPIO_PIN_8
#define LED3_GPIO_PORT                   GPIOC
#define LED4_PIN                         GPIO_PIN_5
#define LED4_GPIO_PORT                   GPIOC

//Relay control pins and ports
#define PA11_OUT0						GPIO_PIN_11
#define PA11_OUT0_PORT					GPIOA
#define PA12_OUT1						GPIO_PIN_12
#define PA12_OUT1_PORT					GPIOA
#define PA13_OUT2						GPIO_PIN_13
#define PA13_OUT2_PORT					GPIOA
#define PA14_OUT3						GPIO_PIN_14
#define PA14_OUT3_PORT					GPIOA
#define PA15_OUT4						GPIO_PIN_15
#define PA15_OUT4_PORT					GPIOA

#define PC10_OUT5						GPIO_PIN_10
#define PC10_OUT5_PORT					GPIOC
#define PC11_OUT6						GPIO_PIN_11
#define PC11_OUT6_PORT					GPIOC
#define PC12_OUT7						GPIO_PIN_12
#define PC12_OUT7_PORT					GPIOC

#define PB3_OUT8						GPIO_PIN_3
#define PB3_OUT8_PORT					GPIOB

#define PB4_OUT9						GPIO_PIN_4
#define PB4_OUT9_PORT					GPIOB



//LED output control signals
#define LED7_SDI						GPIO_PIN_2
#define LED7_SDI_PORT					GPIOC
#define LED7_SCK						GPIO_PIN_3
#define LED7_SCK_PORT					GPIOC
#define LED7_LE							GPIO_PIN_4
#define LED7_LE_PORT					GPIOC
#define LED7_OE							GPIO_PIN_5
#define LED7_OE_PORT					GPIOC

//BUZZER
#define PB5_BUZZER						GPIO_PIN_5
#define PB5_BUZZER_PORT					GPIOB


//3G control signals pins ports
#define PC7_3G_WAKEUP					GPIO_PIN_7
#define PC7_3G_WAKEUP_PORT				GPIOC
#define PC8_3G_PWRON					GPIO_PIN_8
#define PC8_3G_PWRON_PORT				GPIOC
#define PC9_3G_PERST					GPIO_PIN_9
#define PC9_3G_PERST_PORT				GPIOC
#define PA8_3G_REG_EN					GPIO_PIN_8
#define PA8_3G_REG_EN_PORT				GPIOA


//timer
#define TIMx                           TIM3
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM3_CLK_ENABLE()


/* Definition for TIMx's NVIC */
#define TIMx_IRQn                      TIM3_IRQn
#define TIMx_IRQHandler                TIM3_IRQHandler



/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define USART1_CLK_ENABLE()              __HAL_RCC_USART1_CLK_ENABLE();
#define DMA1_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()
#define USART1_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART1_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()

#define USART1_FORCE_RESET()             __HAL_RCC_USART1_FORCE_RESET()
#define USART1_RELEASE_RESET()           __HAL_RCC_USART1_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USART1_TX_PIN                    GPIO_PIN_9
#define USART1_TX_GPIO_PORT              GPIOA
#define USART1_RX_PIN                    GPIO_PIN_10
#define USART1_RX_GPIO_PORT              GPIOA




/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
/* Size of Trasmission buffer */
#define TXBUFFERSIZE                      (COUNTOF(aTxBuffer) - 1)
/* Size of Reception buffer */
#define RXBUFFERSIZE                      100



#define USART2_TX_PIN 					GPIO_PIN_2
#define USART2_TX_GPIO_PORT 				GPIOA
#define USART2_RX_PIN 					GPIO_PIN_3
#define USART2_RX_GPIO_PORT 				GPIOA

#define USART2_CLK_ENABLE()              __HAL_RCC_USART2_CLK_ENABLE();
#define DMA2_CLK_ENABLE()                __HAL_RCC_DMA2_CLK_ENABLE()
#define USART2_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART2_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()

#define USART2_FORCE_RESET()             __HAL_RCC_USART2_FORCE_RESET()
#define USART2_RELEASE_RESET()           __HAL_RCC_USART2_RELEASE_RESET()



#define		SAMPLE_STEPS							4
#define 	NUMBER_OF_SAMPLES_PER_AVERAGE			1 << SAMPLE_STEPS
#define 	NUMBER_OF_SAMPLES_PER_SECOND			100
#define 	NUMBER_OF_ADC_CHANNELS					14




//SPI2
#define MASTER_BOARD
#define SPI2_CLK_ENABLE()                __HAL_RCC_SPI2_CLK_ENABLE()
#define SPI2_SCK_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()
#define SPI2_MISO_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define SPI2_MOSI_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()

/* Definition for SPIx Pins */
#define SPI2_NSS_PIN                     GPIO_PIN_12
#define SPI2_NSS_GPIO_PORT               GPIOB

#define SPI2_SCK_PIN                     GPIO_PIN_13
#define SPI2_SCK_GPIO_PORT               GPIOB
#define SPI2_MISO_PIN                    GPIO_PIN_14
#define SPI2_MISO_GPIO_PORT              GPIOB
#define SPI2_MOSI_PIN                    GPIO_PIN_15
#define SPI2_MOSI_GPIO_PORT              GPIOB

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
