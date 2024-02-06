/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Servo-RP2040/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "107-Arduino-Servo-RP2040.h"

#include "pico/stdlib.h"
#include "hardware/pwm.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace _107_
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void Servo::attach(pin_size_t const pin)
{
  attach(pin, DEFAULT_MIN_PULSE_WIDTH_us, DEFAULT_MAX_PULSE_WIDTH_us);
}

void Servo::attach(pin_size_t const pin, uint16_t const min_pulse_width_us, uint16_t const max_pulse_width_us)
{
  if (_is_attached)
    return;

  _min_pulse_width_us = min_pulse_width_us;
  _max_pulse_width_us = max_pulse_width_us;

  _slice_num = pwm_gpio_to_slice_num(pin);
  _channel = pwm_gpio_to_channel(pin);

  uint32_t const SYS_CLK_hz = clock_get_hz(clk_sys);
  uint32_t const PWM_CLK_hz = 1*1000*1000UL;
  float const clk_divider = static_cast<float>(SYS_CLK_hz) / static_cast<float>(PWM_CLK_hz);

  /* Set system clock to 1 MHz. This is a time increment of 1 us. */
  pwm_set_clkdiv(_slice_num, clk_divider);
  /* Set system period to 20 ms. */
  pwm_set_wrap(_slice_num, PWM_PERIOD_us);
  /* Set initial output value to 1.5 ms. */
  pwm_set_chan_level(_slice_num, _channel, _neutral_pulse_width_us);
  /* Enable PWM. */
  pwm_set_enabled(_slice_num, true);

  /* Configure GPIO for output. */
  gpio_set_function(pin, GPIO_FUNC_PWM);

  _is_attached = true;
}

void Servo::setMaxAngle(int const max_angle)
{
  _max_angle = max_angle;
}

void Servo::writeMicroseconds(uint16_t const pulse_width_us)
{
  if (!_is_attached)
    return;

  if (pulse_width_us < _min_pulse_width_us)
    return;

  if (pulse_width_us > _max_pulse_width_us)
    return;

  pwm_set_chan_level(_slice_num, _channel, pulse_width_us);
}

void Servo::write(int const value)
{
  if (!_is_attached)
    return;

  int clamped = value;
  clamped = max(0, clamped);
  clamped = min(180, clamped);

  uint16_t const pulse_width_us = map(clamped, 0, 180, _min_pulse_width_us, _max_pulse_width_us);
  writeMicroseconds(pulse_width_us);
}

void Servo::writeAngle(int const angle)
{
  if (!_is_attached)
    return;

  int clamped = angle;
  clamped = max(0, clamped);
  clamped = min(_max_angle, clamped);

  uint16_t const pulse_width_us = map(clamped, 0, _max_angle, _min_pulse_width_us, _max_pulse_width_us);
  writeMicroseconds(pulse_width_us);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* _107_ */
