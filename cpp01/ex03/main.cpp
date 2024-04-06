#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA alex("Alex", club);

        alex.attack();
        club.setType("some other type of club");
        alex.attack();
    }
    std::cout << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB bob("Bob");

        bob.setWeapon(club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
}
