#include "pipex.h"

int main(int argc, char **argv)
{
	char	**result;

	result = get_cmd(argv, argc);
	for(int i = 0; result[i]; i++)
	{
		printf("%s\n", result[i]);
	}

	return (0);
}