#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Default constructor called: Cat\n";
    std::cout << "Address hold the brain:\t" << this->_brain << "\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy constructor called: Cat\n";
    *this->_brain = *other.getBrain();
}

Cat::~Cat()
{
    std::cout << "Destructor called: Cat\n";
    delete this->_brain;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Copy operator called: Cat\n";
    *this->_brain = *other.getBrain();
    std::cout << "Address hold by other:\t" << other._brain << "\n";
	std::cout << "Address hold by this:\t" << this->_brain << "\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat: meow~~\n";
}

const std::string &Cat::getType() const
{
    return this->type;
}

Brain *Cat::getBrain() const
{
    return this->_brain;
}

void Cat::think(const std::string &idea)
{
    this->getBrain()->setIdea()
}
