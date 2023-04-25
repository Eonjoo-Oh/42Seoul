#include "pipex.h"

void	do_cmd1(t_arg arg)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	if (pipe(fd) == -1)
		return ;
	i = 1;

	while (i < 3)
	{
		pid = fork();
		if (i == 1)
		{
			if (pid == 0)
			{
				dup2(arg.infile_fd, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				execve(arg.cmd1_path, arg.cmd1, NULL);
			}
			else
				waitpid(pid, 0, 0);
		}
		else if (i == 2)
		{
			if (pid == 0)
			{
				waitpid(pid, NULL, 0);
				dup2(fd[1], STDIN_FILENO);
				dup2(arg.outfile_fd, STDOUT_FILENO);
				execve(arg.cmd2_path, arg.cmd2, NULL);
			}
			else
				waitpid(pid, 0, 0);
		}
		i++;
	}
}
/*
	if (pid == 0)
	{
		dup2(arg.infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(arg.cmd1_path, arg.cmd1, NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd[1], STDIN_FILENO);
		dup2(arg.outfile_fd, STDOUT_FILENO);
		execve(arg.cmd2_path, arg.cmd2, NULL);
	}


	while(i < argc - 3)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				infile + command
			else if (i == argc - 4)
				outfile + command
			else
				execve (fd[2] 잘 기억도록)
		}
		else
		{
			기다리고 
			표준 입력을 계속 연결줘야해
			waitpid();
		}
	}
}
//./pipex infile "ls" "wc -l" outfile -> 결과 36
// < infile ls | wc -l > outfile
