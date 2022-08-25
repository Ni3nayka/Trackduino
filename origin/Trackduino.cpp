#include <Arduino.h>
#include <TimerOne.h>
#include <TimerThree.h>
//#include <PinChangeInt.h> 
#include <EnableInterrupt.h> 
#include <OneWire.h>


#include "..\..\libraries\Wire\Wire.h"
#include <SoftPWM.h>


// void test()

// {digitalWrite(13, HIGH);
// 	delay(1000);
// 	digitalWrite(13,LOW);
// 	delay(1000);}

#define MPU (0x68) //i2c address of MPU (gyroscope)
#define ACCEL_XOUT_H (0x3b)
#define ACCEL_XOUT_L (0x3c)
#define ACCEL_YOUT_H (0x3d)
#define ACCEL_YOUT_L (0x3e)
#define ACCEL_ZOUT_H (0x3f)
#define ACCEL_ZOUT_L (0x40)
#define TEMP_OUT_H (0x41)
#define TEMP_OUT_L (0x42)
#define GYRO_XOUT_H (0x43)
#define GYRO_XOUT_L (0x44)
#define GYRO_YOUT_H (0x45)
#define GYRO_YOUT_L (0x46)
#define GYRO_ZOUT_H (0x47)
#define GYRO_ZOUT_L (0x48)

#define READ_2_BYTES (Wire.read() << 8 | Wire.read())




void setupGyro(void){
	Wire.begin();
	Wire.beginTransmission(MPU);
	Wire.write(0x6b);
	Wire.write(0);
	Wire.endTransmission(true);
}

int GyroScan(gyroAxis axis){
	Wire.beginTransmission(MPU);
	Wire.write(GYRO_XOUT_H);
	Wire.endTransmission(false);
	Wire.requestFrom(MPU, 6, true);
	int X = READ_2_BYTES; 
	int Y = READ_2_BYTES;
	int Z = READ_2_BYTES;
	switch(axis){
		case GYRO_X_AXIS:
			return X;
		case GYRO_Y_AXIS:
			return Y;
		case GYRO_Z_AXIS:
			return Z;
	}
}

void trackduinoInit(void) {
	pinMode(RGB_BLUE,OUTPUT);
	pinMode(RGB_RED,OUTPUT);
	pinMode(RGB_GREEN,OUTPUT);

	digitalWrite(RGB_BLUE,LOW);
	digitalWrite(RGB_RED,LOW);
	digitalWrite(RGB_GREEN,LOW);

	pinMode(MOTOR1_IN1,OUTPUT);
	pinMode(MOTOR1_IN2,OUTPUT);
	pinMode(MOTOR1_EN,OUTPUT);
	pinMode(MOTOR2_IN1,OUTPUT);
	pinMode(MOTOR2_IN2,OUTPUT);
	pinMode(MOTOR2_EN,OUTPUT);
	pinMode(MOTOR3_IN1,OUTPUT);
	pinMode(MOTOR3_IN2,OUTPUT);
	pinMode(MOTOR3_EN,OUTPUT);
	pinMode(MOTOR4_IN1,OUTPUT);
	pinMode(MOTOR4_IN2,OUTPUT);
	pinMode(MOTOR4_EN,OUTPUT);

	digitalWrite(MOTOR1_IN1,LOW);
	digitalWrite(MOTOR1_IN2,HIGH);
	digitalWrite(MOTOR1_EN ,LOW);
	digitalWrite(MOTOR2_IN1,LOW);
	digitalWrite(MOTOR2_IN2,HIGH);
	digitalWrite(MOTOR2_EN ,LOW);
	digitalWrite(MOTOR3_IN1,LOW);
	digitalWrite(MOTOR3_IN2,HIGH);
	digitalWrite(MOTOR3_EN ,LOW);
	digitalWrite(MOTOR4_IN1,LOW);
	digitalWrite(MOTOR4_IN2,HIGH);
	digitalWrite(MOTOR4_EN ,LOW);

	pinMode(IN1, INPUT);
	pinMode(IN1INT, INPUT);
	pinMode(IN2, INPUT);
	pinMode(IN2INT, INPUT);
	pinMode(IN3, INPUT);
	pinMode(IN3INT, INPUT);
	pinMode(IN4, INPUT);
	pinMode(IN4INT, INPUT);
	pinMode(IN5, INPUT);
	pinMode(IN6, INPUT);
	pinMode(IN7, INPUT);
	pinMode(IN8, INPUT);

	pinMode(OUT1, OUTPUT);
	pinMode(OUT2, OUTPUT);
	pinMode(OUT3, OUTPUT);
	pinMode(OUT4, OUTPUT);
	pinMode(OUT5, OUTPUT);
	pinMode(OUT6, OUTPUT);
	pinMode(OUT7, OUTPUT);
	pinMode(OUT8, OUTPUT);

	digitalWrite(OUT1, LOW);
	digitalWrite(OUT2, LOW);
	digitalWrite(OUT3, LOW);
	digitalWrite(OUT4, LOW);
	digitalWrite(OUT5, LOW);
	digitalWrite(OUT6, LOW);
	digitalWrite(OUT7, LOW);
	digitalWrite(OUT8, LOW);

	pinMode(BTN_UP, INPUT_PULLUP);
	pinMode(BTN_DOWN, INPUT_PULLUP);
	pinMode(BTN_LEFT, INPUT_PULLUP);
	pinMode(BTN_RIGHT, INPUT_PULLUP);
	pinMode(BTN_CENTER, INPUT_PULLUP);

	pinMode(SOUND_PIN, OUTPUT);
	digitalWrite(SOUND_PIN, LOW);

	pinMode(BT_SW, OUTPUT);
	//digitalWrite(BT_SW,LOW);
	
	pinMode(13, OUTPUT);
	digitalWrite(13,LOW);
	
	//Timer3.initialize(1000);         // initialize timer1 to overflow every ...
	//Timer3.attachInterrupt(motorsHandler);  // attaches motorsHandler() to a timer overflow interrupt

	//SoftPWMBegin();
}

void stopProgram() {
	   while(1)
    {

    }
}

// -----------Working with quadratic Encoder--------------
// the user should define ENC_CH_A and ENC_CH_B. By default IN1 and IN2 correspondigly
// to understand how this code is working, please read this article: easyelectronics.ru/avr-uchebnyj-kurs-inkrementalnyj-enkoder.html


#define ENC1_STATUS ((digitalRead(ENC1_CH_B) << 1) + digitalRead(ENC1_CH_A))
#define ENC2_STATUS ((digitalRead(ENC2_CH_B) << 1) + digitalRead(ENC2_CH_A))
#define ENC3_STATUS ((digitalRead(ENC3_CH_B) << 1) + digitalRead(ENC3_CH_A))
#define ENC4_STATUS ((digitalRead(ENC4_CH_B) << 1) + digitalRead(ENC4_CH_A))

int ENC1_CH_A;
int ENC1_CH_B;
int ENC2_CH_A;
int ENC2_CH_B;
int ENC3_CH_A;
int ENC3_CH_B;
int ENC4_CH_A;
int ENC4_CH_B; 

volatile long Enc1Data = 0;
volatile long Enc2Data = 0;
volatile long Enc3Data = 0;
volatile long Enc4Data = 0;


void setEncToZero(int encoder){
	switch(encoder){
		case 1:{
			Enc1Data=0;
			break;
		}
		case 2:{
			Enc2Data=0;
			break;
		}
		case 3:{
			Enc3Data=0;
			break;
		}
		case 4:{
			Enc4Data=0;
			break;
		}
	}
}


long getEncDegrees(int encoder){
	
		switch(encoder){
		case 1:{
			return (Enc1Data*5);
			break;
		}
		case 2:{
			return (Enc2Data*5);
			break;
		}
		case 3:{
			return (Enc3Data*5);
			break;
		}
		case 4:{
			return (Enc4Data*5);
			break;
		}
	}
	//return (EncData*5); //we have 72 clicks per rotation, so 5 degrees per click
}

void Encoder1Scan(void){
    static int Enc1State = ENC1_STATUS;
	int New = ENC1_STATUS;
	switch(Enc1State){
		case 0b10:{
			if (New == 3) Enc1Data++;
			if (New == 0) Enc1Data--;
			break;
		}
		case 0b00:{
			if (New == 2) Enc1Data++;
			if (New == 1) Enc1Data--;
			break;
		}
		case 0b01:{
			if (New == 0) Enc1Data++;
			if (New == 3) Enc1Data--;
			break;
		}
		case 0b11:{
			if (New == 1) Enc1Data++;
			if (New == 2) Enc1Data--;
			break;
		}
	}
	Enc1State = New;
}

void Encoder2Scan(void){
    static int Enc2State = ENC2_STATUS;
	int New = ENC2_STATUS;
	switch(Enc2State){
		case 0b10:{
			if (New == 3) Enc2Data++;
			if (New == 0) Enc2Data--;
			break;
		}
		case 0b00:{
			if (New == 2) Enc2Data++;
			if (New == 1) Enc2Data--;
			break;
		}
		case 0b01:{
			if (New == 0) Enc2Data++;
			if (New == 3) Enc2Data--;
			break;
		}
		case 0b11:{
			if (New == 1) Enc2Data++;
			if (New == 2) Enc2Data--;
			break;
		}
	}
	Enc2State = New;
}

void Encoder3Scan(void){
    static int Enc3State = ENC3_STATUS;
	int New = ENC3_STATUS;
	switch(Enc3State){
		case 0b10:{
			if (New == 3) Enc3Data++;
			if (New == 0) Enc3Data--;
			break;
		}
		case 0b00:{
			if (New == 2) Enc3Data++;
			if (New == 1) Enc3Data--;
			break;
		}
		case 0b01:{
			if (New == 0) Enc3Data++;
			if (New == 3) Enc3Data--;
			break;
		}
		case 0b11:{
			if (New == 1) Enc3Data++;
			if (New == 2) Enc3Data--;
			break;
		}
	}
	Enc3State = New;
}

void Encoder4Scan(void){
    static int Enc4State = ENC4_STATUS;
	int New = ENC4_STATUS;
	switch(Enc4State){
		case 0b10:{
			if (New == 3) Enc4Data++;
			if (New == 0) Enc4Data--;
			break;
		}
		case 0b00:{
			if (New == 2) Enc4Data++;
			if (New == 1) Enc4Data--;
			break;
		}
		case 0b01:{
			if (New == 0) Enc4Data++;
			if (New == 3) Enc4Data--;
			break;
		}
		case 0b11:{
			if (New == 1) Enc4Data++;
			if (New == 2) Enc4Data--;
			break;
		}
	}
	Enc4State = New;
}

void setupEnc(int encoder,int  CH_A,int  CH_B){
	//attachInterrupt(digitalPinToInterrupt(ENC_CH_A_INT), EncoderScan, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(ENC_CH_B_INT), EncoderScan, CHANGE);
	switch(encoder){
		case 1:{
			ENC1_CH_A = CH_A;
			ENC1_CH_B = CH_B;
			//attachPinChangeInterrupt(ENC1_CH_A,Encoder1Scan,CHANGE);
			//attachPinChangeInterrupt(ENC1_CH_B,Encoder1Scan,CHANGE);
			enableInterrupt(ENC1_CH_A,Encoder1Scan,CHANGE);
			enableInterrupt(ENC1_CH_B,Encoder1Scan,CHANGE);
			
			break;
		}
		case 2:{
			ENC2_CH_A = CH_A;
			ENC2_CH_B = CH_B;
			//attachPinChangeInterrupt(ENC2_CH_A,Encoder2Scan,CHANGE);
			//attachPinChangeInterrupt(ENC2_CH_B,Encoder2Scan,CHANGE);
			enableInterrupt(ENC2_CH_A,Encoder2Scan,CHANGE);
			enableInterrupt(ENC2_CH_B,Encoder2Scan,CHANGE);
			break;
		}
		case 3:{
			ENC3_CH_A = CH_A;
			ENC3_CH_B = CH_B;
			//attachPinChangeInterrupt(ENC3_CH_A,Encoder3Scan,CHANGE);
			//attachPinChangeInterrupt(ENC3_CH_B,Encoder3Scan,CHANGE);
			enableInterrupt(ENC3_CH_A,Encoder3Scan,CHANGE);
			enableInterrupt(ENC3_CH_B,Encoder3Scan,CHANGE);
			break;
		}
		case 4:{
			ENC4_CH_A = CH_A;
			ENC4_CH_B = CH_B;
			//attachPinChangeInterrupt(ENC4_CH_A,Encoder4Scan,CHANGE);
			//attachPinChangeInterrupt(ENC4_CH_B,Encoder4Scan,CHANGE);
			enableInterrupt(ENC4_CH_A,Encoder4Scan,CHANGE);
			enableInterrupt(ENC4_CH_B,Encoder4Scan,CHANGE);
			break;
		}
	}
}

//============== Motors stuff========================

 volatile int newMotorSpeed[4] = {0, 0, 0, 0}; //сюда записываются "целевые" значения скорости
 volatile int currentMotorSpeed[4] = {0, 0, 0, 0}; //текущие значения скорости, первый элемент не используется
 
void motorsAccelerationSetup(unsigned int millisToFullSpeed)
{
	unsigned long newTimerValue = (millisToFullSpeed*10);
	Timer3.initialize(newTimerValue);	
}

 
void motorsHandler()
{

for (int i = 0; i<4; i++)
{
  if (newMotorSpeed[i] > currentMotorSpeed[i])
  {
    currentMotorSpeed[i]++;
    changeMotorSpeed(i, currentMotorSpeed[i]);
  }

  else if (newMotorSpeed[i] < currentMotorSpeed[i])
  {
    currentMotorSpeed[i]--;
    changeMotorSpeed(i, currentMotorSpeed[i]);
  }

  else if (newMotorSpeed[i] = currentMotorSpeed[i])
  {
    //do nothing
  }
  
    // Serial.print(currentMotorSpeed[i]);
	// Serial.print("/");
	// Serial.print(newMotorSpeed[i]);
	// Serial.print("\t");
	
	
}
// Serial.println("");

}

void changeMotorSpeed(int motorPort, int speed)
{
    if (speed >= 0) {
    changeMotorDirection(motorPort, 0);
  }
  else if (speed < 0) {
    changeMotorDirection(motorPort, 1);
  }
  
  switch (motorPort)
  {
	  case 0:
	  analogWrite(MOTOR1_EN, abs(map(speed, 0, 100, 0, 255)));
	  break;
	  
	  case 1:
	  analogWrite(MOTOR2_EN, abs(map(speed, 0, 100, 0, 255)));
	  break;
	  
	  case 2:
	  analogWrite(MOTOR3_EN, abs(map(speed, 0, 100, 0, 255)));
	  break;
	  
	  case 3:
	  analogWrite(MOTOR4_EN, abs(map(speed, 0, 100, 0, 255)));
	  break;
  }
  //Serial.println(speed);
}

void changeMotorDirection(int motorPort, bool direction)
{

  switch (motorPort)
  {
    case 0:
      switch (direction)
      {
        case 0:
          digitalWrite(MOTOR1_IN1, HIGH);
          digitalWrite(MOTOR1_IN2, LOW);
          break;

        case 1:
          digitalWrite(MOTOR1_IN1, LOW);
          digitalWrite(MOTOR1_IN2, HIGH);
          break;
        break;
      }

    case 1:
      switch (direction)
      {
        case 0:
          digitalWrite(MOTOR2_IN1, HIGH);
          digitalWrite(MOTOR2_IN2, LOW);
          break;

        case 1:
          digitalWrite(MOTOR2_IN1, LOW);
          digitalWrite(MOTOR2_IN2, HIGH);
          break;
        break;
      }

    case 2:
      switch (direction)
      {
        case 0:
          digitalWrite(MOTOR3_IN1, HIGH);
          digitalWrite(MOTOR3_IN2, LOW);
          break;

        case 1:
          digitalWrite(MOTOR3_IN1, LOW);
          digitalWrite(MOTOR3_IN2, HIGH);
          break;
        break;
      }

    case 3:
      switch (direction)
      {
        case 0:
          digitalWrite(MOTOR4_IN1, HIGH);
          digitalWrite(MOTOR4_IN2, LOW);
          break;

        case 1:
          digitalWrite(MOTOR4_IN1, LOW);
          digitalWrite(MOTOR4_IN2, HIGH);
          break;
        break;
      }
  }
}

/* void startMotor (int motorPort, int speed)
{
  //newMotorSpeed[(motorPort-1)] = constrain(speed,-100,100);
  newMotorSpeed[(motorPort-1)] = speed;
} */

// -----------1st-level Motor control functions------------
	 void startMotor(int motorPort, int speed) {

		if (speed > 100) {
			speed = 100;
		}
		if (speed < -100) {
			speed = -100;
		}


		if (speed > 0)
		{

			speed = abs(speed);
			speed = map(speed, 0, 100, 0, 255);

			switch (motorPort)
			{
				case 1:
				digitalWrite(MOTOR1_IN1, HIGH);
				digitalWrite(MOTOR1_IN2, LOW);
				analogWrite(MOTOR1_EN, speed);
				break;

				case 2:
				digitalWrite(MOTOR2_IN1, HIGH);
				digitalWrite(MOTOR2_IN2, LOW);
				analogWrite(MOTOR2_EN, speed);
				break;

				case 3:
				digitalWrite(MOTOR3_IN1, HIGH);
				digitalWrite(MOTOR3_IN2, LOW);
				analogWrite(MOTOR3_EN, speed);
				break;

				case 4:
				digitalWrite(MOTOR4_IN1, HIGH);
				digitalWrite(MOTOR4_IN2, LOW);
				analogWrite(MOTOR4_EN, speed);
				break;
			}
		}
		else if (speed <= 0)
		{

			speed = abs(speed);
			speed = map(speed, 0, 100, 0, 255);

			switch (motorPort)
			{
				case 1:
				digitalWrite(MOTOR1_IN1, LOW);
				digitalWrite(MOTOR1_IN2, HIGH);
				analogWrite(MOTOR1_EN, speed);
				break;

				case 2:
				digitalWrite(MOTOR2_IN1, LOW);
				digitalWrite(MOTOR2_IN2, HIGH);
				analogWrite(MOTOR2_EN, speed);
				break;

				case 3:
				digitalWrite(MOTOR3_IN1, LOW);
				digitalWrite(MOTOR3_IN2, HIGH);
				analogWrite(MOTOR3_EN, speed);
				break;

				case 4:
				digitalWrite(MOTOR4_IN1, LOW);
				digitalWrite(MOTOR4_IN2, HIGH);
				analogWrite(MOTOR4_EN, speed);
				break;
			}
		}
	} 
	

void stopMotor(int motorPort){
	
	newMotorSpeed[(motorPort-1)] = 0;
	currentMotorSpeed[(motorPort-1)] = 0;
		
	switch (motorPort)
	{
		
		
		case 1:
		analogWrite(MOTOR1_EN, 0);
		break;

		case 2:
		analogWrite(MOTOR2_EN, 0);
		break;

		case 3:
		analogWrite(MOTOR3_EN, 0);
		break;

		case 4:
		analogWrite(MOTOR4_EN, 0);
		break;
	}
}

	void stopMotorHard (int motorPort)	{
	newMotorSpeed[(motorPort-1)] = 0;
	currentMotorSpeed[(motorPort-1)] = 0;
		switch (motorPort)
		{
			case 1:
			digitalWrite(MOTOR1_IN1, LOW);
			digitalWrite(MOTOR1_IN2, LOW);
			analogWrite(MOTOR1_EN, 255);
			break;
			case 2:
			digitalWrite(MOTOR2_IN1, LOW);
			digitalWrite(MOTOR2_IN2, LOW);
			analogWrite(MOTOR2_EN, 255);
			break;
			case 3:
			digitalWrite(MOTOR3_IN1, LOW);
			digitalWrite(MOTOR3_IN2, LOW);
			analogWrite(MOTOR3_EN, 255);
			break;
			case 4:
			digitalWrite(MOTOR4_IN1, LOW);
			digitalWrite(MOTOR4_IN2, LOW);
			analogWrite(MOTOR4_EN, 255);
			break;
		}
	}



	void releaseServo(int outPort) {
		pinMode(outPort, OUTPUT);
		digitalWrite(outPort,LOW);
	}



// -----------2nd-level control functions------------

// -----------RGB LED functions------------
//0-off, 1-white, 2-red, 3-green, 4-blue
	void builtInRGB(int color) {

		switch (color)
		{

			case 0:
			digitalWrite(RGB_RED, LOW);
			digitalWrite(RGB_GREEN, LOW);
			digitalWrite(RGB_BLUE, LOW);
			break;

			case 1:
			digitalWrite(RGB_RED, HIGH);
			digitalWrite(RGB_GREEN, HIGH);
			digitalWrite(RGB_BLUE, HIGH);
			break;
			
			case 2:
			digitalWrite(RGB_RED, HIGH);
			digitalWrite(RGB_GREEN, LOW);
			digitalWrite(RGB_BLUE, LOW);
			break;
			
			case 3:
			digitalWrite(RGB_RED, LOW);
			digitalWrite(RGB_GREEN, HIGH);
			digitalWrite(RGB_BLUE, LOW);
			break;
			
			case 4:
			digitalWrite(RGB_RED, LOW);
			digitalWrite(RGB_GREEN, LOW);
			digitalWrite(RGB_BLUE, HIGH);
			break;
		}


	}

//-------------Sensors read functions----------

    bool buttonRead(int port) {
        return !digitalRead(port);
    }




int distanceCM(int port)  {
  unsigned long duration[3];
  unsigned int distance = 0;
  for (int i = 0; i < 4; i++)
  {
  pinMode(port, OUTPUT);  
  digitalWrite(port, LOW);
  delayMicroseconds(2);
  digitalWrite(port, HIGH);
  delayMicroseconds(10);
  digitalWrite(port, LOW);
  pinMode(port, INPUT);
  duration[i] = pulseIn(port, HIGH, 20000);
  
  }

  int falseduration = 0;
  int maxerror = 50;

// if ((abs(duration[0]-duration[1])>maxerror) && (abs(duration[0]-duration[1]) >maxerror))
// {
// falseduration = 1;	
// }

// if ((abs(duration[1]-duration[0])>maxerror) && (abs(duration[1]-duration[0]) >maxerror))
// {
// falseduration = 2;	
// }

// if ((abs(duration[2]-duration[0])>maxerror) && (abs(duration[2]-duration[1]) >maxerror))
// {
// falseduration = 3;	
// }

// switch (falseduration)
// {

// 	case 0:
	
// 		break;


// 	case 1:
// 	duration[1] = ((duration[2]+duration[3])/2);
// 		break;

// 	case 2:
// 	duration[2] = ((duration[1]+duration[3])/2);
// 		break;

// 	case 3:
// 	duration[3] = ((duration[2]+duration[1])/2);
// 		break;
// }



  // for (int c = 0; c < 4; c++)
  // {
  // 	Serial.println(duration[c], DEC);
  // }
//Serial.println(falseduration, DEC);





  distance = ((duration[0] +duration[1] + duration[2])/3) / 58;
  //TODO: implement kalman filter here for ultrasonic reads 

 if ((duration[0]+duration[1]+duration[2])==0) return 300;
 
 if (distance > 300) {return 300;} 
 if (distance < 2) {return 1;}


return distance;
}

bool irWhite(int port, int threshold) {
	int reading = analogRead(port);
	if (reading>=threshold)
		{return true;}
	else
		{return false;}
}

bool irBlack(int port, int threshold) {
	int reading = analogRead(port);
	if (reading<threshold)
		{return true;}
	else
		{return false;}
}

int irAnalog(int port){
	int reading=analogRead(port);

	return reading;
}

bool flame(int port) {
	int value = analogRead(port);
	if (value>=900) {return true;}
	else {return false;}
}

bool shock(int port){
	int reading = analogRead(port);
	if (reading < 200) 
	{return true;}
	else 
	{return false;}
	
}

int temperature(int port){
OneWire ds(port);
byte data[2];
ds.reset(); 
ds.write(0xCC);
ds.write(0x44);
delay(750);
ds.reset();
ds.write(0xCC);
ds.write(0xBE);
data[0] = ds.read(); 
data[1] = ds.read();
int Temp = (data[1]<< 8)+data[0];
Temp = Temp>>4;
return Temp;
}

bool vibration(int port){
	int reading = analogRead(port);
	if (reading > 1000) 
	{return true;}
	else 
	{return false;}
}

bool mic (int port) {
	int threshold = 100;
	pinMode(port,INPUT_PULLUP);
	int reading=analogRead(port);
	if (reading>=threshold)
		{return false;}
	else
		{return true;}
}

int micAnalog(int port)
{
 analogReference(INTERNAL1V1);

  int oldvalue = 0;
  int newvalue = 0;

    for (int i = 0; i < 150; i++)
  {
    newvalue = analogRead(port);
    if (newvalue > oldvalue)
    {
      oldvalue = newvalue;
    }
  }
analogReference(DEFAULT);
return oldvalue;
}

bool cdsLight(int port, int threshold) {
	int reading = analogRead(port);
	
	
	if (reading>=threshold)
		{return true;}
	else
		{return false;}
}

bool cdsDark(int port, int threshold) {
	int reading = analogRead(port);
	if (reading<threshold)
		{return true;}
	else
		{return false;}
}

int cdsAnalog(int port){
	int reading=analogRead(port);

	return reading;
}


//------------Actuators funcrions------------

void led (int ledPort, bool state) {
	pinMode(ledPort, OUTPUT);
	digitalWrite(ledPort, state);
}

void ledPWM (int ledPort, int PWM) {
	pinMode(ledPort, OUTPUT);
	analogWrite(ledPort, PWM);
}



// -----------Color sensor------------
int colorSensorCDSpin = IN1;//default pin, changes in setup
int ledArrayOfcolorArray[3];
int colorArray[] = {0, 0, 0};
int whiteArray[] = {0, 0, 0};
int blackArray[] = {0, 0, 0};
float greyDiff[] = {0, 0, 0};


void setupColorSensor(int Rpin, int Bpin, int Gpin, int colorSensorCDSpin) {
  //setup the outputs for the Color sensor на всякий случай
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(colorSensorCDSpin, INPUT);

  ledArrayOfcolorArray[0] = Rpin;
  ledArrayOfcolorArray[1] = Gpin;
  ledArrayOfcolorArray[2] = Bpin;

  colorSensorCDSpin = colorSensorCDSpin;

  //мигаем 3 раза белым о необходимости произвести калибровку
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(Rpin, HIGH);
    digitalWrite(Gpin, HIGH);
    digitalWrite(Bpin, HIGH);
    delay(150);
    digitalWrite(Rpin, LOW);
    digitalWrite(Gpin, LOW);
    digitalWrite(Bpin, LOW);
    delay(70);
  }

  analogReference(INTERNAL2V56);
  //set white balance
  delay(3000);                              //delay, this gives us time to get a white sample in front of our sensor
  //scan the white sample.
  //go through each light, get a reading, set the base reading for each Color red, green, and blue to the white array
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledArrayOfcolorArray[i], HIGH);
    delay(50);
    //number is the number of scans to take for average, this whole function is redundant, one reading works just as well.
    whiteArray[i] = getCDSReading(colorSensorCDSpin, 5);
    digitalWrite(ledArrayOfcolorArray[i], LOW);
    delay(100);
  }
  //set black balance
  delay(3000);              //wait for five seconds so we can position our black sample
  //go ahead and scan, sets the Color values for red, green, and blue when exposed to black
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledArrayOfcolorArray[i], HIGH);
    delay(100);    
    blackArray[i] = getCDSReading(colorSensorCDSpin, 5);
    digitalWrite(ledArrayOfcolorArray[i], LOW);
    delay(100);
  }
  // расчитываем диапазон возможных значений между черным и белим
  for (int i = 0; i <= 2; i++) {
    greyDiff[i] = whiteArray[i] - blackArray[i];
  }

  //DEBUG
  //  for (int i = 0; i <= 2; i++) {
  //   Serial.print(whiteArray[i]);
  //   Serial.print("--");
  //   Serial.print(blackArray[i]);
  //   Serial.print("--");
  //   Serial.println(greyDiff[i]);
  // }
  

  //delay another 3 seconds to allow the human to catch up to what is going on
  delay(3000);
  analogReference(DEFAULT);
}

int getColor(void) {

for (int i = 0; i <= 2; i++) {
digitalWrite(ledArrayOfcolorArray[i], LOW);
}

  analogReference(INTERNAL2V56);
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledArrayOfcolorArray[i], HIGH); //turn on the LED, red, green or blue depending which iteration
    delay(70);                      //delay to allow CdS to stabalize, they are slow

    colorArray[i] = getCDSReading(colorSensorCDSpin, 5);        //set the current Color in the array to the average reading

    colorArray[i] = (colorArray[i] - blackArray[i]) / (greyDiff[i]) * 100; //выражаем прочитанный цвет в % между черным и белым
    digitalWrite(ledArrayOfcolorArray[i], LOW);  //turn off the current LED
    delay(70);
  //  округление в рамки 0 - 100%
    for (int i = 0 ; i <= 2; i++)
    {
      if (colorArray[i] < 0) {
        colorArray[i] = 0;
      }
      if (colorArray[i] > 100) {
        colorArray[i] = 100;
      }
    }
  }

 //  -------DEBUG---------
  // Serial.print("R = ");
  // Serial.println(int(colorArray[0]));
  // Serial.print("G = ");
  // Serial.println(int(colorArray[1]));
  // Serial.print("B = ");
  // Serial.println(int(colorArray[2]));
 // ------/DEBUG----------

int deltaW = 20;
int deltaB = 7;
int deltaColor = 4;

  //0-black 1-white 2-red 3-green 4-blue
  //белый: все три компоненты > 50, разница между ними МЕНЬШЕ deltaW
  if ((colorArray[0] > 50) && (colorArray[1] > 50) && (colorArray[2] > 50) && (abs(colorArray[0] - colorArray[1]) <  deltaW) && (abs(colorArray[0] - colorArray[2]) <  deltaW) && (abs(colorArray[1] - colorArray[2]) <  deltaW))
  {
    return 1;
  }
  //черный: все три компоненты < 10, разница между ними МЕНЬШЕ deltaB
  if ((colorArray[0] < 20) && (colorArray[1] < 20) && (colorArray[2] < 20) && (abs(colorArray[0] - colorArray[1]) <  deltaB) && (abs(colorArray[0] - colorArray[2]) <  deltaB) && (abs(colorArray[1] - colorArray[2]) <  deltaB))
  {
    return 0;
  }
  //КРАСНЫЙ: если красная компонента выбивается на deltaColor над любой из остальных
  if (((colorArray[0] - colorArray[1]) >  deltaColor) && ((colorArray[0] - colorArray[2]) >  deltaColor))
  {
    return 2;
  }
  //ЗЕЛЕНЫЙ: если зеленая компонента выбивается на deltaColor над любой из остальных
  if (((colorArray[1] - colorArray[0]) >  deltaColor) && ((colorArray[1] - colorArray[2]) >  deltaColor))
  {
    return 3;
  }
  //СИНИЙ: если синяя компонента выбивается хотя бы на на deltaColor над любой из остальных
  if (((colorArray[2] - colorArray[1]) >  deltaColor) && ((colorArray[2] - colorArray[1]) > deltaColor))
  {
    return 4;
  }

  return 9;

  analogReference(DEFAULT);
}


int getCDSReading(int colorSensorCDSpin, int times) {
  int reading = 0;
  //  int tally = 0;
  //take the reading however many times was requested and add them up
  for (int i = 0; i < times; i++)
  {
    reading = reading + analogRead(colorSensorCDSpin);
    //    tally = reading + tally;
    delay(10);
  }
  //calculate the average and set it
  reading = reading / times;
  return reading;
}

//====================IR RC Functions=================


//
// local var
//
byte impuls = 1;

unsigned long time, dtime;

unsigned long timeout_mark;

unsigned long res = 0;
unsigned int buf = 0;

byte Channl_ID = 1;
unsigned long Button_ID = 0;

byte Button_en = 0;

byte state = 0;
byte Channl_buf = 0;



//
// функция для конструкци if ( RC(кнопка)){}
//

bool RC(long BT_ID)
{ 
	if (Timeout < millis() - timeout_mark)
	{
		Button_ID = OFF_KEY;
	}

	
  if (BT_ID == Button_ID) 
    {
      return 1;
    } 
		
  return 0;    
}





void IRRC_setup(int pin, uint8_t Channl)
{
	
	pinMode(pin, INPUT);     //set the pin to input
	digitalWrite(pin, HIGH); //use the internal pullup resistor
	
	time = micros();  
	//PCintPort::attachInterrupt(pin, change, CHANGE); // attach a PinChange Interrupt to our first pin
	enableInterrupt(pin, change, CHANGE);
	
	
	  switch ( Channl )
    {
        case 1:
            Channl_ID = Channl_1;
            return;
        case 2:
            Channl_ID = Channl_2;
            return;
        case 3:
            Channl_ID = Channl_3;
            return;        
        case 4:
            Channl_ID = Channl_4;
            return;
        case 5:
            Channl_ID = Channl_5;
            return;
        case 6:
            Channl_ID = Channl_6;
            return;
        case 7:
            Channl_ID = Channl_7;
            return;
        case 8:
            Channl_ID = Channl_8;
            return;
        //default:
      }
}


//
//Inerupt function
//

void change()
{
	
	
	dtime = micros();
  buf = dtime - time ;
  time = dtime;

  // обработка длины импульса (по 200 с округлением в большую сторону при buf % 200 > 101 
  //и(или) если импульс < 101 присвоение единичной длинны)
  if (buf % 200 > 101)
  {
    buf = (buf / 200) + 1;
  }
  else 
  {
    buf = buf / 200;
  }
  if (buf == 0) buf = 1;

  if (state == 0) // начальное состояние
  {
      if (!impuls) //проверка на первые знаяащие биты (000)
      {
        state++;
        res = 0;
        res = res << buf;
        //Serial.println("Start");
      }
  } else {
    if (impuls)
    {
      res = res << buf;
      for (int i = 0; i < buf ; i++) 
      {
        res |= 1 << i ;
      }
    }else{
       res = res << buf;
      
       if ((byte)(res & 0x7F) == 0x38)
       { 
          buf = 1;
          for (int i = 1; i < Shift; i ++)
            buf = (buf << 1) + 1; 

          Channl_buf = (res >> 6) & buf ;
  
          if (Channl_buf == Channl_ID)
            {
              Button_ID = res >> (6+Shift);
              while(!(Button_ID & 1)) Button_ID = Button_ID >> 1; 
              timeout_mark = millis();
              //Serial.println (Button_ID, HEX);
            }
          state = 0;
          res = 0;
       }
    }  
  }
  impuls = !impuls;
}


//======================BLUETOOTH RC==========================
int count = 0;
int commandSize = 9;
byte command[9];

boolean f[6];
int value[7];

int bluetooth_X, bluetooth_Y, bluetooth_Z, bluetooth_W, bluetooth_aX, bluetooth_aY,
bluetooth_aZ;

bool bluetooth_F1, bluetooth_F2, bluetooth_F3, bluetooth_F4, bluetooth_F5, bluetooth_F6;

extern bool BTenable; // from main.c
void BTinit(void)
{
 Serial.begin(115200); 
 clearValues();
 BTenable = 1;
}

void clearValues() {
for (int i=0;i<6;i++)// Обнулим массив клавиш F
  f[i] = false;
for (int i=0;i<7;i++)
  value[i]=0;
for (int i=0;i<9;i++)
  command[i] = 0x00;
}

/* String getString(String name, int value) {
  String result = "";
  result += name;
  result += value;
  result += ", ";
  return result;
}
String getAnotherString(String name, boolean value) {
  String result = "";
  result += name;
  result += value;
  result += ", ";
  return result; 
}*/

/* void showValues() {
      String str = "";
      str += getString("x=",value[0]);
      str += getString("y=",value[1]);
      str += getString("z=",value[2]);
      str += getString("w=",value[3]);
      str += getString("ax=",value[4]);
      str += getString("ay=",value[5]);
      str += getString("az=",value[6]);
      str += getAnotherString("f1=",f[0]);
      str += getAnotherString("f2=",f[1]);
      str += getAnotherString("f3=",f[2]);
      str += getAnotherString("f4=",f[3]);
      str += getAnotherString("f5=",f[4]);
      str += getAnotherString("f6=",f[5]);
      str += getString("Voice=",(int)(command[8]));
      Serial.println(str);      
} */

void calculateValues() {  
      int fData = (int)command[7];
      
      // Найдем все включенные клавиши
      if (fData - 64 >= 0) { f[5] = true; fData -= 64; } // Зафиксируем, включен ли F6
      if (fData - 32 >= 0) { f[4] = true; fData -= 32; } // Зафиксируем, включен ли F5
      if (fData - 16 >= 0) { f[3] = true; fData -= 16; } // Зафиксируем, включен ли F4
      if (fData - 8 >= 0) { f[2] = true; fData -= 8; } // Зафиксируем, включен ли F3
      if (fData - 4 >= 0) { f[1] = true; fData -= 4; } // Зафиксируем, включен ли F2
      if (fData - 2 >= 0) { f[0] = true; fData -= 2; } // Зафиксируем, включен ли F1
      
      int buffer;
      for (int i=0;i<7;i++) {
        buffer = (int)command[i];
        if (buffer > 128) // Переведём знаковый байт в целое число с учетом знака
          buffer -= 256;
        value[i] = buffer;
      }
}



void BTEventRun(void) {
   if (Serial.available() >=commandSize) {
    
	for (int i = 0; i <= commandSize; i++)
	{
		command[i] = (byte)Serial.read(); // Save command
	}
	
    //count++;
   // if (count == commandSize) {          // Is it is the end of the array of bytes
     // count = 0;                    
     // for (int i=0;i<commandSize;i++) Serial.write(command[i]);} // Send the answer to an Android device
      
      for (int i=0;i<6;i++)// Обнулим массив клавиш F
	  {f[i] = false;}
      
      calculateValues();
	  
	  bluetooth_X = value[0];
      bluetooth_Y = value[1];
	  bluetooth_Z = value[2];
	  bluetooth_W = value[3];
	  bluetooth_aX = value[4];
	  bluetooth_aY = value[5];
	  bluetooth_aZ = value[6];
	  
	  bluetooth_F1 = f[0];
	  bluetooth_F2 = f[1];
	  bluetooth_F3 = f[2];
	  bluetooth_F4 = f[3];
	  bluetooth_F5 = f[4];
	  bluetooth_F6 = f[5];



      // Согласно ТЗ расшифровка следующая:
      // 0 - x
      // 1 - y
      // 2 - z
      // 3 - w
      // 4 - ax
      // 5 - ay
      // 6 - az
      // 7 - f1..f6
      // 8 - голосовые команды. по умолчанию 0x00, 1-6 - номер команды
  }
  }

  // void analogWrite (int port, int value)
// {
	// pinMode(port, OUTPUT);
	// SoftPWMSet(port, value);
// }