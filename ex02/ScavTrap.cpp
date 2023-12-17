#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
 
ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is GateKeeper mode!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << "'s hit point is ZERO" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << "'s energy point is ZERO" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target 
	<< ", causing "<< _attackDamage << " points of damage" << std::endl;
	_energyPoints--;
}