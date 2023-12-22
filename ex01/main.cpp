#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define NUM_OF_ANIMALS 6

void	leaks()
{
	system("leaks main");
}

int main() {
	atexit(leaks);
	const Animal* animal[NUM_OF_ANIMALS];

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	std::cout << "<< Check Animal Array >>" << std::endl;
	for(int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		std::cout << "animal [" << i << "]" << "'s type : " << animal[i]->getType() << std::endl;
		std::cout << "and its sound : ";
		animal[i]->makeSound();
	}

	std::cout << std::endl << "------------------------------------" << std::endl << std::endl;
	Dog* dog = new Dog();
	Cat* cat = new Cat();
	std::cout << std::endl;
	std::cout << "<< Check Dog and Cat's Idea! >>" << std::endl;
	std::cout << "Dog's default idea is : " << dog->getIdea(0) << std::endl;
	std::cout << "Cat's default idea is : " << cat->getIdea(0) << std::endl;
	std::cout << "<<They have new thinking! >>" << std::endl; 
	dog->setIdea(0, "I'm a super dog!");
	std::cout << "Dog's new idea is : " << dog->getIdea(0) << std::endl;
	cat->setIdea(0, "I'm a super cat!");
	std::cout << "Cat's new idea is : " << cat->getIdea(0) << std::endl;
	std::cout << std::endl;
	for(int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		delete animal[i];
	}
	delete dog;
	delete cat;
// 깊은 복사 테스트  original dog, copy dog
// 얕은 복사 차이 테스트
	return 0;
}