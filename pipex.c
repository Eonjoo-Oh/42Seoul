#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char	*cmd1;
	char	*cmd2;
	int		fd;

	if (argc < 5)
		return (0);

	cmd1 = find_cmd(envp, argv[2]);
	cmd2 = find_cmd(envp, argv[3]);
	fd = do_cmd(argv[1], cmd1);//이쯤에서 fork를 써야된다.
	do_pipe(fd, cmd2, argv[4]);
}