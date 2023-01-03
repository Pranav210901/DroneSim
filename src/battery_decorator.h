#pragma once
//done by holm0715
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "vec3.h"
 /*******************************************************************************
  * Class Definitions
  ******************************************************************************/
  /**
   * @brief a base class for battery decorators
   *
   */
class BatteryDecorator : public Entity {
public:
	/**
	* @brief constuctor, requires an entity and what it's batterylife should be
	*/
	BatteryDecorator(Entity* entity, double batteryLife) {
		this->entity = entity;
		this->batteryLife = batteryLife;
	}
	/**
	* @brief Virtual update class, does nothing in base form but can be updated
	*/
	virtual void Update(double dt) = 0;
	/**
	* @brief Virtual FinishUpdate class, does nothing in base form but can be updated
	*/
	virtual void FinishUpdate(double dt) = 0;
protected:
	/**
	* @brief Entity the battery is decorating
	*/
	Entity* entity;
	/**
	* @brief Double containing the current batteryLife
	*/
	double batteryLife;
};

