#ifndef BEELINE_H_
#define BEELINE_H_

/******************************************************************
 * Includes
 *****************************************************************/
#include "vec3.h"

/**
 * @copyright kruta007: Kathryn Kruta
 *
 */
/**
 * @brief the Beeline class, used to move the drone
 * It will move the drone towards towards a robot
 */

class Beeline {
 public:
 /**
  * @brief Beeline Move function, takes in the current position, the position to go to, and the current speed
  */
 
  void Move(Vec3 position, Vec3 goal, double speed);
 
};
#endif
