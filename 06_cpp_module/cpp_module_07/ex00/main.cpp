#include "whatever.hpp"
#include <iostream>

int main ()
{
	int	i1 = 2;
	int	i2 = -1;
	char	c1 = '!';
	char	c2 = '%';
	float	f1 = 42.0f;
	float	f2 = 38.5f;

	swap(i1, i2);
	std::cout << "i1 : " << i1 << std::endl;
	std::cout << "i2 : " << i2 << std::endl << std::endl;

	swap(c1, c2);
	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "c2 : " << c2 << std::endl << std::endl;

	swap(f1, f2);
	std::cout << "f1 : " << f1 << std::endl;
	std::cout << "f2 : " << f2 << std::endl << std::endl;
	
	std::cout << "min between i1 and i2 is : " << min(i1, i2) << std::endl;
	std::cout << "max between i1 and i2 is : " << max(i1, i2) << std::endl;
	
	std::cout << "min between c1 and c2 is : " << min(c1, c2) << std::endl;
	std::cout << "max between c1 and c2 is : " << max(c1, c2) << std::endl;
	
	std::cout << "min between f1 and f2 is : " << min(f1, f2) << std::endl;
	std::cout << "max between f1 and f2 is : " << max(f1, f2) << std::endl;
}