/**********************************************************/
/* Author    : Besho	                                  */
/* Date      : 30 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"



/* MAFIO_voidSetEXTIConfiguration(2, 0b0001) ===> Pin B2 */
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	
	if(Copy_u8Line <= 3 )
	{
		Local_u8RegIndex = 0;
	}
	else if(Copy_u8Line <= 7)
	{
		Local_u8RegIndex = 1;
		/* to remain between 0 ~ 3 */
		Copy_u8Line -=4;
	}
	else if(Copy_u8Line <= 11)
	{
		Local_u8RegIndex = 2;
		Copy_u8Line -=8;
	}
	else if(Copy_u8Line <= 15)
	{
		Local_u8RegIndex = 3;
		Copy_u8Line -=12;
	}
	
	/* to clear the bits */
	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111)<<(Copy_u8Line*4));
	/* to select port A, B or C & pin depend on line */
	AFIO->EXTICR[Local_u8RegIndex] |= ((Copy_u8PortMap)<<(Copy_u8Line*4));
	
}
