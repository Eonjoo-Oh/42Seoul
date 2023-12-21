#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Default Constructor Called" << std::endl;
	_type = "Cure";
}

Cure::Cure(const Cure &obj)
{
	std::cout << "Cure Copy Constructor Called" << std::endl;
	*this = obj;
}

Cure &Cure::operator=(const Cure &obj)
{
	std::cout << "Cure Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor Called" << std::endl;
}

AMateria* Cure::clone() const
{

}

void	Cure::use(ICharacter& target)
{

}