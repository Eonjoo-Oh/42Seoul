#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor Called" << std::endl;
	_name = "default";
	_numOfEquiped = 0;
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
	//_slot을 어떻게 복사를 할지? 다 빈 슬롯으로해야하나? 아닐것같음
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
			_slot[i] = m;//얘의 포인터 그 자체를 넣어야하니까 복사하지 않고 넣는다?
	}
	_numOfEquiped++;
}

void	Character::unequip(int idx)
{
	//어떻게 unequip한걸 저장해놓을지 고민중
	_slot[idx] = NULL;
	_numOfEquiped--;
}

void	Character::use(int idx, ICharacter& target)
{
	_slot[idx]->use(target);
}