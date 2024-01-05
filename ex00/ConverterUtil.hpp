#ifndef CONVERTERUTIL_HPP
#define CONVERTERUTIL_HPP

#include <iostream>
#include <sstream>

class	ConverterUtil
{
	public :
		ConverterUtil();
		ConverterUtil(const ConverterUtil &obj);
		ConverterUtil &operator=(const ConverterUtil &obj);
		~ConverterUtil();
		static std::string	deleteWhiteSpace(const std::string &input);
		static bool			isValidChar(int num);
		static bool			isDisplayableChar(int num);
		static bool			isValidInt(float num);
		static bool			isFloat(std::string str);
		static int			floatToInt(std::string str);
		static bool			isDouble(std::string str);
		static int			doubleToInt(std::string str);
		class	RangeException : public std::exception
		{
			public :
			const char *what(void) const throw();
		};
		class	charDisplayException : public std::exception
		{
			const char *what(void) const throw();
		};
};

#endif