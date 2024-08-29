#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"

#define NUM_OF_ANIMALS 6

void	leaks()
{
	system("leaks main");
}

int main() {
	//atexit(leaks);
	const Animal* animal[NUM_OF_ANIMALS];

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << "<< Check Animal Array >>" << std::endl;
	for(int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		std::cout << "animal [" << i << "]" << "'s type : " << animal[i]->getType() << std::endl;
		std::cout << "and its sound : ";
		animal[i]->makeSound();
	}
	std::cout << std::endl;

	for(int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		delete animal[i];
	}

	std::cout << std::endl << "--------------------- Deep Copy Test -------------------" << std::endl;
	std::cout << std::endl << "<< Check Dog Copy >>" << std::endl;
	Dog* originDog = new Dog();
	Dog cloneDog = Dog(*originDog);
	std::cout << std::endl;

	std::cout << "origin dog's idea is: " << originDog->getIdea(0) << std::endl;
	std::cout << "clone dog's idea is: " << cloneDog.getIdea(0) << std::endl << std::endl;
	originDog->setIdea(0, "I am a origin dog!");
	std::cout << "origin dog's new idea is: " << originDog->getIdea(0) << std::endl;
	std::cout << "clone dog's idea is " << cloneDog.getIdea(0) << std::endl << std::endl;
	cloneDog.setIdea(0, "I am a clone dog!");
	std::cout << "clone dog's new idea is: " << cloneDog.getIdea(0) << std::endl;
	std::cout << "origin dog's idea is: " << originDog->getIdea(0) << std::endl <<std::endl;
	delete originDog;
	std::cout << std::endl;

	std::cout << std::endl << "<< Check Wrong Dog Copy >>" << std::endl;
	WrongDog* originWrongDog = new WrongDog();
	WrongDog cloneWrongDog = WrongDog(*originWrongDog);
	std::cout << std::endl;
	
	std::cout << "origin WrongDog's idea is: " << originWrongDog->getIdea(0) << std::endl;
	std::cout << "clone WrongDog's idea is: " << cloneWrongDog.getIdea(0) << std::endl << std::endl;

	originWrongDog->setIdea(0, "I am a origin WrongDog!");
	std::cout << "origin WrongDog's new idea is: " << originWrongDog->getIdea(0) << std::endl;
	std::cout << "clone WrongDog's idea is " << cloneWrongDog.getIdea(0) << std::endl << std::endl;
	cloneWrongDog.setIdea(0, "I am a clone WrongDog!");
	std::cout << "clone WrongDog's new idea is: " << cloneWrongDog.getIdea(0) << std::endl;
	std::cout << "origin WrongDog's idea is: " << originWrongDog->getIdea(0) << std::endl <<std::endl;

	delete originWrongDog->getBrain();
	delete originWrongDog;
	//delete cat;
// 깊은 복사 테스트  original dog, copy dog
// 얕은 복사 차이 테스트
	return 0;
}