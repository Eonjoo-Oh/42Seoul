#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std:: cout << "DiamondTrap Default Constructor Called";
	_name = "default";
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap()
{
	std:: cout << "DiamondTrap Constructor Called";
	_name = "_name";
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "DiamondTrap Assignment Operator called" << std::endl;
	_name = diamondTrap._name;
	_hitPoints = diamondTrap._hitPoints;
	_energyPoints = diamondTrap._energyPoints;
	_attackDamage = diamondTrap._attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << _name
	<< ", ClapTrap name is " << ClapTrap::_name << std::endl;
}