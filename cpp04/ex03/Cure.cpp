#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Default constructor called: Cure\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout << "Copy constructor called: Cure\n";
}

Cure::~Cure()
{
    std::cout << "Destructor called: Cure\n";
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Copy operator & called: Cure\n";
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria *Cure::clone() const
{
    return new Cure();
}
