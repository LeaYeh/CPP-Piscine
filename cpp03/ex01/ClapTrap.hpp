#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &other);

    const std::string &getName(void) const;
    int getHitPoint(void) const;
    int getEnergyPoint(void) const;
    int getAttackDamage(void) const;
    void printStatus(void) const;
    bool checkAction(const std::string &action) const;
    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    std::string _name;
    int _hitPoint;
    int _energyPoint;
    int _attackDamage;
};

#endif
