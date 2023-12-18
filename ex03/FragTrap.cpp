#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std:: endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
	_name = fragTrap._name;
	_hitPoints = fragTrap._hitPoints;
	_energyPoints = fragTrap._energyPoints;
	_attackDamage = fragTrap._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << "'s hit point is ZERO" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << "'s energy point is ZERO" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " High Five Guys!" << std::endl;
}

int	FragTrap::getDefaultAttackDamage(void)
{
	return (defaultAttackDamage);
}

int	FragTrap::getDefaultHitPoints(void)
{
	return (defaultHitPoints);
}