/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:59:52 by eoh               #+#    #+#             */
/*   Updated: 2023/06/09 02:00:31 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	int		s;

	if (argc != 5)
		exit(1);
	arg = init_arg(&arg, argc, argv, envp);
	while (arg.order < argc - 1)
	{
		find_order(&arg);
		arg.order++;
	}
	close(arg.fd[0]);
	close(arg.fd[1]);
	while (1)
	{
		if (wait(&s) == -1)
			break ;
	}
}

// < file1 cmd1 | cmd2 | cmd3 |> file2
// ./pipex "file1" "cmd1" "cmd2" "file2"
// ./pipex "infile" "ls -l" "wc -l" "outfile"
//14, 25, 28