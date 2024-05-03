#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
public:
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(const Dog &other);

    void makeSound() const;
    const std::string &getType() const;
    Brain *getBrain() const;

protected:
private:
    Brain *_brain;
};

#endif