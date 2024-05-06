#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constructor called: MateriaSource\n";
    for (int i = 0; i < NUM_SOURCE_SLOT; i++)
        this->_materia_array[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "Copy constructor called: MateriaSource\n";
    for (int i = 0; i < NUM_SOURCE_SLOT; i++)
    {
        if (other._materia_array[i])
            this->_materia_array[i] = other._materia_array[i]->clone();
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "Destructor called: MateriaSource\n";
    for (int i = 0; i < NUM_SOURCE_SLOT; i++)
    {
        if (this->_materia_array[i])
        {
            delete this->_materia_array[i];
            this->_materia_array[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "Copy operator & called: MateriaSource\n";
    if (this != &other)
    {
        for (int i = 0; i < NUM_SOURCE_SLOT; i++)
        {
            if (this->_materia_array[i])
            {
                delete this->_materia_array[i];
                this->_materia_array[i] = NULL;
            }
            this->_materia_array[i] = other._materia_array[i]->clone();
        }
    }
    return *this;
}

MateriaType MateriaSource::toMateriaType(const std::string &type)
{
    if (type == "cure")
        return CURE;
    else if (type == "ice")
        return ICE;
    else
        return INVALID;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < NUM_SOURCE_SLOT; i++)
    {
        if (this->_materia_array[i] == NULL)
        {
            this->_materia_array[i] = m;
            return;
        }
    }
    std::cout << "learnMateria: All slot are full, the " << m->getType() << " can not be learned.\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    MateriaType materiaType = toMateriaType(type);

    switch (materiaType)
    {
    case CURE:
        return new Cure();
    case ICE:
        return new Ice();
    default:
        std::cout << "Invalid type: " << type << std::endl;
        return NULL;
    }
}
