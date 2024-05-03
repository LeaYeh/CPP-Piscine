#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "==========================\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound(); //will output the cat sound! j->makeSound(); meta->makeSound(); ...
    std::cout << "==========================\n";
    delete meta;
    delete i;
    delete j;
    std::cout << "==========================\n";
    return 0; 
}
