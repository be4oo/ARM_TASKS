/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 14 SEP 2020														*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_int.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"



void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	/* send bit by bit starting from MSb (Most S bit) */
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7 ; Local_s8Counter >= 0; Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA, Local_u8Bit);
		
		/* Send PULSE to Shift Clock */
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
	/* Send PULSE to Storge Clock */
	MGPIO_voidSetPinValue(HSTP_STORE_DATA, GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_DATA, GPIO_LOW);
	MSTK_voidSetBusyWait(1);
}
