#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"


/* Notes:
    - virtual inherit scenario is for solving diamond issue
    - for simple inheritation structure the virtual inherit is not nescessary
    - when design a class which might be inherit in complex way, then could use virtual inherit for safety
*/
class Dog : public Animal
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
