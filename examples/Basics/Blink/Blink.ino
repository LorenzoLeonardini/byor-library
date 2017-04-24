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
 * Default led pin: 13
 */

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
