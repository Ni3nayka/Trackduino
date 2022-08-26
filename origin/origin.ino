#include "bluetooth.h"

#define RGB_BLUE  32

Bluetooth bluetooth;

void setup()
{
  bluetooth.setup();
  
  pinMode(RGB_BLUE,OUTPUT);
  digitalWrite(RGB_BLUE,1);
  delay(1000);
  digitalWrite(RGB_BLUE,0);
  Serial.println("!");
}

void loop()
{
  bluetooth.update();

  
  if (bluetooth.x>1) {
    digitalWrite(RGB_BLUE,1);
    delay(1000);
    digitalWrite(RGB_BLUE,0);
  }
}
