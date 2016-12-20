/*
 *	This sketch allows BYOR to go forward and backward
 *	just using reverseMotor functions instead of a
 *	negative parameter.
 */

#include "byor.h"

#define RITARDO	0.05

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
		byor.delay_s(RITARDO);
	}

	byor.delay_s(2);

	byor.reverseMotorL();
	byor.reverseMotorR();
}
