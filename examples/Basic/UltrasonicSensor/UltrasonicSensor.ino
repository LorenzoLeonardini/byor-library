/*
 * Distance in cm by default.
 */

#include "byor.h"

BYOR byor;

void setup()
{
	Serial.begin(9600);
	//byor.setUSMode(DIST_MM)	// uncomment for distance in mm
	//byor.setUSMode(DIST_INCHES)	// uncomment for distance in inches
}

void loop()
{
	Serial.println(byor.distance());
	delay(700);
}
