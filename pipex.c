/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:32:04 by eoh               #+#    #+#             */
/*   Updated: 2023/05/10 16:27:23 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	if (argc != 5)
		exit(1);

	arg.path = get_path(envp);
	arg.infile_fd = open(argv[1], O_RDONLY | O_CREAT);
	if (arg.infile_fd == -1)
		perror("infile open error");
	arg.outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg.outfile_fd == -1)
		print_error("outfile open error");//왜 두개 다르게 해줘야 통과?*/
	arg.cmd1 = get_cmd(argv[2]);
	arg.cmd2 = get_cmd(argv[3]);
	arg.cmd1_path = get_cmd_path(arg, 1);
	arg.cmd2_path = get_cmd_path(arg, 2);//여기까지 명령어 파싱부분
	do_cmd(arg);

	return (0);
}