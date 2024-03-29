/**
  ******************************************************************************
  * @file    system_stm32f10x.h
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer System Header File.
  ******************************************************************************
  * This file contains the system header file for the STM32F10x device, which
  * is part of the CMSIS (Cortex Microcontroller Software Interface Standard).
  * It includes the necessary definitions, macros, and function prototypes for
  * initializing and managing the system clock and other related system services.
  *
  * @attention
  * The present firmware is provided as a guidance only and STMicroelectronics
  * shall not be held liable for any direct, indirect or consequential damages
  * with respect to any claims arising from the content of such firmware and/or
  * the use made by customers of the coding information contained herein in
  * connection with their products.
  *
  * Copyright (c) 2011 STMicroelectronics
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f10x_system
  * @{
  */  
  
/**
  * @brief Define to prevent recursive inclusion
  */
// Prevents the header file from being included multiple times in the same source file,
// which can cause errors and unnecessary redefinition of symbols.
#ifndef __SYSTEM_STM32F10X_H
#define __SYSTEM_STM32F10X_H

#ifdef __cplusplus
 extern "C" {
#endif 

/** @addtogroup STM32F10x_System_Includes
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_types
  * @{
  */

// Defines a variable that holds the System Clock Frequency (Core Clock)
extern uint32_t SystemCoreClock;

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_Functions
  * @{
  */
  
// Initializes the system, including the clock system and other related services.
extern void SystemInit(void);

// Updates the value of the SystemCoreClock variable with the current core clock frequency.
extern void SystemCoreClockUpdate(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_STM32F10X_H */

/**
  * @}
  */

