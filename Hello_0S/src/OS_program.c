/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V02																*/
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


void SOS_voidCreateTask(u8 Copy_u8ID, u32 Copy_u8Priodicity, void (*ptr) (void), u32 Copy_u8FirstDelay)
{
	OS_Tasks[Copy_u8ID].Priodicity = Copy_u8Priodicity;
	OS_Tasks[Copy_u8ID].Fptr = ptr;
	OS_Tasks[Copy_u8ID].FirstDelay = Copy_u8FirstDelay;
	OS_Tasks[Copy_u8ID].State = TASK_READY;
}



void SOS_voidStart(void)
{
	/* Intialization */
	MSTK_voidInit();
	/* Tick => 1 msec */
	/* HSE 8MHz / 8 ==> 1000 Micro Sec ===> 1 msec */
	MSTK_voidSetIntervalPeriodic(1000,Schedular);
	
	
	
}

//volatile u16 TickCounts = 0;
static void Schedular(void)
{

	for(u8 i = 0 ; i < NUMBER_OF_TASKS ; i++)
	{
		if((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].State == TASK_READY))
		{
		//OS_Tasks[i].Fptr();
			if((OS_Tasks[i].FirstDelay) == 0)
			{
				/* counts until it equal 0 */
				OS_Tasks[i].FirstDelay = OS_Tasks[i].Priodicity - 1;
				OS_Tasks[i].Fptr();
			}
			else
			{
				/* counts until it equal 0 */
				OS_Tasks[i].FirstDelay--;
			}
		//}
		}
	//TickCounts++;
	}
}

void SuspendTask(u8 Copy_u8TaskSID)
{
	OS_Tasks[Copy_u8TaskSID].FirstDelay = TASK_SUSPENDED;
}

void ResumeTask(u8 Copy_u8TaskRID)
{
	OS_Tasks[Copy_u8TaskRID].FirstDelay = TASK_READY;
}


void DeleteTask(u8 Copy_u8TaskRID)
{
	OS_Tasks[Copy_u8TaskRID].Fptr = NULL;
}



