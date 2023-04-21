#include <stdio.h>
#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char	**path;
	char	*cmd;
	int		i;

	if (argc < 0)
		return (0);
	i = 0;
	path = get_path(envp);
	cmd = get_cmd(path, argv[1]);

	printf("cmd path : %s\n", cmd);

	return (0);
}

//gcc test_get_cmd.c get_path.c ft_strncmp.c ft_split.c ft_strjoin.c get_cmd.c ft_strlen.c
