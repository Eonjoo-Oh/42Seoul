#include <sstream>
#include <iostream>

int main()
{
	double val = 0.1;
	std::stringstream ss;
	ss << val;
	std::string strVal= ss.str();
	std::cout << strVal;
}