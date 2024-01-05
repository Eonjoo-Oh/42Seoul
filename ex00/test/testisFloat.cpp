#include <iostream>

bool	isFloat(std::string str)
{
	int		pointCnt = 0;
	size_t	length = str.length();

	if (length < 4)
		return (false);
	for(size_t i = 0; i < length; i++)
	{
		if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '.' && str[i] != 'f')
			return (false);
		if (str[i] == 'f' && i != length - 1)
			return (false);
		if (str[i] == '.' && !(i > 0 && i < length - 2))
			return (false);
		else if (str[i] == '.')
			pointCnt++;
	}
	if (str[length - 1] != 'f' || pointCnt != 1)
		return (false);
	return (true);
}

int main()
{
	std::cout << isFloat("0.0.0f") << std::endl;
}