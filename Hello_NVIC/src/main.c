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




void main(void)
{

	RCC_voidInitSysClock();
	/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);


	/* Pin Mode */
	MGPIO_voidSetPinDirection(GPIOA,0,OUTPUT_SPEED_2MHZ_PP);		/* A0 Output pp 2MHz */
	MGPIO_voidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);

	MNVIC_voidSetPriority(6,1,0);		/* EXTI 0 G1 S0 */
	MNVIC_voidSetPriority(7,0,3);		/* EXTI 1 G0 S3 */

	MNVIC_voidEnableInterrupt(6);		/*EXTI 0*/
	MNVIC_voidEnableInterrupt(7);		/*EXTI 1*/

	MNVIC_voidSetPendingFlag(6);
	while(1)
	{

	}

}

void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,0, GPIO_HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPIO_voidSetPinValue(GPIOA,1, GPIO_HIGH);
}

void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,2, GPIO_HIGH);
}

void EXTI2_IRQHandler(void)
{

}


