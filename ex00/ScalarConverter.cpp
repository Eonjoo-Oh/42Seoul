#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) 
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) 
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string input)
{
	std::string	joinedInput;
	char		charConverted;
	//int			intConverted;
	//float		floatConverted;
	//double		doubleConverted;

	for(std::size_t i = 0; i < input.length(); i++)
	{
		if (!(input[i] == 32 || (input[i] >= 9 && input[i] <= 13)))
			joinedInput += input[i];
	}
	try {
		std::istringstream	iss(joinedInput);
		int					temp;
		std::cout << "char: ";
		iss >> temp;
		if (iss.fail() || !iss.eof() || joinedInput.empty())
			throw	std::exception();//따로 클래스만들기
		if (temp < 0 || temp > 127)
			throw	std::exception();
		charConverted = static_cast<char>(temp);
		//charConverted = std::atoi(joinedInput.c_str());
		//charConverted = stoi(input);//stoi가 c++98에선 안됨;
		if ((charConverted >= 0 && charConverted <= 8) \
		|| (charConverted >= 14 && charConverted <= 31) \
		|| charConverted == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << charConverted << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}
