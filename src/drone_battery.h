#pragma once
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "vec3.h"
#include "drone.h"
#include "battery_decorator.h"
#include "Beeline.h"
 /*******************************************************************************
  * Class Definitions
  ******************************************************************************/
  /**
   * @brief A drone battery decorator for the drone class
   * Derived from battery decorator
   */
class DroneBattery : public BatteryDecorator {
	//Needs further testing after Drone is done.
public:
	/**
	* @brief Constuctor, requires drone and batteryLife
	*/
	DroneBattery(Drone* drone, double batteryLife);
	/**
	* @brief Sets the location of the recharge station
	*/
	void SetStationLoc(Vec3 loc);
	/**
	* @brief Updates the batterylife of the drone battery, decreasing it if it's not at a recharge station and increasing it if it is and is not fully charged.
	* Will also call the update function of the drone it decorates, if it has battery. If it does not it simply sets the drones speed to 0.
	* If need charge is true it will make the drone beeline to the station.
	*/
	void Update(double dt);
	/**
	* @brief Will check if drone is reaching point where it will not have enough batterylife to make it back to a charging station, and if so it will change needCharge to true
	*/
	void FinishUpdate(double dt);
private:
	/**
	* @brief Drone Decorated by the battery
	*/
	Drone* drone;
	/**
	* @brief Bool stating whether the drone needs to charge or nto
	*/
	bool needCharge;
	/**
	* @brief double for batteryLife remaining
	*/
	double batteryLife;
	/**
	* @brief Vec3 Containing location of station
	*/
	Vec3 stationLoc;
};
