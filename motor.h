#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "definitions.h"
#include "led.h"

void setupMotor(void);
void stateControl(int state);

void run(int speed);
void stop(void);
void left(int speed);
void spin_left(int speed);  
void right(int speed);
void spin_right(int speed);
void back(int speed);

#endif