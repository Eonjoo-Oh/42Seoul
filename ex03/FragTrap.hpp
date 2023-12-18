#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:
		static const int	defaultAttackDamage = 30;
		static const int	defaultHitPoints = 100;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap& operator=(const FragTrap &fragTrap);
		~FragTrap();
		void	highFivesGuys(void);
		int		getDefaultAttackDamage(void);
		int		getDefaultHitPoints(void);
};

#endif