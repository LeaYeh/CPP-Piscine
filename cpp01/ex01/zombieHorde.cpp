#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        std::stringstream ss;
        ss << i;
        std::string str_i = ss.str();
        horde[i].set_name(name + str_i);
    }
    return horde;
}
