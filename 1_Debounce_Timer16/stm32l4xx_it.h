/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l4xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L4xx_IT_H
#define __STM32L4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI0_IRQHandler(void);
void TIM1_UP_TIM16_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);
/* USER CODE BEGIN EFP */
/*
* Notes		Frequency(Hz)			Cycle/Period				ARR value
*    C4				261					1M/261=3831				65535-261/2=65405
*    D4				293					1M/293=3412				65535-293/2=65389
*    E4				329					1M/329=3039				65535-329/2=65371
*    F4				349					1M/349=2865				65535-349/2=65361
*    G4				392					1M/392=2551				65535-392/2=65339
*    A4				440					1M/440=2272				65535-440/2=65315
*    B4				493					1M/493=2028				65535-493/2=65289
*    */
//int toneFreq[] = {65405, 65389, 65371, 65361, 65339, 65315, 65289};
extern int toneFreq[] = {130, 146, 164, 174, 196, 220, 246};	// APB1 Timer clocks frequency = 72M, prescale value of Timer6 is 71
extern int toneOn[] = {900, 800, 700, 600, 500, 400, 300};		// prescale value of Timer7 is 7199
extern int toneOff[] = {100, 200, 300, 400, 500, 600, 700};		// ARR = 9, 1 tick = 1 miliseconds

int msTone = 0;		// miliseconds

volatile bool flagOnOff = SET;
extern volatile bool flagDebounce = SET;
extern volatile int ticksDebounce = 0;

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L4xx_IT_H */
