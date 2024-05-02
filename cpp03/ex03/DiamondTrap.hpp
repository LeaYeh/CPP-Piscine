#ifndef __DIAMOND_TRAP_H__
#define __DIAMOND_TRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &other);

    void whoAmI();
    void printStatus() const;

private:
    std::string _name;
};

#endif
