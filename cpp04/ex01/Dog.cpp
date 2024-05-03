#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default constructor called: Dog\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy constructor called: Dog\n";
}

Dog::~Dog()
{
    std::cout << "Destructor called: Dog\n";
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Copy operator called: Dog\n";
    this->_brain = other.getBrain();
    delete this->_brain;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog: wolf~~\n";
}

const std::string &Dog::getType() const
{
    return this->type;
}

Brain *Dog::getBrain() const
{
    return this->_brain;
}
