/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  august 2022
 * modify: august 2022
 */

#include <Trackduino.h>

void setup() { 
  Serial.begin(9600);
  Trackduino.setup();

  // проверить версию библиотеки
  // Serial.println(TRACKDUINO_LIB_VERSION); 

  // для работы доступно 8 IN и OUT пинов: IN1..IN8, OUT1..OUT8
  // по умолчанию они все настроены pinMode(IN*, INPUT); и pinMode(OUT*, OUTPUT);
  // выводим в монитор порта показания IN1 порта
  Serial.println(analogRead(IN1));
  // запускаем OUT1 порт
  digitalWrite(OUT1,HIGH);
  
}

void loop () { 
  
}
