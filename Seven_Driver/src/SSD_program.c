/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 15 AGU 2020														*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "SSD_interface.h"


/* SSD_voidSendNum(CATHODE, 3) */
void SSD_voidASendNum(u8 Copy_u8AType, u8 Copy_u8ANum)
{

	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_PP);
	if(Copy_u8AType==1)
	{
		switch(Copy_u8ANum)
		{
			case 0:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_LOW);
				break;
			case 1:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_LOW);
				break;
			case 2:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
			case 3:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
			case 4:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
			case 5:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
			case 6:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
			case 7:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_LOW);
				break;
			case 8:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
			case 9:
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				break;
		}
	}
}

void SSD_voidBSendNum(u8 Copy_u8BType, u8 Copy_u8BNum)
{

	MGPIO_voidSetPinDirection(GPIOB, PIN9 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN10, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN11, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN12, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN13, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN14, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN15, OUTPUT_SPEED_10MHZ_PP);

	if(Copy_u8BType==1)
	{
		switch(Copy_u8BNum)
		{
			case 0:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_LOW);
				break;
			case 1:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_LOW);
				break;
			case 2:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
			case 3:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
			case 4:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
			case 5:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
			case 6:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
			case 7:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_LOW);
				break;
			case 8:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
			case 9:
				MGPIO_voidSetPinValue(GPIOB, PIN9 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);
				break;
		}
	}
}



