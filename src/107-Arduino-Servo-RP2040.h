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
  static uint16_t constexpr DEFAULT_MIN_PULSE_WIDTH_us = 1000;
  static uint16_t constexpr DEFAULT_MAX_PULSE_WIDTH_us = 2000;


  Servo(uint16_t const min_pulse_width_us,
        uint16_t const max_pulse_width_us)
  : _min_pulse_width_us{min_pulse_width_us}
  , _max_pulse_width_us{max_pulse_width_us}
  , _is_attached{false}
  , _slice_num{0}
  , _channel{0}
  { }
  Servo() : Servo{DEFAULT_MIN_PULSE_WIDTH_us, DEFAULT_MAX_PULSE_WIDTH_us} { }


  void attach(pin_size_t const pin);
  void writeMicroseconds(uint16_t const pulse_width_us);

private:
  uint16_t const _min_pulse_width_us;
  uint16_t const _max_pulse_width_us;
  bool _is_attached;
  uint8_t _slice_num, _channel;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* _107_ */
