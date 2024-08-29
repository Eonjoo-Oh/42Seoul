#include "ClapTrap.hpp"

int main()
{
	ClapTrap mango("mango");
	ClapTrap berry("berry");

	mango.attack("berry");
	berry.takeDamage(0);
	berry.beRepaired(2);
	berry.attack("mango");
	mango.takeDamage(6);
	mango.beRepaired(5);
	mango.takeDamage(10);
	mango.takeDamage(11);
}