#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "string.h"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria	*_learnedMaterias[4];
		int			_learnedIdx;
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		~MateriaSource();
	public :

		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(std::string const & type);
};

#endif