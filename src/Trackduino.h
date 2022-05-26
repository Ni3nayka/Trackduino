#include <Arduino.h>
#pragma once

/*
mode:
0 - ERROR
1 - DIR
2 - DIR, DIR
3 - SPEED, DIR
4 - SPEED, DIR, DIR
*/

#define DIR "DIR"
#define PWM "PWM"

class motor {

  public:

    //#define AUTOMATIC  1

    motor(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0);
    int TestMode();
    void SetSpeed(int predel);

    void run(int speed);
    void stop();
    void block();

  private:

    //void Initialize();
    //double dispKp;
    int _max_speed;
    byte _mode;
    byte _pwm_pin;
    byte _dir_1_pin;
    byte _dir_2_pin;


};
