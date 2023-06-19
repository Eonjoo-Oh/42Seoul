/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:19:36 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 20:11:01 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *name)
{
	if (rev_strncmp(name, "reb.", 4) == -1)
		exit(1);
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


/*int	delete_n(char **res, t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	map->form = (char **)malloc(sizeof(char) * (map->l + 1));
	if (map->form == 0)
		return (0);
	map->form[map->l] = 0;
	while (map->form[i])
	{
		j = 0;
		map->form[i] = (char *)malloc(sizeof(char) * (map->w + 1));
		if (map->form[i])
			return (0);
		map->form[i][map->w] = '\0';
		while (j < map->w)
		{
			map->form[i][j] = res[i][j];
			j++;
		}
		i++;
	}//free res해야됨
}*/