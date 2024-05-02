#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default constructor called: FragTrap\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, _HP, _EP, _AD)
{
    std::cout << "Constructor called: FragTrap(" << name << ")\n";
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
