#ifndef DRONE_H_
#define DRONE_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "vec3.h"
#include "camera.h"
#include "Beeline.h"
//#include "movement_controller.h"
#include "physics_engine.h"
#include "acceleration_strategy.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A drone class derived from entity.
 */
class Drone : public Entity {
public:
    /**
    * @brief Constructor for the drone class.
    * Takes a string for the name, two doubles for the id and speed, and
    * two Vec3s for the position and direction of the drone.
    */
    Drone(std::string name, double id, double speed, Vec3 position, Vec3 direction, ICameraController* controller);
    Drone(std::string name, double id, double speed, Vec3 position, Vec3 direction);
    /**
    * @brief Deconstructor for the drone class.
    * Deletes all dynamically allocated objects.
    */
    ~Drone();

    /**
    * @brief Getter for the drone's position.
    * Returns a Vec3.
    */
    Vec3 GetPosition() { return position; }
    /**
    * @brief Getter for the drone's direction.
    * Returns a Vec3.
    */
    Vec3 GetDirection() { return direction; }
    /**
    * @brief Getter for the drone's name.
    * Returns a string.
    */
    std::string GetName() { return name; }
    /**
    * @brief Setter for the drone's speed.
    * Takes a double.
    */
    double GetSpeed() {return speed;}
    /**
    * @brief Setter for the drone's speed.
    * Takes a double.
    */
    void SetSpeed(double speed);
    /**
    * @brief Setter for the drone's direction.
    * Takes a Vec3.
    */
    
    void SetDirection(Vec3 direction);
    /**
    * @brief Updates the drone's position.
    * Using its current speed and PhysicsEngine, calculates its
    * new speed and position.
    * Takes a double for the change in time.
    */
    void Update(double dt);
    /**
    * @brief Returns a PicoJSON object of the drone.
    */
    picojson::object ReturnAsPicoJSON();
    /**
    * @brief Sets the direction for the drone based on manual movement.
    * Takes four doubles denoting the side, vertical, forward, and turn movement.
    */
    void SetJoystick(double side_movement, 
                    double vertical_movement, 
                    double forward_movement, 
                    double turn_direction);
    /**
    * @brief Gets the data of the entity as a string for data collection.
    */
    std::string GetData();

    /**
    * @brief Prevents cloning.
    */
    Drone(const Drone& drone) = delete;
    /**
    * @brief Prevents assigning.
    */
    Drone& operator=(const Drone& drone) = delete;

private:
    /**
    * @brief A double for the drone's speed.
    */
    double speed;
    /**
    * @brief A string for the drone's name.
    */
    std::string name;
    /**
    * @brief A pointer to the drone's physics engine
    */
    PhysicsEngine* physics_engine;
    /**
    * @brief A Vec3 of the drone's position.
    */
    Vec3 position;
    /**
    * @brief A Vec3 of the drone's direction.
    */
    Vec3 direction;
    /**
    * @brief A camera pointer for the drone.
    */
    Camera* camera;
    /**
    * @brief A MovementController pointer for the drone.
    */
    //MovementController* movement;
};

#endif