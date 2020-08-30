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

u32 Sec = 1000000;
void Besho(void);

void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);

	MSTK_voidInit();




		/* Pin Mode */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);		/* A0 Output pp 2MHz */
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);

	//MSTK_voidSetIntervalPeriodic(5*Sec, Besho);

	while(1)
	{
		//MGPIO_voidSetPinValue(GPIOA,PIN0, GPIO_HIGH);
		/* 1000000 = 1 Sec */
		//MSTK_voidSetIntervalSingle(Sec, Besho);
		/*
		MSTK_voidSetBusyWait(5*Sec);
		MGPIO_voidSetPinValue(GPIOA,PIN0, GPIO_LOW);
		MSTK_voidSetBusyWait(Sec);
		*/
		Besho();
	}

}


void Besho(void)
{
	MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
	MSTK_voidSetBusyWait(Sec);
	MGPIO_voidSetPinValue(GPIOA,PIN1, GPIO_LOW);
	MSTK_voidSetBusyWait(Sec);
}

/*
void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,0, GPIO_HIGH);
}

void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,1, GPIO_HIGH);
}
*/
