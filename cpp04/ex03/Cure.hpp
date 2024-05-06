#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &other);
    ~Cure();
    Cure &operator=(const Cure &other);
    void use(ICharacter &target);
    AMateria *clone() const;

protected:
private:
};
