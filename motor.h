#ifndef MOTOR_H
#define MOTOR_H

#include "definitions.h"
#include "Arduino.h"
#include "led.h"

void setupMotor();
void stateControl(int state);

void run();
void stop();
void left();
void spin_left();  
void right();
void spin_right();
void back();

void tckrunspeed();
void tckbrake();
void tckleftspeed();
void tckrightspeed();

#endif