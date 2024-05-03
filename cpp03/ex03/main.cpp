#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("haha");
	DiamondTrap diamond2;

	std::cout << "----------------------\n";
	diamond.whoAmI();
	diamond.attack("target");
	diamond.highFivesGuys();
	diamond.guardGate();
	std::cout << "----------------------\n";
	diamond2 = diamond;
	diamond.whoAmI();
	std::cout << "----------------------\n";
}
