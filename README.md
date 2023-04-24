<a href="https://107-systems.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/107-systems.png" width="15%"></a>
:floppy_disk: `107-Arduino-Servo-RP2040`
========================================
<a href="https://opencyphal.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/opencyphal.svg" width="25%"></a>
[![Arduino Library Badge](https://www.ardu-badge.com/badge/107-Arduino-Servo-RP2040.svg?)](https://www.ardu-badge.com/107-Arduino-Servo-RP2040)
[![Compile Examples](https://github.com/107-systems/107-Arduino-Servo-RP2040/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-Servo-RP2040/actions?workflow=Compile+Examples)
[![Arduino Lint](https://github.com/107-systems/107-Arduino-Servo-RP2040/workflows/Arduino%20Lint/badge.svg)](https://github.com/107-systems/107-Arduino-Servo-RP2040/actions?workflow=Arduino+Lint)
[![keywords.txt Checks](https://github.com/107-systems/107-Arduino-Servo-RP2040/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Servo-RP2040/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-Servo-RP2040/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Servo-RP2040/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-Servo-RP2040/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-Servo-RP2040/actions?workflow=Spell+Check)

This Arduino library provides Hardware-PWM based servo signal generation for the RP2040 if more than 8 servo channels are needed. Otherwise, the servo library shipped with [arduino-pico](https://github.com/earlephilhower/arduino-pico) is the better choice, as it uses [PIO](https://en.wikipedia.org/wiki/Programmed_input%E2%80%93output) and therefore does not consume CPU resources.

<p align="center">
  <a href="https://github.com/107-systems/l3xz"><img src="https://raw.githubusercontent.com/107-systems/.github/main/logo/l3xz-logo-memento-mori-github.png" width="30%"></a>
</p>

This library works for
* [arduino-pico](https://github.com/earlephilhower/arduino-pico): [`Raspberry Pi Pico`](https://www.raspberrypi.org/products/raspberry-pi-pico), `Adafruit Feather RP2040`, ... :heavy_check_mark:
