/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:24:09 by eoh               #+#    #+#             */
/*   Updated: 2023/05/18 21:32:31 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd_path(int argc, char **argv, t_arg arg)
{
	char	*cmd_path[argc - 3];
	char	**path;
	char	**result;
	int		i;
	int		j;

	path = arg.path;
	i = 1;
	j = 0;
	while (i < argc - 2)
	{
		while (path[j])
		{
			cmd_path[i - 1] = ft_strjoin(path[j], argv[i]);
			if (access(cmd_path[i - 1], F_OK) == 0)
				continue ;
		}
		exit(errno);
		i++;
	}
	result = cmd_path;
	return (result);
}

/*char	*get_cmd_path(char **argv, int argc)
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
			break ;
		i++;
	}
	if (access(result, F_OK) != 0)
		print_error("wrong command");
	return (result);
}*/


int main(int argc, char **argv, char **envp)
{
	char **cmd;
	t_arg	arg;

	if (argc != 2)
		return (0);
	arg.path = get_path(envp);
	cmd = get_cmd_path(argc, argv, arg);

	for(int i = 0; cmd[i]; i++)
	{
		printf("cmd path : %s\n", cmd[i]);
	}
	
	return (0);
}

//gcc get_cmd_path.c ft_strjoin.c get_path.c ft_strlen.c ft_strncmp.c ft_split.c