/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 26 AUG 2020														*/
/********************************************************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/*
void (*Callback) (void);
 */
 
/*		Apply Clock choise from configuration file
		Disable SysTick interrupt
		Disable SysTick
		*/
void MSTK_voidInit(void);


void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
/*
	Load_Reg = Copy_u32Ticks;
	
	/* enable systick *//*
	while(Flag == 0)
		*/


/*	 MSTK_voidSetIntervalSingle(1000, func)		*/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
/* 	
	Load_Reg = Copy_u32Ticks;
	
	/* enable of interrupt and enable systick *//*
	Callback = Copy_ptr;  
	*/
/*	
void SysTick_Handler(void)
{
	Callback();
}
*/

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr)(void));
void MSTK_voidStopInterval(void);
void MSTK_void_u32GetElapsedTime(void);
void MSTK_void_u32GetRemainingTime(void);



#endif
