#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called: ScavTrap\n";
    this->_name = "";
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
    std::cout << "Constructor called: ScavTrap(" << name << ")\n";
    this->_name = name;
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "Copy constructor called: ScavTrap\n";
    this->_attackDamage = other.getAttackDamage();
    this->_energyPoint = other.getEnergyPoint();
    this->_hitPoint = other.getHitPoint();
    this->_name = other.getName();
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
    this->guardGate();
    if (!this->checkAction("attack " + target))
        return;
    std::cout << "ScavTrap " << this->getName() << " attacks " << target \
            << ", causing " << this->getAttackDamage() << " points of damage!\n";
    this->_energyPoint--;
    this->printStatus();
}
