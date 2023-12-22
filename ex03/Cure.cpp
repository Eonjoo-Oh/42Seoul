#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Default Constructor Called" << std::endl;
	_type = "cure";
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
	AMateria* newCure = new Cure(*this);
	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std:: cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}