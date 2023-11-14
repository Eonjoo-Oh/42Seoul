#include "Zombie.hpp"

//void	randomChump(std::string name)
//{
//	Zombie* zombie;

//	zombie = newZombie(name);
//	zombie->announce();
//	delete zombie;
//}//heap
//stack에 heap 영역 중 해당 영역에 선언한 이유
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}//stack