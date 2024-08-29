#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(const Ice &obj)
{
	*this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
	_type = obj._type;
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	AMateria* newIce = new Ice(*this);
	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std:: cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}