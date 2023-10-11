/*
 * servo_motor2.c
 *
 * Created: 10/23/2019 4:39:23 PM
 *  Author: Mohamed Zaghlol
 */ 


#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	SET_BIT(DDRD,0);
    while(1)
    {
		SET_BIT(PORTD,0);
		_delay_ms(1);
		CLR_BIT(PORTD,0);
		_delay_ms(1000);
		
		
         SET_BIT(PORTD,0);
		 _delay_ms(1.5);
		 CLR_BIT(PORTD,0);
		 _delay_ms(1000);
		
		 
		 
		  SET_BIT(PORTD,0);
		  _delay_ms(2);
		  CLR_BIT(PORTD,0);
		  _delay_ms(1000); 
		  
		   SET_BIT(PORTD,0);
		   _delay_ms(1.5);
		   CLR_BIT(PORTD,0);
		   _delay_ms(1000);
		   
    }
}