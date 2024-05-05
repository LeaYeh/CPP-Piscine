#pragma once

#include "IMateriaSource.hpp"

class MateriaSource
{
public:
    MateriaSource();
    MateriaSource (const MateriaSource &other);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};
