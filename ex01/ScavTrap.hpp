#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap(std::string name) : ClapTrap(name) {
			std::cout << "ScavTrap constructor called" << std::endl;
			_hitPoints = 100;
			_energyPoints = 50;
			_attackDamage = 20;
		}
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap& operator=(const ScavTrap &scavtrap);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string &target);
};

#endif