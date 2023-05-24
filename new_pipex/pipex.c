#include "pipex.h"

t_arg init_arg(t_arg *arg, int argc, char **argv)
{
	if (pipe(arg->fd) == -1)
		exit(errno);
	var->order = 0;
	var->argc = argc;
}

int	main(int argc, char **argv, char **envp);
{
	t_arg	arg;
	pid_t	pid;

	if (argc != 5)
		exit(errno);

	arg = init_arg(&arg, argc, argv);

	while (arg.order < argc - 2)
	{
		get_cmd(&arg);
		get_cmd_path(&arg);
		arg.order++;
	}
	close(fd[0]);
	close(fd[1]);
}