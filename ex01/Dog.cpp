#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Class Default Constructor Called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		setIdea(i, "I'm a dog!");
	}
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
	_brain = new Brain();
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Class Destructor Called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog says : Wooooof!" << std::endl;
}

void	Dog::setIdea(int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}