/***************************************************
 *  Module : ir_sensor.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_


#include "std_types.h"
#include "gpio.h"
#include "common_macros.h"


#define IRSensorPORT_ID      PORTB_ID
#define IRSensorPin1_ID       PIN3_ID
#define IRSensorPin2_ID       PIN4_ID
#define IRSensorPPin          PINB


void IRSensor_init (void);
uint8 IR_Read1(void);
uint8 IR_Read2(void);

#endif /* IR_SENSOR_H_ */
