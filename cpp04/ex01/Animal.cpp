#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor called: Animal\n";
}

Animal::Animal(const std::string &type)
{
    std::cout << "Type constructor called: Animal(" << type << ")\n";
    this->type = type;
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
    std::cout << "Copy operator & called: Animal\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal &Animal::operator=(const Animal *other)
{
    std::cout << "Copy operator * called: Animal\n";
    if (this != other)
        this->type = other->type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal: balabala\n";
}

const std::string &Animal::getType() const
{
    return this->type;
}
