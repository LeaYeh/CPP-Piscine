#ifndef __MATERIA_H__
#define __MATERIA_H__

#include "AMateria.hpp"

class IMateriaSource : public AMateria
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
