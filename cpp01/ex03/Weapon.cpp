#include "Weapon.hpp"

Weapon::Weapon(void) : _type("default") {}

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon(void) {}

std::string Weapon::getType(void)
{
    return this->_type;
}

void Weapon::setType(const std::string& type)
{
    this->_type = type;
}
