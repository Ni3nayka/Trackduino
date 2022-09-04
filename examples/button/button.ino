/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  august 2022
 * modify: august 2022
 */

// подключаем библиотеку
#include <Trackduino.h>

void setup() { 
  // инициализируем
  Serial.begin(9600);
  Trackduino.setup();

  // инициализировать только кнопки
  // Trackduino.setup_BTN(); 
}

void loop () { 
  Serial.print(Trackduino.BTN_up());     // вывести значение с кнопки "вверх"
  Serial.print(" ");
  Serial.print(Trackduino.BTN_down());   // вывести значение с кнопки "вниз"
  Serial.print(" ");
  Serial.print(Trackduino.BTN_left());   // вывести значение с кнопки "лево"
  Serial.print(" ");
  Serial.print(Trackduino.BTN_right());  // вывести значение с кнопки "право"
  Serial.print(" ");
  Serial.print(Trackduino.BTN_center()); // вывести значение с кнопки "центр"
  Serial.println();
  delay(100);
}
