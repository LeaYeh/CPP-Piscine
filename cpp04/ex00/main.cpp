#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testSubject();
void testAnimal();
void testCat();
void testDog();
void testWrongAnimal();
void testWrongCat();

int main(void)
{
    testSubject();
    testAnimal();
    testCat();
    testDog();
    testWrongAnimal();
    testWrongCat();

    return 0;
}

void testSubject()
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

void testAnimal()
{
    std::cout << "\n--- TEST Animal ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Animal a;
    a.printInfo();
    std::cout << "\n--- TEST Copy Constructor ---\n";
    Animal b(a);
    b.printInfo();
    std::cout << "\n--- TEST Copy Operator ---\n";
    a = b;
    a.printInfo();
}

void testWrongAnimal()
{
    std::cout << "\n--- TEST WrongAnimal ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    WrongAnimal a;
    a.printInfo();
    std::cout << "\n--- TEST Copy Constructor ---\n";
    WrongAnimal b(a);
    b.printInfo();
    std::cout << "\n--- TEST Copy Operator ---\n";
    a = b;
    a.printInfo();
}

void testCat()
{
    std::cout << "\n--- TEST Cat ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Cat a;
    a.printInfo();
    std::cout << "\n--- TEST Copy Constructor ---\n";
    Cat b(a);
    b.printInfo();
    std::cout << "\n--- TEST Copy Operator ---\n";
    Cat d;
    d = a;
    d.printInfo();
    std::cout << "\n--- TEST Virtual ---\n";
    Animal *e = new Cat();
    e->printInfo();
    delete e;
}

void testWrongCat()
{
    std::cout << "\n--- TEST WrongCat ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    WrongCat a;
    a.printInfo();
    std::cout << "\n--- TEST Copy Constructor ---\n";
    WrongCat b(a);
    b.printInfo();
    std::cout << "\n--- TEST Copy Operator ---\n";
    WrongCat d;
    d = a;
    d.printInfo();
    std::cout << "\n--- TEST Virtual ---\n";
    WrongAnimal *e = new WrongCat();
    WrongCat f;
    e->printInfo();
    f.printInfo();
    delete e;
}

void testDog()
{
    std::cout << "\n--- TEST Dog ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Dog a;
    a.printInfo();
    std::cout << "\n--- TEST Copy Constructor ---\n";
    Dog b(a);
    b.printInfo();
    std::cout << "\n--- TEST Copy Operator ---\n";
    Dog d;
    d = a;
    d.printInfo();
    std::cout << "\n--- TEST Virtual ---\n";
    Animal *e = new Dog();
    e->printInfo();
    delete e;
}
