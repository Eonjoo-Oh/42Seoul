/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:14:17 by eoh               #+#    #+#             */
/*   Updated: 2023/06/04 18:14:21 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	int		s;
	
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		heredoc_bonus(argc, argv, envp);
	else
	{
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
}

// < file1 cmd1 | cmd2 > file2
// ./pipex "file1" "cmd1" "cmd2" "file2"
// ./pipex "infile" "ls -l" "wc -l" "outfile"
//14, 25, 28