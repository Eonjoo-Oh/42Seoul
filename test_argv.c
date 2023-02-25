#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
	int j;
    if (argc == 1)
        printf("wrong");
        
	i = 0;
    while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			printf("[%d][%d]: %c\n", i, j, argv[i][j]);
			j++;
		}
		i++;
	}
    return (0);
}