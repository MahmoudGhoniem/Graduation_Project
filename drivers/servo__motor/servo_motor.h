/***************************************************
 *  Module : pwm_timer1.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef PWM_TIMER0_H_
#define PWM_TIMER0_H_


typedef enum {

	degree_90_left = 60, degree_45_left = 155 ,degree_0 = 185 , degree_45_right = 218 , degree_90_right = 250

} degree ;



void timer0_pwm_init (void ) ;

void servo_rotate (degree theta) ;

#endif /* PWM_TIMER0_H_ */
