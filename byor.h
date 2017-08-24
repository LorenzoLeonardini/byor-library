/*
byor.cpp    - Version 2.0
Library for BYOR robot
Created: 2 December 2016
Last changes: 23 August 2017

Lorenzo Daidone
lorenzodaidone [at] yahoo [dot] it

Scuola di Robotica
www.scuoladirobotica.it
*/

#ifndef BYOR_h
#define BYOR_h

#include "Arduino.h"

#define LED_PIN    13   // led pin
#define L_MOTOR_1  11     // first direction pin (left motor)
#define L_MOTOR_2  10     // second direction pin (left motor)
#define L_MOTOR_E  12     // enable pin (left motor)

#define BUZZER_PIN  9

#define BUTTON_1  8

#define US_ECHO   7
#define US_TRIGGER  6

#define R_MOTOR_1 5       // first direction pin (right motor)
#define R_MOTOR_2 3       // second direction pin (right motor)
#define R_MOTOR_E 4       // enable pin (right motor)
#define BUTTON_2  2

#define LIGHTSENSORPIN  0
#define DEFAULT_SAMPLES_NO 20u

#define TOGGLED   1
#define NORMAL    0

#define DIST_INCHES 3
#define DIST_RAW  2
#define DIST_MM   1
#define DIST_CM   0

#define PERCENTAGE  1
#define RAW     0


class BYOR
{
public:

	BYOR();

	/* SETUP ROUTINES */
	void setButton1Mode(bool mode);
	void setButton2Mode(bool mode);
	void setUSMode(char mode);
	void setUSFilter(bool enabled);
	void setSamplesNo(unsigned int samplesNo);
	void setLightSensorMode(bool mode);
	void reverseMotorL();
	void reverseMotorR();

	/* READING ROUTINES */
	bool button1(void);
	bool button2(void);
	float distance(void);
	inline unsigned int getSamplesNo(void) const { return samples; };
	int light(void);

	/* WRITING ROUTINES */
	inline void led(bool state);
	void move(int left_speed, int right_speed);
	inline void stop(void);
	inline void buzzer(unsigned int note, float duration_s);

	/* OTHER ROUTINES */
	inline void delay_s(float seconds) const { delay((unsigned long)(seconds * 1000)); };

private:
	bool toggleButton1 = 0;
	bool toggleButton2 = 0;
	char usMode = 0;
	bool usFilter = 0;
	float usTemp[6] = { -10, -10, -10, -10, -10, -10 };
	bool lightSensorMode = 0;
	bool leftMotorMode = 0;
	bool rightMotorMode = 0;
	unsigned int samples = 0;

	inline int SpeedCheck(int speed);
};

#endif
