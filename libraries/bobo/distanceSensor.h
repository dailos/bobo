#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "bobo.h"

void setupDistanceSensors(void);
float getDistance(void);
int isThereObstacle();
int isThereALine();

#endif