/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  june 2022
 * modify: september 2022
 */

#include "Trackduino_main.h"
#pragma once

TrackDuino::setup_motor() {
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(STBY[i], OUTPUT);
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(MOTOR_IN1[i], OUTPUT);
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(MOTOR_IN2[i], OUTPUT);
  for (int i = 0; i<COUNT_MOTOR; i++) pinMode(MOTOR_EN[i], OUTPUT);
}

TrackDuino::reverse_clear() {
  for (int i = 0; i<COUNT_MOTOR; i++) {
    _revers_motor[i] = 0;
  }
}

TrackDuino::reverse_motor(int n, bool dir) {
  if (n>COUNT_MOTOR || n<1) return;
  _revers_motor[n-1] = dir;
}

TrackDuino::motor_forward(int n) { 
  TrackDuino::motor(n,100);
}

TrackDuino::motor_backward(int n) { 
  TrackDuino::motor(n,-100);
}

TrackDuino::block_motor(int n) {
  if (n>COUNT_MOTOR || n<1) return;
  n--;
  digitalWrite(STBY[n],1);
  digitalWrite(MOTOR_EN[n],1);
  digitalWrite(MOTOR_IN1[n],1);
  digitalWrite(MOTOR_IN2[n],1);
}

TrackDuino::stop_motor(int n) {
  TrackDuino::motor(n, 0);
}

TrackDuino::motor(int n, int speed=0) {
  if (n>COUNT_MOTOR || n<1) return;
  n--;
  speed = map(constrain(speed,-100,100),0,100,0,255);
  //Serial.println(speed);
  analogWrite(STBY[n],abs(speed));
  digitalWrite(MOTOR_EN[n],speed!=0);
  digitalWrite(MOTOR_IN1[n],(speed>0)==_revers_motor[n]);
  digitalWrite(MOTOR_IN2[n],(speed<0)==_revers_motor[n]);
}
