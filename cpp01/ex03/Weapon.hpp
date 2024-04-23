#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
    Weapon(void);

public:
    Weapon(const std::string &type);
    ~Weapon(void);

    const std::string &getType(void) const;
    void setType(const std::string &type);
};

#endif
