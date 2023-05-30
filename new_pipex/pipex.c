#include "pipex.h"

t_arg init_arg(t_arg *arg, int argc, char **argv, char **envp)
{
	arg->argv = argv;
	get_path(envp, arg);
	arg->cmd = NULL;
	arg->cmd_path = NULL;
	//close((arg->fd)[0]);
	//close((arg->fd)[1]);
	arg->argc = argc;
	arg->order = 2;
	return (*arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	int		s;
	if (argc != 5)
		exit(errno);
	arg = init_arg(&arg, argc, argv, envp);
	while (arg.order < argc - 1)
	{
		find_order(&arg);
		arg.order++;
	}
	close(arg.fd[0]);
	close(arg.fd[1]);
	while (1)
	{
		if (wait(&s) == -1)
			break ;
	}
}

// < file1 cmd1 | cmd2 > file2
// ./pipex "file1" "cmd1" "cmd2" "file2"
// ./pipex "infile" "ls -l" "wc -l" "outfile"