#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	private:
		static const int	defaultEnergyPoints = 100;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap& operator=(const ScavTrap &scavTrap);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string &target);
		int		getDefaultEnergyPoints(void);
};

#endif