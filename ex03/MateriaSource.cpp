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
	//learnedMaterias가 어떻게 복사되는지는 모르겠다. 텅 빈 배열로 복사되어야한다. (과연?)
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
	int	sameTypeFlag;
	int	i;

	sameTypeFlag = 0;
	i = 0;
	
	while (i <= _learnedIdx)
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
	return (_learnedMaterias[i]->clone());
}