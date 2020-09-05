/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 5 SEP 2020														*/
/********************************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H





void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Priodicity, void (*ptr) (void));

void SOS_voidStart(void);

void Schedular(void);









#endif
