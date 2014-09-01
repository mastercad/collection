#include <iostream>
#include "Entity.h"

std::string Entity::getName() const {
  return _sName;
}

void Entity::setName(const std::string sName) {
  _sName = sName;
}

Entity::Entity() {

}

Entity::~Entity() {
}
