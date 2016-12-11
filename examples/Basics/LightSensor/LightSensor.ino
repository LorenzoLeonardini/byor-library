/*
 * Before run this sketch you have to set two
 * parameters in byor.h file.
 * Run first "LightSensorCalibration.ino" file
 * in examples/Advanced/LightSensorCalibration
 * and then copy and paste values.
 */

#include "byor.h"

#define SERIAL_SPEED	9600	// baud rate

BYOR byor;

void setup()
{
	Serial.begin(SERIAL_SPEED);
	byor.setLightSensorMode(PERCENTAGE);
}

void loop()
{
	int light = byor.light();	// read light [%]

	if(light > 70)
		Serial.println("Very bright");
	else if(light > 45)
		Serial.println("Half-light");
	else
		Serial.println("Dark");

	byor.delay_s(1);
}
