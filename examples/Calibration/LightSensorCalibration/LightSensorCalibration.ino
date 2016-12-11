/*
 * If you want to use percentage mode, you have to set
 * two parameters in byor library header file.
 * This sketch will calculate for you, just copy and paste!
 *
 * When this code will run, you have to darken LDR to a minimum
 * and then exhibit the sensor at maximum brightness.
 */

#include "byor.h"

BYOR byor;

#define SERIAL_SPEED	9600
#define SAMPLES			10000

int minValue = 1023;
int maxValue = 0;
int sample;
unsigned long time;

void setup()
{
	Serial.begin(SERIAL_SPEED);
	Serial.println("It will take few seconds.");
	byor.setLightSensorMode(RAW);
	time = millis();



	for(int i = 0; i < SAMPLES; i++)
	{
		sample = byor.light();
		if(sample < minValue)
			minValue = sample;
		else if(sample > maxValue)
			maxValue = sample;
		delay(2);
	}

	time = (millis() - time)/1000;
	Serial.print("Sampling ended in: ");
	Serial.print(time);
	Serial.println(" seconds.");
	Serial.print("Min value: "); Serial.println(minValue);
	Serial.print("Max value: "); Serial.println(maxValue);
	
	Serial.print("\nLIGHT_MIN_VAL: ");
	Serial.println(minValue);
	Serial.print("LIGHT_CONSTANT: ");
	float costant = 100.0/(maxValue-minValue);
	Serial.println(costant);

	Serial.println("\nCopy and paste these two values in byor.h file.");
}

void loop()
{
	;
}
