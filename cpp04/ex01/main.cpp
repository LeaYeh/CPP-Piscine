#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testSubject();
void testSubject2();
void testCat();
void testDog();
void testBrain();

int main(void)
{
    testSubject();
    testSubject2();
    testBrain();

    return 0;
}

void testSubject()
{
    std::cout << "\n--- TEST Subject example ---\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
}

void testSubject2()
{
    std::cout << "\n--- TEST Base pointer ---\n";
    const int size = 10;
    Animal* animal_array[size];

    for (int i = 0; i < size / 2; i++)
        animal_array[i] = new Cat();

    for (int i = size / 2; i < size; i++)
        animal_array[i] = new Dog();
    
    for (int i = 0; i < size; i++)
        delete animal_array[i];
}

void testBrain()
{
    std::cout << "\n--- TEST Brain ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Brain a;
    
    a.setIdea(0, "haha0");
    a.setIdea(11, "haha11");
    try {
        a.setIdea(100, "haha101");
    } catch (const std::out_of_range& e) {
        std::cout << "We should not access/write out of range QQ.\n";
    }
    a.printAllIdea();
    std::cout << "\n--- TEST Cpoy Constructor ---\n";
    Brain b(a);
    a.printAllIdea();
    std::cout << "a idea(0) address: " << &a.getIdea(0) << std::endl;
    std::cout << "b idea(0) address: " << &b.getIdea(0) << std::endl;
    std::cout << "\n--- TEST Cpoy Operator ---\n";
    Brain c;
    c = b;
    a.printAllIdea();
}

void testAnimal()
{
    std::cout << "\n--- TEST Animal ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Animal a;
    a.printInfo();
    std::cout << "\n--- TEST Cpoy Constructor ---\n";
    Animal b(a);
    b.printInfo();
    std::cout << "\n--- TEST Cpoy Operator ---\n";
    a = b;
    a.printInfo();
}

void testCat()
{
    std::cout << "\n--- TEST Cat ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Cat a;
    a.printInfo();
    std::cout << "\n--- TEST Cpoy Constructor ---\n";
    Cat b(a);
    b.printInfo();
    std::cout << "\n--- TEST Cpoy Operator ---\n";
    Cat d;
    d = a;
    d.printInfo();
    std::cout << "\n--- TEST Virtual ---\n";
    Animal *e = new Cat();
    e->printInfo();
    delete e;
}

void testDog()
{
    std::cout << "\n--- TEST Dog ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Dog a;
    a.printInfo();
    std::cout << "\n--- TEST Cpoy Constructor ---\n";
    Dog b(a);
    b.printInfo();
    std::cout << "\n--- TEST Cpoy Operator ---\n";
    Dog d;
    d = a;
    d.printInfo();
    std::cout << "\n--- TEST Virtual ---\n";
    Animal *e = new Dog();
    e->printInfo();
    delete e;
}
