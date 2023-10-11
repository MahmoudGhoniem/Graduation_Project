#include <avr/io.h>
#include "LCD.h"
#include "altrasonic.h"
#define  F_CPU 1000000UL
#define eight_bits_mode
#include <util/delay.h>
int main(void)
{
	LCD_vInit();
	altrasonic_init();
	unsigned short distance;
	DIO_vsetPINDir('D',7,1);
    while(1)
    {	
		 distance=altrasonic_read();
		if (distance>=80)
		{
			LCD_clearscreen();
			LCD_vSend_string("no object");
			_delay_ms(500);
		}
		else
		{
		LCD_clearscreen();
		LCD_vSend_string("distance=");
		LCD_vSend_char((distance/10)+48);
		LCD_vSend_char((distance%10)+48);
	    LCD_vSend_string("cm");
		_delay_ms(500);
		}		
	}
}

