#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("Cat")
{
    std::cout << "Default constructor called: Cat\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Copy constructor called: WrongCat\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called: WrongCat\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Copy operator called: Cat\n";
    WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: meow~~\n";
}

