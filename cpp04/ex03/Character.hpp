#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(const Character&other);
    ~Character();
    Character &operator=(const Character &other);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

protected:
    Character(const std::string &name);

private:
    AMateria* _memory_slot[4];
    std::string _name;
};

#endif