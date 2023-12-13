#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	_name = "default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
	this->_name = claptrap._name;
	this->_hitPoints = claptrap._hitPoints;
	this->_energyPoints = claptrap._energyPoints;
	this->_attackDamage = claptrap._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap" << _name << "'s hit point is ZERO" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap" << _name << "'s energy point is ZERO" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << "attacks " << target 
	<< ", causing"<< _attackDamage << " points of damage" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap" << _name << "is attacked" << amount << " amount of damage" << std::endl;
		if (_hitPoints > amount)
		{
			_hitPoints -= amount;
			std::cout << "Remaining amount of hitpoints is " << _hitPoints << std::endl;
		}
		else
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " has lost all energy points" << std::endl;
		}
	
	}
	else
		std::cout << "ClapTrap" << _name << "was already died" << std::endl;
}
