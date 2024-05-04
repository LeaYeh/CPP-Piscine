#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);
    Animal &operator=(const Animal *other);

    virtual void makeSound() const;
    void printInfo() const;
    virtual const std::string &getType() const;

protected:
    std::string type;

private:
};

#endif
