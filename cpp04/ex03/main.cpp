#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testBasic();
void testAMateria();
void testMateriaSource();
void testMateriaSourceWithAMateria();
void testCharacter();
void testCharacterWithEquipment();

int main(void)
{
    testBasic();
    std::cout << "=========== FINISH ===========\n\n";
    testAMateria();
    std::cout << "=========== FINISH ===========\n\n";
    testMateriaSource();
    std::cout << "=========== FINISH ===========\n\n";
    testMateriaSourceWithAMateria();
    std::cout << "=========== FINISH ===========\n\n";
    testCharacter();
    std::cout << "=========== FINISH ===========\n\n";
    testCharacterWithEquipment();
    std::cout << "=========== FINISH ===========\n\n";

    return 0;
}

void testBasic()
{
    std::cout << "\n[TEST Basic]\n";
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void testAMateria()
{
    std::cout << "\n[TEST AMateria]\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    std::cout << "No way to call abstract class constructor directly.\n";

    std::cout << "\n--- TEST Argument Constructor ---\n";
    std::cout << "No way to call abstract class constructor directly, but we could do this...\n";
    AMateria *m = new Cure();
    std::cout << "The type is: " << m->getType() << std::endl;

    std::cout << "\n--- TEST Copy Constructor ---\n";
    std::cout << "No way to call abstract class constructor directly\n";

    std::cout << "\n--- TEST Copy Operator ---\n";
    std::cout << "No way to call abstract class copy operator directly, need to use clone()\n";
    AMateria *n;

    n = m->clone();
    std::cout << "-----------------------------\n";
    delete m;
    delete n;
}

void testMateriaSource()
{
    std::cout << "\n[TEST MateriaSource]\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    MateriaSource a;
    a.printInfo();

    std::cout << "\n--- TEST Copy Constructor ---\n";
    MateriaSource c(a);
    c.printInfo();

    std::cout << "\n--- TEST Copy Operator ---\n";
    MateriaSource d;

    d = a;
    d.printInfo();
}

void testMateriaSourceWithAMateria()
{
    std::cout << "\n[TEST MateriaSource With AMateria]\n";
    MateriaSource src;
    AMateria *tmp;

    tmp = src.createMateria("cure");
    src.learnMateria(tmp);
    tmp = src.createMateria("ice");
    src.learnMateria(tmp);
    tmp = src.createMateria("haha");
    src.learnMateria(tmp);

    src.printInfo();
}

void testCharacter()
{
    std::cout << "\n[TEST Character]\n";
    std::cout << "--- TEST Detault Constructor ---\n";
    Character a;
    a.printInfo();

    std::cout << "\n--- TEST Argument Constructor ---\n";
    Character b("Batman");
    b.printInfo();

    std::cout << "\n--- TEST Copy Constructor ---\n";
    Character c(a);
    c.printInfo();

    std::cout << "\n--- TEST Copy Operator ---\n";
    Character d;

    d = b;
    d.printInfo();
}

void testCharacterWithEquipment()
{
    std::cout << "\n[TEST Character With Equipment]\n";
    IMateriaSource *src = new MateriaSource();
    Character me("me");
    AMateria *tmp;

    tmp = src->createMateria("ice");
    me.equip(tmp);
    tmp = src->createMateria("cure");
    me.equip(tmp);
    me.equip(tmp);
    tmp = src->createMateria("cure");
    me.equip(tmp);
    tmp = src->createMateria("cure");
    me.equip(tmp);
    tmp = src->createMateria("ice");
    me.equip(tmp);

    me.unequip(2);
    me.equip(tmp);

    me.printInfo();

    delete src;
    std::cout << "-----------------------------\n";
}
