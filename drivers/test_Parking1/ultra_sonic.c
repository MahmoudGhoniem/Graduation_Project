/***************************************************
 *  Module : ultra_sonic.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#include <avr/io.h>
#include "lcd.h"
#include "gpio.h"
#include "ultra_sonic.h"
#include <util/delay.h>



void Ultrasonic_init()
{
	TCCR1A = 0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT);
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/

}

void Ultrasonic_trigger ()
{
		/*Give 15us trigger pulse */
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_HIGH);
	_delay_us(15);
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);

}


uint16 Ultrasonic_readDistance(void)
{

	Ultrasonic_trigger ();
	uint16 a,b,high,distance;
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
