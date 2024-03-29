/**
 * @file stm32f10x_gpio.h
 * @author STMicroelectronics
 * @version V3.5.0
 * @date 2013-02-26
 * @brief This file contains the header file for the STM32F10x GPIO driver.
 *
 * This file provides the definitions and prototypes for the GPIO driver functions,
 * which allow you to configure and control the General Purpose Input/Output (GPIO)
 * pins on the STM32F10x microcontroller.
 *
 * The GPIO pins can be configured for different modes, such as input, output,
 * alternate function, and analog. The output pins can also be configured for
 * push-pull or open-drain operation, and the input pins can be configured with
 * pull-up or pull-down resistors.
 *
 * The GPIO driver functions are provided in the `stm32f10x_gpio.c` file.
 */

/** @addtogroup STM32F10x_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO
 * @{
 */

/**
 * @brief GPIO pin number definitions.
 *
 * These definitions represent the different GPIO pins on the STM32F10x
 * microcontroller.
 */
typedef enum {
    GPIO_Pin_0 = 0x00000001,  /*!< Pin 0 */
    GPIO_Pin_1 = 0x00000002,  /*!< Pin 1 */
    GPIO_Pin_2 = 0x00000004,  /*!< Pin 2 */
    GPIO_Pin_3 = 0x000000
