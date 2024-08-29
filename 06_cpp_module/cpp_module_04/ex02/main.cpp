#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define NUM_OF_ANIMALS 6

void	leaks()
{
	system("leaks main");
}

int main() {
	//atexit(leaks);
	//const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;
	std::cout << "<< What Animals Type? >>" << std::endl;
	std::cout << "dog type is : " << dog->getType() << " " << std::endl;
	std::cout << "cat type is : " << cat->getType() << " " << std::endl;
	//std::cout << "animal type is : " << animal->getType() << " " << std::endl;
	std::cout << "<< What Animals Saying? >>" << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	//animal->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	return 0;
}