#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipe	pipe;

	if (argc != 5)
		return (0);

	pipe.path = get_path(envp);
	pipe.infile_fd = open(argv[1], O_RDONLY);
	pipe.outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipe.cmd1 = get_cmd(pipe.path, argv[2]);
	pipe.cmd2 = get_cmd(pipe.path, argv[3]);

/*
	printf("%s\n", pipe.cmd1);
	printf("%s\n", pipe.cmd2);*/
	/*
	fd = do_cmd(argv[1], cmd1);//이쯤에서 fodrk를 써야된다.
	do_pipe(fd, cmd2, argv[4]);*/
}