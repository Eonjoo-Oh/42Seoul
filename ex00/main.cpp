#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

void	leaks()
{
	system("leaks main");
}

int main()
{
	//atexit(leaks);

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;
	std::cout << "<< What Animals Type? >>" << std::endl;
	std::cout << "dog type is : " << dog->getType() << " " << std::endl;
	std::cout << "cat type is : " << cat->getType() << " " << std::endl;
	std::cout << "animal type is : " << animal->getType() << " " << std::endl;
	std::cout << "<< What Animals Saying? >>" << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongDog = new WrongDog();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;
	std::cout << "<< What Wrong Animals Type? >>" << std::endl;
	std::cout << "wrong dog type is "<< wrongDog->getType() << " " << std::endl;
	std::cout << "wrong cat type is "<< wrongCat->getType() << " " << std::endl;
	std::cout << "wrong animal type is "<< wrongAnimal->getType() << " " << std::endl;
	std::cout << "<< What 'Wrong' Animals Saying? >>" << std::endl;
	wrongCat->makeSound();
	wrongDog->makeSound();
	wrongAnimal->makeSound();
	std::cout << std::endl;
	delete wrongAnimal;
	delete wrongDog;
	delete wrongCat;
	return 0;
}