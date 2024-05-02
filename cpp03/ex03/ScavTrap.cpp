#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called: ScavTrap\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, _HP, _EP, _AD)
{
    std::cout << "Constructor called: ScavTrap(" << name << ")\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor called: ScavTrap\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called: ScavTrap(" << this->getName() << ")\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Copy operator called: ScavTrap\n";
    ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "Gate keeper mode\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (!this->checkAction("attack " + target))
        return;
    std::cout << "ScavTrap " << this->getName() << " attacks " << target
              << ", causing " << this->getAttackDamage() << " points of damage!\n";
    this->_energyPoint--;
    this->printStatus();
}
