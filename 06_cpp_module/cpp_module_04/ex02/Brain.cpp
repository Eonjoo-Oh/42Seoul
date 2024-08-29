#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Class Default Constructor Called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		_ideas[i] = "no ideas..";
	}
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain Class Copy Constructor Called" << std::endl;
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain Class Assignment Operator Called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = obj._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Class Destructor Called" << std::endl;
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 100)
	{
		std::cout << "wrong index!" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}

std::string	Brain::getIdea(int index)
{
	return (_ideas[index]);
}