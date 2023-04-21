#include "pipex.h"

char	*get_cmd(char **path, char *cmd)
{
	int		i;
	char	*result;

	i = 0;
	while (path[i])
	{
		result = ft_strjoin(path[i], cmd);
		if (access(result, F_OK) == 0)
			break ;
		i++;
	}
	if (result == 0)
		return (0);
	return (result);
}

/*
int main(int argc, char **argv, char **envp)
{
	char *cmd;

	if (argc != 2)
		return (0);
	cmd = get_cmd(envp, argv[1]);
	printf("cmd path : %s\n", cmd);

	return (0);
}*/