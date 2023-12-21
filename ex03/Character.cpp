#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(const Character &obj)
{
	std::cout << "Character Copy Constructor Called" << std::endl;
	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	std::cout << "Character Assignment Operator Called" << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor Called" << std::endl;
}

std::string const &Character::getName() const
{

}

void	Character::equip(AMateria* m)
{

}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter& target)
{

}