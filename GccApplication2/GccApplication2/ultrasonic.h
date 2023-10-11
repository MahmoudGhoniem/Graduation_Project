 /******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the HC-SR04 Ultrasonic driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ULTRASONIC_TRIGGER_PORT_ID          PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID           PIN5_ID
#define ULTRASONIC_NUM_OF_DETECTED_EDGES    2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Function calculates the distance measured by the Ultrasonic sensor by:
 * 1. Clear all the variables from the previous read operation.
 * 2. Clear the ICU timer register
 * 3. Send the Trigger to the Ultrasonic by call Ultrasonic_Trigger function
 * 4. Wait for the measurements to be done by the ICU. We need two edges raising and falling.
 * 5. Calculate the distance in Centimeter value
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description :
 * Initialize the Ultrasonic driver by:
 * 1. Initialize the Trigger pin direction
 * 2. Initialize the ICU driver and Its Call back function.
 */
void Ultrasonic_init(void);

#endif /* ULTRASONIC_H_ */
