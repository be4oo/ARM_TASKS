/*****************************************
*  Author  :  Ahmed Assaf                *
*  Version :  V01                        *
*  Date    :  29 August 2020             *
*****************************************/

#ifndef EXTI0_CONFIG_H     /* Include guard to prevent multiple inclusions */
#define EXTI0_CONFIG_H

/*
*  EXTI_LINE0
*  EXTI_LINE1
*  EXTI_LINE2
*  .
*  .
*  .
*/

/* Define the EXTI line to be configured */
#define	EXTI_LINE			EXTI_LINE0

/*
*  FALLING_EDGE
*  RISING_EDGE
*  ON_CHANGE
*/

/* Define the sense mode for the EXTI line */
#define	EXTI_SENSE_MODE		FALLING_EDGE

#endif /* EXTI0_CONFIG_H */
