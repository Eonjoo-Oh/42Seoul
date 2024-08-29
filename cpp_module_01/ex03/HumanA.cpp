#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their ";
	std::cout << weapon.getType();
	std::cout << std::endl;
}