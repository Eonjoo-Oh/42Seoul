#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	std::string	name;

	name = "eoh";
	Zombie *zombie = newZombie(name);
	randomChump(name);
	delete zombie;
}//왜 소멸자가 두번 실행되는것?