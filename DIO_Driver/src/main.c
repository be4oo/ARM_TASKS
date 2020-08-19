
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"

int main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);

	RCC_voidEnableClock(RCC_APB2,3);

	RCC_voidEnableClock(RCC_APB2,4);

	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN7, INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_HIGH);

	//int w = 500;
	u8 x;
	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_LOW);
		x = MGPIO_voidGetPinValue(GPIOA, PIN7);
		if(x==0)
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
		}
		else
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
		}



	}

}


/*
 for(int i = 0 ; i < w ; i++)
				{
					for(int j = 0 ; j < w ; j++)
					{
						asm("NOP");
					}
				}

		MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
		for(int i = 0 ; i < w ; i++)
				{
					for(int j = 0 ; j < w ; j++)
					{
						asm("NOP");
					}
				}*/
