#include <iostream>
#define DefaultMessage "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 0)
		std::cout << DefaultMessage;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			std::cout << static_cast<char>(toupper(argv[i][j]));
			j++;
		}
		std::cout << std::endl;
		i++;
	}
	return 0;
}