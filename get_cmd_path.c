/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:24:09 by eoh               #+#    #+#             */
/*   Updated: 2023/04/22 10:29:33 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(t_arg arg, int n)
{
	int		i;
	char	**path;
	char	**cmd;
	char	*result;

	path = arg.path;
	result = 0;
	if (n == 1)
		cmd = arg.cmd1;
	else
		cmd = arg.cmd2;
	i = 0;
	while (path[i])
	{
		result = ft_strjoin(path[i], cmd[0]);
		if (access(result, F_OK) == 0)
			return (result);
		i++;
	}
	return (result);
}

/*
int main(int argc, char **argv, char **envp)
{
	char *cmd;

	if (argc != 2)
		return (0);
	cmd = get_cmd(envp, argv[1]);
	printf("cmd path : %s\n", cmd);

	return (0);
}*/