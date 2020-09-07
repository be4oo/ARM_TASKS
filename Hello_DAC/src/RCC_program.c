/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 8 AGU 2020															*/
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{
	#if	  RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR	 = 0x00010000; /*Enable HSE CR with no bypass */
		RCC_CFGR = 0x00000001;

	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR	 = 0x00050000; /*Enable HSE RC with bypass */
		RCC_CFGR = 0x00000001;
		
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR	 = 0x00000081; /*Enable HSI + Tremming 0 */
		RCC_CFGR = 0x00000000;
	
	/* ********TASK********* */
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if		RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			
		#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			
		#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif
	
	#else
		#Error("You chosed wrong cklock type")
	#endif
	
	   
}



/* ex >> 	RCC_voidEnableClock(0, 10)
			RCC_voidEnableClock(RCC_AHB, SDIOEN)
*/
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerId);	break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId);	break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId);	break;
			/*default       : /* Return Error 					break;*/
		}
	}
	else
	{
		/* Return Error */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerId);	break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId);	break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId);	break;
			/*default       : /* Return Error 					break;*/
		}
	}
	else
	{
		/* Return Error */
	}
}


/* u8 x;
	/* setting HSI
	if(RCC_CR_HSION==1)
	{
		SET_BIT(RCC_CR,HSION);
		for(;;){
			x = GET_BIT(RCC_CR,HSIRDY)
			if(x==1){
				break;
			}
		}
		
	}
	else
	{
		CLR_BIT(RCC_CR,HSION)
	}
	
	if(RCC_CR_HSEON==1)
	{
		SET_BIT(RCC_CR,HSEON);
		for(;;){
			x = GET_BIT(RCC_CR,HSERDY)
			if(x==1){
				break;
			}
		}
	}
	else
	{
		CLR_BIT(RCC_CR,HSEON)
	}
	
	if(RCC_CR_HSEBYP==1)
	{
		SET_BIT(RCC_CR,HSEBYP);
	}
	else
	{
		CLR_BIT(RCC_CR,HSEBYP)
	}
	
	if(RCC_CR_CSSON==1)
	{
		SET_BIT(RCC_CR,CSSON);
	}
	else
	{
		CLR_BIT(RCC_CR,CSSON)
	}
	
	if(RCC_CR_PLLON==1)
	{
		SET_BIT(RCC_CR,PLLON);
	}
	else
	{
		CLR_BIT(RCC_CR,PLLON)
	} 
	*/