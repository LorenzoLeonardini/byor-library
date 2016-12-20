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
	byor.move(35, 75);
	byor.delay_s(2.5);
	byor.stop();
	byor.delay_s(1);

	//move right
	byor.move(75, 35);
	byor.delay_s(2.5);
	byor.stop();
	byor.delay_s(1);
}
