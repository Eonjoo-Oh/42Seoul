/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:27:34 by eoh               #+#    #+#             */
/*   Updated: 2023/05/24 17:35:55 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd_path(t_arg *arg)
{
	char	**path;
	char	*cmd;
	char	*result;
	int		i;

	path = arg->path;
	cmd = argv[arg->order + 2];
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
		free(result);
		exit(errno);
	}
	arg->cmd_path = result;
}

void	get_cmd(t_arg *arg)
{
	char	*cmd;
	char	**result;

	cmd = argv[arg->order + 2];
	result = ft_split(cmd, ' ');
	if (!result)
		exit(errno);
	//여기서는 access로 확인해주어야하나? //가능한 옵션인지는 어떻게 확인?
	arg->cmd = result;
}
