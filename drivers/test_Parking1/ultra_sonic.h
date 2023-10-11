/***************************************************
 *  Module : ultra_sonic.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_


#include "std_types.h"


#define TRIGGER_PORT     PORTD_ID
#define TRIGGER_PIN      PIN7_ID


void Ultrasonic_init() ;

void Ultrasonic_trigger () ;

uint16 Ultrasonic_readDistance(void);


#endif /* ULTRA_SONIC_H_ */
