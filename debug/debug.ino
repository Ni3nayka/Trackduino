/*
 * Integration the Trackduino to Arduino IDE
 * 
 * Bakay Egor, june 2022
 * https://github.com/Ni3nayka/Trackduino
 */


//#define Trackduino_SD_enable
#include "Trackduino.h"                               // подключаем библиотеку
TrackDuino Trackduino;

void setup() {                                         // установка
  Serial.begin(9600);                                  // открытие монитора порта
  Trackduino.setup();
  Trackduino.motor(3,100);
}

void loop () { 
  
}
