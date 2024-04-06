#include "HumanB.hpp"

HumanB::HumanB(void) : _name("default"), _weapon(NULL)
{
     std::cout << "HumanB default constructor called" << std::endl;
}

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
    std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::attack(void)
{
    std::cout << this->_name + " attacks with his " + this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}
