#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
    std::cout << "Default constructor called: Ice\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout << "Copy constructor called: Ice\n";
}

Ice::~Ice()
{
    std::cout << "Destructor called: Ice\n";
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Copy operator & called: Ice\n";
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone() const
{
    return new Ice();
}
