#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	arg.infile_fd = open(argv[1], O_RDONLY);
	arg.outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRIMC, 0644);
	arg.cmd_path = get_cmd_path(argv);
	arg.num = 0;
	do_pipe(argc, arg);
}