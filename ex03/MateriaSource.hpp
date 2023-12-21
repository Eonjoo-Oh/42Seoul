#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "string.h"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria	*_learnedMaterias[4];
		AMateria	*_createdMaterias;
		int			_learnedIdx;
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		~MateriaSource();
		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(std::string const & type);
};

#endif
