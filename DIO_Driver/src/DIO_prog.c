/********************************************************************************/
/* Author  : BESHO																*
/* Version : V01																*
/* Date    : 12 AGU 2020														*
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


/*******************************************************************************
* Description : Sets the direction of a specific pin on a given port.			*
* Arguments   : copy_u8PORT : The port number (GPIOA, GPIOB, or GPIOC).		*
*				 copy_u8PIN  : The pin number (0 to 15).						*
*				 copy_u8Mode : The desired pin direction (INPUT or OUTPUT).		*
*******************************************************************************/
void MGPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					if(copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~((0b1111) << (copy_u8PIN * 4(
						GPIOA_CRL |=  ((copy_u8Mode) << (copy_u8PIN * 4(
					}
					else if(copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
						GPIOA_CRH &= ~((0b1111) << (copy_u8PIN * 4(
						GPIOA_CRH |=  ((copy_u8Mode) << (copy_u8PIN * 4(
					}
					break;
		case GPIOB :
					if(copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~((0b1111) << (copy_u8PIN * 4(
						GPIOB_CRL |=  ((copy_u8Mode) << (copy_u8PIN * 4(
					}
					else if(copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
						GPIOB_CRH &= ~((0b1111) << (copy_u8PIN * 4(
						GPIOB_CRH |=  ((copy_u8Mode) << (copy_u8PIN * 4(
					}
					break;
		case GPIOC :
					if(copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~((0b1111) << (copy_u8PIN * 4(
						GPIOC_CRL |=  ((copy_u8Mode) << (copy_u8PIN * 4(
					}
					else if(copy_u8PIN <= 15)
					{
						copy_u8PIN = copy_u8PIN - 8;
						GPIOC_CRH &= ~((0b1111) << (copy_u8PIN * 4(
						GPIOC_CRH |=  ((copy_u8Mode) << (copy_u8PIN * 4(
					}
					break;
		default	: break;
	}
}

/*******************************************************************************
* Description : Sets the value of a specific pin on a given port.				*
* Arguments   : copy_u8PORT : The port number (GPIOA, GPIOB, or GPIOC).		*
*				 copy_u8PIN  : The pin number
