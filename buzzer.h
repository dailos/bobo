#ifndef BUZZER_H
#define BUZZER_H

#include "Arduino.h"

void setupBuzzer();
void buzzFor(int miliseconds);
void disableBuzzer();
void ModeBEEP(int mode);
void BeepOnOffMode();

#endif