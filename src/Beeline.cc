#include "Beeline.h"

void Beeline::Move(Vec3 position, Vec3 goal, double speed){
  Vec3 distance = Vec3();
  distance = goal - position;
  distance.Normalize();
  Vec3 new_velocity = Vec3();
  new_velocity = distance * speed;
}
