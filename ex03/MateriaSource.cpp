#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_learnedIdx = 0;
	for(int i = 0; i < 4; i++)
	{
		_learnedMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	_learnedIdx = obj._learnedIdx;
	for(int i = 0; i < 4; i++)
	{
		_learnedMaterias[i] = obj._learnedMaterias[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _learnedIdx; i++)
	{
		delete _learnedMaterias[i];
	}
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
	int	sameTypeFlag;
	int	i;

	sameTypeFlag = 0;
	i = 0;
	
	while (i < _learnedIdx)
	{
		if (type.compare(_learnedMaterias[i]->getType()) == 0)
		{
			sameTypeFlag = 1;
			break;
		}
		i++;
	}
	if (sameTypeFlag == 0)
	{
		std::cout << "There's no right type!" << std::endl;
		return 0;
	}
	return (_learnedMaterias[i]);
}