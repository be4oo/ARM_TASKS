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

u32 Sec = 100000;
void PoolingL(void);
void PoolingR(void);

void VAnimationON(void);
void VAnimationOFF(void);

void OnAll(void);
void OffAll(void);

void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);

	MSTK_voidInit();


	while(1)
	{

		for(int x = 0 ; x < 2 ; x++)
		{
			PoolingL();

			PoolingR();
		}

		for(int y = 0 ; y < 4 ; y++)
		{
			VAnimationON();
			VAnimationOFF();
		}

		for(int z = 0 ; z < 4 ; z++)
		{
			OnAll();
			MSTK_voidSetBusyWait(Sec);
			OffAll();
			MSTK_voidSetBusyWait(Sec);
		}
	}

}


void PoolingL(void)
{
	LED_voidOn(GPIOA,PIN0);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN0);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN1);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN1);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN2);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN2);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN3);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN3);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN4);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN4);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN5);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN5);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN6);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN6);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN7);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN7);
	MSTK_voidSetBusyWait(Sec);

}

void PoolingR(void)
{
	LED_voidOn(GPIOA,PIN7);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN7);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN6);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN6);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN5);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN5);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN4);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN4);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN3);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN3);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN2);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN2);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN1);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN1);
	MSTK_voidSetBusyWait(Sec);

	LED_voidOn(GPIOA,PIN0);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN0);
	MSTK_voidSetBusyWait(Sec);

}

void VAnimationON(void)
{
	LED_voidOn(GPIOA,PIN3);
	LED_voidOn(GPIOA,PIN4);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOn(GPIOA,PIN2);
	LED_voidOn(GPIOA,PIN5);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOn(GPIOA,PIN1);
	LED_voidOn(GPIOA,PIN6);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOn(GPIOA,PIN0);
	LED_voidOn(GPIOA,PIN7);
	MSTK_voidSetBusyWait(Sec);
}
void VAnimationOFF(void)
{
	LED_voidOff(GPIOA,PIN0);
	LED_voidOff(GPIOA,PIN7);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN1);
	LED_voidOff(GPIOA,PIN6);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN2);
	LED_voidOff(GPIOA,PIN5);
	MSTK_voidSetBusyWait(Sec);
	LED_voidOff(GPIOA,PIN3);
	LED_voidOff(GPIOA,PIN4);
	MSTK_voidSetBusyWait(Sec);
}

void OnAll(void)
{
	LED_voidOn(GPIOA,PIN0);
	LED_voidOn(GPIOA,PIN1);
	LED_voidOn(GPIOA,PIN2);
	LED_voidOn(GPIOA,PIN3);
	LED_voidOn(GPIOA,PIN4);
	LED_voidOn(GPIOA,PIN5);
	LED_voidOn(GPIOA,PIN6);
	LED_voidOn(GPIOA,PIN7);

}

void OffAll(void)
{
	LED_voidOff(GPIOA,PIN0);
	LED_voidOff(GPIOA,PIN1);
	LED_voidOff(GPIOA,PIN2);
	LED_voidOff(GPIOA,PIN3);
	LED_voidOff(GPIOA,PIN4);
	LED_voidOff(GPIOA,PIN5);
	LED_voidOff(GPIOA,PIN6);
	LED_voidOff(GPIOA,PIN7);
}
