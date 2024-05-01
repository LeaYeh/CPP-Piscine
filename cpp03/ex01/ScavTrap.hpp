#ifndef __SCAV_TRIP_H__
#define __SCAV_TRIP_H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &other);

private:
    /* Inherit from parent */
};

#endif
