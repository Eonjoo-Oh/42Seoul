#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}

void	HumanB::attack(void)
{
	if (weapon == NULL)
		std::cout << name << " has no weapon!" << std::endl;
	else
	{
		std::cout << name << " attacks with their ";
		std::cout << weapon->getType();
		std::cout << std::endl;
	}
}