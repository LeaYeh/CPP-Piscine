#pragma once

#include "IMateriaSource.hpp"

enum MateriaType
{
    CURE,
    ICE,
    INVALID
};
class MateriaSource : public IMateriaSource
{
public:
    static const int NUM_SOURCE_SLOT = 4;
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
    void printInfo() const;

protected:
    MateriaType toMateriaType(const std::string &type);

private:
    AMateria *_materia_array[NUM_SOURCE_SLOT];
};
