#include "key.h"
int KEY = 13;

void setupKey()
{
  pinMode(KEY, INPUT_PULLUP);// Set button as input and internal pull-up mode
}

void checkMode(int &mode)
{
  int val;
  while (!digitalRead(KEY)) // When the button is pressed
  {
    delay(10);
    val = digitalRead(KEY);// Reads the button ,the level value assigns to val
    if (val == LOW) //Double check the button is pressed
    {
      if (mode == 0)// In Infrared remote control
      {
        mode = 1; // Switch to Bluetooth remote control
        //digitalWrite(LED, HIGH); //led lights up
      }
      else//In  Bluetooth remote control
      {
        mode = 0; //Switch to Infrared remote control
        //digitalWrite(LED, LOW); led lights off
      }
      buzzFor(100);     
      while (!digitalRead(KEY));	//Determine if the button is released or not
    }
    else
      disableBuzzer();      
  }
}