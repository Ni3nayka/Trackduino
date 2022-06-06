/*
 * Integration the Trackduino to Arduino IDE
 * 
 * Bakay Egor, june 2022
 * https://github.com/Ni3nayka/Trackduino
 */


//#define Trackduino_SD_enable
#include "Trackduino.h"
TrackDuino Trackduino;

void setup() { 
  Serial.begin(9600); 
  Trackduino.setup();
  /*for (int i = -100; i<=150; i++) {
    Trackduino.motor(3,i);
    delay(10);
  }
  Trackduino.stop_motor(3);*/
  Trackduino.RGB(0,0,100);
  delay(1000);
  Trackduino.RGB(0,0,50);
  delay(1000);
  Trackduino.RGB_off();
}

void loop () { 
  
}
