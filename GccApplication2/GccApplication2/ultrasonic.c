 /******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the HC-SR04 Ultrasonic driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/


#include "ultrasonic.h"
#include "gpio.h"
#include "icu.h"
#include <util/delay.h> /* For the delay functions */

static uint8 g_edgeCount = 0;
static uint16 g_timeHigh = 0;
static uint8 g_distance = 0;

/*
 * Description :
 * Call-Back Function used to calculate g_timeHigh for the Ultrasonic pulse
 */
static void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Icu_clearTimerValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Icu_getInputCaptureValue();
		/* Detect rising edge */
		Icu_setEdgeDetectionType(RISING);
	}
}

/*
 * Description :
 * Function send trigger pulse for Ultrasonic sensor to start measurements
 */
static void Ultrasonic_Trigger(void)
{
	/* Send the Trigger pulse */
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_LOW);
}

/*
 * Description :
 * Initialize the Ultrasonic driver by:
 * 1. Initialize the Trigger pin direction
 * 2. Initialize the ICU driver and Its Call back function.
 */
void Ultrasonic_init(void)
{
	/* Create configuration structure for ICU driver */
	Icu_ConfigType Icu_Config = {F_CPU_8,RISING};

	/* Configure the Trigger pin as output */
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);

	/* Initialize the ICU Driver */
	Icu_init(&Icu_Config);

	/* Set the Call back function pointer in the ICU driver */
	Icu_setCallBack(Ultrasonic_edgeProcessing);
}

/*
 * Description :
 * Function calculates the distance measured by the Ultrasonic sensor by:
 * 1. Clear all the variables from the previous read operation.
 * 2. Clear the ICU timer register
 * 3. Send the Trigger to the Ultrasonic by call Ultrasonic_Trigger function
 * 4. Wait for the measurements to be done by the ICU. We need two edges raising and falling.
 * 5. Calculate the distance in Centimeter value.
 */
uint16 Ultrasonic_readDistance(void)
{
	/* Clear all variables as they may have values from previous read operation */
	g_distance = 0;
	g_edgeCount = 0;
	g_timeHigh = 0;

	/* Clear the timer counter register to start measurements once trigger is sent */
	Icu_clearTimerValue();

	/* Send the trigger to activate the Ultra-sonic sensor (Start measurements) */
	Ultrasonic_Trigger();

	/* Wait until the ICU measures the pulse in the ECHO pin */
	while(g_edgeCount != ULTRASONIC_NUM_OF_DETECTED_EDGES);

	/* Calculate the distance in Centimeter value */
	g_distance = g_timeHigh / 58;

	return g_distance;
}
