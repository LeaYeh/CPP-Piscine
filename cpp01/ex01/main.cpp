#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    Zombie* horde = zombieHorde(5, "Zombie ");

    delete[] horde;
    return 0;
}
