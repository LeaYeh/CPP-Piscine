#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void)
{
    std::cout << this->getName() << " attacks with his " << std::endl;
}

std::string HumanA::getName(void)
{
    return this->_name;
}

std::string HumanA::getWeaponType(void)
{
    return this->_weapon.getType();
}
