#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Class Default Constructor Called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		setIdea(i, "I'm a cat!");
	}
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
	_brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		_brain->setIdea(i, obj.getIdea(i));
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Class Destructor Called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat says : Meooooow!" << std::endl;
}

void	Cat::setIdea(int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}