/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define USB_DET_Pin GPIO_PIN_14
#define USB_DET_GPIO_Port GPIOC
#define USB_DET_EXTI_IRQn EXTI15_10_IRQn
#define IMU_PWR_Pin GPIO_PIN_15
#define IMU_PWR_GPIO_Port GPIOC
#define IrRx_Pin GPIO_PIN_0
#define IrRx_GPIO_Port GPIOA
#define BtnB_Pin GPIO_PIN_4
#define BtnB_GPIO_Port GPIOA
#define BtnC_Pin GPIO_PIN_5
#define BtnC_GPIO_Port GPIOA
#define BtnD_Pin GPIO_PIN_6
#define BtnD_GPIO_Port GPIOA
#define BtnE_Pin GPIO_PIN_7
#define BtnE_GPIO_Port GPIOA
#define IrTx_Pin GPIO_PIN_0
#define IrTx_GPIO_Port GPIOB
#define LedCh_Pin GPIO_PIN_1
#define LedCh_GPIO_Port GPIOB
#define LedCg_Pin GPIO_PIN_2
#define LedCg_GPIO_Port GPIOB
#define LedCf_Pin GPIO_PIN_10
#define LedCf_GPIO_Port GPIOB
#define LedCe_Pin GPIO_PIN_11
#define LedCe_GPIO_Port GPIOB
#define LedCd_Pin GPIO_PIN_12
#define LedCd_GPIO_Port GPIOB
#define LedCc_Pin GPIO_PIN_13
#define LedCc_GPIO_Port GPIOB
#define LedCb_Pin GPIO_PIN_14
#define LedCb_GPIO_Port GPIOB
#define LedCa_Pin GPIO_PIN_15
#define LedCa_GPIO_Port GPIOB
#define BtnF_Pin GPIO_PIN_8
#define BtnF_GPIO_Port GPIOA
#define BtnG_Pin GPIO_PIN_9
#define BtnG_GPIO_Port GPIOA
#define BtnH_Pin GPIO_PIN_10
#define BtnH_GPIO_Port GPIOA
#define UsbDm_Pin GPIO_PIN_11
#define UsbDm_GPIO_Port GPIOA
#define UsbDp_Pin GPIO_PIN_12
#define UsbDp_GPIO_Port GPIOA
#define BtnA_Pin GPIO_PIN_15
#define BtnA_GPIO_Port GPIOA
#define LedA0_Pin GPIO_PIN_3
#define LedA0_GPIO_Port GPIOB
#define LedA1_Pin GPIO_PIN_4
#define LedA1_GPIO_Port GPIOB
#define DEC_EN_Pin GPIO_PIN_5
#define DEC_EN_GPIO_Port GPIOB
#define LedA2_Pin GPIO_PIN_8
#define LedA2_GPIO_Port GPIOB
#define LedA3_Pin GPIO_PIN_9
#define LedA3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#ifndef DEC_EN_GPIO_Port
#define DEC_EN_GPIO_Port GPIOB
#endif

#undef LedA0_Pin
#undef LedA1_Pin
#undef DEC_EN_Pin

#if defined(V1_1)
#undef USB_DET_Pin
#undef USB_DET_GPIO_Port
#undef USB_DET_EXTI_IRQn
#define USB_DET_Pin GPIO_PIN_3
#define USB_DET_GPIO_Port GPIOB
#define USB_DET_EXTI_IRQn EXTI3_IRQn
#define LedA0_Pin GPIO_PIN_6
#define LedA1_Pin GPIO_PIN_7
#define DEC_EN_Pin GPIO_PIN_5
#elif defined(V2_0)
#define LedA0_Pin GPIO_PIN_3
#define LedA1_Pin GPIO_PIN_4
#define DEC_EN_Pin GPIO_PIN_5
#elif defined(V2_1) || defined(V2_2)
#define LedA0_Pin GPIO_PIN_3
#define LedA1_Pin GPIO_PIN_5
#define DEC_EN_Pin GPIO_PIN_4
#endif
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
