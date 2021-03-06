/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: besho
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "STK_interface.h"

#include "STP_interface.h"


u16 B[8] = {28, 36, 36, 28, 36, 36, 28, 0};

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
	/*
	u8 i = 0;
	HSTP_voidSendSynchronus(B[i], 2);
*/
	//HSTP_voidSendSynchronus(0xAA);

	while(1)
	{

		u8 Col = 1;
		//u8 x = 8;
		for(u8 i = 0 ; i > 16 ; i++)
		{
			u16 Local_u16Data = (~Col << 8) | B[i];
			HSTP_voidSendSynchronus(Local_u16Data, 2);
			MSTK_voidSetBusyWait(2500);
			Col = Col << 1;
		}
	}
}
