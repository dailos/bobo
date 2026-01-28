#include "bobo.h"

void setupBobo()
{
  setupMotor();
  setupLed();
  setupBuzzer();
  setupKey();
  setupInfraredCom();
  setupDistanceSensors();
}