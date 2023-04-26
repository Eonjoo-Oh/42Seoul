/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:08:03 by eoh               #+#    #+#             */
/*   Updated: 2023/04/26 14:07:36 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_cmd1(t_arg arg)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(arg.infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(arg.infile_fd);
		close(fd[1]);
		execve(arg.cmd1_path, arg.cmd1, NULL);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(arg.outfile_fd, STDOUT_FILENO);
		close(fd[0]);
		close(arg.outfile_fd);
		execve(arg.cmd2_path, arg.cmd2, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
}

	//갑자기된다? close도 다 제대로 해줘야하는것 같음

	/*while (i < 3)
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
			{
				pid = fork();
				waitpid(pid, 0, 0);
			}
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
}*/
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
}*/
//./pipex infile "ls" "wc -l" outfile -> 결과 36
// < infile ls | wc -l > outfile
