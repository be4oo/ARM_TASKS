/**********************************************************/
/* Author    : Besho	                                  */
/* Date      : 29 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



static void (* EXTI0_CallBack) (void);

void MEXTI_voidInit(void)
{
	#if EXTI_LINE == LINE0
		SET_BIT(EXTI->IMR, LINE0);
	#elif EXTI_LINE == LINE1
		SET_BIT(EXTI->IMR, LINE1);
	#elif EXTI_LINE == LINE2
		SET_BIT(EXTI->IMR, LINE2);
	#elif EXTI_LINE == LINE8
		SET_BIT(EXTI->IMR, LINE8);
	#else 
		#error ("Wrong External Interrupt Line")
	#endif
	

	#if EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR, EXTI_LINE);
	#elif EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR, EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI->RTSR, EXTI_LINE);
		SET_BIT(EXTI->FTSR, EXTI_LINE);
	#else 
		#error ("Wrong External Interrupt Line")
	#endif
	
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case FALLING	:	SET_BIT(EXTI->FTSR, EXTI_LINE);		break;
		case RISING		:	SET_BIT(EXTI->RTSR, EXTI_LINE);		break;
		case ON_CHANGE	:	SET_BIT(EXTI->RTSR, EXTI_LINE);
							SET_BIT(EXTI->FTSR, EXTI_LINE);		break;
	}
	SET_BIT(EXTI->IMR, Copy_u8Line);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR, Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR, Copy_u8Line);
}
void MEXTI_voidSoftwareTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER , Copy_u8Line);
}

void MEXTI_voidSetCallBack(void (*ptr) (void))
{
	EXTI0_CallBack = ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*Clear pending Bit */
	SET_BIT(EXTI->PR, 0);
}

void EXTI9_5_IRQHandler(void)
{
	EXTI0_CallBack();
	/*Clear pending Bit */
	SET_BIT(EXTI->PR, 0);
}


