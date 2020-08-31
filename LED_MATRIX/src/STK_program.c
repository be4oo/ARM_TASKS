/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01.1																*/
/* Date    : 26 AUG 2020														*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

/* Define Callback Global Variable */
void (*MSTK_Callback) (void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	/* Counter enable */
	SET_BIT(SYS->STK_CTRL,ENABLE);
	/* Interrupt enable */
	SET_BIT(SYS->STK_CTRL,TICKINT);
	CLR_BIT(SYS->STK_CTRL,CLKSOURCE);
	//SYS[0] = 0x00000003;
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* We Should clear (Disable) the TICKINT (interrupt bit) */
	CLR_BIT(SYS->STK_CTRL,TICKINT);
	//STK_LOAD
	/* Clear reg */
	SYS->STK_LOAD &= ~((0xFFFF)<<0);
	/* write on reg (load time) */
	SYS->STK_LOAD |= (Copy_u32Ticks<<0);
	/* START */
	SET_BIT(SYS->STK_CTRL, 0);
	//u8 BusyFlag = GET_BIT(SYS->STK_CTRL,COUNTFLAG);
	while(GET_BIT(SYS->STK_CTRL,COUNTFLAG) == 0)
	{
		/*when the Local_u8Flag = 1 then the counting ends*/
	/* waiting until reach 0 to get out the func */	
	}
	/* STOP TIMER */
	SYS->STK_LOAD = 0;
	SYS->STK_VAL  = 0;
	
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Clear reg */
	SYS->STK_LOAD &= ~((0xFFFF)<<0);
	/* write on reg (load time) */
	SYS->STK_LOAD |= (Copy_u32Ticks<<0);
	/* enable of interrupt and enable systick */
	MSTK_Callback = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(SYS->STK_CTRL,TICKINT);
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Clear reg */
	SYS->STK_LOAD &= ~((0xFFFF)<<0);
	/* write on reg (load time) */
	SYS->STK_LOAD |= (Copy_u32Ticks<<0);

	/* enable of interrupt and enable systick */
	/* Start Timer */
	SET_BIT(SYS->STK_CTRL, ENABLE);

	MSTK_Callback = Copy_ptr;
	/* Set Mode to Periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(SYS->STK_CTRL, TICKINT);
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(SYS->STK_CTRL, TICKINT);

	SET_BIT(SYS->STK_LOAD,1);
	SET_BIT(SYS->STK_VAL,1);
}

u32 MSTK_u32GetElapsedTime(void)
{
	return (SYS->STK_VAL - SYS->STK_LOAD);
}

u32 MSTK_u32GetRemainingTime(void)
{
	return SYS->STK_VAL;
}

void SysTick_Handler(void)
{

	u8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
			/* Disable STK Interrupt */
			CLR_BIT(SYS->STK_CTRL, 1);

			/* Stop Timer */
			SET_BIT(SYS->STK_CTRL, 0);
			SYS->STK_LOAD = 0;
			SYS->STK_VAL  = 0;
	}

	/* Callback notification */
	MSTK_Callback();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(SYS->STK_CTRL,COUNTFLAG);
}

