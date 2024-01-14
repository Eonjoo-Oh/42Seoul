#include "Array.hpp"

int main()
{
	std::cout << "<< OCCF test >>" << std::endl;
	std::cout << std::endl << "default constructor test" << std::endl;
	Array<int>	intArr1;
	std::cout << &(intArr1._arr) << std::endl;

	std::cout << std::endl << "constructor test" << std::endl;
	Array<int>	intArr2(10);
	std::cout << &(intArr2._arr) << std::endl;

}