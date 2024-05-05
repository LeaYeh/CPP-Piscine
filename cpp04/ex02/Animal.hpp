#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

/*
Notes:
    - When a class include at least one pure vitrual function then the class is a abstract class
    - An abstract class can not have instance
    - The contructors can only be called in derived class
*/
class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);

    void printInfo() const;
    const std::string &getType() const;
    virtual void makeSound() const = 0;
    virtual void printAllThought() const = 0;

protected:
    Animal(const std::string &type);
    std::string type;

private:
};

#endif
