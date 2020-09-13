/*
 * main.c
 *
 *  Created on: 12 sep 2020
 *      Author: besho
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "AFIO_interface.h"
#include "file.h"


#include "DIO_private.h"

volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

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

void voidPlay(void)
{
	//MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);
	switch (u8Data)
	{
		/* BUTTON MODE */
		//case 70: MSTK_voidSetIntervalPeriodic(125,voidSetDACHello); break;
		/* BUTTON 0 *//*
		case 22:	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);
					break;*/
		/* BUTTON 1 */
		case 12:	MSTK_voidSetIntervalPeriodic(150,voidSetDAC);
					break;
		/* BUTTON 2 */
		case 24:	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);
					break;
		/* BUTTON 3 */
		case 94:	MSTK_voidSetIntervalPeriodic(115,voidSetDAC);
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
	MGPIO_voidSetPinDirection(GPIOB,PIN0,INPUT_FLOATING); /* B0 Input Floating        */

	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);





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

	//MSTK_voidSetIntervalPeriodic(125,voidSetDACHello);



	while(1)
	{

	}

}
