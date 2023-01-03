#ifndef PHYSICS_ENGINE_H_
#define PHYSICS_ENGINE_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "physics_strategy.h"
#include <stdio.h>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A basic Physics Engine using the Strategy pattern.
 * Calculates the speed of an entity based on physics principles such as 
 * acceleration, wind, and gravity.
 */
class PhysicsEngine {
public:
    /**
    * @brief Constructor for the Physics Engine.
    * Takes in two doubles: the base acceleration of an entity, and its
    * maximum speed in any direction.
    * Sets accelerating to false and physics_strategy to null.
    */
    PhysicsEngine(double acceleration, double max_speed);
    /**
    * @brief Deconstructor for the Physics Engine.
    * Deletes the physics_strategy.
    */
    virtual ~PhysicsEngine();

    /**
    * @brief Gets the acceleration.
    * Returns as a double.
    */
    double GetAcceleration() { return acceleration; }
    /**
    * @brief Sets the acceleration.
    * Takes a double.
    */
    void SetAcceleration(double accel) { acceleration = accel; }

    /**
    * @brief Gets the maximum speed.
    * Returns as a double.
    */
    double GetMaxSpeed() { return max_speed; }
    /**
    * @brief Sets the maximum speed.
    * Takes a double.
    */
    void SetMaxSpeed(double speed) { max_speed = speed; }
    
    /**
    * @brief Changes whether or not an entity is accelerating.
    * Takes a boolean.
    */
    void Accelerating(bool accel) { accelerating = accel; }

    /**
    * @brief Sets the PhysicsStrategy being used by the engine.
    * Also deletes the old PhysicsStrategy.
    * Takes a PhysicsStrategy.
    */
    void Set_Strategy(PhysicsStrategy* physics_strategy);
    /**
    * @brief Calculates speeds using the current PhysicsStrategy.
    * Takes two doubles: The current speed and change in time.
    * Returns a double: The new speed.
    */
    double Calculate(double current_spd, double dt);

    /**
    * @brief Prevents cloning.
    */
    PhysicsEngine(const PhysicsEngine& physics_engine) = delete;
    /**
    * @brief Prevents assigning.
    */
    PhysicsEngine& operator=(const PhysicsEngine& physics_engine) = delete;
private:
    /**
    * @brief The engine's PhysicsStrategy. Used to determine how to calculate speed.
    */
    PhysicsStrategy* physics_strategy;
    /**
    * @brief A double for the entity's acceleration.
    */
    double acceleration;
    /**
    * @brief A double for the entity's maximum speed.
    */
    double max_speed;
    /**
    * @brief A boolean representing whether or not an entity is accelerating.
    */
    bool accelerating;


};

#endif