#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
	this->name = _name;
}

Zombie::~Zombie()
{
	std::cout << "name" << ": is gone" << "std::endl";
}

void	Zombie::setName(std::string _name)
{
	this->name = _name;
}