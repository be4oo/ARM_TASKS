/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 5 SEP 2020														*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* mcal
	hal
	*/
#include "STK_interface.h"
	

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL (void *)0

/* Array of Tasks " Array of Structure" */
static Task OS_Tasks[NUMBER_OF_TASKS] = { NULL };


void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Priodicity, void (*ptr) (void))
{
	OS_Tasks[Copy_u8ID].Priodicity = Copy_u8Priodicity;
	OS_Tasks[Copy_u8ID].Fptr = ptr;
}



void SOS_voidStart(void)
{
	/* Intialization */
	MSTK_voidInit();
	/* Tick => 1 msec */
	/* HSE 8MHz / 8 ==> 1000 Micro Sec ===> 1 msec */
	MSTK_voidSetIntervalPeriodic(1000,Schedular);
	
	
	
}

volatile u16 TickCounts = 0;
void Schedular(void)
{
	for(u8 i = 0 ; i < NUMBER_OF_TASKS ; i++)
	{
		if((TickCounts % OS_Tasks[i].Priodicity) == 0)
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++;
}
