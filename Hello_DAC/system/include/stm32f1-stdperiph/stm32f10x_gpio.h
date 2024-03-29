/**
 * @file    stm32f10x_gpio.h
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    11-March-2011
 * @brief   This file contains all the functions prototypes for the GPIO firmware library.
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
 */

#ifndef __STM32F10x_GPIO_H
#define __STM32F10x_GPIO_H

#include "stm32f10x.h"
#include <stdint.h>

/** @addtogroup STM32F10x_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO
 * @{
 */

/** @defgroup GPIO_Exported_Types
 * @{
 */

#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                     ((PERIPH) == GPIOB) || \
                                     ((PERIPH) == GPIOC) || \
                                     ((PERIPH) == GPIOD) || \
                                     ((PERIPH) == GPIOE) || \
                                     ((PERIPH) == GPIOF) || \
                                     ((PERIPH) == GPIOG))
                                   const

/**
 * @brief  Output Maximum frequency selection
 */
typedef enum
{
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz,
  GPIO_Speed_50MHz
} GPIOSpeed_TypeDef;

static inline bool IS_GPIO_SPEED(GPIOSpeed_TypeDef SPEED)
{
  return (SPEED == GPIO_Speed_10MHz) || (SPEED == GPIO_Speed_2MHz) || (SPEED == GPIO_Speed_50MHz);
}

/**
 * @brief  Configuration Mode enumeration
 */
typedef enum
{
  GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 
