/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: besho
 */

/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01.1																*/
/* Date    : 31 AUG 2020														*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"


u8 DataArray1[ArraySize1] = {0, 0, 0, 0, 0, 0, 0, 127, 73, 73, 54, 0, 56, 84, 84, 72, 0, 8, 84, 84, 32, 0, 126, 16, 16, 112, 0, 48, 72, 72, 48, 0, 0, 0, 0, 0, 0, 0, 0};

u8 DataArray2[] = {0, 136, 87, 63, 87, 136, 64, 0};

void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
		/* Enable GPIOB */
	RCC_voidEnableClock(RCC_APB2,3);

	MSTK_voidInit();

	HLEDMRX_voidInit();

	//HLEDMRX_voidDisplay(DataArray2);

	HLEDMRX_voidDisplayScroll(DataArray1);




}
