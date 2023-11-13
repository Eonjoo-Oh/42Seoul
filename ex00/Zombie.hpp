#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>

class	Zombie{
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		void	announce(void);
};

#endif