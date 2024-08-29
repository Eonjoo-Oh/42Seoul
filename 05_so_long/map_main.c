/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:13 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 13:11:50 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_map *map)
{
	int		i;
	char	**res;
	char	*str;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (map->l + 1));
	if (!res)
		return (0);
	res[map->l] = 0;
	while (i < map->l)
	{
		str = get_next_line(map->fd);
		res[i] = ft_strdup(str);
		if (i < map->l - 1 && ft_strlen(res[i]) != (map->w + 1))
			error_msg("invalid map");
		if (i == map-> l - 1 && ft_strlen(res[i]) != (map->w))
			error_msg("invalid map");
		free(str);
		i++;
	}
	close(map->fd);
	return (res);
}

t_map	*init_map(void *m_ptr, char *argv)
{
	t_map	*map;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	i = 0;
	map->form = 0;
	map->mlx_ptr = m_ptr;
	map->win_ptr = 0;
	check_map_name(argv, map);
	map->path = argv;
	while (i < 3)
	{
		map->element[i] = 0;
		i++;
	}
	get_map_length(map->path, map);
	map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
		perror_msg();
	map->move = 0;
	map->collected = 0;
	return (map);
}

t_map	*map_main(void *mlx_ptr, char *argv, t_all *all)
{
	t_map	*map;

	map = init_map(mlx_ptr, argv);
	map->form = read_map(map);
	if (map->form == 0)
		error_msg("map error");
	map_validate_main(map, all);
	return (map);
}
