#include <Arduino.h>
//#include <TimerOne.h>

#define OFF 0
#define ON 1

#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define BROWN 5
#define YELLOW 6
#define GREY 7

//gyro-accelerometer reading modes
#define RAW_GYRO 0 
#define RAW_ACCEL 1 
#define FILTERED 2 

#define SMALL_SERVO 544,2050
#define BIG_SERVO 544,1500


void setEncToZero(int encoder);
long getEncDegrees(int encoder);
void setupEnc(int encoder, int CH_A, int CH_B);


//void test();

typedef enum{
	GYRO_X_AXIS = 0,
	GYRO_Y_AXIS = 1,
	GYRO_Z_AXIS = 2,
} gyroAxis;

void setupGyro(void);
int GyroScan(gyroAxis);

void trackduinoInit(void);

void stopProgram();

// -----------1st-level control functions------------
void motorsAccelerationSetup(unsigned int millisToFullSpeed);
void motorsHandler();

void changeMotorSpeed(int motorPort, int speed);
void changeMotorDirection(int motorPort, bool direction);

void startMotor(int motorPort, int speed);

void stopMotor(int motorPort);

void stopMotorHard (int motorPort);

void releaseServo(int outPort);

// -----------2nd-level control functions------------


// -----------RGB LED functions------------
void builtInRGB(int color);


//-------------Sensors read functions----------
bool buttonRead(int port);

int distanceCM(int port);

bool irWhite(int port, int threshold);
bool irBlack(int port, int threshold);
int irAnalog(int port);
bool flame(int port); 
bool shock(int port);
int temperature(int port);

bool mic(int port);
int micAnalog(int port);

bool cdsLight(int port, int threshold);
bool cdsDark(int port, int threshold);
int cdsAnalog(int port);
//------------Actuators funcrions------------

void led (int ledPort, bool state);

void ledPWM (int ledPort, int PWM);


// -----------Color sensor------------
void setupColorSensor(int Rpin, int Bpin, int Gpin, int colorSensorCDSpin);
int getColor(void);
int getCDSReading(int colorSensorCDSpin, int times);

// --------------IR RC ----------------
/*
	IRDecode.h - Library IR controller.
	Created by Nesterov D.A., October 5, 2015.
*/
// #ifndef IRRC_h
// #define IRRC_h

// #if defined(ARDUINO) && ARDUINO >= 100
  // #include "Arduino.h"
// #else
  // #include "WProgram.h"
// #endif 




#define Timeout 500

#define Channl_1 0xFC
#define Channl_2 0x3C
#define Channl_3 0xCC
#define Channl_4 0x0C
#define Channl_5 0xF0
#define Channl_6 0x30
#define Channl_7 0xC0
#define Channl_8 0x00

#define Shift 8

#define UP_KEY 0x1FC3
#define DOWN_KEY 0x1F
#define LEFT_KEY 0x07
#define RIGHT_KEY 0x73

#define F1_KEY 0x7CF
#define F2_KEY 0x1C3F
#define F3_KEY 0x7F3
#define F4_KEY 0x1CCF
#define F5_KEY 0x1F0F
#define F6_KEY 0x703

#define OFF_KEY 0x733

#define UP_AND_LEFT_KEY 0x7C3
#define UP_AND_RIGHT_KEY 0x7F
#define DOWN_AND_LEFT_KEY 0x70F
#define DOWN_AND_RIGHT_KEY 0x1CF
	
//#define  SoftPWMSet(x,y, z) analogWrite(x,y)	
	
	void IRRC_setup(int pin, uint8_t Channl);
	void change();
	//void Set_Channle(byte Channle);
	bool RC(long BT_ID);
	
// #endif

//======================BLUETOOTH RC==========================
void BTinit(void);
void clearValues();
//String getString(String name, int value);
//String getAnotherString(String name, boolean value);
//void showValues();
void calculateValues();
void BTEventRun(void);

//void analogWrite (int port, int value);