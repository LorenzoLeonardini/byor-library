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
 * Sensor: QRE1113 (Analog) by Sparkfun
 */

#include "byor.h"

#define SERIAL_SPEED  9600  // baud rate
#define LIGHT_THRESHOLD 70  // percentage threshold

BYOR byor;

void setup()
{
  Serial.begin(SERIAL_SPEED);
  byor.setLightSensorMode(PERCENTAGE); // comment for a raw reading
  //byor.setSamplesNo(200); // uncomment if necessary
}

void loop()
{
  int light = byor.light(); // read light [%]

  if(light > LIGHT_THRESHOLD)
    Serial.print("Black");
  else
    Serial.print("White");

  Serial.print("\t"); Serial.println(light);

  byor.delay_s(0.01); // wait 10 ms
}
