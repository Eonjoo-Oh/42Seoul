#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria	*_learnedMaterias;
		AMateria	*_createdMaterias;
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		~MateriaSource();
		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(std::string const & type);
};

#endif
