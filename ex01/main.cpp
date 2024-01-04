#include "Bureaucrat.hpp"

int  main()
{
	std::cout << std::endl << "<< Constructor Exception Test >> " << std::endl;
	try {
		Form	taskA("A", 4, 4);
		Form	taskB("B", -1, 2);
	}
	catch (std::exception &e)
	{
		std::cout << "Form error! : " << e.what() << std::endl;
	}
	try {
		Form	taskA("A", 4, 4);
		Form	taskB("B", 10, 170);
	}
	catch (std::exception &e)
	{
		std::cout << "Form error! : " << e.what() << std::endl;
	}

	std::cout << std::endl << "<< Operator << Overloading Test >> " << std::endl;
	Form	taskA("A", 4, 4);
	Form	taskD("D", 120, 150);
	std::cout << taskA;
	std::cout << taskD;

	std::cout << std::endl << "<< beSigned and signForm test >> " << std::endl;
	Bureaucrat kim("Kim", 1);
	Bureaucrat han("Han", 100);
	han.signForm(taskA);
	std::cout << "A signed : " << taskA.getIsSigned() << std::endl;
	std::cout << std::endl;

	han.signForm(taskD);
	std::cout << "D signed : " << taskD.getIsSigned() << std::endl;
	std::cout << std::endl;
	
	kim.signForm(taskA);
	std::cout << "A signed : " << taskA.getIsSigned() << std::endl;
	std::cout << std::endl;
}