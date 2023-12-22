#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor Called" << std::endl;
	_type = "default";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria Constructor Called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria &obj)
{
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = obj;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	std::cout << "AMateria Assignment Operator Called" << std::endl;
	_type = obj._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor Called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << "Use AMateria" << std::endl;
}
