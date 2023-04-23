#include "pipex.h"

char	**get_cmd(char *cmd)
{
	char	**result;

	result = ft_split(cmd, ' ');
	return (result);
}