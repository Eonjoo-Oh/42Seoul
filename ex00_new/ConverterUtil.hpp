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
		static int			determineType(const std::string &input);
		static bool			isChar(const std::string &input);
		static bool			isValidRangeChar(int num);
		static bool			isDisplayableChar(int num);
		static bool			isInt(const std::string &input);
		static bool			isFloat(std::string input);
		static bool			isDouble(const std::string &input);
		static void			printConvertedFromInt(std::string input);
		static void			printConvertedFromFloat(std::string input);
		static bool			onlyZeroBelowPoint(std::string input);
		//static char			convertToChar(std::string input, int type);
//----------------
		static bool			isValidInt(float num);
		static int			floatToInt(std::string str);
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
		enum type{
			CHAR = 0,
			INT,
			FLOAT,
			DOUBLE,
			OTHER
		};
};

#endif