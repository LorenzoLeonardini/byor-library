#include "byor.h"
#include "pitches.h"

#define QUARTER	500		// quarter duration

BYOR byor;

// notes in the melody
int notes[] = {NOTE_E6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6};

void setup()
{
	;
}

void loop()
{
	for(int i = 0; i < 8; i++)
	{
	   byor.buzzer(notes[i], QUARTER);
	   delay(100);
	}
	byor.buzzer(NOTE_C6, QUARTER*2);
	delay(100);
}