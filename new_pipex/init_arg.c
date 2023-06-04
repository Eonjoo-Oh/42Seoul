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