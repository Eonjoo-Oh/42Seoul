#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Default Constructor Called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice &obj)
{
	std::cout << "Ice Copy Constructor Called" << std::endl;
	*this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
	std::cout << "Ice Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor Called" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria* newIce = new Ice(*this);
	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std:: cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}