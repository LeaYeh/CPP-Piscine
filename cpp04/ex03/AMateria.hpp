#pragma once
#include <iostream>

// Note: use forward declaration to avoid circular dependency
class ICharacter;

class AMateria
{
public:
    AMateria();
    AMateria(const AMateria &other);
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &other);
    std::string const &getType() const;
    virtual void use(ICharacter &target);
    virtual AMateria *clone() const = 0;

protected:
    std::string _type;

private:
};
