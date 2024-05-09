#include "Character.hpp"

Character::Character() : _name("no-name hero")
{
    std::cout << "Default constructor called: Character\n";
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
        this->_memory_slot[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    std::cout << "Type constructor called: Character(" << name << ")\n";
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
        this->_memory_slot[i] = NULL;
}

Character::Character(const Character &other) : _name(other.getName())
{
    std::cout << "Copy constructor called: Character\n";
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
    {
        this->_memory_slot[i] = NULL;
        if (other._memory_slot[i])
            this->_memory_slot[i] = other._memory_slot[i]->clone();
    }
}

Character::~Character()
{
    std::cout << "Destructor called: Character\n";
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
    {
        if (this->_memory_slot[i])
        {
            delete this->_memory_slot[i];
            this->_memory_slot[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Copy operator & called: Character\n";
    if (this != &other)
    {
        this->_name = other.getName();
        for (int i = 0; i < NUM_MEMORY_SLOT; i++)
        {
            if (this->_memory_slot[i] != NULL)
                delete this->_memory_slot[i];
            this->_memory_slot[i] = NULL;
            if (other._memory_slot[i])
                this->_memory_slot[i] = other._memory_slot[i]->clone();
        }
    }
    return *this;
}

const std::string &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
    {
        if(this->_memory_slot[i] == m)
        {
            std::cout << "equip: The materia(" << m << ") already be equipped at slot[" << i << "].\n";
            return;
        }
    }
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
    {
        if (this->_memory_slot[i] == NULL)
        {
            this->_memory_slot[i] = m;
            std::cout << "equip: The materia(" << m->getType() << ") be equipped at slot[" << i << "].\n";
            return;
        }
    }
    std::cout << "equip: All memory slot are full, the " << m->getType() << " can not be equipped.\n";
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= NUM_MEMORY_SLOT)
    {
        std::cout << "unequip: Index[" << idx << "] is out of the range.\n";
        return;
    }
    if (this->_memory_slot[idx] == NULL)
    {
        std::cout << "unequip: Index[" << idx << "] is an empty slot.\n";
        return;
    }
    std::cout << "unequip: Index[" << idx << "] the " << this->_memory_slot[idx]->getType() << " is unloaded.\n";
    delete this->_memory_slot[idx];
    this->_memory_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= NUM_MEMORY_SLOT)
    {
        std::cout << "use: Index[" << idx << "] is out of the range.\n";
        return;
    }
    if (this->_memory_slot[idx] == NULL)
    {
        std::cout << "use: Index[" << idx << "] is an empty slot.\n";
        return;
    }
    this->_memory_slot[idx]->use(target);
}

void Character::printInfo() const
{
    std::cout << "My name is " << this->getName() << " and I know ";
    if (this->_memory_slot[0] == NULL)
    {
        std::cout << "nothing...\n";
        return;
    }
    for (int i = 0; i < NUM_MEMORY_SLOT; i++)
    {
        if (this->_memory_slot[i])
            std::cout << this->_memory_slot[i]->getType() << " ";
    }
    std::cout << std::endl;
}
