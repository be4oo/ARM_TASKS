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
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"

#include "Image.h"

void main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
		/* Enable SPI1 */
	RCC_voidEnableClock(RCC_APB2,12);

	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP); /* A0 */
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP); /* RST */
	MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_10MHZ_AFPP); /* CLK */
	MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_10MHZ_AFPP); /* MOSI */

	MSTK_voidInit();

	MSPI1_voidInit();

	HTFT_voidInitialize();

	//HTFT_voidDisplayImage(Besho);

	HTFT_voidFillColor(0xffff);

	/* testing Rect function */
	//HTFT_voidDrawRect(10,118,20,139,0);

	/* testing pixel function */
	//HTFT_voidDrawPixel(20,20,0);
	//HTFT_voidDrawPixel(20,21,0);
	//HTFT_voidDrawPixel(20,22,0);
	//HTFT_voidDrawPixel(21,20,0);

	HTFT_voidDrawChar(70,70,0,0xffff,'w');

	//HTFT_voidDrawString(10,100,0,0xffff,"BESHO");
}
