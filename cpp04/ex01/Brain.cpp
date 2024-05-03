#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Default constructor called: Brain\n";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor called: Brain\n";
    for (int i = 0; i < Brain::NUM_IDEA; i++)
        this->_ideas[i] = other.getIdea(i);
}

Brain::~Brain()
{
    std::cout << "Destructor called: Brain\n";
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Copy operator called: Brain\n";
    for (int i = 0; i < Brain::NUM_IDEA; i++)
        this->_ideas[i] = other.getIdea(i);
    return *this;
}

const std::string& Brain::getIdea(const unsigned int i) const
{
    if (i >= Brain::NUM_IDEA) {
        throw std::out_of_range("Index is out of range");
    }
    return this->_ideas[i];
}

void Brain::setIdea(const unsigned i, const std::string &idea)
{
    if (i >= Brain::NUM_IDEA) {
        throw std::out_of_range("Index is out of range");
    }
    this->_ideas[i] = idea;
}
