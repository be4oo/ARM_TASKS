/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: besho
 */

/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 31 AUG 2020														*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"

u8 DataArray[8] = {0, 127, 73, 73, 54, 0, 0, 0};

void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
		/* Enable GPIOB */
	RCC_voidEnableClock(RCC_APB2,3);

	MSTK_voidInit();

	HLEDMRX_voidInit();

	HLEDMRX_voidDisplay(DataArray);




}
