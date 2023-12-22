#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "default";
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	_type = obj._type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout  << "* Use AMateria at " << target.getName() << " *" << std::endl;
}
