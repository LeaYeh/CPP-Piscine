#pragma once
#ifndef __MATERIA_H__
#define __MATERIA_H__

#include <iostream>
#include "Character.hpp"

class AMateria
{
public:
    AMateria();
    AMateria(const AMateria &other);
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &other);
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
private:
    std::string _type;
};

#endif
