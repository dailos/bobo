#include "definitions.h"
#include "motor.h"
#include "led.h"
#include "buzzer.h"
#include "key.h"
#include "infraredCom.h"
#include "distanceSensor.h"

int _mode_ = 0;  // 0:remote control mode; 1:follow line mode ; 2: ultrasonic obstacle avoiding mode; 3: infrared follow mode
int _state_ = STOP; //  1:front 2:back 3:left 4:right 0:stop // State of vehicle 

void setup()
{
  setupMotor();
  setupLed();
  setupBuzzer();
  setupKey();
  setupInfraredCom();
  setupDistanceSensors();
}

void loop()
{
  readIRCommand();
  checkKey();
  switch (_mode_)
  {
    case REMOTE : remoteMode(); break;
    case OBSTACLE_AVOIDING: obstacleAvoidingMode(); break;
    case FOLLOW_LINE: followLineMode(); break;    
    case FOLLOW: followMode(); break;
    default: break;
  }   
}

//*************MODES*********************

void remoteMode()
{  
  const int speed = 200;
  switch (_state_)
  {    
    case STOP: stop(); break;
    case RUN: run(speed); break;
    case LEFT: left(speed); break;
    case RIGHT: right(speed); break;
    case BACK: back(speed); break;
    case TLEFT: spin_left(speed); break;
    case TRIGHT: spin_right(speed); break;
    case BUZZ:  buzzFor(1000); break;
    default: stop(); break;
  }
}

void obstacleAvoidingMode()
{
  const int speed = 180;
  int distance = getDistance();
  if (distance < 38) 
  {
    delay(10);
    distance = getDistance();
    while (distance < 38)  
    {
      spin_right(speed);
      delay(90);
      stop();
      distance = getDistance();
    }
  }
  else
    run(speed);
}

void followLineMode()
{
  const int speed = 150;
  int RS = digitalRead(RIGHT_VERTICAL_IR_SENSOR);
  int LS = digitalRead(LEFT_VERTICAL_IR_SENSOR);

  if (LS == LOW && RS == LOW) 
    run(speed);  
  else if (LS == LOW & RS == HIGH)
   right(speed);
  else if (RS == LOW & LS ==  HIGH) 
    left(speed);
  else 
    stop();
}

void followMode()
{
  const int speed = 150;
  int RS = digitalRead(RIGHT_HORIZONTAL_IR_SENSOR);
  int LS = digitalRead(LEFT_HORIZONTAL_IR_SENSOR);
  if (LS == LOW && RS == LOW)
    run(speed);
  else if (LS == HIGH & RS == LOW)
    right(speed);
  else if (RS == HIGH & LS == LOW)
    left(speed);
  else 
    stop();
}
