#include "pipex.h"

char	**get_cmd(char *cmd)
{
	char	**result;

	result = ft_split(cmd, ' ');
	if (result == 0)
	{
		perror("blank cmd");
		exit (errno);
	}
	return (result);
}