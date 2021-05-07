#include "definitions.h"
#include "motor.h"
#include "led.h"
#include "buzzer.h"
#include "key.h"
#include "infraredCom.h"

int _mode_ = 0;  // 0:remote control mode; 1:follow line mode ; 2: ultrasonic obstacle avoiding mode; 3: infrared follow mode
int _state_ = STOP; //  1:front 2:back 3:left 4:right 0:stop // State of vehicle running state


/*Set Ultrasonic Sensor*/
int Echo = A1;  // Set Echo port
int Trig = A0; // Set Trig port
int Distance = 0;
/*Line Walking*/
const int SensorRight = A3;   	// Set Right Line Walking Infrared sensor port
const int SensorLeft = A2;     	// Set Left Line Walking Infrared sensor port
int SL;    // State of Left Line Walking Infrared sensor
int SR;    // State of Right Line Walking Infrared sensor
/*follow*/
const int SensorRight_2 = A4;     // Right Tracking Infrared sensor
const int SensorLeft_2 = A5;     // Left Tracking Infrared sensor
int SL_2;    // State of Left Tracking Infrared sensor
int SR_2;    // State of Right Tracking Infrared sensor

void setup()
{
  setupMotor();
  setupLed();
  setupBuzzer();
  setupKey();
  setupInfraredCom();

  pinMode(Echo, INPUT);    // Set Ultrasonic echo port as input
  pinMode(Trig, OUTPUT);   // Set Ultrasonic trig port as input

  pinMode(SensorRight, INPUT); // Set Right Line Walking Infrared sensor as input
  pinMode(SensorLeft, INPUT); // Set left Line Walking Infrared sensor as input
  Serial.begin(9600);
}

void loop()
{
  readIRCommand();
  switch (_mode_)
  {
    case REMOTE : remoteMode(); break;
    case ULTRASONIC_OBSTACLE_AVOIDING: ultrasonicObstacleAvoiding(); break;
    case FOLLOW_LINE: followLineMode(); break;    
    case INFRARED_FOLLOW: infraredFollowMode(); break;
    default: break;
  }   
}

void getDistance()   // Measuring front distance
{
  digitalWrite(Trig, LOW);   // set trig port low level for 2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  // set trig port high level for 10μs(at least 10μs)
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    // set trig port low level
  float Fdistance = pulseIn(Echo, HIGH);  // Read echo port high level time(unit:μs)
  Fdistance = Fdistance / 58;    // Distance(m) =(time(s) * 344(m/s)) / 2     /****** The speed of sound is 344m/s.*******/
                                 //  ==> 2*Distance(cm) = time(μs) * 0.0344(cm/μs)
                                 // ==> Distance(cm) = time(μs) * 0.0172 = time(μs) / 58
  Distance = Fdistance;
}

//*************MODES*********************

void remoteMode()
{  
  switch (_state_)
  {    
    case STOP: stop(); break;
    case RUN: run(); break;
    case LEFT: left(); break;
    case RIGHT: right(); break;
    case BACK: back(); break;
    case TLEFT: spin_left(); break;
    case TRIGHT: spin_right(); break;
    case BUZZ:  buzzFor(1000); break;
    default: stop(); break;
  }
}

void ultrasonicObstacleAvoiding()
{
  getDistance();// Measuring front distance

  if (Distance < 38) ////The value is the distance that meets the obstacle, and can be set according to the actual situation
  {
    delay(10);
    getDistance();////Measuring front distance
    while (Distance < 38)  //Determine whether there is an obstruction again.If there is obstacle , turn the direction and determine again
    {

      spin_right();//Right rotation for 90ms
      delay(90);
      stop();//stop
      getDistance();////Measuring front distance
    }
  }
  else
    run();//There is nothing obstacled. Go  Advance
}


void followLineMode()
{
  SR = digitalRead(SensorRight);//Right Line Walking Infrared sensor against white undersurface,then LED[L2] light illuminates and while against black undersurface,LED[L2] goes off
  SL = digitalRead(SensorLeft);//Left Line Walking Infrared sensor against white undersurface,then LED[L3] light illuminates and while against black undersurface,LED[L3] goes off

  if (SL == LOW && SR == LOW) // Black lines were not detected at the same time
    tckrunspeed();  // go ahead
  else if (SL == LOW & SR == HIGH)// Left sensor against white undersurface and right against black undersurface , the car left off track and need to adjust to the right.
   tckrightspeed();
  else if (SR == LOW & SL ==  HIGH) // Rihgt sensor against white undersurface and left against black undersurface , the car right off track and need to adjust to the left.
    tckleftspeed();
  else // Black lines were detected at the same time , the car stop.
    tckbrake();
}


void infraredFollowMode()
{
 /**************************************************************************************
  Infrared signal back means there is something obstacled ,returns low level and led lights up.
  Infrared signal gone means there is nothing obstacled ,returns high level and led lights off.
  **************************************************************************************/
  SR_2 = digitalRead(SensorRight_2);//Right infrared sensor detects the obstacle,then LED[L5] light illuminates and otherwise it goes off.
  SL_2 = digitalRead(SensorLeft_2);//Left infrared sensor detects the obstacle,then LED[L4] light illuminates and otherwise it goes off.
  if (SL_2 == LOW && SR_2 == LOW)//There is something obstacled ,goes and follow it.
    run();
  else if (SL_2 == HIGH & SR_2 == LOW)// There is something obstacled on the right then LED[L4] light illuminates,turns right and follow.
    right();
  else if (SR_2 == HIGH & SL_2 == LOW)// There is something obstacled on the left then LED[L4] light illuminates,turns left and follow.
    left();
  else // There is nothing obstacled , stop.
    stop();
}
