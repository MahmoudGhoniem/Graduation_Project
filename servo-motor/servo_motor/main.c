/***************************************************
 *  Module : main.c
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/


#include "pwm_timer0.h"
#include "util/delay.h"




int main (void)
{
	timer0_pwm_init ();

	while(1)
	{

		 servo_rotate (degree_0 );
		_delay_ms(2000);

		servo_rotate (degree_45_left);
		_delay_ms(2000);

		servo_rotate (degree_90_left);
		_delay_ms(2000);

		servo_rotate (degree_0);
		_delay_ms(2000);

		servo_rotate (degree_45_right);
		_delay_ms(2000);

		servo_rotate (degree_90_right);
		_delay_ms(2000);


	}







}
