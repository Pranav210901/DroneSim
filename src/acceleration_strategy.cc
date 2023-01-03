#include "acceleration_strategy.h"

double AccelerationStrategy::Calculate(double current_spd, double acceleration, double dt, bool accelerating) {
    int speed = current_spd;
    if (accelerating) {
        speed += acceleration * dt;
        accelerating = false;
    }
    else {
        speed -= acceleration * dt;
    }
    return speed;
}