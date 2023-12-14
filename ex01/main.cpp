#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap mango("mango");
	ScavTrap apple("apple");

	apple.attack("mango");
	mango.takeDamage(20);
	mango.attack("apple");
	apple.guardGate();
	mango.beRepaired(5);
}