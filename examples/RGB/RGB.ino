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

  // проверить версию библиотеки
  // Serial.begin(9600);
  // Serial.println(TRACKDUINO_LIB_VERSION); 
  
  // красный
  Trackduino.RGB_red();       
  Trackduino.RGB(1,0,0);
  Trackduino.RGB_color("RED");
  delay(1000);
  // зеленый
  Trackduino.RGB_green();     
  Trackduino.RGB(0,1,0);
  Trackduino.RGB_color("GREEN");
  delay(1000);
  // синий
  Trackduino.RGB_blue();      
  Trackduino.RGB(0,0,1);
  Trackduino.RGB_color("BLUE");
  delay(1000);
  // белый
  Trackduino.RGB_white();     
  Trackduino.RGB(1,1,1);
  Trackduino.RGB_color("WHITE");
  delay(1000);
  // желтый
  Trackduino.RGB_yellow();    
  Trackduino.RGB(1,1,0);
  Trackduino.RGB_color("YELLOW");
  delay(1000);
  // фиолетовый
  Trackduino.RGB_purple();   
  Trackduino.RGB(1,0,1);
  Trackduino.RGB_color("PURPLE");
  delay(1000);
  // бирюзовый
  Trackduino.RGB_turquoise(); 
  Trackduino.RGB(0,1,1);
  Trackduino.RGB_color("TURQUOISE");
  delay(1000);
  // выключить
  Trackduino.RGB_off();       
  Trackduino.RGB(0,0,0);
  Trackduino.RGB_color("OFF");
  delay(1000);
}

void loop () { 
  
}
