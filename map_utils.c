/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:19:36 by eoh               #+#    #+#             */
/*   Updated: 2023/06/17 00:15:35 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

check_map_name(char *name)
{
	if (rev_strncmp(name, "reb.", 4) == -1)
		exit(1);
}

int	get_map_length(char *name)
{
	int		fd;
	int		l;
	char	*str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		perror("file open error");
		exit(1);
	}
	l = 1;
	str = get_next_line(fd);
	free(str)
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		l++;
		free(str);
	}
	close(fd);
	return (l);
}

int	get_map_width(char *name)
{
	int		fd;
	int		w;
	char	*str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		perror("file open error");
		exit(1);
	}
	w = 0;
	str = get_next_line(fd);
	while (str[w])
	{
		w++;
	}
	free(str);
	close(fd);
	return (w);
}

int	check_map_width(char *line, int w)
{
	if (ft_strlen(line) != w)
		return (-1);
	else
		return (1);
}