#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << "==========================\n";
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        meta->makeSound();
        i->makeSound();
        j->makeSound();
        std::cout << "==========================\n";
        delete meta;
        delete i;
        delete j;
        std::cout << "==========================\n";
    }
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();

        std::cout << "==========================\n";
        std::cout << i->getType() << " " << std::endl;
        meta->makeSound();
        i->makeSound();

        std::cout << "==========================\n";
        delete meta;
        delete i;
        std::cout << "==========================\n";
    }
    std::cout << "==========================\n";
    return 0;
}
