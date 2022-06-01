/*
 * Integration the Trackduino to Arduino IDE
 * 
 * Bakay Egor, june 2022
 * https://github.com/Ni3nayka/Trackduino
 */
 
#pragma once
//#ifndef wdefaerhtsrymdsgaegrthfhbdvsthdtydrhgfghmjtrgseafgyjut
//#define wdefaerhtsrymdsgaegrthfhbdvsthdtydrhgfghmjtrgseafgyjut

#include <Arduino.h>

#include "pins.h"

#ifdef Trackduino_SD_enable
#include <SPI.h>
#include <SD.h>
#endif


class TrackDuino {

  public:

    //#define AUTOMATIC  1

    /*motor(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0);
    int TestMode();
    void SetSpeed(int predel);

    void run(int speed);
    void stop();
    void block();*/

    setup();

    // RGB
    void RGB(int r=0, int g=0, int b=0);
    void RGB_color(String color="OFF");
    void RGB_red();
    void RGB_green();
    void RGB_blue();
    void RGB_off();

    // motor 
    motor(int n, int speed=0);
    motor_forward(int n);
    motor_backward(int n);
    stop_motor(int n);
    block_motor(int n);
    reverse_clear();
    reverse_motor(int n, bool dir);
    
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
    bool revers_motor[COUNT_MOTOR] = {0,0,0,0}; // WEAK NODE!!! - when changing COUNT_MOTOR
};
//#endif

//extern TrackDuino Trackduino;
