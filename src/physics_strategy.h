#ifndef PHYSICS_STRATEGY_H_
#define PHYSICS_STRATEGY_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A strategy interface for the PhysicsEngine
 */
class PhysicsStrategy {
public:
    /**
    * @brief A virtual deconstructor.
    */
   // virtual ~PhysicsStrategy() = 0;
    /**
    * @brief A virtual method for calculating speed.
    * Takes 3 doubles for speed, acceleration and change in time, and a 
    * boolean to signify whether or not an entity is accelerating.
    * Returns a double.
    */
    virtual double Calculate(double current_spd, double acceleration, double dt, bool accelerating) = 0;
};

#endif