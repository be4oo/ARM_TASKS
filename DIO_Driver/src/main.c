#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h" // Include header file for the RCC module
#include "DIO_int.h" // Include header file for the GPIO module

int main(void)
{
	RCC_voidInitSysClock(); // Initialize the system clock

	// Enable clocks for GPIOA, GPIOB, and GPIOC
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);
	RCC_voidEnableClock(RCC_APB2,4);

	// Set the direction of the pins on GPIOA to output with a speed of 10 MHz
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN7, INPUT_PULL_UP_DOWN); // Set the direction of pin 7 on GPIOA to input with pull-up/pull-down resistor
	MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_HIGH); // Set the value of pin 7 on GPIOA to high

	//u8 x; // Declare an 8-bit variable x
	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW); // Set the value of pin 0 on GPIOA to low
		MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH); // Set the value of pin 1 on GPIOA to high
		MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH); // Set the value of pin 2 on GPIOA to high
		MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW); // Set the
