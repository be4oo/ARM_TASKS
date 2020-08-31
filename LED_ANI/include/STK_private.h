/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 26 AUG 2020														*/
/********************************************************************************/



#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


typedef struct{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;	
}SYS_t;

#define SYS		 				((volatile SYS_t *) 0xE000E010)

#define ENABLE 					0
#define TICKINT					1
#define CLKSOURCE				2
#define COUNTFLAG				16

#define MSTK_SINGLE_INTERVAL    0
#define MSTK_PERIOD_INTERVAL    1

#endif
