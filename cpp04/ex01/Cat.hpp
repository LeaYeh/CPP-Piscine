#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(const Cat &other);

    Brain *getBrain() const;
    const std::string &getType() const;
    void think(const std::string &idea);
    void makeSound() const;
    void printAllThought() const;

protected:
private:
    Brain *_brain;
};

#endif
