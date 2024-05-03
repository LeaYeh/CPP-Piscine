#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat : virtual public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(const Cat &other);

    void makeSound() const;
    const std::string &getType() const;

protected:
private:
};

#endif
