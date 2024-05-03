#ifndef __WRONG_CAT_H__
#define __WRONG_CAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &other);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &other);
    void makeSound() const;

protected:
private:
};

#endif
