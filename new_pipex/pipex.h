/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:58:23 by eoh               #+#    #+#             */
/*   Updated: 2023/05/24 17:06:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_arg{
	char	**argv;
	char	**path;
	char	**cmd;
	char	*cmd_path;
	int		fd[2];
	int		argc;
	int		order;
	int		infile_fd;
}t_arg;


#endif