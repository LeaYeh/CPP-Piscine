#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << this->_name << " constructor called" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << this->_name << " destructor called" << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->getName() << " attacks with his " << this->getWeaponType() << std::endl;
}

std::string HumanA::getName(void)
{
    return this->_name;
}

std::string HumanA::getWeaponType(void)
{
    return this->_weapon.getType();
}
