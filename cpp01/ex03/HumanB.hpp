#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(const std::string &name);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon &weapon);
};

#endif
