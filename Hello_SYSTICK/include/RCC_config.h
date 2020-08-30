/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 8 AGU 2020															*/
/********************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* RCC_CR Selecting Clock 
#define HSION				1
#define HSITRIM				10000
#define HSEON				0
#define HSERDY				0
#define HSEBYP				0				// 1 For RC, 0 For Crystal
#define CSSON				0
#define PLLON				0

/* RCC_CFGR applying clock 
#define SW					00				// HSI selected as system clock
#define PLLSRC				0				// Internal clock become 4MHZ entering pll
#define PLLXTPRE			0
#define PLLMUL				0000
#define USBPRE				0
#define MCO					000	*/

/* RCC_CR Selecting Clock 
#define RCC_CR_HSION				0x00000001
#define RCC_CR_HSITRIM				0x00000010
#define RCC_CR_HSEON				0x00000000
#define RCC_CR_HSEBYP				0x00000000	// 1 For RC, 0 For Crystal
#define RCC_CR_CSSON				0x00000000
#define RCC_CR_PLLON				0x00000000
											 
/* RCC_CFGR applying clock               
#define RCC_CR_SW					0x00000000	// HSI selected as system clock
#define RCC_CR_PLLSRC				0x00000000	// Internal clock become 4MHZ entering pll
#define RCC_CR_PLLXTPRE				0x00000000
#define RCC_CR_PLLMUL				0x00000000
#define RCC_CR_USBPRE				0x00000000
#define RCC_CR_MCO					0x00000000*/

/* Options:
			RCC_HSE_CRYSTAL	
			RCC_HSE_RC		
			RCC_HSI	
			*/
#define RCC_CLOCK_TYPE		RCC_HSI

/* Options:
			 RCC_PLL_IN_HSI_DIV_2
			 RCC_PLL_IN_HSE_DIV_2
			 RCC_PLL_IN_HSE			
			 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT		RCC_PLL_IN_HSE_DIV_2
#endif

/* Options:
			2~16
			*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL		4
#endif



#endif