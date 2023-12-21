#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	*this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor Called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *materia)
{

}

AMateria*	MateriaSource::createMateria(std::string const &type)
{

}
