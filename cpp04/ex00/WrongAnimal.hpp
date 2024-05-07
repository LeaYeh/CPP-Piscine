#ifndef __WRONG_ANIMAL_H__
#define __WRONG_ANIMAL_H__

#include <iostream>

/*
Notes:
    - Since virtual is not used, this type of inheritance does not support polymorphism. This means:
        - The method call will completely depend on the object's static type (compile-time type).
        - If you have a pointer or reference of type WrongAnimal pointing to a WrongCat object, and you call makeSound() through it,
            it will call WrongAnimal's makeSound(), not WrongCat's, because dynamic binding does not occur.
*/
class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &other);

    void makeSound() const;
    void printInfo() const;
    const std::string &getType() const;

protected:
    std::string type;
    WrongAnimal(const std::string &type);

private:
};

#endif
