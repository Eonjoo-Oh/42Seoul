#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria	*_materiaList;
	public :
		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(std::string const & type);
};

#endif
