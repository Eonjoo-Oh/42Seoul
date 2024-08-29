#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std:: cout << "DiamondTrap Default Constructor Called";
	_name = "default";
	ClapTrap::_name = _name + "_clap_name";
	_energyPoints = ScavTrap::getDefaultEnergyPoints();
	_hitPoints = FragTrap::getDefaultHitPoints();
	_attackDamage = FragTrap::getDefaultAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap()
{
	std:: cout << "DiamondTrap Constructor Called" << std::endl;
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_energyPoints = ScavTrap::getDefaultEnergyPoints();
	_hitPoints = FragTrap::getDefaultHitPoints();
	_attackDamage = FragTrap::getDefaultAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap)
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
	return (*this);
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
	std::cout << "DiamondTrap name is " << _name << ", ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::printAllInfo()
{
	std::cout << "name : " << _name << std::endl;
	std::cout << "hitpoints : " << _hitPoints << std::endl;
	std::cout << "energyPoints : " << _energyPoints << std::endl;
	std::cout << "attackDamage : " << _attackDamage << std::endl;
}