/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:19:36 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 01:29:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *name, t_map *map)
{
	if (rev_strncmp(name, "reb.", 4) == -1)
	{
		free(map);
		error_msg("wrong map name");
	}
}

int	get_map_width(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i - 1);//개행때문에 i - 1을 해준다.
}

void	get_map_length(char *name, t_map *map)
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
	map->w = get_map_width(str);
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		l++;
		free(str);
	}
	close(fd);
	map->l = l;
}
