#ifndef BUZZER_H
#define BUZZER_H

#include "Arduino.h"
#include "definitions.h"

void setupBuzzer(void);
void buzzFor(int miliseconds);
void disableBuzzer(void);
void ModeBEEP(int mode);
void BeepOnOffMode(void);

#endif