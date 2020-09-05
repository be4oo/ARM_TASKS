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
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "OS_interface.h"



void LED1(void);
void LED2(void);
void LED3(void);


int main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);

	//MSTK_voidInit();

	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);

	SOS_voidCreateTask(0, 1000, LED1);
	SOS_voidCreateTask(1, 2000, LED2);
	SOS_voidCreateTask(2, 3000, LED3);

	SOS_voidStart();

	while(1)
	{

	}

	return 0;
}


void LED1(void)
{
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0,0);
	MGPIO_voidSetPinValue(GPIOA,PIN0,Local_u8Pin0);
}

void LED2(void)
{
	static u8 Local_u8Pin1 = 0;
	TOG_BIT(Local_u8Pin1,0);
	MGPIO_voidSetPinValue(GPIOA,PIN1,Local_u8Pin1);
}

void LED3(void)
{
	static u8 Local_u8Pin2 = 0;
	TOG_BIT(Local_u8Pin2,0);
	MGPIO_voidSetPinValue(GPIOA,PIN2,Local_u8Pin2);
}
