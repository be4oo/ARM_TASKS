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
#include "LEDMRX_interface.h"


volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

u8 Player[] = {0, 196, 43, 63, 43, 196, 0, 0};

u8 Ball[] = {0, 196, 43, 63, 43, 68, 128, 0};



void voidPlay(void)
{

	switch (u8Data)
	{
		/* BUTTON ON */
		case 69:
			HLEDMRX_voidDisplayOnce(Player, 0);
			break;
		/* BUTTON 2 */
		case 24:
			HLEDMRX_voidDisplayPlayer(Player, Ball);
			break;
		/* BUTTON 3 */
		case 94:

			break;
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
	MGPIO_voidSetPinDirection(GPIOA,PIN8,INPUT_FLOATING); /* B0 Input Floating        */


	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(); /* A8 EXTI9_5 Enabled / Falling Edge */

	//MEXTI_voidEnableEXTI(8);


	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(23); /* EXTI9_5 */

	MAFIO_voidSetEXTIConfiguration(0,0b0000);

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */


	HLEDMRX_voidInit();

	while(1)
		{



		}

}

