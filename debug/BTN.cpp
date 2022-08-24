/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  august 2022
 * modify: august 2022
 */

#include "Trackduino_main.h"
#pragma once

TrackDuino::BTN_up()     { return !digitalRead(BTN_UP); }
TrackDuino::BTN_down()   { return !digitalRead(BTN_DOWN); }
TrackDuino::BTN_left()   { return !digitalRead(BTN_LEFT); }
TrackDuino::BTN_right()  { return !digitalRead(BTN_RIGHT); }
TrackDuino::BTN_center() { return !digitalRead(BTN_CENTER); }

  
