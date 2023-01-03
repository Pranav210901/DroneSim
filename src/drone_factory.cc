#include "drone_factory.h"

Drone* DroneFactory::CreateEntity(picojson::object& entityData, ICameraController* controller) {
    // Get direction as a vector
    Vec3 direction = Vec3();
    picojson::array dir = entityData["direction"].get<picojson::array>();
    direction.SetX(dir[0].get<double>());
    direction.SetY(dir[1].get<double>());
    direction.SetZ(dir[1].get<double>());

    // Get direction as a vector
    Vec3 position = Vec3();
    picojson::array position_in = entityData["position"].get<picojson::array>();
    position.SetX(position_in[0].get<double>());
    position.SetY(position_in[1].get<double>());
    position.SetZ(position_in[1].get<double>());

    // Creation of the drone
    Drone* drone = new Drone(entityData["name"].get<std::string>(),
                            entityData["entityId"].get<double>(),
                            entityData["speed"].get<double>(),
                            position, 
                            direction, controller);
    return drone;
}
Drone* DroneFactory::CreateEntity(picojson::object& entityData) {
    // Get direction as a vector
    Vec3 direction = Vec3();
    picojson::array dir = entityData["direction"].get<picojson::array>();
    direction.SetX(dir[0].get<double>());
    direction.SetY(dir[1].get<double>());
    direction.SetZ(dir[1].get<double>());

    // Get direction as a vector
    Vec3 position = Vec3();
    picojson::array position_in = entityData["position"].get<picojson::array>();
    position.SetX(position_in[0].get<double>());
    position.SetY(position_in[1].get<double>());
    position.SetZ(position_in[1].get<double>());
    // Creation of the drone
    Drone* drone = new Drone(entityData["name"].get<std::string>(),
        entityData["entityId"].get<double>(),
        entityData["speed"].get<double>(),
        position,
        direction);
    return drone;
}
