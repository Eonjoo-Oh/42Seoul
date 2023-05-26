/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:44:22 by eoh               #+#    #+#             */
/*   Updated: 2023/05/26 22:02:29 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_first(t_arg *arg)
{
	pid_t	pid;

	arg->infile_fd = open((arg->argv)[1], O_RDONLY);
	if (arg->infile_fd == -1)
		perror("infile open error");
	if (pipe(arg->fd) == -1)
		exit(errno);
	close(arg->fd[0]);
	pid = fork();
	if (pid == -1)
		exit(errno);
	if (pid == 0)
	{
		dup2(arg->infile_fd, STDIN_FILENO);
		dup2(arg->fd[1], STDOUT_FILENO);
		close(arg->infile_fd);
		close(arg->fd[1]);
		if (execve(arg->cmd_path, arg->cmd, NULL) == -1)
			exit(errno);
	}
	else
		wait(NULL);
}

void	do_last(t_arg *arg)
{
	pid_t	pid;

	arg->outfile_fd = open(arg->argv[arg->argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile_fd == -1)
		perror("outfile open fd");
	pid = fork();
	if (pid == -1)
		exit(errno);
	if (pid == 0)
	{
		dup2(arg->fd[0], STDIN_FILENO);
		dup2(arg->outfile_fd, STDIN_FILENO);
		close(arg->fd[0]);
		close(arg->fd[0]);
		if (execve(arg->cmd_path, arg->cmd, NULL) == -1)
			exit(errno);
	}
	else
		wait(NULL);
}

void	find_order(t_arg *arg)
{

	if (arg->order == 0)
	{
		get_cmd(arg);
		get_cmd_path(arg);
		do_first(arg);
	}

	else if (arg->order == (arg->argc) - 3)
	{
		get_cmd_path(arg);
		get_cmd(arg);
		do_last(arg);
	}
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