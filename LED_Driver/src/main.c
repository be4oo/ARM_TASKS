/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: besho
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "LED_interface.h"

int main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);

	RCC_voidEnableClock(RCC_APB2,3);

	RCC_voidEnableClock(RCC_APB2,4);

	while(1)
	{
		LED_voidTogle(GPIOB, PIN13);
	}

}
