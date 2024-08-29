/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:41:48 by eoh               #+#    #+#             */
/*   Updated: 2023/06/12 13:29:48 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_dimension(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	free_arg(t_arg *arg)
{
	if (arg == 0)
		return ;
	free_dimension(arg->path);
	free_dimension(arg->cmd1);
	free_dimension(arg->cmd2);
	free(arg->cmd1_path);
	free(arg->cmd2_path);
}

void	print_error(char *message)
{
	perror(message);
	exit(1);
}
