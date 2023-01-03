#ifndef MANMOVE_H_
#define MANMOVE_H_

/******************************************************************
 * Includes
 *****************************************************************/
#include <iostream>
#include <stdio.h>
#include <string>
//#inlcude "MovementController.h"
#include "web_app.h"

/**
 * @copyright kruta007: Kathryn Kruta
 *
 */
/**
 * @brief The ManualMovement class, used to manually move the drone in the simulation
 * This class takes manual input from teh keyboard to move the drone around in the simulation
 */
class ManualMovement{
  /**
  * @brief The Move function, moves the drone based on keyboard input
  * Checks to see is keyboard input is being given and move the drove accoringly
  */
  void Move();
  /**
   * @returns true or false if a key on the keyboard in down
   */
  bool IsKeyDown(const std::string& key);
  /**
   * @brief sets the key values to 1
   */
  void KeyDown(const std::string& key, int keyCode);
  /**
   * @brief sets the key values to 0
   */
  void KeyUp(const std::string& key, int keyCode);
private:
	Drone drone;
	std::map<std::string, int> keyValue;
};

#endif
