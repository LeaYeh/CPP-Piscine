#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor called: Animal\n";
}

Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor called: Animal \n";
    this->type = other.type;
}

Animal::~Animal()
{
    std::cout << "Destructor called: Animal\n";
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Animal::makeSound()
{
    std::cout << "Animal: balabala\n";
}
