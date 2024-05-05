#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Default constructor called: Dog\n";
    this->think("I want meats.\n");
    this->think("I want to play.\n");
    this->think("Touch me more!\n");
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain())
{
    std::cout << "Copy constructor called: Dog\n";
    *this->_brain = *other.getBrain();
    std::cout << "Address brain hold by this:\t" << this->_brain << "\n";
    std::cout << "Address brain hold by other:\t" << other._brain << "\n";
}

Dog::~Dog()
{
    std::cout << "Destructor called: Dog\n";
    delete this->_brain;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Copy operator called: Dog\n";
    if (this != &other)
    {
        Animal::operator=(other);
        *this->_brain = *other.getBrain();
    }
    std::cout << "Address hold by this:\t" << this->_brain << "\n";
    std::cout << "Address hold by other:\t" << other._brain << "\n";
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "wolf~~\n";
}

const std::string &Dog::getType() const
{
    return this->type;
}

Brain *Dog::getBrain() const
{
    return this->_brain;
}

void Dog::think(const std::string &idea)
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

void Dog::printAllThought() const
{
    this->getBrain()->printAllIdea();
}
