/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 5 SEP 2020														*/
/********************************************************************************/


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define 		NULL 					(0)

#define			TASK_SUSPENDED			1

#define			TASK_READY				2


typedef struct
{
	u32 Priodicity;
	void (*Fptr) (void);
	u32 FirstDelay;
	u8 State;
}Task;









#endif
