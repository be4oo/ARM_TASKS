/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 8 AGU 2020															*/
/********************************************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* REGISTER DEFINITION */

// 0x4002 1000

#define RCC_CR         *((u32*)0x40021000)
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)


/* DIO */ 
/* 	A 0x4001 0800
	B 0x4001 0C00
	C 0x4001 1000 */
#define GPIOA_CRL      *((u32*)0x40010800)
#define GPIOA_CRH      *((u32*)0x40010804)
#define GPIOA_IDR      *((u32*)0x40010808)
#define GPIOA_ODR      *((u32*)0x4001080C)

/* clock Types */
#define RCC_HSE_CRYSTAL		0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3


#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE			2


#endif
