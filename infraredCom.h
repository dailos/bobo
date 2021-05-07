#ifndef INFRAREDCOM_H
#define INFRAREDCOM_H

#include "Arduino.h"
#include "definitions.h"
#include "IRremote.h"
#include "buzzer.h"

void setupInfraredCom(void);
void readIRCommand(void);

#endif