/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Servo-RP2040/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <107-Arduino-Servo-RP2040.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static _107_::Servo servo_0, servo_1, servo_2, servo_3;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(115200);
  while (!Serial) { }

  servo_0.attach(12);
  servo_1.attach(13);
  servo_2.attach(14);
  servo_3.attach(15);

  servo_0.writeMicroseconds(1000);
  servo_1.writeMicroseconds(1250);
  servo_2.writeMicroseconds(1750);
  servo_3.writeMicroseconds(2000);
}

void loop()
{

}
