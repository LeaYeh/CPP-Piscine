#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : virtual public Animal
{
public:
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(const Dog &other);

    void makeSound() const;

protected:
private:
};

#endif
