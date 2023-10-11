/***************************************************
 *  Module : gpio.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef GPIO_H_
#define GPIO_H_


#include "std_types.h"

/*******************************************************************************
 *****************                Definitions             *********************/


#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7


#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

/******************************************************************************
 *****************            Type declaration          **********************/

typedef enum{
	PIN_INPUT, PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum{
	PORT_INPUT, PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/******************************************************************************
 *****************           function prototypes        **********************/

/* Description :
 * this function used to setup the direction of the required pin
 * if the pin or port number is not correct, the function will do nothing
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/* Description :
 * this function is used to write value to the required pin
 * write the value logic high or low
 * if this pin is input , this function will enable/disable the internal pull-up resistor
 * if the pin or port number is not correct, the function will do nothing
 * */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/* Description :
 * this function is used to read value to the required pin
 * it return logic high or low
 * if the pin or port number is not correct, the function will do nothing
 * */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/* Description :
 * this function used to setup the direction of the required port
 * if the port number is not correct, the function will do nothing
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);
/* Description :
 * this function used to write value of the required port
 * if this port is input , this function will enable/disable the internal pull-up resistor
 * if the port number is not correct, the function will do nothing
 */

void GPIO_writePort(uint8 port_num, uint8 value);
/* Description :
 * this function used to read value of the required port
 * it return logic high or low
 * if this port is input , this function will enable/disable the internal pull-up resistor
 * if the port number is not correct, the function will do nothing
 */
uint8 GPIO_readPort(uint8 port_num);



#endif /* GPIO_H_ */
