#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* zombie(name);
//동적할당안하고 이렇게?
	return (zombie);
}