/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: besho
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "DIO_int.h"
#include "UART_interface.h"
#include "ESP_interface.h"

int Besho(void)
{
	RCC_voidInitSysClock();

	/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
	/* Enable UART */
	RCC_voidEnableClock(RCC_APB2,14);


	/* A9 	==> TX out 50 MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_AFPP);
	/* A10 	==> RT input floating */
	MGPIO_voidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);

	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);


	MUART_voidInit();


	ESP_voidInit();
	ESP_WIFIConnect();

	u8 Led_State = 0;

	while(1)
	{

		ESP_voidSendData();
		Led_State = ESP_u8WebState();

		if(Led_State == 1)
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
		}
		else
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
		}

	}
	return 0;
}
/*
 * 		MUART_voidTransmit("AT\r\n");
		for(u8 i = 0; i<5 ;i++)
		{
			x[i] = MUART_u8Receive();
		}

		if (x[y] == 'O' && x[y++] == 'K')
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
		}
	}
 *
 */

