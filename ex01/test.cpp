#include <iostream>

int main()
{
	std::string hello = "helloeveryone";
	//std::cout << hello;
	hello = hello.substr(0, 9);
	std::cout << hello;
	//hello.append(".");
}