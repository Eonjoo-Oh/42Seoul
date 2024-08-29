#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongDog : public WrongAnimal
{
	private:
		Brain	*_brain;
	public:
	WrongDog();
	WrongDog(const WrongDog &obj);
	WrongDog &operator=(const WrongDog &obj);
	~WrongDog();
	void	makeSound() const;
	void		setIdea(int index, std::string idea);
	std::string	getIdea(int index) const;
	Brain*		getBrain();
};

#endif