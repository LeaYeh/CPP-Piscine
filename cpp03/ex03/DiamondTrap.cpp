#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "Default constructor called: DiamondTrap\n";
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name", FragTrap::_HP, ScavTrap::_EP, FragTrap::_AD)
{
    std::cout << "Constructor called: DiamondTrap\n";
    this->_name = name;
    this->printStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor called: DiamondTrap\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor called: DiamondTrap(" << this->getName() << ")\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Copy operator called: DiamondTrap\n";
    ClapTrap::operator=(other);
    this->_name = other.getName();
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->_name << ", but my ClapTrap name is " << ClapTrap::getName() << "\n";
}

void DiamondTrap::printStatus(void) const
{
    std::cout << "Name: " << this->_name << "; ";
    std::cout << "Hit Point: " << this->_hitPoint << "; ";
    std::cout << "Energe Point: " << this->_energyPoint << "; ";
    std::cout << "Attck Damage: " << this->_attackDamage << std::endl;
    std::cout << std::endl;
}
