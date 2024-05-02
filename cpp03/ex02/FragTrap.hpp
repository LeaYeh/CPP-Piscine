#ifndef __FRAG_TRAP_H__
#define __FRAG_TRAP_H__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap &other);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &other);
    void highFivesGuys();

private:
    /* The private member from ClapTrap is not accessible from ScavTrap */
};

#endif
