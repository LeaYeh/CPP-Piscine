#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string _type;
    Weapon(void);
public:
    Weapon(const std::string &type);
    ~Weapon(void);

    std::string getType(void);
    void setType(const std::string &type);
};

#endif