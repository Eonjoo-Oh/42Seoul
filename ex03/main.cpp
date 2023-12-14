#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap mango("mango");
	ClapTrap melon("melon");
	FragTrap banana("banana");

	banana.attack("mango");
	mango.takeDamage(30);
	melon.attack("banana");
	banana.highFivesGuys();
	mango.beRepaired(5);
	melon.beRepaired(5);
}