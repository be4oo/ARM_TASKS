/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 5 SEP 2020														*/
/********************************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H





void SOS_voidCreateTask(u8 Copy_u8ID, u32 Copy_u8Priodicity, void (*ptr) (void), u32 Copy_u8FirstDelay);

void SOS_voidStart(void);

static void Schedular(void);

/* taking task ID to suspend  */
void SuspendTask(u8 Copy_u8TaskSID);

/* taking task ID to resume  */
void ResumeTask(u8 Copy_u8TaskRID);

/* taking task ID to delete  */
void DeleteTask(u8 Copy_u8TaskRID);










#endif
