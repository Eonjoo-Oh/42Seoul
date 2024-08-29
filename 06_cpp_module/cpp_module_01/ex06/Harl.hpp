#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#define MAX_NUMBER_OF_COMPLAIN 4

class	Harl
{
	private:
		std::string	filterLevelArr[MAX_NUMBER_OF_COMPLAIN];
		std::string	complainLevelArr[MAX_NUMBER_OF_COMPLAIN];
		int			filterLevel;
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public:
		Harl(std::string inputFilterLevel);
		~Harl();
		void	setFilterLevel(std::string input);
		int		getFilterLevel(void);
		void	complainFilter(void);
};

#endif