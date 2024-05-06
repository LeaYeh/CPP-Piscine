#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testSubject();
void testSubject2();
void testBrain();
void testCatWithBrain();
void testDogWithBrain();
void testDog();

int main(void)
{
    testSubject();
    testSubject2();
    testBrain();
    testCatWithBrain();
    testDogWithBrain();

    return 0;
}

void testSubject()
{
    std::cout << "\n--- TEST Subject example ---\n";
    const Animal *i = new Cat();
    const Animal *j = new Dog();

    i->printInfo();
    j->printInfo();

    delete i;
    delete j;
}

void testSubject2()
{
    std::cout << "\n--- TEST Base pointer ---\n";
    const int size = 10;
    Animal *animal_array[size];

    std::cout << "--- TEST Detault Constructor ---\n";
    for (int i = 0; i < size / 2; i++)
        animal_array[i] = new Cat();
    for (int i = size / 2; i < size; i++)
        animal_array[i] = new Dog();
    animal_array[0]->printInfo();
    animal_array[0]->printAllThought();
    animal_array[size / 2]->printInfo();
    animal_array[size / 2]->printAllThought();

    int dst_idx = size / 2;
    int src_idx = 0;
    if (dynamic_cast<Cat *>(animal_array[src_idx]))
    {
        delete animal_array[dst_idx];
        animal_array[dst_idx] = new Cat(*dynamic_cast<Cat *>(animal_array[src_idx]));
    }
    else
    {
        std::cout << "Oh no!!!!! Index: " << src_idx << " is a " << animal_array[src_idx]->getType();
        std::cout << ", can not be cast to a Cat.\n";
    }
    std::cout << "--- TEST Distructor ---\n";
    for (int i = 0; i < size; i++)
        delete animal_array[i];
    std::cout << "\n-------------------------\n";
}

void testBrain()
{
    std::cout << "\n--- TEST Brain ---\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Brain a;

    a.setIdea(0, "haha0");
    a.setIdea(11, "haha11");
    a.setIdea(100, "haha101");
    a.printAllIdea();
    std::cout << "\n--- TEST Copy Constructor ---\n";
    Brain b(a);
    a.printAllIdea();
    std::cout << "a idea(0) address: " << &a.getIdea(0) << std::endl;
    std::cout << "b idea(0) address: " << &b.getIdea(0) << std::endl;
    std::cout << "\n--- TEST Copy Operator ---\n";
    Brain c;
    c = b;
    a.printAllIdea();
}

void testCatWithBrain()
{
    std::cout << "\n--- TEST Cat with Brain ---\n";
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

void testDogWithBrain()
{
    std::cout << "\n--- TEST Dog with Brain ---\n";
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
