/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 14 SEP 2020														*/
/********************************************************************************/


#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H


/* Synchronus == wait the signal clock */
void HSTP_voidSendSynchronous(u32 Copy_u8DataToSend, u8 Copy_u8NumberOfRegisters);
/*
u16 HSTP_u16SetSignalForLedMatrix(u8 frame[]);

void GetRow(u8 Arr[]);

void GetSignal(u8 C[8],u8 R[8]);
*/
#endif
