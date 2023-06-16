#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg(&arg, argc, argv, envp);

	printf("%s\n", arg.path[0]);
}