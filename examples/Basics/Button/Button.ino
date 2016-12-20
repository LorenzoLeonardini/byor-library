/*
 * Button requires a pull-down resistor.
 * If you place a pull-up resistor, uncomment setup line.
 */

#include "byor.h"

BYOR byor;

void setup()
{
	//byor.setButton1Mode(TOGGLED); // toggle button read
}

void loop()
{
	if(byor.button1())
		Serial.println("Pressed");
	else
		Serial.println("Not pressed");

	byor.delay_s(1);
}
