/**
 * @file    stm32f10x_iwdg.h
 * @author  MCD Application Team
 * @brief   This file provides the IWDG (Independent Watchdog) driver functions.
 */

#ifndef STM32F10X_IWDG_H
#define STM32F10X_IWDG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
 * @{
 */

/** @defgroup IWDG 
 * @brief IWDG driver modules
 * @{
 */

/** @defgroup IWDG_Exported_Types
 * @{
 */
typedef enum
{
  IWDG_WriteAccess_Enable = 0xAAAA,
  IWDG_WriteAccess_Disable = 0xCCCC
} IWDG_WriteAccess_t;

typedef enum
{
  IWDG_Prescaler_4 = 0x00,
  IWDG_Prescaler_8 = 0x01,
  IWDG_Prescaler_16 = 0x02,
  IWDG_Prescaler_32 = 0x03,
  IWDG_Prescaler_64 = 0x04,
  IWDG_Prescaler_128 = 0x05,
  IWDG_Prescaler_256 = 0x06
} IWDG_Prescaler_t;

typedef enum
{
  IWDG_FLAG_PVU = 0x0100,
  IWDG_FLAG_RVU = 0x0200
} IWDG_FLAG_t;

typedef enum
{
  RESET = 0,
  SET   = !RESET
} FlagStatus;

/**
 * @}
 */

/* IWDG driver functions -----------------------------------------------------*/
/**
 * @brief  Enables or disables write access to IWDG_PR and IWDG_RLR registers.
 * @param  IWDG_WriteAccess: new state of write access to IWDG_PR and IWDG_RLR registers.
 *   This parameter can be one of the following values:
 *     @arg IWDG_WriteAccess_Enable: Enable write access to IWDG_PR and IWDG_RLR registers
 *     @arg IWDG_WriteAccess_Disable: Disable write access to IWDG_PR and IWDG_RLR registers
 * @retval None
 */
void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess);

/**
 * @brief  Sets IWDG Prescaler value.
 * @param  IWDG_Prescaler: specifies the IWDG Prescaler value.
 *   This parameter can be one of the following values:
 *     @arg IWDG_Prescaler_4: IWDG prescaler set to 4
 *     @arg IWDG_Prescaler_8: IWDG prescaler set to 8
 *     @arg IWDG_Prescaler_16: IWDG prescaler set to 16
 *     @arg IWDG_Prescaler_32: IWDG prescaler set to 32
 *     @arg IWDG_Prescaler_64: IWDG prescaler set to 64
 *     @arg IWDG_Prescaler_128: IWDG prescaler set to 128
 *     @arg IWDG_Prescaler_256: IWDG prescaler set to 256
 * @retval None
 */
void IWDG_SetPrescaler(IWDG_Prescaler_t IWDG_Prescaler);

/**
 * @brief  Sets IWDG Reload value.
 * @param  Reload: specifies the IWDG Reload value.
 *   This parameter must be a number between 0 and 0x0FFF.
 * @retval None
 */
void IWDG_SetReload(uint16_t Reload);

/**
 * @brief  Reloads IWDG counter with value defined in the reload register
 *   (write access to IWDG_PR and IWDG_RLR registers disabled).
 * @param  None
 * @retval None
 */
void IWDG_ReloadCounter(void);

/**
 * @brief  Enables IWDG (write access to IWDG_PR and IWDG_RLR registers disabled).
 * @param  None
 * @retval None
 */
void IWDG_Enable(void);

/**
 * @brief  Checks whether the specified IWDG flag is set or not.
 * @param  IWDG_FLAG: specifies the flag to check.
 *   This parameter can be one of the following values:
 *     @arg IWDG_FLAG_PVU: Prescaler Value Update on going
 *     @arg IWDG_FLAG_RVU: Reload Value Update on going
 * @retval The new state of IWDG_FLAG (SET or RESET).
 */
FlagStatus IWDG_GetFlagStatus(IWDG_FLAG_t IWDG_FLAG);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* STM32F10X_IWDG_H */

/**
 * @file    stm32f10x_iwdg.c
 * @author  MCD Application Team
 * @brief   This file provides all the IWDG firmware functions.

