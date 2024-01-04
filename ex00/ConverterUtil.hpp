#ifndef CONVERTERUTIL_HPP
#define CONVERTERUTIL_HPP

#include <iostream>

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