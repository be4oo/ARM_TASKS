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
#include "file.h"

#include "DIO_private.h"

volatile u32 i = 0;

void voidSetDAC(void)
{
	GPIOA_ODR = faded_raw[i];
	i++;

	if(i == 30743)
	{
		i = 0;
	}

}



void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);



	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);


}
