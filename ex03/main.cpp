#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	dia("Dia");
	ScavTrap	cake("Cake");
	dia.getAllInfo();
	dia.whoAmI();
	dia.attack("Cake");
	dia.guardGate();
	dia.highFivesGuys();
}