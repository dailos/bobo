#include "motor.h"

const int MR = 1; //Motor right
const int ML = 2; //Motor left
const int S=0; //Stop
const int F=1; //Forward
const int B=2; //Backward

void setupMotor()
{
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT); 
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT); 
  pinMode(RIGHT_MOTOR_BACK, OUTPUT); 
  pinMode(RIGHT_MOTOR_ON, OUTPUT); 
  pinMode(LEFT_MOTOR_ON, OUTPUT); 
}

void motor(int motor, int direction, int speed)
{
   if(motor == MR){
     switch(direction){
      case S: 
        digitalWrite(RIGHT_MOTOR_FORWARD,LOW);
        digitalWrite(RIGHT_MOTOR_BACK,LOW); 
        analogWrite(RIGHT_MOTOR_ON,0); 
        break;
      case F:      
        digitalWrite(RIGHT_MOTOR_FORWARD,HIGH);
        digitalWrite(RIGHT_MOTOR_BACK,LOW);   
        analogWrite(RIGHT_MOTOR_ON,speed);    
        break;  
      case B:
        digitalWrite(RIGHT_MOTOR_BACK,HIGH);  
        digitalWrite(RIGHT_MOTOR_FORWARD,LOW);  
        analogWrite(RIGHT_MOTOR_ON,speed);          
     }        
   }else{
     switch(direction){
      case S: 
        digitalWrite(LEFT_MOTOR_FORWARD,LOW);
        digitalWrite(LEFT_MOTOR_BACK,LOW);  
        analogWrite(LEFT_MOTOR_ON,0); 
        break;
      case F:      
        digitalWrite(LEFT_MOTOR_FORWARD,HIGH);
        digitalWrite(LEFT_MOTOR_BACK,LOW);   
        analogWrite(LEFT_MOTOR_ON,speed);    
        break;  
      case B:
        digitalWrite(LEFT_MOTOR_BACK,HIGH);  
        digitalWrite(LEFT_MOTOR_FORWARD,LOW);  
        analogWrite(LEFT_MOTOR_ON,speed);          
     }             
   }
}

void run(int speed)    
{
  motor(MR, F, speed);
  motor(ML, F, speed);    

  setLeds(LOW, LOW);
}

void stop()    
{
  motor(MR, S, 0);
  motor(ML, S, 0);  

  setLeds(HIGH, HIGH);
}

void left(int speed)   
{
  motor(MR, F, speed);
  motor(ML, S, 0);  

  setLeds(LOW, HIGH);
}

void spin_left(int speed)   
{
  motor(MR, F, speed);
  motor(ML, B, speed); 
 
  setLeds(LOW, HIGH);
}

void right(int speed)    
{  
  motor(MR, S, 0);
  motor(ML, F, speed);  

  setLeds(HIGH, LOW);
}

void spin_right(int speed)    
{
  motor(MR, B, speed);
  motor(ML, F, speed); 

  setLeds(HIGH, LOW);
}

void back(int speed)    
{
   motor(MR, B, speed);
   motor(ML, B, speed); 
 
  setLeds(HIGH, HIGH);
}