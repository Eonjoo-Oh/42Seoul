#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* pBrain = &brain;
	std::string& rBrain = brain;

	std::cout << "brain's address : "<< &brain << std::endl;
	std::cout << "pBrain's address : "<< &pBrain << std::endl;
	std::cout << "rBrain's address : "<< &rBrain << std::endl;
	std::cout << "Brain's value : "<< brain << std::endl;
	std::cout << "rBrain's value : "<< pBrain << std::endl;
	std::cout << "rBrain's value : "<< rBrain << std::endl;
}