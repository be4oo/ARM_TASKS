/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 19 AGU 2020														*/
/********************************************************************************/

#ifndef NCIC_INTERFACE_H
#define NCIC_INTERFACE_H

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_voidGetActiveFlag(u8 Copy_u8IntNumber);

void MNVIC_voidSetPriority(u8 Copy_s8IntID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );




#endif
