/***************************************************
 *  Module : pwm_timer1.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/
#include <avr/io.h>
#include <util/delay.h>

void timer0_pwm_init (void )
{
	//Configure TIMER0
	TCNT0 = 0; // Set Timer Initial Value to 0


		DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

		/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);


}

void servo_rotate (degree theta)
{

	OCR0  = theta; // Set Compare Value

}
