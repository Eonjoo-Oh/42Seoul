#include <unistd.h>
#include <fcntl.h>

int	do_pipe(int fd, char *cmd2, char *filename
{
	char		**arg;
	pid_t		pid;
	int			fd;
	const char	*result_file;

	arg = arg_pipe(fd);
	if (arg == 0)
		return (0);
	pid = fork();
 	result_file = get_resfile(filename);
	fd = open(result_file, O_CREAT | O_RDWR);
	if (pid == 1)
	{
		dup2(fd, 1);
		execve(cmd2, arg, NULL);
	}

}
