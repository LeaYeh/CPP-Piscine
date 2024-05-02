#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    ~Animal();
    Animal &operator=(const Animal &other);

    void makeSound();

protected:
    std::string type;

private:
};

#endif
