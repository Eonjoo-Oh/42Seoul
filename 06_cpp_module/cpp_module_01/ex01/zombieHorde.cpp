#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	zombie;
	if (N <= 0)
	{
		std::cout << "You have entered an invalid number!" << std::endl;
		return (NULL);
	}
	zombie = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombie[i].setName(name);
	}
	return (zombie);
}