#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor called: Cat\n";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy constructor called: Cat\n";
    this->_brain = other.getBrain();
    // for (int i = 0; i < Brain::NUM_IDEA; i++)
    //     this->_brain->setIdea(i, other.getBrain()->getIdea(i));
}

Cat::~Cat()
{
    std::cout << "Destructor called: Cat\n";
    delete this->_brain;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Copy operator called: Cat\n";
    this->_brain = other.getBrain();
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
