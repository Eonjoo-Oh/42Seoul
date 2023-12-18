#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	DiamondTrap	dia("dia");
	ScavTrap	cake("cake");

	dia.printAllInfo();
	dia.whoAmI();
	dia.attack("cake");
	cake.takeDamage(2);
	dia.guardGate();
	dia.highFivesGuys();
	cake.attack("dia");
	dia.takeDamage(30);
	dia.printAllInfo();
}