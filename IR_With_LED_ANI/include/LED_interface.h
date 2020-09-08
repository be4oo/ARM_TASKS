/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 17 AGU 2020														*/
/********************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H



void LED_voidOn(u8    Copy_u8nPort, u8 Copy_u8nPin);
void LED_voidOff(u8   Copy_u8fPort, u8 Copy_u8fPin);
void LED_voidTogle(u8 Copy_u8tPort, u8 Copy_u8tPin);

#define TIME 500
void delay(void);

















#endif
