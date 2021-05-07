#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "Arduino.h"

/* Modes */
enum {
  REMOTE = 0,
  OBSTACLE_AVOIDING,
  FOLLOW_LINE,  
  FOLLOW     
} Mode;

/* Actions */
enum {
  STOP = 0,
  RUN, 
  BACK,
  LEFT,
  RIGHT,
  TLEFT,
  TRIGHT,
  BUZZ
} Actions;

/* Distance IR sensor*/
const int RIGHT_HORIZONTAL_IR_SENSOR = A4;
const int LEFT_HORIZONTAL_IR_SENSOR = A5;   

/* Follow Line IR Sensor*/
const int RIGHT_VERTICAL_IR_SENSOR = A3;
const int LEFT_VERTICAL_IR_SENSOR = A2;

/*IR receiver*/
const int IR_PIN = 2; 

/* Key button */
const int KEY = 13;

/* Buzzer */
const int BUZZER = 12;

/* Leds */
const int RIGHTLED=4;
const int LEFTLED=3;

/* Motor */
const int LEFT_MOTOR_BACK=6;       
const int LEFT_MOTOR_FORWARD=7;         

const int RIGHT_MOTOR_FORWARD=9;       
const int RIGHT_MOTOR_BACK=8;   

const int RIGHT_MOTOR_ON=10;                                  
const int LEFT_MOTOR_ON=5;  
 
#endif