#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Class Default Constructor Called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal()
{
	std::cout << "Dog Class Copy Constructor Called" << std::endl;
	*this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog Class Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Class Destructor Called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog says : Wooooof!" << std::endl;
}