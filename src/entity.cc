#include "entity.h"


std::string Entity::GetName() { return name; }
double Entity::GetID() { return id; };
void Entity::SetName(std::string name) {
    this->name = name;
}