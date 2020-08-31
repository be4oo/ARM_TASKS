/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
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


