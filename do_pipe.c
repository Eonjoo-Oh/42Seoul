#include "pipex.h"

#include <unistd.h>
#include <fcntl.h>

void	do_pipe(int temp_fd, char *cmd2, char *outfile)
{
	pid_t		pid;
	int			outfile_fd;

	dup2(0, temp_fd);
	outfile_fd = open(outfile, O_CREAT | O_RDWR);
	pid = fork();
	if (pid == 1)
	{
		dup2(1, outfile_fd);
		execve(cmd2, STDIN_FILENO, NULL);
	}
}
