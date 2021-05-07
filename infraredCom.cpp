#include "infraredCom.h"

extern int _mode_;
extern int _state_;

IRrecv irrecv(IR_PIN);
decode_results results; // Store infrared remote decode data
unsigned long last = millis();

void setupInfraredCom()
{
  irrecv.enableIRIn();
  pinMode(IR_PIN, INPUT_PULLUP);  
}

void setMode(unsigned long  value)
{
  switch (value){
    case 0x00FD00FF: _mode_ = REMOTE;  ModeBEEP(_mode_); break; // 1  
    case 0x00FD807F: _mode_ = OBSTACLE_AVOIDING;  ModeBEEP(_mode_); break; // 2  
    case 0x00FD40BF: _mode_ = FOLLOW_LINE;  ModeBEEP(_mode_); break; //3   
    case 0x00FD20DF: _mode_ = FOLLOW;  ModeBEEP(_mode_); break; //4  
    default: break;
  }
}

void setState(unsigned long  value)
{
  switch (value){        
    case 0x00FDB04F:  _state_ = BUZZ; break;  //   0  beep  OFF/ON
    case 0x00FD8877:  _state_ = RUN; break;    // up  Advance
    case 0x00FD28D7:  _state_ = LEFT; break;   // <   Turn left
    case 0x00FDA857:  _state_ = STOP; break;   // ok   Stop
    case 0x00FD6897:  _state_ = RIGHT; break;  // >   Turn right
    case 0x00FD9867:  _state_ = BACK; break;   //  DW  Back
    case 0x00FD30CF:  _state_ = TLEFT; break;  // *  Left rotation
    case 0x00FD708F:  _state_ = TRIGHT; break; // #  right rotation
    default: break; //Stay the same
  }
}

void readIRCommand()
{
  if (irrecv.decode(&results))  {
    setMode(results.value);
    if (_mode_ == REMOTE)
      setState(results.value);    
    last = millis();
    irrecv.resume(); // received next Infrared decode
  }else if (millis() - last > 120){
    _state_ = STOP;
    last = millis();    
  }

}