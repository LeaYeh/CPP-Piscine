#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

/*
Notes:
    - If no virtual infront of ~Animal() this will only call Animal's destructor, not child class (e.g. Cat)
    - And it will occur a leak, because the child destructor not be called
*/
class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);
    Animal &operator=(const Animal *other);

    void printInfo() const;
    virtual const std::string &getType() const;
    virtual void makeSound() const;
    virtual void printAllThought() const;

protected:
    Animal(const std::string &type);
    std::string type;

private:
};

#endif
