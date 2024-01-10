#include <iostream>

bool	onlyZeroBelowPoint(std::string input)
{
	size_t	i;

	i = 0;
	while (i < input.length())
	{
		if (input[i] == '.')
			break;
		i++;
	}
	i++;
	while (i < input.length())
	{
		if (input[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

int main()
{
	std::cout << onlyZeroBelowPoint("42.0001") << std::endl;
	std::cout << onlyZeroBelowPoint("42.000") << std::endl;
	std::cout << onlyZeroBelowPoint("42") << std::endl;
	std::cout << onlyZeroBelowPoint("42.") << std::endl;
}