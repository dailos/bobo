#include "src/libraries/bobo/bobo.h"

void setup()
{
  setupBobo();
}

void loop()
{
    int speed = 100;
    int turn_delay = 200; 
    int obstacle = isThereObstacle();

    switch (obstacle){
      case OBSTACLE: 
        right(speed);
        buzzFor(100);
        delay(turn_delay);
        buzzFor(100);
        break;
      case OBSTACLE_LEFT: 
        spin_right(speed); 
        buzzFor(100);
        delay(turn_delay);
        break;
      case OBSTACLE_RIGHT: 
        spin_left(speed); 
        buzzFor(100);
        delay(turn_delay);
        break;
      default: 
        run(speed); 
        break;
    }
}