#include "pipex.h"

void	do_cmd2(t_arg arg)
{
	pid_t	pid;
	if (arg.cmd1 == 0)
		return ;
	int		fd[2];

	pipe(fd);
	dup2(fd[1], STDIN_FILENO);
	dup2(arg.outfile_fd, STDOUT_FILENO);
	pid = fork();
	if (pid == 1) //child 프로세스가 2개 열리니까 여기는 pid 1로 판단 
	{
		execve(arg.cmd2_path, arg.cmd2, NULL);
	}
}