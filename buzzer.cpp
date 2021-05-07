#include "buzzer.h"

int BUZZER = 12;

void setupBuzzer() {
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
}
void buzzFor(int miliseconds) {
  digitalWrite(BUZZER, HIGH);
  delay(miliseconds);
  digitalWrite(BUZZER, LOW);
}
void disableBuzzer() {
  digitalWrite(BUZZER, LOW);
}

void ModeBEEP(int mode)
{
  for (int i = 0; i < mode + 1; i++)
  {
    buzzFor(100);    
    delay(100);
  }
  delay(100);
  disableBuzzer();
}

void BeepOnOffMode()
{
  buzzFor(1000);
}