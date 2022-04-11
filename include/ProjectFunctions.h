#ifndef PROJECTFUNCTIONS_H
#define PROJECTFUNCTIONS_H

#define BLYNK_PRINT Serial  //enabling output to Serial monitor of what Blynk.Edgent is doing for debugging purposes
#define BLYNK_TEMPLATE_ID "TMPLToQIqG4l"
#define BLYNK_DEVICE_NAME "IoT Based Automated Drug Infusion Device "
#define BLYNK_AUTH_TOKEN "illICME4BOjF-2xQrtZSCJBUcQVLvdez"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ezButton.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Arduino.h>
#include <BlynkSimpleEsp32.h>

#define DEBOUNCE_TIME 50 // the debounce time in millisecond, increase this time if it still chatters
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define motor_pin_1 26
#define motor_pin_2 25
#define motor_pin_3 33
#define motor_pin_4 32

#define DripPin  15  // the number of the Drip sensor pin
#define ledPin  13    // the number of the LED pin

extern ezButton buttonUp; 
extern ezButton buttonDown; 
extern ezButton buttonStart; 
extern ezButton buttonCancel;
extern ezButton buttonEnter; 

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
extern Adafruit_SSD1306 display;

//Global Variables
extern const int stepsPerRevolution;
extern volatile double FlowRate;
extern volatile double VTBI;
extern int Inf_Hours;
extern int Inf_Minutes;
extern int Inf_Seconds;
extern int totalSteps;
extern float rpm;
extern bool Start_Infuse;
extern bool Cancel_Infuse;

// variable for storing the drip status 
extern int pinState;
extern float dripCount;
extern float flowRate_RT;
extern unsigned long timePassed;
extern unsigned long lastTime;
extern unsigned long infStart_Time;
extern double infCounter;

//flags
extern volatile bool infState;

// Function Declarations
double FlowRate_Option ();
double VTBI_Option (double);
void Calibration_Infusion (double, double, double, int*, float*);
void Infusion_Duration(double, double, int*, int*, int*);
void Infusion_Process(int, unsigned long);
void stepMotor(int);
float SetSpeed(float, int);
void Send_Time (int, int, int, bool, int);
void TaskCcode( void * pvParameters );
void TaskDcode( void * pvParameters );

#endif
