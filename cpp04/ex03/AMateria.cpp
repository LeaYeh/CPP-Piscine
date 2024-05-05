#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default constructor called: AMateria\n";
}

AMateria::AMateria(const std::string &type) : _type(type)
{
    std::cout << "Type constructor called: AMateria(" << type << ")\n";
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "Copy constructor called: AMateria \n";
    this->_type = other.getType();
}

AMateria::~AMateria()
{
    std::cout << "Destructor called: AMateria\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "Copy operator & called: AMateria\n";
    if (this != &other)
        this->_type = other.getType();
    return *this;
}

const std::string &AMateria::getType() const
{
    return this->_type;
}
