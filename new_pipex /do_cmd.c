/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:44:22 by eoh               #+#    #+#             */
/*   Updated: 2023/06/04 20:17:56 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_first(t_arg *arg)
{
	pid_t	pid;

	if (pipe(arg->fd) == -1)
	{
		perror("pipe error");
		exit(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(errno);
	}
	if (pid == 0)
	{
		close(arg->fd[0]);
		arg->infile_fd = open(arg->argv[1], O_RDONLY);
		if (arg->infile_fd == -1)
		{
			perror("infile open error");
			exit(errno);
		}
		dup2(arg->infile_fd, STDIN_FILENO);
		close(arg->infile_fd);
		dup2(arg->fd[1], STDOUT_FILENO);
		close(arg->fd[1]);
		if (execve(arg->cmd_path, arg->cmd, NULL) == -1)
		{
			perror("execve error");
			exit(errno);
		}
	}
	//close(arg->fd[0]);
	//close(arg->fd[1]);
	//else
	//	wait(NULL);
}

void	do_last(t_arg *arg)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(errno);
	}
	if (pid == 0)
	{
		close(arg->fd[1]);
		arg->outfile_fd = open(arg->argv[arg->argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (arg->outfile_fd == -1)
		{
			perror("infile open error");
			exit(errno);
		}
		dup2(arg->fd[0], STDIN_FILENO);
		close(arg->fd[0]);
		dup2(arg->outfile_fd, STDOUT_FILENO);
		close(arg->outfile_fd);
		if (execve(arg->cmd_path, arg->cmd, NULL) == -1)
		{
			perror("execve error");
			exit(errno);
		}
	}
	//close(arg->fd[0]);
	//close(arg->fd[1]);
	//else
	//	wait(NULL);
}

void	find_order(t_arg *arg)
{
	arg->cmd = get_cmd(arg->argv[arg->order]);
	arg->cmd_path = get_cmd_path(arg, arg->cmd[0]);
	if (arg->order == 2)
		do_first(arg);
	else if (arg->order == 3)
		do_last(arg);
}

/*
//bonus
else
{
	find_cmd(&arg);
	do_middle;
}

void	do_middle(t_arg *arg)
{
	pid_t = pid;

	dup2(arg->fd[0], STDIN_FILENO);
	dup2(arg->fd[1], STDOUT_FILENO);
	close(arg->fd[0]);
	close(arg->fd[1]);
	if (execve(arg->cmd_path, arg->cmd, NULL) == -1)
		print_error("execve failed");
}
*/