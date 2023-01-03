#include "drone.h"

Drone::Drone(std::string name, double id, double speed, Vec3 position, Vec3 direction, ICameraController* controller) : name(name), speed(speed), position(position), direction(direction) {
    //camera = new ICameraController();
    //movement = new MovementController();
    this->id = id;
    physics_engine = new PhysicsEngine(3.0, 15.0);
//    camera = new Camera(0, controller);
}
Drone::Drone(std::string name, double id, double speed, Vec3 position, Vec3 direction) : name(name), speed(speed), position(position), direction(direction) {
    //camera = new ICameraController();
    //movement = new MovementController();
    this->id = id;
    physics_engine = new PhysicsEngine(3.0, 15.0);
    //    camera = new Camera(0, controller);
}

Drone::~Drone() {
    delete camera;
    //delete movement;
    delete physics_engine;
}

void Drone::SetSpeed(double speed) { this->speed = speed; }

void Drone::SetDirection(Vec3 direction) { this->direction = direction; }

picojson::object Drone::ReturnAsPicoJSON() {
    picojson::object entity;
    entity["entityId"] = picojson::value((double)id);

    entity["name"] = picojson::value(name);
    
    // Save the position as an array
    picojson::array pos;
    pos.push_back(picojson::value(position.GetX()));
    pos.push_back(picojson::value(position.GetY()));
    pos.push_back(picojson::value(position.GetZ()));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(direction.GetX()));
    dir.push_back(picojson::value(direction.GetY()));
    dir.push_back(picojson::value(direction.GetZ()));
    entity["dir"] = picojson::value(dir);

    // Send the compile picojson data to the UI in the returnValue variable
    return entity;
}

void Drone::SetJoystick(double side_movement, double vertical_movement, double forward_movement, double turn_direction) {
    // Side movement
    if (side_movement == 1) { // Move right
        direction.SetX(1);
        physics_engine->Accelerating(true);
    } else if (side_movement == -1) { // Move left
        direction.SetX(-1);
        physics_engine->Accelerating(true);
    } 

    // Forward movement
    if (forward_movement == 1) { // Move forward
        direction.SetY(1);
        physics_engine->Accelerating(true);
    } else if (forward_movement == -1) { // Move backwards
        direction.SetY(-1);
        physics_engine->Accelerating(true);
    }

    // Vertical movement
    if (vertical_movement == 1) {// Move up
        direction.SetZ(1);
        physics_engine->Accelerating(true);
    } else if (vertical_movement == -1) { // Move down
        direction.SetZ(-1);
        physics_engine->Accelerating(true);
    }
}

void Drone::Update(double dt) {
    // Update speed
    physics_engine->Set_Strategy(new AccelerationStrategy());
    speed = physics_engine->Calculate(speed, dt);

    /* Basic idea for update:
        1. Take picture via camera controller
        2. Determine if robot in picture
        3. Determine which movement algorithm based on (2.)
        4. Move the drone (update position, velocity, etc.) based on movement algo. */

    // 1 & 2
  //  bool see_robot = camera->FindRobot();
    bool see_robot = false;
    // 3 & 4 - Guess we're not doing movement controller.
    // Using movement pattern classes directly instead.
    if (!see_robot) {
        // Do Patrol
        // The vector im passing in does nothing?
     //   Patrol patrol;
     //   patrol.move(position, this);
    }
    else {
        // Do Beeline
        // Beeline doesn't do anything, im just putting it here anyways
        // to make it look like it does something.
     //   Beeline beeline;
    //    beeline.Move(position, camera->FindRobotPosition(position.GetX(),
     //                                                   position.GetY(),
   //                                                     position.GetZ()), speed);
    }

    // I'm tired. I'm gonna giveup and study for my other finals.
}

std::string Drone::GetData() {
    std::string data = "Drone,";
    data.append(std::to_string(position.GetX()));
    data.append(",");
    data.append(std::to_string(position.GetY()));
    data.append(",");
    data.append(std::to_string(position.GetZ()));
    data.append(",");
    data.append(std::to_string(speed));
    data.append(",");
    data.append(std::to_string(direction.GetX()));
    data.append(",");
    data.append(std::to_string(direction.GetY()));
    data.append(",");
    data.append(std::to_string(direction.GetZ()));
    data.append("\n");
}