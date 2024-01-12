#include "whatever.hpp"
#include <iostream>

int main ()
{
	int	a = 2;
	int	b = -1;
	char	c = '!';
	char	c2 = '%';
	float	f1 = 42.0f;
	float	f2 = 38.5f;

	swap(a, b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl << std::endl;

	swap(c, c2);
	std::cout << "c : " << c << std::endl;
	std::cout << "c2 : " << c2 << std::endl << std::endl;

	swap(f1, f2);
	std::cout << "f1 : " << f1 << std::endl;
	std::cout << "f2 : " << f2 << std::endl << std::endl;
	
	std::cout << "min between a and b is : " << min(a, b) << std::endl;
	std::cout << "max between a and b is : " << max(a, b) << std::endl;
}