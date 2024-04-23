#include "Weapon.hpp"

Weapon::Weapon(void) : type("default") {}

Weapon::Weapon(const std::string &type) : type(type) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}
