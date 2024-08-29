#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	std::string	name;

	std::cout << "enter the zombie name" << std::endl;
	std::getline(std::cin >> std::ws, name);
	Zombie *zombie = newZombie(name);
	randomChump(name);
	delete zombie;
}