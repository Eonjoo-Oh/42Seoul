#include "pipex.h"

void	arg_init(t_arg *arg, char **argv)
{
	arg->argv = argv;
	arg->cmd = NULL;
	arg->cmd_path = get_cmd_path(argv, argc);

}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	arg_init(&arg, char **argv);
}