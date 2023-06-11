/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:08:03 by eoh               #+#    #+#             */
/*   Updated: 2023/06/11 23:23:15 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pid2(t_arg *arg)
{
	if (close(arg->fd[1]) == -1)
		print_error("close error");
	if (dup2(arg->fd[0], STDIN_FILENO) == -1)
		print_error("dup error");
	if (dup2(arg->outfile_fd, STDOUT_FILENO) == -1)
		print_error("dup error");
	if (close(arg->fd[0]) == -1)
		print_error("close error");
	if (close(arg->outfile_fd) == -1)
		print_error("close error");
	if (execve(arg->cmd2_path, arg->cmd2, NULL) == -1)
		print_error("execve failed");
}

void	do_pid1(t_arg *arg)
{
	if (close(arg->fd[0]) == -1)
		print_error("close error");
	if (dup2(arg->infile_fd, STDIN_FILENO) == -1)
		print_error("dup error");
	if (dup2(arg->fd[1], STDOUT_FILENO) == -1)
		print_error("dup error");
	if (close(arg->infile_fd) == -1)
		print_error("close error");
	if (close(arg->fd[1]) == -1)
		print_error("close error");
	if (execve(arg->cmd1_path, arg->cmd1, NULL) == -1)
		print_error("execve failed");
}

//void	do_pid1(t_arg *arg)
//{
//	if (close(arg->fd[0]) == -1)
//		print_error("close error", arg);
//	if (dup2(arg->infile_fd, STDIN_FILENO) == -1)
//		print_error("dup error", arg);
//	if (dup2(arg->fd[1], STDOUT_FILENO) == -1)
//		print_error("dup error", arg);
//	if (close(arg->infile_fd) == -1)
//		print_error("close error", arg);
//	if (close(arg->fd[1]) == -1)
//		print_error("close error", arg);
//	if (execve(arg->cmd1_path, arg->cmd1, NULL) == -1)
//		print_error("execve failed", arg);
//}

void	do_cmd(t_arg *arg)
{
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(arg->fd) == -1)
		print_error("pipe error");
	pid1 = fork();
	if (pid1 == -1)
		print_error("fork error");
	if (pid1 == 0)
		do_pid1(arg);
	if (waitpid(pid1, 0, 0) == -1)
		print_error("wait error");
	pid2 = fork();
	if (pid2 == -1)
		print_error("fork error");
	if (pid2 == 0)
		do_pid2(arg);
	if (close(arg->fd[0]) == -1)
		print_error("close error");
	if (close(arg->fd[1]) == -1)
		print_error("close error");
	if (waitpid(pid2, 0, 0) == -1)
		print_error("wait error");
}
