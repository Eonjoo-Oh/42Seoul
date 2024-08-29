#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap mango("mango");
	ScavTrap apple("apple");

	mango.attack("apple");
	apple.takeDamage(3);
	apple.guardGate();
	apple.attack("mango");
	mango.takeDamage(20);
	mango.attack("apple");
	mango.beRepaired(5);
}