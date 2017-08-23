/*
 * Lorenzo Daidone
 * lorenzodaidone [at] yahoo [dot] it
 * 
 * Scuola di Robotica
 * www.scuoladirobotica.it
 * 
 * Created: 24 April 2017
 * Last changes: 24 April 2017
 * 
 * Distance in cm by default.
 */

#include "byor.h"

BYOR byor;

void setup()
{
	Serial.begin(9600);
	//byor.setUSMode(DIST_MM)	// uncomment for distance in mm
	//byor.setUSMode(DIST_INCHES)	// uncomment for distance in inches
  //byor.setUSFilter(true) //uncomment to use the built in filter
}

void loop()
{
	Serial.println(byor.distance());
	delay(700);
}
