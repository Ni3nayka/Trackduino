/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  june 2022
 * modify: august 2022
 */


//#define Trackduino_SD_enable
#include "Trackduino.h"

void setup() { 
  Serial.begin(9600); 
  Trackduino.setup();

  // motor
  /*int n = 1;
  Trackduino.motor(n,-100);
  delay(1000);
  for (int i = -100; i<=150; i++) {
    Trackduino.motor(n,i);
    delay(20);
  }
  Trackduino.motor(n,100);
  delay(1000);
  Trackduino.stop_motor(n);*/

  // RGB

  // BTN
  /*Serial.print(Trackduino.BTN_up());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_down());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_left());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_right());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_center()); 
  Serial.println();*/

  // bluetooth
  
}

void loop () { 
  
  
}
