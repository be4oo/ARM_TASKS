/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: besho
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "SSD_interface.h"

int w = 1000;
void delay(void);

int main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);

	RCC_voidEnableClock(RCC_APB2,3);

	RCC_voidEnableClock(RCC_APB2,4);

	int w = 1500;
	while(1)
	{

		SSD_voidASendNum(CATHODE, 2);
		SSD_voidBSendNum(CATHODE, 8);

	}



}

void delay(void){
	for(int i = 0 ; i < w ; i++)
											{
												for(int j = 0 ; j < w ; j++)
												{
													asm("NOP");
												}
											}

}


/*
 * SSD_voidASendNum(CATHODE, 0);
		delay();
		SSD_voidASendNum(CATHODE, 1);
		delay();
		SSD_voidASendNum(CATHODE, 2);
		delay();
		SSD_voidASendNum(CATHODE, 3);
		delay();
		SSD_voidASendNum(CATHODE, 4);
		delay();
		SSD_voidASendNum(CATHODE, 5);
		delay();
		SSD_voidASendNum(CATHODE, 6);
		delay();
		SSD_voidASendNum(CATHODE, 7);
		delay();
		SSD_voidASendNum(CATHODE, 8);
		delay();
		SSD_voidASendNum(CATHODE, 9);
		delay();
 *  */


/*
 * for(int i = 0 ; i < w ; i++)
						{
							for(int j = 0 ; j < w ; j++)
							{
								asm("NOP");
							}
						}
						*/

