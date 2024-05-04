#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
    std::cout << "Default constructor called: WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const std::string &type)
{
    std::cout << "Type constructor called: WrongAnimal(" << type << ")\n";
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Copy constructor called: WrongAnimal \n";
    this->type = other.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called: WrongAnimal\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal: balabala\n";
}

const std::string &WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::printInfo() const
{
    std::cout << "It is a " << this->getType() << ": ";
    this->makeSound();
}
