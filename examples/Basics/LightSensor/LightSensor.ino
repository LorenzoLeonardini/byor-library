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
		Serial.print("Very bright");
	else if(light > 45)
		Serial.print("Half-light");
	else
		Serial.print("Dark");
	
	Serial.print("\t"); Serial.println(light);

	byor.delay_s(1);
}
