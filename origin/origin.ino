#include "Trackduino.h"

extern int bluetooth_X, bluetooth_Y, bluetooth_Z, bluetooth_W, bluetooth_aX, bluetooth_aY,bluetooth_aZ;
extern bool bluetooth_F1, bluetooth_F2, bluetooth_F3, bluetooth_F4, bluetooth_F5, bluetooth_F6,BTenable;

void setup()
{
  trackduinoInit();
  BTinit();
  pinMode(RGB_BLUE,OUTPUT);
  digitalWrite(RGB_BLUE,1);
  delay(1000);
  digitalWrite(RGB_BLUE,0);
  Serial.println("!");
}

void loop()
{
  if (serialEventRun && BTenable==1) BTEventRun(); // run function BTEventRun from Trackduino.cpp
  //if (serialEventRun && NEUROenable==1) NEUROEventRun();// run function NEUROEventRun from Trackduino.cpp
  //if (BTenable==1) digitalWrite(RGB_RED, HIGH);
  //  loop();
  if (serialEventRun && BTenable==0) serialEventRun();

  
  if (( ( bluetooth_X ) > ( 1 ) ))
  {
    builtInRGB(BLUE);
    digitalWrite(RGB_BLUE,1);
    delay(1000);
    digitalWrite(RGB_BLUE,0);
  }
  else
  {
    builtInRGB(OFF);
  }
}
