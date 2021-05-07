#include "key.h"

extern int _mode_;

void setupKey()
{
  pinMode(KEY, INPUT_PULLUP);
}

void checkKey(void)
{
  int val;
  while (!digitalRead(KEY)) // When the button is pressed
  {
    delay(10);
    val = digitalRead(KEY);// Reads the button ,the level value assigns to val
    if (val == LOW) //Double check the button is pressed
    {
      if(_mode_ != FOLLOW)
        _mode_ = _mode_ + 1;
      else
        _mode_ = REMOTE;
      
      buzzFor(100);     
      while (!digitalRead(KEY));	//Determine if the button is released or not
    }
    else
      disableBuzzer();      
  }
}