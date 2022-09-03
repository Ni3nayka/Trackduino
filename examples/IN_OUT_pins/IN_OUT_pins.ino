/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  august 2022
 * modify: september 2022
 */

// подключаем библиотеку
#include <Trackduino.h>

void setup() { 
  // инициализируем
  Serial.begin(9600);
  Trackduino.setup();

  // инициализировать только пины IN и OUT
  // Trackduino.setup_IN_OUT_pins();

  // проверить версию библиотеки
  // Serial.println(TRACKDUINO_LIB_VERSION); 

  // для работы доступно 8 IN и OUT пинов: IN1..IN8, OUT1..OUT8
  // по умолчанию они все настроены pinMode(IN*, INPUT); и pinMode(OUT*, OUTPUT);
  // выводим в монитор порта показания IN1 порта
  Serial.println(analogRead(IN1));
  // запускаем OUT1 порт
  digitalWrite(OUT1,HIGH);

  // также можно настроить пины на другой режим работы 
  // ВНИМАНИЕ: ШИМ есть только у OUT пинов, а у IN пинов только АЦП, не наоборот!
  pinMode(IN2,OUTPUT);
  digitalWrite(IN2,1);
  pinMode(OUT2,INPUT);
  Serial.println(digitalRead(OUT2));
}

void loop () { 
  
}
