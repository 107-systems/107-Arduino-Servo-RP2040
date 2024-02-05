/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Servo-RP2040/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdint>

#include <Arduino.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace _107_
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Servo
{
public:
  static uint16_t constexpr DEFAULT_MIN_PULSE_WIDTH_us     = 1000;
  static uint16_t constexpr DEFAULT_MAX_PULSE_WIDTH_us     = 2000;
  static uint16_t constexpr DEFAULT_NEUTRAL_PULSE_WIDTH_us = 1500;
  static int constexpr DEFAULT_MAX_ANGLE                   = 180;

  static uint16_t constexpr PWM_PERIOD_us = 20*1000UL;

  Servo()
  : _min_pulse_width_us{DEFAULT_MIN_PULSE_WIDTH_us}
  , _max_pulse_width_us{DEFAULT_MAX_PULSE_WIDTH_us}
  , _neutral_pulse_width_us{DEFAULT_NEUTRAL_PULSE_WIDTH_us}
  , _max_angle{DEFAULT_MAX_ANGLE}
  , _is_attached{false}
  , _slice_num{0}
  , _channel{0}
  { }

  void attach(pin_size_t const pin);
  void attach(pin_size_t const pin, uint16_t min_pulse_width_us, uint16_t max_pulse_width_us);
  void setMaxAngle(int const max_angle);
  void writeMicroseconds(uint16_t const pulse_width_us);
  void write(int const value);
  void writeAngle(int const angle);

private:
  uint16_t _min_pulse_width_us, _max_pulse_width_us, _neutral_pulse_width_us;
  int _max_angle;
  bool _is_attached;
  uint8_t _slice_num, _channel;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* _107_ */
