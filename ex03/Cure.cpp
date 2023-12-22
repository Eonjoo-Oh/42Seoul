#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure &obj)
{
	*this = obj;
}

Cure &Cure::operator=(const Cure &obj)
{
	_type = obj._type;
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	AMateria* newCure = new Cure(*this);
	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std:: cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}