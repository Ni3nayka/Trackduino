/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  september 2022
 * modify: september 2022
 */

// подключаем библиотеку
#include "Trackduino.h"

// создаем объект для блютуза (для управления трекдуино через официальное приложение для телефона)
// https://robotrack-rus.ru/wiki/doku.php/po/robotrek_pdu
Bluetooth bluetooth;

/*
 * Краткий Гайд по bluetooth у трекдуино:
 * bluetooth и "USB" у трекдуино подключены к одному и тому же UART, из за чего
 * в один момент пользоваться можно только одним! из этих устройств, т.е.
 * если у вас подключен USB кабель трекдуино не будет принимать данные с bluetooth
 * Стандартный пароль от bluetooth: 1234 или 0000
 * Стандартное название bluetooth: TD_xxxx (где xxxx - четырехзначное число)
 */

void setup() { 
  Trackduino.setup(); // инициализируем трекдуино
  bluetooth.setup();  // инициализируем блютуз
  
  // проверить версию библиотеки
  // Serial.begin(9600);
  // Serial.println(TRACKDUINO_LIB_VERSION); 
}

void loop () { 
  // обновить блютуз
  bluetooth.update();

  int X = bluetooth.x;   // взять данные с джойстика, по оси X
  Trackduino.motor(1,X); // запустить мотор 1 с полученной скоростью X

  if (bluetooth.f1) {      // если кнопка f1 нажата
    Trackduino.RGB_blue(); // включить синий
  }
  else {
    Trackduino.RGB_off();  // выключить светодиод
  }

  
  /*
   * bluetooth.x - взять данные с джойстика, по оси X [-100;100]
   * bluetooth.y - взять данные с джойстика, по оси Y [-100;100]
   * bluetooth.z - взять данные с джойстика, по оси Z [-100;100]
   * bluetooth.w - взять данные с джойстика, по оси W [-100;100]
   * bluetooth.ax - взять данные с акселерометра, по оси X [-100;100]
   * bluetooth.ay - взять данные с акселерометра, по оси Y [-100;100]
   * bluetooth.az - взять данные с акселерометра, по оси Z [-100;100]
   * bluetooth.f1 - состояние кнопки f1 [0;1]
   * bluetooth.f2 - состояние кнопки f2 [0;1]
   * bluetooth.f3 - состояние кнопки f3 [0;1]
   * bluetooth.f4 - состояние кнопки f4 [0;1]
   * bluetooth.f5 - состояние кнопки f5 [0;1]
   * bluetooth.f6 - состояние кнопки f6 [0;1]
   */
}
