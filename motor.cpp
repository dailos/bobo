#include "motor.h"

void setupMotor()
{
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT); 
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT); 
  pinMode(RIGHT_MOTOR_BACK, OUTPUT); 
  pinMode(RIGTH_MOTOR_ON, OUTPUT); 
  pinMode(LEFT_MOTOR_ON, OUTPUT); 
  digitalWrite(LEFT_MOTOR_ON, HIGH); 
  digitalWrite(RIGTH_MOTOR_ON, HIGH); 
}

void run(int speed)    
{
  digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);  
  digitalWrite(LEFT_MOTOR_FORWARD,HIGH); 
  digitalWrite(RIGHT_MOTOR_BACK,LOW);   
  digitalWrite(LEFT_MOTOR_BACK,LOW);

  analogWrite(RIGHT_MOTOR_FORWARD,speed);
  analogWrite(LEFT_MOTOR_FORWARD,speed);
  analogWrite(RIGHT_MOTOR_BACK,0);   
  analogWrite(LEFT_MOTOR_BACK,0);

  setLeds(LOW, LOW);
}

void stop()    
{
  digitalWrite(LEFT_MOTOR_BACK, LOW);
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACK, LOW);

  setLeds(HIGH, HIGH);
}

void left(int speed)   
{
  digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);	
  digitalWrite(RIGHT_MOTOR_BACK,LOW);
  digitalWrite(LEFT_MOTOR_FORWARD,LOW);   
  digitalWrite(LEFT_MOTOR_BACK,LOW); 

  analogWrite(RIGHT_MOTOR_FORWARD,speed); 
  analogWrite(RIGHT_MOTOR_BACK,0);
  analogWrite(LEFT_MOTOR_FORWARD,0); 
  analogWrite(LEFT_MOTOR_BACK,0); 
  
  setLeds(HIGH, LOW);
}

void spin_left(int speed)   
{
  digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);
  digitalWrite(LEFT_MOTOR_BACK,HIGH);
  digitalWrite(RIGHT_MOTOR_BACK,LOW);    
  digitalWrite(LEFT_MOTOR_FORWARD,LOW);  
  
  analogWrite(RIGHT_MOTOR_FORWARD,speed);
  analogWrite(LEFT_MOTOR_BACK,speed);
  analogWrite(LEFT_MOTOR_FORWARD,0); 
  analogWrite(RIGHT_MOTOR_BACK,0);
 
  setLeds(HIGH, LOW);
}

void right(int speed)    
{
  digitalWrite(LEFT_MOTOR_FORWARD,HIGH);
  digitalWrite(LEFT_MOTOR_BACK,LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD,LOW);   
  digitalWrite(RIGHT_MOTOR_BACK,LOW);

  analogWrite(LEFT_MOTOR_FORWARD,speed);
  analogWrite(RIGHT_MOTOR_FORWARD,0); 
  analogWrite(RIGHT_MOTOR_BACK,0);    
  analogWrite(LEFT_MOTOR_BACK,0);

  setLeds(LOW, HIGH);
}

void spin_right(int speed)    
{
  digitalWrite(LEFT_MOTOR_FORWARD,HIGH);
  digitalWrite(RIGHT_MOTOR_BACK,HIGH);
  digitalWrite(RIGHT_MOTOR_FORWARD,LOW);  
  digitalWrite(LEFT_MOTOR_BACK,LOW);

  analogWrite(LEFT_MOTOR_FORWARD,speed);
  analogWrite(RIGHT_MOTOR_BACK,speed);  
  analogWrite(RIGHT_MOTOR_FORWARD,0);        
  analogWrite(LEFT_MOTOR_BACK,0);

  setLeds(LOW, HIGH);
}

void back(int speed)    
{
  digitalWrite(RIGHT_MOTOR_BACK,HIGH);
  digitalWrite(LEFT_MOTOR_BACK,HIGH);
  digitalWrite(RIGHT_MOTOR_FORWARD,LOW); 
  digitalWrite(LEFT_MOTOR_FORWARD,LOW);
 
  analogWrite(RIGHT_MOTOR_FORWARD,0);

  analogWrite(RIGHT_MOTOR_BACK,speed);
  analogWrite(LEFT_MOTOR_BACK,speed); 
  analogWrite(RIGHT_MOTOR_FORWARD,0);
  analogWrite(LEFT_MOTOR_FORWARD,0);
 
  setLeds(LOW, HIGH);
}