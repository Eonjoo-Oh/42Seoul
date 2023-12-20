#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Class Default Constructor Called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal()
{
	std::cout << "WrongCat Class Copy Constructor Called" << std::endl;
	*this = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat Class Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Class Destructor Called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat says : Meooooow!" << std::endl;
}