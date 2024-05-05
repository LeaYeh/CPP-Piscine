#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor called: Brain\n";
    for (int i = 0; i < NUM_IDEA; i++)
        this->setIdea(i, "");
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor called: Brain\n";
    if (this != &other)
    {
        for (int i = 0; i < Brain::NUM_IDEA; i++)
            this->_ideas[i] = other.getIdea(i);
    }
    std::cout << "Address _ideas hold by this:\t" << this->_ideas << "\n";
    std::cout << "Address _ideas hold by other:\t" << other._ideas << "\n";
}

Brain::~Brain()
{
    std::cout << "Destructor called: Brain\n";
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Copy operator called: Brain\n";
    if (this != &other)
    {
        for (int i = 0; i < Brain::NUM_IDEA; i++)
            this->_ideas[i] = other._ideas[i];
    }
    std::cout << "Address _ideas hold by this:\t" << this->_ideas << "\n";
    std::cout << "Address _ideas hold by other:\t" << other._ideas << "\n";
    return *this;
}

const std::string &Brain::getIdea(const unsigned int i) const
{
    if (i >= Brain::NUM_IDEA)
    {
        throw std::out_of_range("Index is out of range");
    }
    return this->_ideas[i];
}

void Brain::setIdea(const unsigned i, const std::string &idea)
{
    if (i >= Brain::NUM_IDEA)
    {
        throw std::out_of_range("Index is out of range");
    }
    this->_ideas[i] = idea;
}

void Brain::printIdea(const unsigned i) const
{
    std::cout << "The index " << i << " idea in the brain is: " << this->getIdea(i);
    std::cout << std::endl;
}

void Brain::printAllIdea() const
{
    for (int i = 0; i < Brain::NUM_IDEA; i++)
    {
        const std::string &tmp = this->getIdea(i);
        if (!tmp.empty())
            this->printIdea(i);
    }
}
