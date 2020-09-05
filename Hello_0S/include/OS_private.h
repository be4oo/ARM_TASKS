/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 5 SEP 2020														*/
/********************************************************************************/


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H



typedef struct
{
	u32 Priodicity;
	void (*Fptr) (void);
	u8 FirstDelay;
	u8 State;
}Task;









#endif
