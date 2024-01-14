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
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator = (const ScalarConverter  &obj);
		~ScalarConverter();
	public :
		static void	convert(std::string input);
};

#endif