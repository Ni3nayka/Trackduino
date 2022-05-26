#include <Arduino.h>
#pragma once

#include "pins.h"

#ifdef Trackduino_SD_enable
#include <SPI.h>
#include <SD.h>
#endif

class Trackduino {

  public:

    //#define AUTOMATIC  1

    /*motor(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0);
    int TestMode();
    void SetSpeed(int predel);

    void run(int speed);
    void stop();
    void block();*/

    int qwerty = 0;
    int get_qwerty();

    // RGB
    void RGB(int r=0, int g=0, int b=0);
    void RGB_color(String color="OFF");
    void RGB_red();
    void RGB_green();
    void RGB_blue();
    void RGB_off();

    // motor 
    motor(int n, int speed=0);
    stop_motor(int n);
    block_motor(int n);
    
    // SD
    #ifdef Trackduino_SD_enable
    int sd = 0;
    #endif

    // bluetooth

    // encoder

    // sound

    // servo

    // button


  private:

    //void Initialize();
    //double dispKp;
    int _max_speed;
    byte _mode;
    byte _pwm_pin;
    byte _dir_1_pin;
    byte _dir_2_pin;


};

Trackduino trackduino;

Trackduino::get_qwerty() {
  return 3;
}
