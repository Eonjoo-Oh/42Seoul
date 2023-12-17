#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap& operator=(const DiamondTrap &diamondTrap);
		~DiamondTrap();
		void	attack(const std::string &target);
		void	whoAmI();
		void	getAllInfo();
};

#endif