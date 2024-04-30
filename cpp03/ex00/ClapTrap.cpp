#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "Default constructor called: ClapTrap\n";
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "Constructor called: ClapTrap(" << name << ")\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called: ClapTrap \n";
    this->_name = other.getName();
    this->_hitPoint = other.getHitPoint();
    this->_energyPoint = other.getEnergyPoint();
    this->_attackDamage = other.getAttackDamage();
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called: ClapTrap\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy operator called: ClapTrap\n";
    if (this != &other)
    {
        this->_name = other.getName();
        this->_hitPoint = other.getHitPoint();
        this->_energyPoint = other.getEnergyPoint();
        this->_attackDamage = other.getAttackDamage();
    }
    return *this;
}

const std::string& ClapTrap::getName(void) const
{
    return this->_name;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->_attackDamage;
}

int ClapTrap::getEnergyPoint(void) const
{
    return this->_energyPoint;
}

int ClapTrap::getHitPoint(void) const
{
    return this->_hitPoint;
}

void ClapTrap::printStatus(void) const
{
    std::cout << "Name: " << this->getName() << "; ";
    std::cout << "Hit Point: " << this->getHitPoint() << "; ";
    std::cout << "Energe Point: " << this->getEnergyPoint() << "; ";
    std::cout << "Attck Damage: " << this->getAttackDamage() << std::endl;
    std::cout << std::endl;
}

bool ClapTrap::checkAction(const std::string &action) const
{
    if (this->getHitPoint() <= 0 || this->getEnergyPoint() <= 0)
    {
        std::cout << this->getName() << " tried to " << action << ", but it ";
        if (this->getHitPoint() <= 0)
            std::cout << "is dead.\n";
        else if (this->getEnergyPoint() <= 0)
            std::cout << "is out of energe.\n";
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->checkAction("attack " + target))
        return;
    std::cout << "ClapTrap " << this->getName() << " attacks " << target \
            << ", causing " << this->getAttackDamage() << " points of damage!\n";
    this->_energyPoint--;
    this->printStatus();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->getName() << " be attacked " << amount << " hit points!\n";
    if (this->_hitPoint > (int)amount)
        this->_hitPoint -= amount;
    else
    {
        std::cout << this->getName() << " be killed!\n";
        this->_hitPoint = 0;
    }
    this->printStatus();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->checkAction("repair itself"))
        return;
    std::cout << this->getName() << " repaired " << amount << " hit points.\n";
    this->_hitPoint += amount;
    this->_energyPoint--;
    this->printStatus();
}
