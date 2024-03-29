/**
 * @file    stm32f10x_sdio.c
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    11-March-2011
 * @brief   This file provides all the SDIO firmware functions.
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_sdio.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
 * @{
 */

/** @defgroup SDIO 
 * @brief SDIO driver modules
 * @{
 */ 

/** @defgroup SDIO_Private_TypesDefinitions
 * @{
 */ 

/* ------------ SDIO registers bit address in the alias region ----------- */
#define SDIO_OFFSET                (SDIO_BASE - PERIPH_BASE)

/* --- CLKCR Register ---*/

/* Alias word address of CLKEN bit */
#define CLKCR_OFFSET              (SDIO_OFFSET + 0x04)
#define CLKEN_BitNumber           0x08
#define CLKCR_CLKEN_BB            (PERIPH_BB_BASE + (CLKCR_OFFSET * 32) + (CLKEN_BitNumber * 4))

/* --- CMD Register ---*/

/* Alias word address of SDIOSUSPEND bit */
#define CMD_OFFSET                (SDIO_OFFSET + 0x0C)
#define SDIOSUSPEND_BitNumber     0x0B
#define CMD_SDIOSUSPEND_BB        (PERIPH_BB_BASE + (CMD_OFFSET * 32) + (SDIOSUSPEND_BitNumber * 4))

/* Alias word address of ENCMDCOMPL bit */
#define ENCMDCOMPL_BitNumber      0x0C
#define CMD_ENCMDCOMPL_BB         (PERIPH_BB_BASE + (CMD_OFFSET * 32) + (ENCMDCOMPL_BitNumber * 4))

/* Alias word address of NIEN bit */
#define NIEN_BitNumber            0x0D
#define CMD_NIEN_BB               (PERIPH_BB_BASE + (CMD_OFFSET * 32) + (NIEN_BitNumber * 4))

/* Alias word address of ATACMD bit */
#define ATACMD_BitNumber          0x0E
#define CMD_ATACMD_BB             (PERIPH_BB_BASE + (CMD_OFFSET * 32) + (ATACMD_BitNumber * 4))

/* --- DCTRL Register ---*/

/* Alias word address of DMAEN bit */
#define DCTRL_OFFSET              (SDIO_OFFSET + 0x2C)
#define DMAEN_BitNumber           0x03
#define DCTRL_DMAEN_BB            (PERIPH_BB_BASE + (DCTRL_OFFSET * 32) + (DMAEN_BitNumber * 4))

/* Alias word address of RWSTART bit */
#define RWSTART_BitNumber         0x08
#define DCTRL_RWSTART_BB          (PERIPH_BB_BASE + (DCTRL_OFFSET * 32) + (RWSTART_BitNumber * 4))

/* Alias word address of RWSTOP bit */
#define RWSTOP_BitNumber          0x09
#define DCTRL_RWSTOP_BB           (PERIPH_BB_BASE + (DCTRL_OFFSET * 32) + (RWSTOP_BitNumber * 4))

/* Alias word address of RWMOD bit */
#define RWMOD_BitNumber           0x0A
#define DCTRL_RWMOD_BB            (PERIPH_BB_BASE + (DCTRL_OFFSET * 32) + (RWMOD_BitNumber * 4))

/* Alias word address of SDIOEN bit */
#define SDIOEN_BitNumber          0x0B
#define DCTRL_SDIOEN_BB           (PERIPH_BB_BASE + (DCTRL_OFFSET * 32) + (SDIOEN_BitNumber * 4))

/* ---------------------- SDIO registers bit mask ------------------------ */

/* --- CLKCR Register ---*/

/* CLKCR register clear mask */
#define CLKCR_CLEAR_MASK         ((uint32_t)0xFFFF8100) 

/* --- PWRCTRL Register ---*/

/* SDIO PWRCTRL Mask */
#define PWR_PWRCTRL_MASK         ((uint32_t)0xFFFFFFFC)

/* --- DCTRL Register ---*/

/* SDIO DCTRL Clear Mask */
#define DCTRL_CLEAR_MASK         ((uint32_t)0xFFFFFF08)

/* --- CMD Register ---*/

/* CMD Register clear mask */
#define CMD_CLEAR_MASK           ((uint32_t)0xFFFFF800)

/* SDIO RESP Registers Address */
#define SDIO_RESP_ADDR           ((uint32_t)(SDIO_BASE + 0x14))

/**
 * @}
 */

/** @defgroup SDIO_Private_Defines
 * @{
 */

/**
 * @}
 */

/** @defgroup SDIO_Private_Macros
 * @{
 */

/**
 * @}
 */

/** @defgroup SDIO_Private_Variables
 * @{
 */

/**
 * @}
 */

/** @defgroup SDIO
