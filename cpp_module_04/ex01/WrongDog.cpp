#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	std::cout << "WrongDog Class Default Constructor Called" << std::endl;
	_type = "WrongDog";
	_brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		setIdea(i, "I'm a dog!");
	}
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
	_brain = obj._brain;
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

void	WrongDog::setIdea(int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

std::string	WrongDog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}

Brain* WrongDog::getBrain()
{
	return (_brain);
}