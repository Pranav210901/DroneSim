
#include "physics_engine.h"

PhysicsEngine::PhysicsEngine(double acceleration, double max_speed) {
    this->acceleration = acceleration;
    this->max_speed = max_speed;
    this->physics_strategy = nullptr;
    accelerating = false;
}

PhysicsEngine::~PhysicsEngine() {
    delete physics_strategy;
}

void PhysicsEngine::Set_Strategy(PhysicsStrategy* physics_strategy) {
    delete this->physics_strategy;
    this->physics_strategy = physics_strategy;
}

double PhysicsEngine::Calculate(double current_spd, double dt) {
    int speed = physics_strategy->Calculate(current_spd, acceleration, dt, accelerating);
    accelerating = false;
    if (speed > max_speed) speed = max_speed;
    else if (speed < 0) speed = 0;
    
    return speed;
}
