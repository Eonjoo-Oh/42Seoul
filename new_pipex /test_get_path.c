#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;
	int		i = 0;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (argc  == 0 || argv == 0)
		return (0);
	get_path(envp, arg);
	
	while ((arg->path)[i])
	{
		printf("%s\n", (arg->path)[i]);
		i++;
	}
	return (0);
}
//gcc -g test_get_cmd.c get_cmd.c ft_split.c pipex_utils.c