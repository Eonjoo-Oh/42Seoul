/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 02:01:11 by eoh               #+#    #+#             */
/*   Updated: 2023/06/09 02:01:37 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_arg	init_arg(t_arg *arg, int argc, char **argv, char **envp)
{
	arg->argv = argv;
	get_path(envp, arg);
	arg->cmd = NULL;
	arg->cmd_path = NULL;
	arg->argc = argc;
	arg->order = 2;
	return (*arg);
}
