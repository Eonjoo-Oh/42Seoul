#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
	_learnedIdx = 0;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	*this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;
	_learnedIdx = obj._learnedIdx;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor Called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (_learnedIdx >= 4)
		std::cout << "Learned Materia Slot is FUll!" << std::endl;
	else
	{
		_learnedMaterias[_learnedIdx] = materia;
		_learnedIdx++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i <= _learnedIdx; i++)
	{
		if (type.compare(_learnedMaterias[i]->_type) == 0)//?
		{
		
		}
	}
}
