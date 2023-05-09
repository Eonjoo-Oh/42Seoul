#include "pipex.h"

void	print_error(char *message)
{
	perror(message);
	exit(errno);
}
//exit status 128이 뭔데 자꾸 여기서 틀리지?