#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Class Default Constructor Called" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal Class Copy Constructor Called" << std::endl;
	*this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal Class Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Class Destructor Called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal says : Umm.. WrongAnimal!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}