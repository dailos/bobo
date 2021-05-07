#ifndef DEFINITIONS_H
#define DEFINITIONS_H

enum {
  STOP = 0,
  RUN, 
  BACK,
  LEFT,
  RIGHT,
  TLEFT,
  TRIGHT,
  BUZZ
} State;

enum {
  REMOTE = 0,
  ULTRASONIC_OBSTACLE_AVOIDING,
  FOLLOW_LINE,  
  INFRARED_FOLLOW     
} Mode;

#endif