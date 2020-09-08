/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "STK_interface.h"


volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

u32 Sec = 100000;
void PoolingL(void);
void PoolingR(void);

void VAnimationON(void);
void VAnimationOFF(void);

void OnAll(void);
void OffAll(void);



void voidPlay(void)
{
	//MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);
	//VAnimationON();
	switch (u8Data)
	{
		//case 70: MGPIO_voidSetPinValue(GPIOA,3,GPIO_HIGH); break;
		/* BUTTON 0 */
		//case 22: MGPIO_voidSetPinValue(GPIOA,2,GPIO_HIGH); break;

		/* BUTTON 1 */
		case 12:

			for(int x = 0 ; x < 2 ; x++)
			{
				PoolingL();
				PoolingR();
			}break;
		/* BUTTON 2 */
		case 24:

			for(int y = 0 ; y < 4 ; y++)
			{
				VAnimationON();
				VAnimationOFF();
			}break;
		/* BUTTON 3 */
		case 94:

			for(int z = 0 ; z < 4 ; z++)
			{
				OnAll();
				MSTK_voidSetBusyWait(Sec);
				OffAll();
				MSTK_voidSetBusyWait(Sec);
			}break;
	}
}

void voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		voidPlay();
	}

	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}
}


void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA Enable Clock */
	RCC_voidEnableClock(RCC_APB2,3); /* GPIOB Enable Clock */

	/* Enable AFIO */
	RCC_voidEnableClock(RCC_APB2,0);

	/* IO Pins Initialization */
	MGPIO_voidSetPinDirection(GPIOB,PIN0,INPUT_FLOATING); /* B0 Input Floating        */


	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(); /* A8 EXTI0 Enabled / Falling Edge */
	//MEXTI_voidEnableEXTI(8);


	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI9_5 */

	MAFIO_voidSetEXTIConfiguration(0,0b0001);

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */
	while(1)
		{



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
