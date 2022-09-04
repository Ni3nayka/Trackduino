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
  Trackduino.setup();

  // инициализировать только RGB
  // Trackduino.setup_RGB();
  
  // красный
  Trackduino.RGB_red();              // Вариант 1   
  Trackduino.RGB(1,0,0);             // Вариант 2
  Trackduino.RGB_color("RED");       // Вариант 3
  delay(1000);
  // зеленый
  Trackduino.RGB_green();            // Вариант 1    
  Trackduino.RGB(0,1,0);             // Вариант 2
  Trackduino.RGB_color("GREEN");     // Вариант 3
  delay(1000);
  // синий
  Trackduino.RGB_blue();             // Вариант 1      
  Trackduino.RGB(0,0,1);             // Вариант 2
  Trackduino.RGB_color("BLUE");      // Вариант 3
  delay(1000);
  // белый
  Trackduino.RGB_white();            // Вариант 1     
  Trackduino.RGB(1,1,1);             // Вариант 2
  Trackduino.RGB_color("WHITE");     // Вариант 3
  delay(1000);
  // желтый
  Trackduino.RGB_yellow();           // Вариант 1    
  Trackduino.RGB(1,1,0);             // Вариант 2
  Trackduino.RGB_color("YELLOW");    // Вариант 3
  delay(1000);
  // фиолетовый
  Trackduino.RGB_purple();           // Вариант 1   
  Trackduino.RGB(1,0,1);             // Вариант 2
  Trackduino.RGB_color("PURPLE");    // Вариант 3
  delay(1000);
  // бирюзовый
  Trackduino.RGB_turquoise();        // Вариант 1 
  Trackduino.RGB(0,1,1);             // Вариант 2
  Trackduino.RGB_color("TURQUOISE"); // Вариант 3
  delay(1000);
  // выключить
  Trackduino.RGB_off();              // Вариант 1   
  Trackduino.RGB(0,0,0);             // Вариант 2
  Trackduino.RGB_color("OFF");       // Вариант 3
  delay(1000);
}

void loop () { 
  
}
