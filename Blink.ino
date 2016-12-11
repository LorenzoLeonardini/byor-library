#include "byor.h"

BYOR byor;

void setup()
{
	;
}

void loop()
{
	byor.led(HIGH);
	byor.delay_s(1);
	byor.led(LOW);
	byor.delay_s(1);
}