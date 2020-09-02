/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01.1																*/
/* Date    : 31 AUG 2020														*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"
#include "DIO_int.h"



void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);
	
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN, OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	
	while(1)
	{
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[0]);
		/* enable col-0- */
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[1]);
		/* enable col-1- */
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[2]);
		/* enable col-2- */
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[3]);
		/* enable col-3- */
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[4]);
		/* enable col-4- */
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[5]);
		/* enable col-5- */
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[6]);
		/* enable col-6- */
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
		
		/* disable all col */
		DisableAllCols();
		SetRowValues(Copy_u8Data[7]);
		/* enable col-7- */
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);  // 2.5 mSec
	}
	
}

void HLEDMRX_voidDisplayOnce(u8 *Copy_u8Data, u8 Copy_u8ScrollCounter)
{

	volatile u32 x = 2500;

	for(int i = 0 ; i < 5 ; i++)
	{
	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter]);
	/* enable col-0- */
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec


	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+1]);
	/* enable col-1- */
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+2]);
	/* enable col-2- */
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+3]);
	/* enable col-3- */
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+4]);
	/* enable col-4- */
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+5]);
	/* enable col-5- */
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+6]);
	/* enable col-6- */
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	/* disable all col */
	DisableAllCols();
	SetRowValues(Copy_u8Data[Copy_u8ScrollCounter+7]);
	/* enable col-7- */
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(x);  // 2.5 mSec

	//Copy_u8ScrollCounter++;
	//MSTK_voidSetBusyWait(10000);
	}

}

void HLEDMRX_voidDisplayScroll(u8 *Copy_u8BigData)
{

	//volatile long int i = 50000;

	while(1)
	{


		for(int t = 0 ; t < 19 ; t++)
		{
			HLEDMRX_voidDisplayOnce(Copy_u8BigData, t);
			MSTK_voidSetBusyWait(30000);
		}
			/*
		HLEDMRX_voidDisplayOnce(Copy_u8BigData, 1);
		MSTK_voidSetBusyWait(i);
		HLEDMRX_voidDisplayOnce(Copy_u8BigData, 2);
		MSTK_voidSetBusyWait(i);
		HLEDMRX_voidDisplayOnce(Copy_u8BigData, 3);
		MSTK_voidSetBusyWait(i);
		HLEDMRX_voidDisplayOnce(Copy_u8BigData, 4);
		MSTK_voidSetBusyWait(i);
		HLEDMRX_voidDisplayOnce(Copy_u8BigData, 5);
		MSTK_voidSetBusyWait(i);
		HLEDMRX_voidDisplayOnce(Copy_u8BigData, 6);
		MSTK_voidSetBusyWait(i);
			 */

		//HLEDMRX_voidDisplayOnce(Copy_u8BigData, 8);
		//MSTK_voidSetBusyWait(2000000);
		//HLEDMRX_voidDisplayOnce(Copy_u8BigData, 16);
		//MSTK_voidSetBusyWait(2500);
		//HLEDMRX_voidDisplayOnce(Copy_u8BigData, 24);
		//MSTK_voidSetBusyWait(2000000);

	}
}

static void DisableAllCols(void)
{
	/* disable all col */
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}

static void SetRowValues(u8 Copy_u8Value)
{
	
	u8 Local_u8BIT;
	/* Copy_u8Data[0] ==> 0b01111100 */
	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8BIT);
}


