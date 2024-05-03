#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor called: Cat\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy constructor called: Cat\n";
}

Cat::~Cat()
{
    std::cout << "Destructor called: Cat\n";
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Copy operator called: Cat\n";
    Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow~~\n";
}
