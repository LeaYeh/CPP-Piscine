#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon&     _weapon;

public:
    HumanA::HumanA(std::string name, Weapon& weapon);
    HumanA::~HumanA(void);
    void attack(void);
    std::string getName(void);
    std::string getWeaponType(void);
};

#endif
