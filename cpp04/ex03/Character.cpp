#include "Character.hpp"

Character::Character() : _name("no-name hero")
{
    std::cout << "Default constructor called: Character\n";
}

Character::Character(const std::string &name) : _name(name)
{
    std::cout << "Type constructor called: Character(" << name << ")\n";
}

Character::Character(const Character &other)
{
    std::cout << "Copy constructor called: AMateria \n";
    // TODO: magic array
}

Character::~Character()
{
    std::cout << "Destructor called: Character\n";
    // TODO: magic array
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Copy operator & called: Character\n";
    // if (this != &other)
    //     this->_type = other.getType();
    return *this;
}

const std::string &Character::getName() const
{
    return this->_name;
}