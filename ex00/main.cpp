#include "ClapTrap.hpp"

int main()
{
	ClapTrap mango("mango");
	ClapTrap berry("berry");

	mango.attack("berry");
	berry.takeDamage(2);
	berry.beRepaired(2);
	berry.attack("mango");
	mango.takeDamage(11);
	mango.beRepaired(5);
}