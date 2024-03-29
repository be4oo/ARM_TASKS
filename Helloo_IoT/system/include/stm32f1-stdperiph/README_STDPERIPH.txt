/**
 * @file stm32f10x_gpio.h
 * @author Company Name
 * @date Date of creation
 * @brief This file contains the GPIO driver functions and definitions for the STM32F10x microcontroller.
 *
 * The GPIO driver provides functions for configuring and controlling the General Purpose Input/Output (GPIO)
 * ports on the STM32F10x microcontroller. The GPIO ports can be used for a variety of purposes, including
 * digital input and output, alternate functions, and open-drain output.
 *
 * This header file contains the function prototypes, macros, and data structures for the GPIO driver.
 * It also includes any necessary include files and defines any required configuration constants.
 */

#ifndef STM32F10X_GPIO_H
#define STM32F10X_GPIO_H

#include "stm32f10x.h"

/**
 * @defgroup GPIO_Defines GPIO Defines
 * @{
 */

/**
 * @def GPIO_Pin_0
 * @brief Macro for GPIO pin 0
 */
#define GPIO_Pin_0   ((uint16_t)0x0001) 

/**
 * @def GPIO_Pin_1
 * @brief Macro for GPIO pin 1
 */
#define GPIO_Pin_1   ((uint16_t)0x0002) 

...

/**
 * @}
 */

/**
 * @defgroup GPIO_Types GPIO Types
 * @{
 */

/**
 * @struct GPIOPinMode
 * @brief Data structure for GPIO pin mode
 */
typedef struct {
  uint16_t Pin;   /*!< Specifies the GPIO pins to be configured.
                      This parameter can be any combination of @
