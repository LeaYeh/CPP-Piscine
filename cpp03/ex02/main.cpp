#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap a("Alex");
	ScavTrap b("Bob");
	FragTrap c("Claire");
	FragTrap d("Duke");

	std::cout << "------------------------------\n\n";
	FragTrap e(c);
	std::cout << "------------------------------\n\n";
	d = c;
	std::cout << "------------------------------\n\n";
	d.attack("persion1");
	a.attack("persion2");
	c.highFivesGuys();
	std::cout << "------------------------------\n\n";
}
