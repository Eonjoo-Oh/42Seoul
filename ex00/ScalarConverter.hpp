#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "ConverterUtil.hpp"

class	ConverterUtil;

enum type{
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	OTHER
};

class	ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator = (const ScalarConverter  &obj);
		~ScalarConverter();
		static void	convert(std::string input);
};

#endif