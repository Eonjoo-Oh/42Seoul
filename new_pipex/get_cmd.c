/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:27:34 by eoh               #+#    #+#             */
/*   Updated: 2023/06/05 16:29:47 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(t_arg *arg, char *cmd)
{
	char	**path;
	char	*result;
	int		i;

	path = arg->path;
	result = 0;
	i = 0;
	while (path[i])
	{
		result = ft_strjoin(path[i], cmd);
		if (access(result, F_OK) == 0)
			break ;
		free(result);
		result = 0;
		i++;
	}
	if (access(result, F_OK) != 0)
	{
		perror("wrong command path");
		free(result);
		exit(errno);
	}
	return (result);
}

char	**get_cmd(char *cmd)
{
	char	**result;
	
	result = ft_split(cmd, ' ');
	if (!result)
	{
		perror("wrong command");
		exit(errno);
	}
	//여기서는 access로 확인해주어야하나? //가능한 옵션인지는 어떻게 확인?->그건 execve가 확인해줌
	return (result);
}

void	add_slash(t_arg *arg)
{
	int		i;
	char	*old_path;
	i = 0;
	while ((arg->path)[i])
	{
		old_path = (arg->path)[i]; 
		(arg->path)[i] = ft_strjoin((arg->path)[i], "/");
		free(old_path);
		i++;
	}
}

void	get_path(char	**envp, t_arg *arg)
{
	char	*temp_path;
	int		i;

	i = 0;
	temp_path = NULL;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp_path = envp[i];
			break ;
		}
		i++;
	}
	if (temp_path == 0)
	{
		perror("no path");
		exit(errno);//no path
	}
	temp_path += 5;
	arg->path = (ft_split(temp_path, ':'));
	add_slash(arg);
}