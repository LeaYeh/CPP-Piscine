#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default constructor called: FragTrap\n";
}

FragTrap::FragTrap(const std::string &name)
{
    std::cout << "Constructor called: FragTrap(" << name << ")\n";
    this->_name = name;
    this->_hitPoint = 100;
    this->_energyPoint = 10;
    this->_attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor called: FragTrap\n";
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called: FragTrap(" << this->getName() << ")\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Copy operator called: FragTrap\n";
    ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->getName() << ": high fives guys\n";
}
