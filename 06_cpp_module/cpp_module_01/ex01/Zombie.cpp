#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(std::string _name)
{
	name = _name;
}

Zombie::~Zombie()
{
	std::cout << name << ": is gone" << std::endl;
}

void	Zombie::setName(std::string _name)
{
	name = _name;
}

void	Zombie::announceInOrder(int n)
{
	std::cout << name << n << " : BraiiiiiiinnnzzzZ..." << std::endl;
}