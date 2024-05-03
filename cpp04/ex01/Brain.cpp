#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Default constructor called: Brain\n";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor called: Brain\n";
}

Brain::~Brain()
{
    std::cout << "Destructor called: Brain\n";
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Copy operator called: Cat\n";
    this->_ideas = other
}
