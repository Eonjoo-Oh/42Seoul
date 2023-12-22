#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private :
		std::string	_name;
		int			_numOfEquiped;
		int			_unequipedIndex;
		AMateria	*_slot[4];
		AMateria	*_unequipedMaterias[100];
	public :
		Character();
		Character(std::string name);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		virtual ~Character();
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif