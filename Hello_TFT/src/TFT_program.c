/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 21 SEP 2020														*/
/********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


 
void HTFT_voidInitialize(void)
{
	/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);

	/* sleep out command */
	voidWriteCommand(0x11);

	MSTK_voidSetBusyWait(150000);

	/* color mode command */
	voidWriteCommand(0x3A);
	voidWriteData(0x05);

	/* Display on command */
	voidWriteCommand(0x29);

	
}

void HTFT_voidDisplayImage(const u16 * Copy_Image)
{
	u16  Counter;
	/* Set 'x' address */
	voidWriteCommand(0x2A);
		/* area of working */
	/* strat of 'x' */
	voidWriteData(0);
	voidWriteData(0);
	/* end of 'x' */
	voidWriteData(0);
	voidWriteData(127);

	/* Set 'y' address */
	voidWriteCommand(0x2B);
		/* area of working */
	/* strat of 'y' */
	voidWriteData(0);
	voidWriteData(0);
	/* end of 'y' */
	voidWriteData(0);
	voidWriteData(159);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter < 20480 ; Counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_Image[Counter] >> 8);
		/* write the low byte */
		voidWriteData(Copy_Image[Counter] & 0x00FF);


	}

	
}


static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;

	/* Set A0 pin to LOW */
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_LOW);

	/* Send Command over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command,&Local_u8Temp);
}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;

	/* Set A0 pin to HIGH */
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_HIGH);

	/* Send Data over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data,&Local_u8Temp);
}

