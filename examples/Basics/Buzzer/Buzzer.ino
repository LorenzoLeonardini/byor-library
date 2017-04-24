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
 * Default buzzer pin: 9
 */

#include "byor.h"
#include "pitches.h"

#define QUARTER	0.5		// quarter duration [seconds]

BYOR byor;

// notes in the melody
int notes[] = {NOTE_E7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_G7, NOTE_F7, NOTE_E7, NOTE_D7};

void setup()
{
	;
}

void loop()
{
	for(int i = 0; i < 8; i++)
	{
	   byor.buzzer(notes[i], QUARTER);
	   byor.delay_s(0.1); // wait 100 ms
	}
	byor.buzzer(NOTE_C6, QUARTER*2);
	byor.delay_s(2.5); // wait 2500 ms
}
