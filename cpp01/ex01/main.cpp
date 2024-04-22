#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
    int N = 10;
    Zombie *horde = zombieHorde(N, "Zombie ");

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;
    return 0;
}
