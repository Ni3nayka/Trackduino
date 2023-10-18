/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  october 2023
 * modify: october 2023
 */

#pragma once

class UltraSonicSR04 {
  // https://codesforprogram.blogspot.com/2013/08/3-pin-ultrasonic-sensor-and-arduino.html
  // https://arduinomaster.ru/datchiki-arduino/ultrazvukovoj-dalnomer-hc-sr04/
  public:
    void setup(int pin_trig, int pin_echo=-1) {
      UltraSonicSR04::pin_trig = pin_trig;
      if (pin_trig==pin_echo || pin_echo==-1) {
        UltraSonicSR04::one_pin_mode = 1;
        UltraSonicSR04::pin_echo = pin_trig;
      }
      else {
        UltraSonicSR04::one_pin_mode = 0;
        UltraSonicSR04::pin_echo = pin_echo;
        pinMode(UltraSonicSR04::pin_trig, OUTPUT);
        pinMode(UltraSonicSR04::pin_echo, INPUT);
      }
    }
    int read() {
      if (UltraSonicSR04::one_pin_mode) pinMode(UltraSonicSR04::pin_trig, OUTPUT);
      digitalWrite(UltraSonicSR04::pin_trig, LOW);
      delayMicroseconds(2); // 5
      digitalWrite(UltraSonicSR04::pin_trig, HIGH);
      delayMicroseconds(5); // 10
      digitalWrite(UltraSonicSR04::pin_trig, LOW);
      if (UltraSonicSR04::one_pin_mode) pinMode(UltraSonicSR04::pin_trig, INPUT);
      int duration = pulseIn(UltraSonicSR04::pin_echo, HIGH);
      delay(10);
      return duration/58;  
    }
  private:
    int pin_trig,pin_echo;
    bool one_pin_mode;
};


  
