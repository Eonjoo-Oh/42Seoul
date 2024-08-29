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
	banana.takeDamage(10);
	banana.highFivesGuys();
	banana.beRepaired(3);
	mango.beRepaired(5);
	melon.beRepaired(5);
}