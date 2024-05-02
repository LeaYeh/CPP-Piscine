#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("haha");

	std::cout << "----------------------\n";
	diamond.whoAmI();
	diamond.attack("target");
	diamond.highFivesGuys();
	diamond.guardGate();
	std::cout << "----------------------\n";
}
