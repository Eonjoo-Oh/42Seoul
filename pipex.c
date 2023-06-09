/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:32:04 by eoh               #+#    #+#             */
/*   Updated: 2023/06/09 21:03:30 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_leak()
{
	system("leaks pipex");
}

void	init_arg(t_arg *arg, char **argv, char **envp)
{
	arg->infile_fd = open(argv[1], O_RDONLY | O_CREAT);
	if (arg->infile_fd == -1)
	{
		perror("infile open error");
		exit(errno);
	}
	arg->outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile_fd == -1)
	{
		perror("infile open error");
		exit(errno);
	}
	arg->path = get_path(envp);
	arg->cmd1 = get_cmd(argv[2]);
	arg->cmd2 = get_cmd(argv[3]);
	arg->cmd1_path = get_cmd_path(arg, 1);
	arg->cmd2_path = get_cmd_path(arg, 2);//여기까지 명령어 파싱부분
}

//void	free_arg(t_arg *arg)
//{
//	int	i;

//	i = 0;

//	while (arg->path[i])
//	{
//		free(arg->path[i]);
//		i++;
//	}
//}

int main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	atexit(check_leak);
	if (argc != 5)
		exit(1);
	init_arg(&arg, argv, envp);
	do_cmd(&arg);
	free_arg(&arg);
	//free_arg(&arg);
	//system("leaks pipex");
	return (0);
}