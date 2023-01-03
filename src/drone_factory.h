#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "entity_factory.h"
#include "drone.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A factory for drone creation. 
 * Derived from EntityFactory.
 */
class DroneFactory : public EntityFactory {
public:
    /**
    * @brief Creates a drone using a picojson object.
    * Returns a drone pointer.
    */
    Drone* CreateEntity(picojson::object& entityData, ICameraController* controller);
    Drone* CreateEntity(picojson::object& entityData);
private:
};

#endif