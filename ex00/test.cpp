#include <iostream>
#define DefaultMessage "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

class CapitalConverter
{
public:
	void	ConvertToCapital(int c)
	{
		if (c >= 'a' && c <= 'z')
			std::cout << static_cast<char>(c - 32);
		else
			std::cout << static_cast<char>(c);
	}
};

int main(int argc, char **argv)
{
	int	i;
	int	j;
	CapitalConverter converter;

	i = 1;
	if (argc == 0)
		std::cout << DefaultMessage;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			converter.ConvertToCapital(argv[i][j]);
			j++;
		}
		if (i != argc - 1)
			std::cout << ' ';
		i++;
	}
	return 0;
}