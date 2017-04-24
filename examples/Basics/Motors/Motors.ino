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
 */

#include "byor.h"

BYOR byor;

void setup()
{
	//byor.reverseMotorL();		// uncomment if necessary
	//byor.reverseMotorR();		// uncomment if necessary
}

void loop()
{
	// move forward
	byor.move(75, 75);
	byor.delay_s(2.5);
	byor.stop();
	byor.delay_s(1);

	//move backward
	byor.move(-75, -75);
	byor.delay_s(2.5);
	byor.stop();
	byor.delay_s(1);

	//move left
	byor.move(55, 90);
	byor.delay_s(2.5);
	byor.stop();
	byor.delay_s(1);

	//move right
	byor.move(90, 55);
	byor.delay_s(2.5);
	byor.stop();
	byor.delay_s(1);
}
