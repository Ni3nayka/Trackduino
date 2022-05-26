/*
 * Integration the Trackduino to Arduino IDE
 * 
 * Bakay Egor, may 2022
 * https://github.com/Ni3nayka/Trackduino
 */


//#define Trackduino_SD_enable
#include "Trackduino.h"                               // подключаем библиотеку


void setup() {                                         // установка
  Serial.begin(9600);                                  // открытие монитора порта
  Serial.println(trackduino.qwerty);
}

void loop () {                                         // тело основного цикла (в котором мы ничего не делаем)
  
}
