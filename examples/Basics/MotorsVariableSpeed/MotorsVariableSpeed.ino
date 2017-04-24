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
 * This sketch allows BYOR to go forward and backward
 * just using reverseMotor functions instead of a
 * negative parameter
 */

#include "byor.h"

#define DELAY_INC	0.05

BYOR byor;

void setup()
{
	;
}

void loop()
{
	int i;

	for (i = 20; i <= 100; i++)
	{
		byor.move(i, i);
		byor.delay_s(DELAY_INC);
	}

	byor.delay_s(2);

	byor.reverseMotorL();
	byor.reverseMotorR();
}
