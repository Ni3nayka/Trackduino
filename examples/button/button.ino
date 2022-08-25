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

  // инициализировать только кнопки
  // Trackduino.setup_BTN();

  // проверить версию библиотеки
  // Serial.println(TRACKDUINO_LIB_VERSION); 
}

void loop () { 
  Serial.print(Trackduino.BTN_up());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_down());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_left());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_right());
  Serial.print(" ");
  Serial.print(Trackduino.BTN_center()); 
  Serial.println();
  delay(100);
}
