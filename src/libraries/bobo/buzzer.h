#ifndef BUZZER_H
#define BUZZER_H

#include "bobo.h"

void setupBuzzer(void);
void buzzFor(int miliseconds);
void disableBuzzer(void);
void ModeBEEP(int mode);
void BeepOnOffMode(void);

#endif