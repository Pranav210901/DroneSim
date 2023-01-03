#ifndef ACCELERATION_STRATEGY_H_
#define ACCELERATION_STRATEGY_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "physics_strategy.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An Acceleration Strategy derived from the Physics Strategy.
 * Acceleration Strategy is a physics strategy that is used to calculate
 * the speed of an entity given its acceleration and current speed.
 */
class AccelerationStrategy : public PhysicsStrategy {
public:
    /**
    * @brief Calculates the speed of an entity.
    * Takes four inputs: the current speed of an entity, its acceleration, the
    * change it time, and a boolean stating whether or not it is accelerating.
    * The returned double is the sum of the current speed and the product of acceleration and double.
    * If accelerating is false, however, the product will be subtracted from the current speed.
    */
    double Calculate(double current_spd, double acceleration, double dt, bool accelerating) override;

};

#endif