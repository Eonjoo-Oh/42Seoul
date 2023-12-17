
#include "DiamondTrap.hpp"
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	int	attackDamage;
	//int	energyPoints;
	//int	hitpoints;

	std:: cout << "DiamondTrap Default Constructor Called";
	_name = "default";
	attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_energyPoints = ScavTrap::_energyPoints;
	_hitPoints = FragTrap::_hitPoints;
	_attackDamage = attackDamage;
	_hitPoints = 100;
	_attackDamage = 30;
	_energyPoints = 50;
	_attackDamage = attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap()
{
	int	attackDamage;

	attackDamage = FragTrap::_attackDamage;
	std:: cout << "DiamondTrap Constructor Called" << std::endl;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_energyPoints = ScavTrap::_energyPoints;
	_hitPoints = FragTrap::_hitPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "!! : " << attackDamage << std::endl;
	std::cout << "!! : " << FragTrap::_attackDamage << std::endl;
	_attackDamage = attackDamage;
	_attackDamage = FragTrap::defaultAttackDamage;
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

void	DiamondTrap::getAllInfo()
{
	std::cout << "name : " << _name << std::endl;
	std::cout << "hitpoints : " << _hitPoints << std::endl;
	std::cout << "energyPoints : " << _energyPoints << std::endl;
	std::cout << "attackDamage : " << _attackDamage << std::endl;
}