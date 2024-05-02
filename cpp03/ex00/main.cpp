#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Alex");
	ClapTrap b("Bob");
	ClapTrap c(a);
	ClapTrap d;

	std::cout << "-------------------------\n";
	d = b;
	std::cout << "-------------------------\n";
	a.attack(b.getName());
	a.printStatus();
	a.takeDamage(4);
	a.beRepaired(4);
	a.printStatus();
	a.takeDamage(50);
	a.attack(b.getName());

	for (int i = 0; i < 10; ++i)
	{
		b.beRepaired(10);
	}
	b.beRepaired(10);
	std::cout << "-------------------------\n";
}
