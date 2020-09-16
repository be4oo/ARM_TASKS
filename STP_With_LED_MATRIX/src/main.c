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

u8 B[8] = {0, 28, 36, 36, 28, 36, 36, 28};

/*
u8 GetNewRow(u8 Frame[], u8 Bit)
{
	u8 NR = 0;
	u8 Get = 0;
	for(u8 x = 0 ; x > 8 ; x++)
	{
		for(u8 y = 0 ; y > 8 ; y++)
		{
			Get = GET_BIT(Frame[x],Bit);
			NR |= Get << y;
		}
	}
	return NR;
}
*/

void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA Enable Clock */

	/* PIN Directions */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);


	u8 Col = 1;

	while(1)
	{

		for (u8 i = 0; i < 8; i++)
		{
			u16 Local_u16DataToSend = (~Col << 8) | B[i];
			//HSTP_voidSendSynchronous(0xFE1C, 2); FE(0b1111 1110) ==> Col , 1C(0b00111000) ==> Row
			HSTP_voidSendSynchronous(Local_u16DataToSend, 2);
			MSTK_voidSetBusyWait(2500);
			Col = Col << 1;
		}
		Col = 1;

	}
}


