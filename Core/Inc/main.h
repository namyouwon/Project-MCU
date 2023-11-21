/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include "software_timer.h"
#include "display_7_seg.h"
#include "button.h"
#include "fsm.h"
#include "global.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_1_Pin GPIO_PIN_13
#define BUTTON_1_GPIO_Port GPIOC
#define BUTTON_2_Pin GPIO_PIN_14
#define BUTTON_2_GPIO_Port GPIOC
#define BUTTON_3_Pin GPIO_PIN_15
#define BUTTON_3_GPIO_Port GPIOC
#define EN_MODE_0_Pin GPIO_PIN_1
#define EN_MODE_0_GPIO_Port GPIOA
#define EN_MODE_1_Pin GPIO_PIN_2
#define EN_MODE_1_GPIO_Port GPIOA
#define EN_VALUE_0_Pin GPIO_PIN_3
#define EN_VALUE_0_GPIO_Port GPIOA
#define EN_VALUE_1_Pin GPIO_PIN_4
#define EN_VALUE_1_GPIO_Port GPIOA
#define RED_A_Pin GPIO_PIN_5
#define RED_A_GPIO_Port GPIOA
#define YELLOW_A_Pin GPIO_PIN_6
#define YELLOW_A_GPIO_Port GPIOA
#define GREEN_A_Pin GPIO_PIN_7
#define GREEN_A_GPIO_Port GPIOA
#define LED7A_0_Pin GPIO_PIN_0
#define LED7A_0_GPIO_Port GPIOB
#define LED7A_1_Pin GPIO_PIN_1
#define LED7A_1_GPIO_Port GPIOB
#define LED7A_2_Pin GPIO_PIN_2
#define LED7A_2_GPIO_Port GPIOB
#define LED7B_2_Pin GPIO_PIN_10
#define LED7B_2_GPIO_Port GPIOB
#define LED7B_3_Pin GPIO_PIN_11
#define LED7B_3_GPIO_Port GPIOB
#define LED7B_4_Pin GPIO_PIN_12
#define LED7B_4_GPIO_Port GPIOB
#define LED7B_5_Pin GPIO_PIN_13
#define LED7B_5_GPIO_Port GPIOB
#define LED7B_6_Pin GPIO_PIN_14
#define LED7B_6_GPIO_Port GPIOB
#define RED_B_Pin GPIO_PIN_9
#define RED_B_GPIO_Port GPIOA
#define YELLOW_B_Pin GPIO_PIN_10
#define YELLOW_B_GPIO_Port GPIOA
#define GREEN_B_Pin GPIO_PIN_11
#define GREEN_B_GPIO_Port GPIOA
#define LED7A_3_Pin GPIO_PIN_3
#define LED7A_3_GPIO_Port GPIOB
#define LED7A_4_Pin GPIO_PIN_4
#define LED7A_4_GPIO_Port GPIOB
#define LED7A_5_Pin GPIO_PIN_5
#define LED7A_5_GPIO_Port GPIOB
#define LED7A_6_Pin GPIO_PIN_6
#define LED7A_6_GPIO_Port GPIOB
#define LED7B_0_Pin GPIO_PIN_8
#define LED7B_0_GPIO_Port GPIOB
#define LED7B_1_Pin GPIO_PIN_9
#define LED7B_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
