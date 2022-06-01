/*
 * Integration the Trackduino to Arduino IDE
 * 
 * Bakay Egor, june 2022
 * https://github.com/Ni3nayka/Trackduino
 */

#include "Trackduino.h"
#pragma once

TrackDuino::setup() {
  // motor
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(STBY[i], OUTPUT);
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(MOTOR_IN1[i], OUTPUT);
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(MOTOR_IN2[i], OUTPUT);
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(MOTOR_EN[i], OUTPUT);
  // RGB
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  // button
  pinMode(BTN_DOWN, INPUT);
  pinMode(BTN_RIGHT, INPUT);
  pinMode(BTN_LEFT, INPUT);
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_CENTER, INPUT);
  // OUT ports
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);
  // bluetooth
  // ...
}
