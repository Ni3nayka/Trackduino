/*
 * Integration the Trackduino to Arduino IDE
 * 
 * Bakay Egor, june 2022
 * https://github.com/Ni3nayka/Trackduino
 */

#include "Trackduino.h"
#pragma once

TrackDuino::RGB(bool r=0, bool g=0, bool b=0) {
  /*r = map(constrain(r,-100,100),0,100,0,255);
  g = map(constrain(g,-100,100),0,100,0,255);
  b = map(constrain(b,-100,100),0,100,0,255);
  analogWrite(RGB_RED, r);
  analogWrite(RGB_GREEN, g);
  analogWrite(RGB_BLUE, b);*/
  digitalWrite(RGB_RED, r);
  digitalWrite(RGB_GREEN, g);
  digitalWrite(RGB_BLUE, b);
}

TrackDuino::RGB_color(String color="OFF") {
  if      (color=="OFF")       TrackDuino::RGB(0,0,0);
  else if (color=="RED")       TrackDuino::RGB(100,0,0);
  else if (color=="GREEN")     TrackDuino::RGB(0,100,0);
  else if (color=="BLUE")      TrackDuino::RGB(0,0,100);
  else if (color=="WHITE")     TrackDuino::RGB(100,100,100);
  else if (color=="YELLOW")    TrackDuino::RGB(100,100,0);
  else if (color=="PURPLE")    TrackDuino::RGB(100,0,100);
  else if (color=="TURQUOISE") TrackDuino::RGB(0,100,100);
}

TrackDuino::RGB_red() {
  TrackDuino::RGB(100,0,0);
}

TrackDuino::RGB_green() {
  TrackDuino::RGB(0,100,0);
}

TrackDuino::RGB_blue() {
  TrackDuino::RGB(0,0,100);
}

TrackDuino::RGB_white() {
  TrackDuino::RGB(100,100,100);
}

TrackDuino::RGB_off() {
  TrackDuino::RGB(0,0,0);
}
