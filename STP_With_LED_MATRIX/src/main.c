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

/* inverted "B" */
//u8 B[8] = {227, 219, 219, 227, 219, 219, 227, 255};
/* Normal "B" */
u8 B[8] = {28, 36, 36, 28, 36, 36, 28, 0};

void FixDraw(u8 *Frame);

/*
u8 Col[8] = {
		0b11111110,
		0b11111101,
		0b11111011,
		0b11110111,
		0b11101111,
		0b11011111,
		0b10111111,
		0b01111111
};*/
/*
u8 Col[8] = {
		0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b10000000
};*/

void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA Enable Clock */

	/* PIN Directions */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);



	HSTP_voidSendSynchronous(0x018F, 2);

	u8 Col = 1;

	FixDraw(&B);

	while(1)
	{
		for (u8 i = 0; i < 8; i++)
		{
			u16 Local_u16DataToSend = (Col<<8) | B[i];
			//HSTP_voidSendSynchronous(0xFE1C, 2); FE(0b1111 1110) ==> Col , 1C(0b00111000) ==> Row
			HSTP_voidSendSynchronous(Local_u16DataToSend, 2);
			MSTK_voidSetBusyWait(2500);
			Col = Col << 1;
		}
		Col = 1;
	}
}

void FixDraw(u8 *Frame)
{
	for (u8 j = 0; j < 8; j++)
	{
		*(Frame+j) = ~(*(Frame+j));
	}
}


