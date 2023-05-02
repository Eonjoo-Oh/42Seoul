#include "pipex.h"

void	print_error(char *message)
{
	perror(message);
	exit(1);
}