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

#include "font.h"


//static void HTFT_voidBounders(0,127,0,159);

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
	HTFT_voidBounders(0,127,0,159);

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

void HTFT_voidFillColor(u16  Copy_u16Color)
{
	u16  Counter;

	HTFT_voidBounders(0,127,0,159);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter < 20480 ; Counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_u16Color >> 8);
		/* write the low byte */
		voidWriteData(Copy_u16Color & 0x00FF);


	}
	/* to invert color */
	//voidWriteCommand(0x21);


}

void HTFT_voidDrawPixel(u8 x1, u8 y1, u16  Copy_u16Color)
{

	HTFT_voidBounders(x1,x1+2,y1,y1+2);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(u16 Counter = 0 ; Counter <= 9 ; Counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_u16Color >> 8);
		/* write the low byte */
		voidWriteData(Copy_u16Color & 0x00FF);
	}
}

void HTFT_voidDrawChar(u8 x1,u8 y1,u8 color, u8 charcter)
{
	u8 value;
    for (u8 i = 0; i < 5; i++)
    {
        for (u8 j = 0; j < 8; j++)
        {
            value = 0;
            value = ((font[(charcter) - 0x20][i]));

            if((value >> j)  & 0x01)
            {
            	HTFT_voidDrawPixel(x1, y1, color);
            }
         }
        x1 += 3;
        y1 += 3;
     }
}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16  Copy_u16Color)
{
	u16  Counter;

	u16 Size = (x2 - x1 +1) * (y2 - y1 +1);

	HTFT_voidBounders(x1,x2,y1,y2);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter <= Size ; Counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_u16Color >> 8);
		/* write the low byte */
		voidWriteData(Copy_u16Color & 0x00FF);
	}
	/* to invert color */
	//voidWriteCommand(0x21);


}

static void HTFT_voidBounders(u8 x1, u8 x2, u8 y1, u8 y2)
{
	/* Set 'x' address */
	voidWriteCommand(0x2A);
		/* area of working */
	/* start of 'x' */
	voidWriteData(0);
	voidWriteData(x1);
	/* end of 'x' */
	voidWriteData(0);
	voidWriteData(x2);

	/* Set 'y' address */
	voidWriteCommand(0x2B);
		/* area of working */
	/* start of 'y' */
	voidWriteData(0);
	voidWriteData(y1);
	/* end of 'y' */
	voidWriteData(0);
	voidWriteData(y2);

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

