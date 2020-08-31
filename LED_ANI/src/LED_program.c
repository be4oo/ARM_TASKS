/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 15 AGU 2020														*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "LED_interface.h"


void delay(void)
{
	for(int i = 0 ; i < TIME ; i++)
	{
		for(int j = 0 ; j < TIME ; j++)
		{
			asm("NOP");
		}
	}
}
/* LED_voidOn(GPIOA, PIN0) */
void LED_voidOn(u8 Copy_u8nPort, u8 Copy_u8nPin)
{
	switch(Copy_u8nPort)
	{
		case GPIOA:
			switch(Copy_u8nPin)
			{
				case PIN0:
					MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
					break;
				case PIN1:
					MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
					break;
				case PIN2:
					MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
					break;
				case PIN3:
					MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
					break;
				case PIN4:
					MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_HIGH);
					break;
				case PIN5:
					MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
					break;
				case PIN6:
					MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
					break;
				case PIN7:
					MGPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_HIGH);
					break;
				case PIN8:
					MGPIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_HIGH);
					break;
				case PIN9:
					MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN9, GPIO_HIGH);
					break;
				case PIN10:
					MGPIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN10, GPIO_HIGH);
					break;
				case PIN11:
					MGPIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN11, GPIO_HIGH);
					break;
				case PIN12:
					MGPIO_voidSetPinDirection(GPIOA, PIN12, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN12, GPIO_HIGH);
					break;
				case PIN13:
					MGPIO_voidSetPinDirection(GPIOA, PIN13, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN13, GPIO_HIGH);
					break;
				case PIN14:
					MGPIO_voidSetPinDirection(GPIOA, PIN14, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN14, GPIO_HIGH);
					break;
				case PIN15:
					MGPIO_voidSetPinDirection(GPIOA, PIN15, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOA, PIN15, GPIO_HIGH);
					break;
			}
			break;
		case GPIOB:
			switch(Copy_u8nPin)
			{
				case PIN0:
					MGPIO_voidSetPinDirection(GPIOB, PIN0, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN0, GPIO_HIGH);
					break;
				case PIN1:
					MGPIO_voidSetPinDirection(GPIOB, PIN1, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN1, GPIO_HIGH);
					break;
				case PIN2:
					MGPIO_voidSetPinDirection(GPIOB, PIN2, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN2, GPIO_HIGH);
					break;
				case PIN3:
					MGPIO_voidSetPinDirection(GPIOB, PIN3, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN3, GPIO_HIGH);
					break;
				case PIN4:
					MGPIO_voidSetPinDirection(GPIOB, PIN4, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN4, GPIO_HIGH);
					break;
				case PIN5:
					MGPIO_voidSetPinDirection(GPIOB, PIN5, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN5, GPIO_HIGH);
					break;
				case PIN6:
					MGPIO_voidSetPinDirection(GPIOB, PIN6, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN6, GPIO_HIGH);
					break;
				case PIN7:
					MGPIO_voidSetPinDirection(GPIOB, PIN7, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN7, GPIO_HIGH);
					break;
				case PIN8:
					MGPIO_voidSetPinDirection(GPIOB, PIN8, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN8, GPIO_HIGH);
					break;
				case PIN9:
					MGPIO_voidSetPinDirection(GPIOB, PIN9, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN9, GPIO_HIGH);
					break;
				case PIN10:
					MGPIO_voidSetPinDirection(GPIOB, PIN10, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
					break;
				case PIN11:
					MGPIO_voidSetPinDirection(GPIOB, PIN11, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
					break;
				case PIN12:
					MGPIO_voidSetPinDirection(GPIOB, PIN12, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
					break;
				case PIN13:
					MGPIO_voidSetPinDirection(GPIOB, PIN13, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_HIGH);
					break;
				case PIN14:
					MGPIO_voidSetPinDirection(GPIOB, PIN14, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
					break;
				case PIN15:
					MGPIO_voidSetPinDirection(GPIOB, PIN15, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
					break;
			}
			break;
		case GPIOC:
			switch(Copy_u8nPin)
			{
				case PIN0:
					MGPIO_voidSetPinDirection(GPIOC, PIN0, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN0, GPIO_HIGH);
					break;
				case PIN1:
					MGPIO_voidSetPinDirection(GPIOC, PIN1, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN1, GPIO_HIGH);
					break;
				case PIN2:
					MGPIO_voidSetPinDirection(GPIOC, PIN2, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN2, GPIO_HIGH);
					break;
				case PIN3:
					MGPIO_voidSetPinDirection(GPIOC, PIN3, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN3, GPIO_HIGH);
					break;
				case PIN4:
					MGPIO_voidSetPinDirection(GPIOC, PIN4, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN4, GPIO_HIGH);
					break;
				case PIN5:
					MGPIO_voidSetPinDirection(GPIOC, PIN5, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN5, GPIO_HIGH);
					break;
				case PIN6:
					MGPIO_voidSetPinDirection(GPIOC, PIN6, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN6, GPIO_HIGH);
					break;
				case PIN7:
					MGPIO_voidSetPinDirection(GPIOC, PIN7, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN7, GPIO_HIGH);
					break;
				case PIN8:
					MGPIO_voidSetPinDirection(GPIOC, PIN8, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN8, GPIO_HIGH);
					break;
				case PIN9:
					MGPIO_voidSetPinDirection(GPIOC, PIN9, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN9, GPIO_HIGH);
					break;
				case PIN10:
					MGPIO_voidSetPinDirection(GPIOC, PIN10, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN10, GPIO_HIGH);
					break;
				case PIN11:
					MGPIO_voidSetPinDirection(GPIOC, PIN11, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN11, GPIO_HIGH);
					break;
				case PIN12:
					MGPIO_voidSetPinDirection(GPIOC, PIN12, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN12, GPIO_HIGH);
					break;
				case PIN13:
					MGPIO_voidSetPinDirection(GPIOC, PIN13, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN13, GPIO_HIGH);
					break;
				case PIN14:
					MGPIO_voidSetPinDirection(GPIOC, PIN14, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN14, GPIO_HIGH);
					break;
				case PIN15:
					MGPIO_voidSetPinDirection(GPIOC, PIN15, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetPinValue(GPIOC, PIN15, GPIO_HIGH);
					break;
			}
			break;
	}
}
void LED_voidOff(u8   Copy_u8fPort, u8 Copy_u8fPin)
{
	switch(Copy_u8fPort)
	{
		case GPIOA:
			switch(Copy_u8fPin)
			{
				case PIN0:  MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);  break;
				case PIN1:  MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);  break;
				case PIN2:  MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_LOW);  break;
				case PIN3:  MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW);  break;
				case PIN4:  MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);  break;
				case PIN5:  MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);  break;
				case PIN6:  MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_LOW);  break;
				case PIN7:  MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_LOW);  break;
				case PIN8:  MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_LOW);  break;
				case PIN9:  MGPIO_voidSetPinValue(GPIOA, PIN9, GPIO_LOW);  break;
				case PIN10: MGPIO_voidSetPinValue(GPIOA, PIN10, GPIO_LOW); break;
				case PIN11: MGPIO_voidSetPinValue(GPIOA, PIN11, GPIO_LOW); break;
				case PIN12: MGPIO_voidSetPinValue(GPIOA, PIN12, GPIO_LOW); break;
				case PIN13: MGPIO_voidSetPinValue(GPIOA, PIN13, GPIO_LOW); break;
				case PIN14: MGPIO_voidSetPinValue(GPIOA, PIN14, GPIO_LOW); break;
				case PIN15: MGPIO_voidSetPinValue(GPIOA, PIN15, GPIO_LOW); break;
			}
			break;
		case GPIOB:
			switch(Copy_u8fPin)
			{
				case PIN0:  MGPIO_voidSetPinValue(GPIOB, PIN0, GPIO_LOW);  break;
				case PIN1:  MGPIO_voidSetPinValue(GPIOB, PIN1, GPIO_LOW);  break;
				case PIN2:  MGPIO_voidSetPinValue(GPIOB, PIN2, GPIO_LOW);  break;
				case PIN3:  MGPIO_voidSetPinValue(GPIOB, PIN3, GPIO_LOW);  break;
				case PIN4:  MGPIO_voidSetPinValue(GPIOB, PIN4, GPIO_LOW);  break;
				case PIN5:  MGPIO_voidSetPinValue(GPIOB, PIN5, GPIO_LOW);  break;
				case PIN6:  MGPIO_voidSetPinValue(GPIOB, PIN6, GPIO_LOW);  break;
				case PIN7:  MGPIO_voidSetPinValue(GPIOB, PIN7, GPIO_LOW);  break;
				case PIN8:  MGPIO_voidSetPinValue(GPIOB, PIN8, GPIO_LOW);  break;
				case PIN9:  MGPIO_voidSetPinValue(GPIOB, PIN9, GPIO_LOW);  break;
				case PIN10: MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_LOW); break;
				case PIN11: MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_LOW); break;
				case PIN12: MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_LOW); break;
				case PIN13: MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW); break;
				case PIN14: MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_LOW); break;
				case PIN15: MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_LOW); break;
			}
			break;
		case GPIOC:
			switch(Copy_u8fPin)
			{
				case PIN0:  MGPIO_voidSetPinValue(GPIOC, PIN0, GPIO_LOW);  break;
				case PIN1:  MGPIO_voidSetPinValue(GPIOC, PIN1, GPIO_LOW);  break;
				case PIN2:  MGPIO_voidSetPinValue(GPIOC, PIN2, GPIO_LOW);  break;
				case PIN3:  MGPIO_voidSetPinValue(GPIOC, PIN3, GPIO_LOW);  break;
				case PIN4:  MGPIO_voidSetPinValue(GPIOC, PIN4, GPIO_LOW);  break;
				case PIN5:  MGPIO_voidSetPinValue(GPIOC, PIN5, GPIO_LOW);  break;
				case PIN6:  MGPIO_voidSetPinValue(GPIOC, PIN6, GPIO_LOW);  break;
				case PIN7:  MGPIO_voidSetPinValue(GPIOC, PIN7, GPIO_LOW);  break;
				case PIN8:  MGPIO_voidSetPinValue(GPIOC, PIN8, GPIO_LOW);  break;
				case PIN9:  MGPIO_voidSetPinValue(GPIOC, PIN9, GPIO_LOW);  break;
				case PIN10: MGPIO_voidSetPinValue(GPIOC, PIN10, GPIO_LOW); break;
				case PIN11: MGPIO_voidSetPinValue(GPIOC, PIN11, GPIO_LOW); break;
				case PIN12: MGPIO_voidSetPinValue(GPIOC, PIN12, GPIO_LOW); break;
				case PIN13: MGPIO_voidSetPinValue(GPIOC, PIN13, GPIO_LOW); break;
				case PIN14: MGPIO_voidSetPinValue(GPIOC, PIN14, GPIO_LOW); break;
				case PIN15: MGPIO_voidSetPinValue(GPIOC, PIN15, GPIO_LOW); break;
			}
			break;
	}
}
void LED_voidTogle(u8 Copy_u8tPort, u8 Copy_u8tPin)
{
	switch(Copy_u8tPort)
	{
		case GPIOA:
			switch(Copy_u8tPin)
			{
				case PIN0 : LED_voidOn(GPIOA, PIN0 ); delay(); LED_voidOff(GPIOA, PIN0 ); delay(); break;
				case PIN1 : LED_voidOn(GPIOA, PIN1 ); delay(); LED_voidOff(GPIOA, PIN1 ); delay(); break;
				case PIN2 : LED_voidOn(GPIOA, PIN2 ); delay(); LED_voidOff(GPIOA, PIN2 ); delay(); break;
				case PIN3 : LED_voidOn(GPIOA, PIN3 ); delay(); LED_voidOff(GPIOA, PIN3 ); delay(); break;
				case PIN4 : LED_voidOn(GPIOA, PIN4 ); delay(); LED_voidOff(GPIOA, PIN4 ); delay(); break;
				case PIN5 : LED_voidOn(GPIOA, PIN5 ); delay(); LED_voidOff(GPIOA, PIN5 ); delay(); break;
				case PIN6 : LED_voidOn(GPIOA, PIN6 ); delay(); LED_voidOff(GPIOA, PIN6 ); delay(); break;
				case PIN7 : LED_voidOn(GPIOA, PIN7 ); delay(); LED_voidOff(GPIOA, PIN7 ); delay(); break;
				case PIN8 : LED_voidOn(GPIOA, PIN8 ); delay(); LED_voidOff(GPIOA, PIN8 ); delay(); break;
				case PIN9 : LED_voidOn(GPIOA, PIN9 ); delay(); LED_voidOff(GPIOA, PIN9 ); delay(); break;
				case PIN10: LED_voidOn(GPIOA, PIN10); delay(); LED_voidOff(GPIOA, PIN10); delay(); break;
				case PIN11: LED_voidOn(GPIOA, PIN11); delay(); LED_voidOff(GPIOA, PIN11); delay(); break;
				case PIN12: LED_voidOn(GPIOA, PIN12); delay(); LED_voidOff(GPIOA, PIN12); delay(); break;
				case PIN13: LED_voidOn(GPIOA, PIN13); delay(); LED_voidOff(GPIOA, PIN13); delay(); break;
				case PIN14: LED_voidOn(GPIOA, PIN14); delay(); LED_voidOff(GPIOA, PIN14); delay(); break;
				case PIN15: LED_voidOn(GPIOA, PIN15); delay(); LED_voidOff(GPIOA, PIN15); delay(); break;
			}
			break;
		case GPIOB:
			switch(Copy_u8tPin)
			{
				case PIN0:  LED_voidOn(GPIOB, PIN0 ); delay(); LED_voidOff(GPIOB, PIN0 ); delay(); break;
				case PIN1:  LED_voidOn(GPIOB, PIN1 ); delay(); LED_voidOff(GPIOB, PIN1 ); delay(); break;
				case PIN2:  LED_voidOn(GPIOB, PIN2 ); delay(); LED_voidOff(GPIOB, PIN2 ); delay(); break;
				case PIN3:  LED_voidOn(GPIOB, PIN3 ); delay(); LED_voidOff(GPIOB, PIN3 ); delay(); break;
				case PIN4:  LED_voidOn(GPIOB, PIN4 ); delay(); LED_voidOff(GPIOB, PIN4 ); delay(); break;
				case PIN5:  LED_voidOn(GPIOB, PIN5 ); delay(); LED_voidOff(GPIOB, PIN5 ); delay(); break;
				case PIN6:  LED_voidOn(GPIOB, PIN6 ); delay(); LED_voidOff(GPIOB, PIN6 ); delay(); break;
				case PIN7:  LED_voidOn(GPIOB, PIN7 ); delay(); LED_voidOff(GPIOB, PIN7 ); delay(); break;
				case PIN8:  LED_voidOn(GPIOB, PIN8 ); delay(); LED_voidOff(GPIOB, PIN8 ); delay(); break;
				case PIN9:  LED_voidOn(GPIOB, PIN9 ); delay(); LED_voidOff(GPIOB, PIN9 ); delay(); break;
				case PIN10: LED_voidOn(GPIOB, PIN10); delay(); LED_voidOff(GPIOB, PIN10); delay(); break;
				case PIN11: LED_voidOn(GPIOB, PIN11); delay(); LED_voidOff(GPIOB, PIN11); delay(); break;
				case PIN12: LED_voidOn(GPIOB, PIN12); delay(); LED_voidOff(GPIOB, PIN12); delay(); break;
				case PIN13: LED_voidOn(GPIOB, PIN13); delay(); LED_voidOff(GPIOB, PIN13); delay(); break;
				case PIN14: LED_voidOn(GPIOB, PIN14); delay(); LED_voidOff(GPIOB, PIN14); delay(); break;
				case PIN15: LED_voidOn(GPIOB, PIN15); delay(); LED_voidOff(GPIOB, PIN15); delay(); break;
			}
			break;
		case GPIOC:
			switch(Copy_u8tPin)
			{
				case PIN0:  LED_voidOn(GPIOC, PIN0 ); delay(); LED_voidOff(GPIOC, PIN0 ); delay(); break;
				case PIN1:  LED_voidOn(GPIOC, PIN1 ); delay(); LED_voidOff(GPIOC, PIN1 ); delay(); break;
				case PIN2:  LED_voidOn(GPIOC, PIN2 ); delay(); LED_voidOff(GPIOC, PIN2 ); delay(); break;
				case PIN3:  LED_voidOn(GPIOC, PIN3 ); delay(); LED_voidOff(GPIOC, PIN3 ); delay(); break;
				case PIN4:  LED_voidOn(GPIOC, PIN4 ); delay(); LED_voidOff(GPIOC, PIN4 ); delay(); break;
				case PIN5:  LED_voidOn(GPIOC, PIN5 ); delay(); LED_voidOff(GPIOC, PIN5 ); delay(); break;
				case PIN6:  LED_voidOn(GPIOC, PIN6 ); delay(); LED_voidOff(GPIOC, PIN6 ); delay(); break;
				case PIN7:  LED_voidOn(GPIOC, PIN7 ); delay(); LED_voidOff(GPIOC, PIN7 ); delay(); break;
				case PIN8:  LED_voidOn(GPIOC, PIN8 ); delay(); LED_voidOff(GPIOC, PIN8 ); delay(); break;
				case PIN9:  LED_voidOn(GPIOC, PIN9 ); delay(); LED_voidOff(GPIOC, PIN9 ); delay(); break;
				case PIN10: LED_voidOn(GPIOC, PIN10); delay(); LED_voidOff(GPIOC, PIN10); delay(); break;
				case PIN11: LED_voidOn(GPIOC, PIN11); delay(); LED_voidOff(GPIOC, PIN11); delay(); break;
				case PIN12: LED_voidOn(GPIOC, PIN12); delay(); LED_voidOff(GPIOC, PIN12); delay(); break;
				case PIN13: LED_voidOn(GPIOC, PIN13); delay(); LED_voidOff(GPIOC, PIN13); delay(); break;
				case PIN14: LED_voidOn(GPIOC, PIN14); delay(); LED_voidOff(GPIOC, PIN14); delay(); break;
				case PIN15: LED_voidOn(GPIOC, PIN15); delay(); LED_voidOff(GPIOC, PIN15); delay(); break;
			}
			break;
	}
}
