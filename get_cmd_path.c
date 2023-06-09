/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:24:09 by eoh               #+#    #+#             */
/*   Updated: 2023/06/09 21:20:22 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//void	free_path(t_arg *arg)
//{
//	int	i;

//	i = 0;
//	while (arg->path[i])
//	{
//		free(arg->path[i]);
//		i++;
//	}
//	free(arg->path);
//}
char	*get_cmd_path(t_arg *arg, int n)
{
	int		i;
	char	**path;
	char	**cmd;
	char	*result;

	path = arg->path;
	result = 0;
	if (n == 1)
		cmd = arg->cmd1;
	else
		cmd = arg->cmd2;
	i = 0;
	while (path[i])
	{
		result = ft_strjoin(path[i], cmd[0]);
		if (access(result, F_OK) == 0)
			break ;
		free(result);
		i++;
	}
	if (access(result, F_OK) != 0)
	{
		free(result);
		perror("wrong command");
		exit(errno);
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