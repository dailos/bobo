#include "distanceSensor.h"

/*Ultrasonic Sensor*/
int ECHO = A1;  // Set Echo port
int TRIG = A0; // Set Trig port

void setupDistanceSensors(void)
{
  // Set Ultrasonic ports as input
  pinMode(ECHO, INPUT);   
  pinMode(TRIG, OUTPUT); 

  // Set Follow Line IR sensor as input
  pinMode(RIGHT_VERTICAL_IR_SENSOR, INPUT);
  pinMode(LEFT_VERTICAL_IR_SENSOR, INPUT); 

    // Set Distance IR sensor as input
  pinMode(RIGHT_HORIZONTAL_IR_SENSOR, INPUT);
  pinMode(LEFT_HORIZONTAL_IR_SENSOR, INPUT); 
}

/*
 Read echo port high level time(unit:μs)
 Distance(m) =(time(s) * 344(m/s)) / 2  (The speed of sound is 344m/s)
 2*Distance(cm) = time(μs) * 0.0344(cm/μs)
 */
float getDistance(void) 
{
  digitalWrite(TRIG, LOW);   
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);  
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);    
  float distance = pulseIn(ECHO, HIGH);  
  return distance / 58;  
}

int isThereObstacle()  
{
  int RS = digitalRead(RIGHT_HORIZONTAL_IR_SENSOR);
  int LS = digitalRead(LEFT_HORIZONTAL_IR_SENSOR);
  if (LS == LOW && RS == LOW) 
    return OBSTACLE;
  else if (LS == LOW & RS == HIGH)
   return OBSTACLE_LEFT;
  else if (RS == LOW & LS ==  HIGH) 
    return OBSTACLE_RIGHT;
  else 
    return NO_OBSTACLE;
}

int isThereALine()  
{
  int RS = digitalRead(RIGHT_VERTICAL_IR_SENSOR);
  int LS = digitalRead(LEFT_VERTICAL_IR_SENSOR);
  if (LS == LOW && RS == LOW) 
    return NO_LINE;
  else if (LS == LOW & RS == HIGH)
   return LINE_LEFT;
  else if (RS == LOW & LS ==  HIGH) 
    return LINE_RIGHT;
  else 
    return LINE;
}