/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  june 2022
 * modify: august 2022
 */

#include "Trackduino_main.h"
#pragma once

TrackDuino::setup() {
  TrackDuino::setup_motor();
  TrackDuino::setup_RGB();
  TrackDuino::setup_BTN();
  TrackDuino::setup_IN_OUT_pins();
  // bluetooth
  // ...
}

TrackDuino::setup_IN_OUT_pins() {
  // OUT ports
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);
  // IN ports
  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
  pinMode(IN3, INPUT);
  pinMode(IN4, INPUT);
  pinMode(IN5, INPUT);
  pinMode(IN6, INPUT);
  pinMode(IN7, INPUT);
  pinMode(IN8, INPUT);
}
