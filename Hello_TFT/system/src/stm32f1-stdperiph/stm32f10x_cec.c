/**
 * @file    stm32f10x_cec.c
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    11-March-2011
 * @brief   This file provides all the CEC firmware functions.
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_cec.h"
#include "stm32f10x_rcc.h"
#include "assert_param.h" // Added for assert_param macro

/** @addtogroup STM32F10x_StdPeriph_Driver
 * @{
 */

/** @defgroup CEC 
 * @brief CEC driver modules
 * @{
 */

/** @defgroup CEC_Private_TypesDefinitions
 * @{
 */

/**
 * @}
 */


/** @defgroup CEC_Private_Defines
 * @{
 */ 

/* ------------ CEC registers bit address in the alias region ----------- */
#define CEC_OFFSET                (CEC_BASE - PERIPH_BASE)

/* --- CFGR Register ---*/

/* Alias word address of PE bit */
#define CFGR_OFFSET                 (CEC_OFFSET + 0x00)
#define PE_BitNumber                0x00
#define CFGR_PE_BB                  (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (PE_BitNumber * 4))

/* Alias word address of IE bit */
#define IE_BitNumber                0x01
#define CFGR_IE_BB                  (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (IE_BitNumber * 4))

/* --- CSR Register ---*/

/* Alias word address of TSOM bit */
#define CSR_OFFSET                  (CEC_OFFSET + 0x10)
#define TSOM_BitNumber              0x00
#define CSR_TSOM_BB                 (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TSOM_BitNumber * 4))

/* Alias word address of TEOM bit */
#define TEOM_BitNumber              0x01
#define CSR_TEOM_BB                 (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TEOM_BitNumber * 4))
  
#define CFGR_CLEAR_Mask            (uint8_t)(0xF3)        /* CFGR register Mask */
#define FLAG_Mask                  ((uint32_t)0x00FFFFFF) /* CEC FLAG mask */
 
/**
 * @}
 */ 


/** @defgroup CEC_Private_Macros
 * @{
 */ 

/**
 * @}
 */ 


/** @defgroup CEC_Private_Variables
 * @{
 */ 

/**
 * @}
 */ 


/** @defgroup CEC_Private_FunctionPrototypes
 * @{
 */

/**
 * @}
 */ 


/** @defgroup CEC_Private_Functions
 * @{
 */ 

/**
 * @brief  Deinitializes the CEC peripheral registers to their default reset 
 *         values.
 * @param  None
 * @retval None
 */
void CEC_DeInit(void)
{
  /* Enable CEC reset state */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CEC, ENABLE);  
  /* Release CEC from reset state */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CEC, DISABLE); 
}


/**
 * @brief  Initializes the CEC peripheral according to the specified 
 *         parameters in the CEC\_InitStruct.
 * @param  CEC_InitStruct: pointer to an CEC\_InitTypeDef structure that
 *         contains the configuration information for the specified
 *         CEC peripheral.
 * @retval None
 */
void CEC_Init(CEC_InitTypeDef* CEC_InitStruct)
{
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_CEC_BIT_TIMING_ERROR_MODE(CEC_InitStruct->CEC_BitTimingMode)); 
  assert_param(IS_CEC_BIT_PERIOD_ERROR_MODE(CEC_InitStruct->CEC_BitPeriodMode));
     
  /*---------------------------- CEC CFGR Configuration -----------------*/
  /* Get the CEC CFGR value */
  tmpreg = CEC->CFGR;
  
  /* Clear BTEM and BPEM bits */
  tmpreg &= CFGR_CLEAR_Mask;
  
  /* Configure CEC: Bit
