#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const int size = 10;
    Animal* animal_array[size];

    for (int i = 0; i < size / 2; i++)
        animal_array[i] = new Cat();

    for (int i = size / 2; i < size; i++)
        animal_array[i] = new Dog();
    
    for (int i = 0; i < size; i++)
        delete animal_array[i];

    return 0;
}
