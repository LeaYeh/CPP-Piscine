#ifndef __SCAV_TRIP_H__
#define __SCAV_TRIP_H__

#include "ClapTrap.hpp"

/*
class A
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
*/

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &other);
    void guardGate();
    void attack(const std::string &target);

protected:
    static const int _HP = 100;
    static const int _EP = 50;
    static const int _AD = 20;

private:
    /* The private member from ClapTrap is not accessible from ScavTrap */
};

#endif
