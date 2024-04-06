#include "HumanB.hpp"

HumanB::HumanB(std::string& name) : _name(name) {}

HumanB::~HumanB(void) {}

std::string HumanB::attack(void)
{
    return this->_name + " attacks with his " + this->_weapon->getType();
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}
