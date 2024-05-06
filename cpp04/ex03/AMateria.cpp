#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
    std::cout << "Default constructor called: AMateria\n";
}

AMateria::AMateria(const std::string &type) : _type(type)
{
    std::cout << "Type constructor called: AMateria(" << type << ")\n";
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
    std::cout << "Copy constructor called: AMateria\n";
}

AMateria::~AMateria()
{
    std::cout << "Destructor called: AMateria\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "Copy operator & called: AMateria\n";
    if (this != &other)
        this->_type = other._type;
    return *this;
}

const std::string &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Casts a freezing spell on " << target.getName() << std::endl;
}
