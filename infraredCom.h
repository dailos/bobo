#ifndef INFRAREDCOM_H
#define INFRAREDCOM_H

#include "IRremote.h"
#include "definitions.h"
#include "Arduino.h"
#include "buzzer.h"

void setupInfraredCom(void);
void readIRCommand(void);

#endif