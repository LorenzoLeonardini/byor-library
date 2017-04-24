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
 * Default button pin: 8
 * Button requires a pull-down resistor.
 * If you place a pull-up resistor, uncomment setup line.
 */

#include "byor.h"

BYOR byor;

void setup()
{
	//byor.setButton1Mode(TOGGLE); // toggle button read
}

void loop()
{
	if(byor.button1())
		Serial.println("Pressed");
	else
		Serial.println("Not pressed");

	byor.delay_s(1);
}
