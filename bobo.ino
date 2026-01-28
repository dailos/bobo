#include "libraries/bobo/bobo.h"

int speed = 100;
int _turn_delay_ = 200; 


void setup()
{
  setupBobo();
}

void loop()
{
    int obstacle = isThereObstacle();

    switch (obstacle){
      case OBSTACLE: 
        right(speed);
        buzzFor(100);
        delay(_turn_delay_);
        buzzFor(100);
        break;
      case OBSTACLE_LEFT: 
        spin_right(speed); 
        buzzFor(100);
        delay(_turn_delay_);
        break;
      case OBSTACLE_RIGHT: 
        spin_left(speed); 
        buzzFor(100);
        delay(_turn_delay_);
        break;
      default: 
        run(speed); 
        break;
    }
}