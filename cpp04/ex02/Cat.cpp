#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Default constructor called: Cat\n";
    std::cout << "Address hold the brain:\t" << this->_brain << "\n";
    this->think("I'm sooo cute.\n");
    this->think("I want fish.\n");
    this->think("I want to play.\n");
    this->think("Don't touch me!\n");
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain())
{
    std::cout << "Copy constructor called: Cat\n";
    *this->_brain = *other.getBrain();
    std::cout << "Address brain hold by this:\t" << this->_brain << "\n";
    std::cout << "Address brain hold by other:\t" << other._brain << "\n";
}

Cat::~Cat()
{
    std::cout << "Destructor called: Cat\n";
    delete this->_brain;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Copy operator called: Cat\n";
    if (this != &other)
    {
        Animal::operator=(other);
        *this->_brain = *other.getBrain();
    }
    std::cout << "Address hold by this:\t" << this->_brain << "\n";
    std::cout << "Address hold by other:\t" << other._brain << "\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow~~\n";
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
    for (int i = 0; i < Brain::NUM_IDEA; i++)
    {
        if (this->getBrain()->getIdea(i).empty())
        {
            this->getBrain()->setIdea(i, idea);
            return;
        }
    }
    std::cout << "I'm just a " << this->getType() << ", I can not think too much.\n";
}

void Cat::printAllThought() const
{
    this->getBrain()->printAllIdea();
}
