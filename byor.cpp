/*
byor.cpp    - Version 2.0
Library for BYOR robot
Created: 2 Dicember 2016
Last changes: 24 April 2017

Lorenzo Daidone
lorenzodaidone [at] yahoo [dot] it

Scuola di Robotica
www.scuoladirobotica.it
*/

#include "byor.h"

/****************************************/
/************SETUP ROUTINES**************/
/****************************************/

BYOR::BYOR()
{
	pinMode(L_MOTOR_1, OUTPUT);
	pinMode(L_MOTOR_2, OUTPUT);
	pinMode(L_MOTOR_E, OUTPUT);
	// all h-bridges command pins are set as output
	pinMode(R_MOTOR_1, OUTPUT);
	pinMode(R_MOTOR_2, OUTPUT);
	pinMode(R_MOTOR_E, OUTPUT);

	pinMode(BUZZER_PIN, OUTPUT);

	pinMode(BUTTON_1, INPUT);
	pinMode(BUTTON_2, INPUT);

	pinMode(US_ECHO, INPUT);
	pinMode(US_TRIGGER, OUTPUT);

	pinMode(LED_PIN, OUTPUT);

	setSamplesNo(DEFAULT_SAMPLES_NO);
}

void BYOR::setButton1Mode(bool mode)
{
	if (mode == 1)
		toggleButton1 = 1;  // toggled
	else
		toggleButton1 = 0;  // not toggled
}

void BYOR::setButton2Mode(bool mode)
{
	if (mode == 1)
		toggleButton2 = 1;  // toggled
	else
		toggleButton2 = 0;  // not toggled
}

void BYOR::setUSMode(char mode)
{
	if (mode == 0)
		usMode = 0;
	else if (mode == 1)
		usMode = 1;
	else if (mode == 3)
		usMode = 3;
	else
		usMode = 2;
}

void BYOR::setUSFilter(bool enabled)
{
	usFilter = enabled;
}

void BYOR::setSamplesNo(unsigned int samplesNo)
{
	samples = samplesNo;
}

void BYOR::setLightSensorMode(bool mode)    // light sensor result shown as raw or percentage
{
	if (mode == 1)
		lightSensorMode = 1;  // percentage mode
	else
		lightSensorMode = 0;  // raw mode (default)

}

void BYOR::reverseMotorL()
{
	leftMotorMode = !leftMotorMode;
}

void BYOR::reverseMotorR()
{
	rightMotorMode = !rightMotorMode;
}

/****************************************/
/**********READING ROUTINES**************/
/****************************************/

bool BYOR::button1(void)
{
	bool read = digitalRead(BUTTON_1);
	if (toggleButton1)
		read = !read;
	return read;
}

bool BYOR::button2(void)
{
	bool read = digitalRead(BUTTON_2);
	if (toggleButton2)
		read = !read;
	return read;
}

float BYOR::distance(void)
{
	float distanceUS;
	digitalWrite(US_TRIGGER, LOW);
	delayMicroseconds(2);
	digitalWrite(US_TRIGGER, HIGH);
	delayMicroseconds(10);
	digitalWrite(US_TRIGGER, LOW);
	distanceUS = pulseIn(US_ECHO, HIGH);

	if (usMode == DIST_CM)
		distanceUS /= 58.2;
	else if (usMode == DIST_MM)
		distanceUS /= 5.82;
	else if (usMode == DIST_INCHES)
		distanceUS /= 148;

	if (!usFilter)
		return distanceUS;

	if (usTemp[0] == -10)
	{
		usTemp[0] = distanceUS;
		return distanceUS;
	}
	if (usTemp[1] == -10)
	{
		usTemp[1] = distanceUS;
		return distanceUS;
	}
	if (usTemp[2] == -10)
	{
		usTemp[2] = distanceUS;
		return distanceUS;
	}
	if (usTemp[3] == -10)
	{
		usTemp[3] = distanceUS;
		return distanceUS;
	}
	if (usTemp[4] == -10)
	{
		usTemp[4] = distanceUS;
		return distanceUS;
	}
	if (usTemp[5] == -10)
	{
		usTemp[5] = distanceUS;
	}
	else
	{
		usTemp[0] = usTemp[1];
		usTemp[1] = usTemp[2];
		usTemp[2] = usTemp[3];
		usTemp[3] = usTemp[4];
		usTemp[4] = usTemp[5];
		usTemp[5] = distanceUS;
	}

	float maxUS = 0, minUS = 100000000000;

	for (int i = 0; i < 6; i++)
	{
		if (usTemp[i] > maxUS)
			maxUS = usTemp[i];
		if (usTemp[i] < minUS)
			minUS = usTemp[i];
	}

	float filtered = (usTemp[0] + usTemp[1] + usTemp[2] + usTemp[3] + usTemp[4] + usTemp[5] - minUS - maxUS) / 4;

	return filtered;
}

int BYOR::light(void)
{
	float lightValue = 0;

	for (unsigned int i = 0; i < samples; i++)
	{
		lightValue += analogRead(LIGHTSENSORPIN);
	}
	lightValue /= samples;

	if (lightSensorMode) //  percentage mode
	{
		lightValue = (lightValue*100.) / 1024.;
	}

	return (int)(lightValue); // defaul returns a raw read
}

/****************************************/
/************WRITING ROUTINES************/
/****************************************/

inline void BYOR::led(bool state)
{
	digitalWrite(LED_PIN, state);
}


void BYOR::move(int left_speed, int right_speed)
{
	left_speed = SpeedCheck(left_speed); // speed is in range -100, 100 ?
	right_speed = SpeedCheck(right_speed); // speed is in range -100, 100 ?

	if (leftMotorMode) // check reverseMotorL
		left_speed *= -1;
	if (rightMotorMode) // check reverseMotorR
		right_speed *= -1;

	if (left_speed >= 0)   // left motor forward
	{
		analogWrite(L_MOTOR_1, left_speed*2.55);
		digitalWrite(L_MOTOR_2, LOW);
	}
	else          // left motor backward
	{
		digitalWrite(L_MOTOR_1, LOW);
		analogWrite(L_MOTOR_2, (-left_speed)*2.55);
	}

	if (right_speed >= 0)  // right motor forward
	{
		analogWrite(R_MOTOR_1, right_speed*2.55);
		digitalWrite(R_MOTOR_2, LOW);
	}
	else          // right motor backward
	{
		digitalWrite(R_MOTOR_1, LOW);
		analogWrite(R_MOTOR_2, (-right_speed)*2.55);
	}

	digitalWrite(L_MOTOR_E, HIGH);
	digitalWrite(R_MOTOR_E, HIGH);
}

inline void BYOR::stop(void)
{
	digitalWrite(L_MOTOR_1, LOW);
	digitalWrite(L_MOTOR_2, LOW);
	digitalWrite(R_MOTOR_1, LOW);
	digitalWrite(R_MOTOR_2, LOW);
	digitalWrite(L_MOTOR_E, LOW);
	digitalWrite(R_MOTOR_E, LOW);
}

inline void BYOR::buzzer(unsigned int note, float duration_s)
{
	tone(BUZZER_PIN, note);
	delay_s(duration_s);
	noTone(BUZZER_PIN); // stop sound
}

/****************************************/
/*************OTHER ROUTINES*************/
/****************************************/

inline int BYOR::SpeedCheck(int speed)
{
	if (speed > 100)
		speed = 100;
	else if (speed < -100)
		speed = -100;

	return speed;
}
