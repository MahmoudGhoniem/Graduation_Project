/*
 * GccApplication2.c
 *
 * Created: 13-Nov-21 11:00:42 PM
 *  Author: IbrahimElmekawy
 */ 


#include "ultrasonic.h"
#include "lcd.h"
#include "avr/io.h" /* To use the SREG Register */
#include <util/delay.h>

int main(void)
{
	uint16 distance = 0;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize the LCD driver */
	LCD_init();

	/* Initialize the Ultrasonic driver */
	Ultrasonic_init();

	LCD_displayString("Distance=     cm");


	while(1)
	{
		/* Read the distance from the Ultrasonic sensor */
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		if(distance>=100)
		{
			/* Display the distance on LCD screen */

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
