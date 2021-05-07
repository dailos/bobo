#include "led.h"

void setupLed()
{
  pinMode(LEFTLED, OUTPUT);
  pinMode(RIGHTLED, OUTPUT);
}
void setLeds(int leftValue, int rightValue)
{
  digitalWrite(LEFTLED, leftValue);
  digitalWrite(RIGHTLED, rightValue);  
}
