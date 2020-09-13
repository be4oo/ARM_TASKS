/**********************************************************/
/* Author    : Besho	                                  */
/* Date      : 29 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSoftwareTrigger(u8 Copy_u8Line);

void MEXTI_voidSetCallBack(void (*ptr) (void));


#define FALLING			0
#define RISING			1
#define ON_CHANGE		2

#define LINE0			0
#define LINE1			1
#define LINE2			2




#endif
