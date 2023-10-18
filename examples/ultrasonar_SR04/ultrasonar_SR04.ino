/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  october 2023
 * modify: october 2023
 */

// подключаем библиотеку
#include <Trackduino.h>

// создаем объект для работы с ультразвуком
UltraSonicSR04 my_ultrasonic;

void setup() { 
  // инициализировать не обязательно в данном случае
  // Trackduino.setup();

  // инициализируем монитор порта
  Serial.begin(9600);

  // если датчик трехпиновый (объединен пин trig и echo)
  my_ultrasonic.setup(IN1);     // вариант 1
  my_ultrasonic.setup(IN1,IN1); // вариант 2

  // если датчик четырехпиновый (пины trig и echo не объединены)
  my_ultrasonic.setup(IN1,IN2); // (trig_pin, echo_pin) !!!

  // считываем значение с датчика и выводим в монитор порта
  Serial.println( my_ultrasonic.read() );
}

void loop () { 
  
}
