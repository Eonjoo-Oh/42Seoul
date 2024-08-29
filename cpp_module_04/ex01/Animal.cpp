#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Class Default Constructor Called" << std::endl;
	_type = "animal";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal Class Copy Constructor Called" << std::endl;
	*this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal Class Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Class Destructor Called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal says : Umm.. Animal!" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}