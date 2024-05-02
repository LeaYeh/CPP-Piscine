#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("Alex");
	ScavTrap b("Bob");
	ScavTrap c(a);
	ScavTrap d;

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
		b.beRepaired(10);

	b.guardGate();
	b.beRepaired(10);
	std::cout << "-------------------------\n";
}
