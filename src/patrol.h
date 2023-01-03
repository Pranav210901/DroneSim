/**
 * @file patrol.h
 * @author Pranav Pokhrel (pokhr013@umn.edu)
 * @brief Patrol basically asks the drone to fly around in random directions in order to help locate the target
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PATROL_H_
#define PATROL_H_

#include "drone.h"
#include <iostream>
/**
 * @brief the Class Patrol inherits from MovementController which practically handles all of the mobility aspects of the drone
 * 
 */
class Patrol {

private:
	double pos[3];
	double dir[3];
	double speed;

public:
	/**
	 * @brief Construct a new Patrol object
	 *
	 */
	Patrol() {};
	/**
	 * @brief Destroy the Patrol object
	 *
	 */
	~Patrol() {};
	/**
	 * @brief takes in the parameters for the position and direction of the drone and update them frame by frame when update is called in webapp
	 *
	 * @param pos
	 * @param dir
	 */
	void Move(double* pos, double* dir, Drone drone);
	void SetJoystick(double x, double y, double z, double a);
};
#endif