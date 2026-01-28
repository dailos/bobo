#include "modes.h"

int _mode_ = 0;  // 0:remote control mode; 1:follow line mode ; 2: ultrasonic obstacle avoiding mode; 3: infrared follow mode
int _state_ = STOP; //  1:front 2:back 3:left 4:right 0:stop // State of vehicle 
int _speed_ = 100;


void modeLoop()
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
  switch (_state_)
  {    
    case STOP: stop(); break;
    case RUN: run(_speed_); break;
    case LEFT: left(_speed_); break;
    case RIGHT: right(_speed_); break;
    case BACK: back(_speed_); break;
    case TLEFT: spin_left(_speed_); break;
    case TRIGHT: spin_right(_speed_); break;
    case BUZZ:  buzzFor(1000); break;
    default: stop(); break;
  }
}

void obstacleAvoidingMode()
{
  int distance = getDistance();
  if (distance > 38) 
    run(_speed_);
  else
  {
    while (distance < 38)  
    {
      spin_right(_speed_);
      delay(90);
      stop();
      distance = getDistance();
    }
  }
}

void followLineMode()
{
  int line = isThereALine();

   switch (line){
    case LINE: run(_speed_) ;break;
    case LINE_LEFT: right(_speed_); break;
    case LINE_RIGHT: left(_speed_); break;
    default: stop(); break;
  }
}

void followMode()
{
  int obstacleStatus = isThereObstacle();

  switch (obstacleStatus){
    case OBSTACLE: stop(); break;
    case OBSTACLE_LEFT: right(_speed_); break;
    case OBSTACLE_RIGHT: left(_speed_); break;
    default: run(_speed_); break;
  }
}