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
  Trackduino.setup();

  // инициализировать только моторы
  // Trackduino.setup_motor();

  // проверить версию библиотеки
  // Serial.begin(9600);
  // Serial.println(TRACKDUINO_LIB_VERSION); 

  // для работы доступно 4 мотора: 1,2,3,4
  const int motor_number = 1;

  // настроить реверс мотора (изменить направление вращения)
  // Trackduino.reverse_motor(номер_мотора,включить_выключить_реверс);
  Trackduino.reverse_motor(1,false);           // по умолчанию
  Trackduino.reverse_motor(motor_number,true); // установить реверс
  Trackduino.reverse_clear();                  // удалить все настройки реверса

  // запускаем мотор вперед
  Trackduino.motor_forward(motor_number);  // вариант 1
  Trackduino.motor(motor_number,100);      // вариант 2
  delay(1000);                             // задержка
  // запускаем мотор назад
  Trackduino.motor_backward(motor_number); // вариант 1
  Trackduino.motor(motor_number,-100);     // вариант 2
  delay(1000);
  // останавливаем мотор
  Trackduino.stop_motor(motor_number);     // вариант 1
  Trackduino.motor(motor_number,0);        // вариант 2
  Trackduino.motor(motor_number);          // вариант 3
  delay(1000);
  // блокируем мотор (данная операцию не рекомендуется долго использовать, т.к. моторшилд будет перегреваться)
  Trackduino.block_motor(motor_number);
  delay(1000);
  
  // скорость мотора может быть задана в пределах [-100;100]
  // плавно управляем скоростью мотора от -100 до 100
  for (int i = -100; i <= 100; i++) {
    Trackduino.motor(motor_number,i);
    delay(30);
  }
  delay(1000);
  // останавливаем мотор
  Trackduino.stop_motor(motor_number);
  
}

void loop () { 
  
}
