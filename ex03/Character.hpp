#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private :
		std::string	_name;
		int			_numOfEquiped;
		AMateria	*_slot[4];
		AMateria	*unequipedMaterias;
	public :
		Character();
		Character(std::string name);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		~Character();
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif