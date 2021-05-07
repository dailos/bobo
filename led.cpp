#include "led.h"

int RIGHTLED=4;
int LEFTLED=3;

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
