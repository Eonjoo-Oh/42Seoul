#include "Bureaucrat.hpp"

int  main()
{
	//form exception test
	//form << test
	//besigned test
	// sign form test

	std::cout << std::endl << "<< Constructor Exception Test >> " << std::endl;
	Form	taskA("A", 4, 4);
	Form	taskB("B", -1, 2);
	Form	taskC("C", 67, 160);
	Form	taskD("D", 120, 150);

	std::cout << std::endl << "<< Operator << Overloading Test >> " << std::endl;
	std::cout << taskA;
	std::cout << taskD;

	std::cout << std::endl << "<< beSigned and signForm test >> " << std::endl;
	Bureaucrat kim("Kim", 1);
	Bureaucrat han("Han", 100);
	han.signForm(taskA);
	han.signForm(taskD);
	kim.signForm(taskA);
}