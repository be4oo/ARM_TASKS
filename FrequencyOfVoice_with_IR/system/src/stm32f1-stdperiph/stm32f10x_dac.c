/**
 ******************************************************************************
 * @file    stm32f10x_dac.c
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    11-March-2011
 * @brief   This file provides all the DAC firmware functions.
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_dac.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup DAC 
  * @brief DAC driver modules
  * @{
  */ 

/** @defgroup DAC_Private_TypesDefinitions
  * @{
  */

typedef struct
{
  uint32_t DAC_Trigger;          /*!< Specifies the DAC trigger.
                                       This parameter can be a value of @ref DAC_Trigger */

  uint32_t DAC_WaveGeneration;   /*!< Specifies the DAC wave generation.
                                       This parameter can be a value of @ref DAC_WaveGeneration */

  uint32_t DAC_LFSRUnmask_TriangleAmplitude; /*!< Specifies the DAC LFSR unmask and triangle amplitude.
                                                 This parameter can be a value of @ref DAC_LFSRUnmask_TriangleAmplitude */

  uint32_t DAC_OutputBuffer;     /*!< Specifies the DAC output buffer state.
                                       This parameter can be a value of @ref DAC_OutputBuffer */
} DAC_InitTypeDef;

/**
  * @}
  */

/** @defgroup DAC_Private_Defines
  * @{
  */

/* CR register Mask */
#define CR_CLEAR_MASK              ((uint32_t)0x00000FFE)

/* DAC Dual Channels SWTRIG masks */
#define DUAL_SWTRIG_SET            ((uint32_t)0x00000003)
#define DUAL_SWTRIG_RESET          ((uint32_t)0xFFFFFFFC)

/* DHR registers offsets */
#define DHR12R1_OFFSET             ((uint32_t)0x00000008)
#define DHR12R2_OFFSET             ((uint32_t)0x00000014)
#define DHR12RD_OFFSET             ((uint32_t)0x00000020)

/* DOR register offset */
#define DOR_OFFSET                 ((uint32_t)0x0000002C)

/**
  * @}
  */

/** @defgroup DAC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup DAC_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup DAC_Private_FunctionPrototypes
  * @{
  */

static void DAC_ChannelxConfig(uint32_t DAC_Channel, DAC_InitTypeDef* DAC_InitStruct);

/**
  * @}
  */

/** @defgroup DAC_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the DAC peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void DAC_DeInit(void)
{
  /* Enable DAC reset state */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, ENABLE);
  /* Release DAC from reset state */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, DISABLE);
}

/**
  * @brief  Initializes the DAC peripheral according to the specified 
  *         parameters in the DAC_InitStruct.
  * @param  DAC_Channel: the selected DAC channel. 
  *   This parameter can be one of the following values:
  *     @arg DAC_Channel_1: DAC Channel1 selected
  *     @arg DAC_Channel_2: DAC Channel2 selected
  * @param  DAC_InitStruct: pointer to a DAC_InitTypeDef structure that
  *        contains the configuration
