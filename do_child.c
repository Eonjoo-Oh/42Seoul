#include "pipex.h"

void	do_pid1(t_arg arg)
{
	close(arg.fd[0]);
	dup2(arg.infile_fd, STDIN_FILENO);
	dup2(arg.fd[1], STDOUT_FILENO);
	close(arg.infile_fd);
	close(arg.fd[1]);
	execve(arg.cmd1_path, arg.cmd1, NULL);
}

void	do_pid2(t_arg arg)
{
	close(arg.fd[1]);
	dup2(arg.fd[0], STDIN_FILENO);
	dup2(arg.outfile_fd, STDOUT_FILENO);
	close(arg.fd[0]);
	close(arg.outfile_fd);
	execve(arg.cmd2_path, arg.cmd2, NULL);	
}