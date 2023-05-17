#include "pipex.h"

void	do_pipe(int argc, t_arg arg)
{
	pid_t = pid;
	int		status;

	while (arg.num < argc - 1)
	{
		pipe(arg.fd);
		pid = fork;
		if (pid == 0)
		{
			if (arg.num == 1)
			{
				dup2(arg.infile_fd, STDIN_FILENO);
				dup2(arg.fd[1], STDOUT_FILENO);
				close(arg.infile_fd);
				close(arg.fd[1]);
				execve(arg.cmd_path[arg.num], arg.cmd[arg.num], NULL);
			}
			else if (arg.num == argc - 2)
			{
				pid = fork();
				dup2(arg.fd[0], STDIN_FILENO);
				dup2(arg.fd[1], STDOUT_FILENO);
				close(arg.fd[0]);
				close(arg.fd[1]);
				execve(arg.cmd_path[arg.num]. arg.cmd[arg.num], NULL);
			}
			else
			{
				pid = fork();
				dup2(arg.fd[0], STDIN_FILENO);
				dup2(arg.fd[1], STDOUT_FILENO);
				close(arg.fd[0]);
				close(arg.fd[1]);
				execve(arg.cmd_path[arg.num]. arg.cmd[arg.num], NULL);
			}
			(*arg).num++;
		}
		else
			wait(&status);
	}
}