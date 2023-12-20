#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

void	leaks()
{
	system("leaks main");
}

int main()
{
	atexit(leaks);
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << "What Animals Saying?" << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongDog = new WrongDog();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongDog->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << "What 'Wrong' Animals Saying?" << std::endl;
	wrongCat->makeSound();
	wrongDog->makeSound();
	wrongMeta->makeSound();
	delete meta;
	delete dog;
	delete cat;
	delete wrongMeta;
	delete wrongDog;
	delete wrongCat;
	return 0;
}//잘되는 케이스와 잘못된 케이스를 비교해보아라