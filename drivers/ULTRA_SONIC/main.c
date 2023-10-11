/***************************************************
 *  Module : main.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/


#include "ultra_sonic.h"
#include <avr/io.h>       /* for SREG register */
#include "lcd.h"
#include <util/delay.h>


int main(void){

	uint16 distance =0 ;
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	/* Initialize LCD and ultra-sonic driver */
	LCD_init();


	LCD_displayString("Distance =    cm");
	while(1){

		Ultrasonic_init();
		distance =Ultrasonic_readDistance();

		LCD_moveCursor(0,11);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');

		}
		_delay_ms(200);

	}
}
