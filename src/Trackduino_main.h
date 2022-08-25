/*
 * Integration the Trackduino to Arduino IDE:
 * https://github.com/Ni3nayka/Trackduino
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru>
 * write:  june 2022
 * modify: august 2022
 */
 
#pragma once

#include <Arduino.h>

#include "pins.h"

#ifdef Trackduino_SD_enable
#include <SPI.h>
#include <SD.h>
#endif

#define TRACKDUINO_LIB_VERSION "1.0.0 beta"

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
    //version();
    setup_IN_OUT_pins();

    // RGB
    setup_RGB();
    RGB(bool r=0, bool g=0, bool b=0);
    RGB_color(String color="OFF");
    RGB_red();
    RGB_green();
    RGB_blue();
    RGB_white();
    RGB_off();
    RGB_yellow();
    RGB_purple();
    RGB_turquoise();

    // motor 
    setup_motor();
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
    setup_BTN();
    BTN_up();
    BTN_down();
    BTN_left();
    BTN_right();
    BTN_center();


  private:
    bool _revers_motor[COUNT_MOTOR] = {0,0,0,0}; // WEAK NODE!!! - when changing COUNT_MOTOR
};
//#endif

//extern TrackDuino Trackduino;
