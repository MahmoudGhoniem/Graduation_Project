/*
 * altrasonic.c
 *
 * Created: 16-Feb-22 3:53:08 PM
 *  Author: IbrahimElmekawy
 */ 
#include <avr/io.h>
#include "LCD.h"
#include "altrasonic.h"
#define  F_CPU 1000000UL
#include <util/delay.h>

void altrasonic_init()
{
	TCCR1A = 0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
	DIO_write('D',7,1);
	_delay_us(50);
	DIO_write('D',7,0);
	
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
}
unsigned short altrasonic_read()
{
	unsigned short a,b,high,distance;
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCNT1=0;
	TCCR1B = 0;  		/* Stop the timer */
	high=b-a;
	distance=((high*34600)/(F_CPU*2)) ;
	return(distance);
}