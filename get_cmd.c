/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:57:02 by eoh               #+#    #+#             */
/*   Updated: 2023/06/12 00:57:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *cmd)
{
	char	**result;

	if (cmd == 0)
	{
		exit(1);
	}
	result = ft_split(cmd, ' ');
	if (result == 0)
	{
		perror("blank cmd");
		exit (errno);
	}
	return (result);
}
