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
#include "STK_interface.h"

#include "STP_interface.h"


void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA Enable Clock */

	/* PIN Directions */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();

	//HSTP_voidSendSynchronus(0xAA);
	u8 i;
	while(1)
	{

		for(i = 0 ; i < 8 ; i++)
		{
			HSTP_voidSendSynchronus(1<<i);
			MSTK_voidSetBusyWait(300000);
		}
	}
}
