#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Class Default Constructor Called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal()
{
	std::cout << "Cat Class Copy Constructor Called" << std::endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat Class Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Class Destructor Called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat says : Meooooow!" << std::endl;
}