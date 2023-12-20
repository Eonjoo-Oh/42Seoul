#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	std::cout << "WrongDog Class Default Constructor Called" << std::endl;
	_type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog &obj) : WrongAnimal()
{
	std::cout << "WrongDog Class Copy Constructor Called" << std::endl;
	*this = obj;
}

WrongDog &WrongDog::operator=(const WrongDog &obj)
{
	std::cout << "WrongDog Class Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog Class Destructor Called" << std::endl;
}

void	WrongDog::makeSound() const
{
	std::cout << "WrongDog says : Wooooof!" << std::endl;
}