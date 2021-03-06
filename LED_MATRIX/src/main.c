/*
 * main.c
 *
 *  Created on: ??�/??�/????
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

u8 DataArray2[] = {0, 196, 43, 63, 43, 196, 0, 0};

u8 DataArray3[] = {0, 196, 43, 63, 43, 68, 128, 0};


u8 DataArray4 = {0, 0, 0, 0, 0, 0, 0, 1};

void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
		/* Enable GPIOB */
	RCC_voidEnableClock(RCC_APB2,3);

	MSTK_voidInit();

	HLEDMRX_voidInit();

	HLEDMRX_voidDisplay(DataArray4);

	//HLEDMRX_voidDisplayPlayer(DataArray2, DataArray3);

	//HLEDMRX_voidDisplayScroll(DataArray1);




}
