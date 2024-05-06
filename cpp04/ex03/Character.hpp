#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
    static const int NUM_MEMORY_SLOT = 4;
    Character();
    Character(const std::string &name);
    Character(const Character&other);
    ~Character();
    Character &operator=(const Character &other);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

protected:

private:
    AMateria* _memory_slot[NUM_MEMORY_SLOT];
    std::string _name;
};
