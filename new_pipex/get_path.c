/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:25:09 by eoh               #+#    #+#             */
/*   Updated: 2023/05/18 21:20:02 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	*temp_path;
	char	**path;
	int		i;

	temp_path = NULL;
	i = 0;
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
		return (0);
	temp_path += 5;
	path = (ft_split(temp_path, ':'));
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}
//터미널에 export를 치면 환경변수가 나오는데 PATH=은 밀고 : 으로 나눈 것
