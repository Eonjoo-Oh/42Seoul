#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	leaks()
{
	system("leaks main");
}


int main()
{
	atexit(leaks);
	IMateriaSource* met = new MateriaSource();
	std::cout << "<< MateriaSource class Test >>" << std::endl;
	met->learnMateria(new Ice());
	met->learnMateria(new Cure());
	std::cout << met->createMateria("ice")->getType() << std::endl;
	std::cout << met->createMateria("cure")->getType() << std::endl;
	met->createMateria("kkk");

	std::cout << std::endl << "<< Character class getName test >>" << std::endl;
	Character	*ari = new Character("Ari");
	std::cout << "New character name is " << ari->getName() << std::endl;
	Character	*karry = new Character("Karry");
	std::cout << "New character name is " << karry->getName() << std::endl;

	std::cout << std::endl << "<< AMateria class use test >>" << std::endl;
	AMateria	*iceMateria = new Ice();
	AMateria	*cureMateria = new Cure();
	iceMateria->use(*ari);
	cureMateria->use(*karry);

	std::cout << std::endl << "<< AMateria class clone test >>" << std::endl;
	AMateria	*copiedIce = iceMateria->clone();
	AMateria	*copiedCure = cureMateria->clone();
	std::cout << "iceMateria address : " << &iceMateria << std::endl;
	std::cout << "copiedIce address : " << &copiedIce << std::endl;
	copiedIce->use(*ari);
	copiedCure->use(*karry);
	std::cout << "iceMateria type: " << iceMateria->getType() << std::endl;
	std::cout << "copiedIce type: " << copiedIce->getType() << std::endl;

	std::cout << std::endl << "<< Character class equip, unequip test >>" << std::endl;
	ari->equip(iceMateria);
	ari->use(0, *karry);
	ari->use(1, *karry);
	ari->unequip(1);
	ari->equip(cureMateria);
	ari->equip(copiedIce);
	ari->equip(copiedCure);
	ari->equip(copiedCure);
	ari->unequip(0);
	ari->unequip(8);
	ari->use(0, *karry);

	delete met;
	delete ari;
	delete karry;
	delete iceMateria;
	delete cureMateria;
	delete copiedIce;
	delete copiedCure;

	std::cout << std:: endl << "------------------ subject test -------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}


/*
int main()
{
	atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
*/