#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie* zombie(name);
	Zombie::announce();
	return (zombie);
}