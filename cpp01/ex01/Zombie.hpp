#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
public:
    Zombie(void);
    ~Zombie(void);

    void announce(void) const;
    void set_name(std::string name);

private:
    std::string _name;
};

#endif
