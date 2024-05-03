#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

// Notes: Function can be overwrite without virtual but virtual could let the function choose during the runtime
class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);

    virtual void makeSound() const;
    void printInfo() const;
    const std::string &getType() const;

protected:
    std::string type;
    Animal(const std::string &type);

private:
};

#endif
