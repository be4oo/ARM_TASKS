/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01.1																*/
/* Date    : 31 AUG 2020														*/
/********************************************************************************/


#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H


void HLEDMRX_voidInit(void);

void HLEDMRX_voidDisplay(u8 *Copy_u8Data);


void HLEDMRX_voidDisplayScroll(u8 *Copy_u8BigData);

void HLEDMRX_voidDisplayOnce(u8 *Copy_u8Data, u8 Copy_u8ScrollCounter);

void HLEDMRX_voidDisplayOnce2(u8 *Copy_u8Data2);

void HLEDMRX_voidDisplayPlayer(u8 *Copy_u8PlayerData, u8 *Copy_u8BallData);

void HLEDMRX_voidDisplayBall(u8 *Copy_u8DBallData);


#endif
