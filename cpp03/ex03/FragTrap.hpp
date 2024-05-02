#ifndef __FRAG_TRAP_H__
#define __FRAG_TRAP_H__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap &other);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &other);
    void highFivesGuys();

protected:
    static const int _HP = 100;
    static const int _EP = 100;
    static const int _AD = 30;

private:
    /* The private member from ClapTrap is not accessible from ScavTrap */
};

#endif
