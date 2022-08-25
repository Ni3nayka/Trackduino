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

TrackDuino::setup_RGB() {
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
}

TrackDuino::RGB(bool r=0, bool g=0, bool b=0) {
  digitalWrite(RGB_RED, r);
  digitalWrite(RGB_GREEN, g);
  digitalWrite(RGB_BLUE, b);
}

TrackDuino::RGB_color(String color="OFF") {
  if      (color=="OFF")       TrackDuino::RGB(0,0,0);
  else if (color=="RED")       TrackDuino::RGB(1,0,0);
  else if (color=="GREEN")     TrackDuino::RGB(0,1,0);
  else if (color=="BLUE")      TrackDuino::RGB(0,0,1);
  else if (color=="WHITE")     TrackDuino::RGB(1,1,1);
  else if (color=="YELLOW")    TrackDuino::RGB(1,1,0);
  else if (color=="PURPLE")    TrackDuino::RGB(1,0,1);
  else if (color=="TURQUOISE") TrackDuino::RGB(0,1,1);
}

TrackDuino::RGB_red()       { TrackDuino::RGB(1,0,0); }
TrackDuino::RGB_green()     { TrackDuino::RGB(0,1,0); }
TrackDuino::RGB_blue()      { TrackDuino::RGB(0,0,1); }
TrackDuino::RGB_white()     { TrackDuino::RGB(1,1,1); }
TrackDuino::RGB_yellow()    { TrackDuino::RGB(1,1,0); }
TrackDuino::RGB_purple()    { TrackDuino::RGB(1,0,1); }
TrackDuino::RGB_turquoise() { TrackDuino::RGB(0,1,1); }
TrackDuino::RGB_off()       { TrackDuino::RGB(0,0,0); }

  
