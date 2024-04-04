#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie* zombie1 = newZombie("Zombie1");
    zombie1->announce();
    delete zombie1;

    randomChump("Zombie2");

    return 0;
}
