#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor Called" << std::endl;
	_name = "default";
	_numOfEquiped = 0;
	_unequipedIndex = 0;
	for(int i = 0; i < 4; i++)
	{
		_slot[i] = NULL;
	}
}

Character::Character(std::string name)
{
	std::cout << "Character Constructor Called" << std::endl;
	_name = name;
	_numOfEquiped = 0;
	_unequipedIndex = 0;
	for(int i = 0; i < 4; i++)
	{
		_slot[i] = NULL;
	}
}
Character::Character(const Character &obj)
{
	std::cout << "Character Copy Constructor Called" << std::endl;
	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	std::cout << "Character Assignment Operator Called" << std::endl;
	_name = obj._name;
	_numOfEquiped = obj._numOfEquiped;
	for(int i = 0; i < 4; i++)
	{
		_slot[i] = obj._slot[i];
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor Called" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (_numOfEquiped >= 4)
	{
		std::cout << "Your Slot is Full!" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if (_slot[i] == NULL)
		{
			_slot[i] = m;
			break;
		}
	}
	_numOfEquiped++;
	std::cout << "Successfully equipped " << m->getType() << std::endl;
}

void	Character::unequip(int idx)
{
	if (_unequipedIndex >= 100)
	{
		std::cout << "You can't unequipped anymore!" << std::endl;
		return ;
	}
	if (idx >= 4)
	{
		std::cout << "wrong index!" << std::endl;
		return ;
	}
	if (_slot[idx] == NULL)
	{
		std::cout << "no materia in this slot!" << std::endl;
		return ;
	}
	_unequipedMaterias[_unequipedIndex] = _slot[idx];
	_unequipedIndex++;
	_slot[idx] = NULL;
	_numOfEquiped--;
	std::cout << "Successfully unequipped " << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 4)
	{
		std::cout << "wrong index!" << std::endl;
		return ;
	}
	if (_slot[idx] == NULL)
	{
		std::cout << "no materia in this slot!" << std::endl;
		return ;
	}
	_slot[idx]->use(target);
}