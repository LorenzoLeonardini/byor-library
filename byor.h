/*
	byor.cpp 		- Version 0.9 beta
	Library for BYOR robot
	Created: 2 December 2016
	Last changes: 11 December 2016

	Lorenzo Daidone
	Scuola di Robotica
	www.scuoladirobotica.it
*/

#ifndef BYOR_h
#define BYOR_h

#include "Arduino.h"

////////////////////////////////////////
//USER CAN CHANGE THESE TWO PARAMETERS//
//////////SEE DOCUMENTATION/////////////
#define LIGHT_CONSTANT	1
#define LIGHT_MIN_VAL	0
/////////////////END////////////////////
////////////////////////////////////////

#define LED_PIN	   13		// led pin
#define L_MOTOR_1  12    	// first direction pin (left motor)
#define L_MOTOR_2  11    	// second direction pin (left motor)
#define L_MOTOR_E  10    	// enable pin (left motor)

#define BUZZER_PIN	9

#define BUTTON_1	8

#define US_ECHO		7
#define US_TRIGGER	6

#define R_MOTOR_1	5     	// first direction pin (right motor)
#define R_MOTOR_2	4     	// second direction pin (right motor)
#define R_MOTOR_E	3     	// enable pin (right motor)
#define BUTTON_2	2

#define LIGHTSENSORPIN	0

#define	TOGGLED		1
#define NORMAL		0

#define DIST_INCHES	3
#define DIST_RAW	2
#define DIST_MM		1
#define DIST_CM		0

#define PERCENTAGE	1
#define	RAW			0


class BYOR
{
	public:

		BYOR();

		/* SETUP ROUTINES */
		void setButton1Mode(bool mode);
		void setButton2Mode(bool mode);
		void setUSMode(char mode);
		void setLightSensorMode(bool mode);
		void reverseMotorL();
		void reverseMotorR();

		/* READING ROUTINES */
		bool button1(void);
		bool button2(void);
		float distance(void);
		int light(void);

		/* WRITING ROUTINES */
		void led(bool state);
		void move(int left_speed, int right_speed);
		void stop(void);
		void buzzer(unsigned int note, unsigned long duration_ms);

		/* OTHER ROUTINES */
		void delay_s(float seconds);

	private:
		bool toggleButton1 = 0;
		bool toggleButton2 = 0;
		char usMode = 0;
		bool lightSensorMode = 0;
		bool leftMotorMode = 0;
		bool rightMotorMode = 0;
};

#endif