#include <iostream>
#define DefaultMessage "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{

	if (argc == 1)
		std::cout << DefaultMessage;
	for(int i = 1; argv[i] != NULL; i++)
	{
		for(int j = 0; argv[i][j] != '\0'; j++)
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j])) ;
		}
	}
	std::cout << std::endl;
}