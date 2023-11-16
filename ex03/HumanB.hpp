#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
	public:
		Weapon		*weapon;
		HumanB(std::string name);
		void	setWeapon(Weapon _weapon);
		void	attack(void);
};

#endif