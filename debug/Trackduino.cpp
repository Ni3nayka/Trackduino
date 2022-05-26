/*
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
 */

 /*
#include "using_motor.h"
//#include <filters/alfaBeta.h>
#pragma once

motor::motor(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0) {
  char dir = 0, pwm = 0;

  if      (a=="DIR") dir++;
  else if (a=="PWM") pwm++;
  else dir-=10;
  if      (b=="DIR") dir++;
  else if (b=="PWM") pwm++;
  else if (b!="")  dir-=10;
  if      (c=="DIR") dir++;
  else if (c=="PWM") pwm++;
  else if (c!="")  dir-=10;
  
  if (dir>0) {
    if      (dir==1 && pwm==0) _mode = 1;
    else if (dir==2 && pwm==0) _mode = 2;
    else if (dir==1 && pwm==1) _mode = 3;
    else if (dir==2 && pwm==1) _mode = 4;
    else _mode = 0; 
  }
  
  if (_mode>0) { 
    _pwm_pin = 0;
    _dir_1_pin = 0;
    _dir_2_pin = 0;

    if      (a=="DIR") _dir_1_pin = a_pin;
    else if (a=="PWM") _pwm_pin = a_pin;
    else dir-=10;
    if      (b=="DIR") if (_dir_1_pin==0) _dir_1_pin = b_pin; else _dir_2_pin = b_pin;
    else if (b=="PWM") _pwm_pin = b_pin;
    else dir-=10;
    if      (c=="DIR") _dir_2_pin = c_pin;
    else if (c=="PWM") _pwm_pin = c_pin;
    else dir-=10;

    pinMode(_dir_1_pin, OUTPUT);
    if (_dir_2_pin>0) pinMode(_dir_2_pin, OUTPUT);
  }
  else {
    _mode = 0;
    Serial.println("motor SetMode - ERROR!!!");
  }

  // константы
  _max_speed = 100;
}

void motor::SetSpeed(int predel) {
  if (predel<1) Serial.println("ERROR: <SetSpeed> - invalid value");
  else _max_speed = predel; 
} 

int motor::TestMode() { return _mode; } 

void motor::run(int speed) {
  if (_mode==0) return;
  if (_mode==3 || _mode==4) analogWrite(_pwm_pin, map(constrain(abs(speed),0,_max_speed),0,_max_speed,0,255));
  digitalWrite(_dir_1_pin,speed>0);
  if (_mode==2 || _mode==4) digitalWrite(_dir_2_pin,speed<0);
}

void motor::stop() { motor::run(0); }

void motor::block() {
  if (_mode==3 || _mode==4) analogWrite(_pwm_pin, 0);
  if (_mode==2 || _mode==4) {
    digitalWrite(_dir_1_pin,1);
    digitalWrite(_dir_2_pin,1);
  }
  else {
    digitalWrite(_dir_1_pin,0);
  }
}*/
