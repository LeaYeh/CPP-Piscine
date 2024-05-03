#ifndef __WRONG_ANIMAL_H__
#define __WRONG_ANIMAL_H__

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const std::string &type);
    WrongAnimal(const WrongAnimal &other);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &other);

    void makeSound() const;
    const std::string &getType() const;

protected:
    std::string type;

private:
};

#endif
