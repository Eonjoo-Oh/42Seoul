/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:13 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 03:44:04 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, char **map_form)
{
	int	i;

	i = 0;
	free(map->path);
	while (map_form[i])
	{
		free(map_form[i]);
		i++;
	}
	free(map_form);
}

char	**read_map(t_map *map)
{
	char	**map_form;
	int		i;

	map_form = (char **)malloc(sizeof(char *) * (map->l + 1));
	if (!map_form)
		return (0);
	map_form[map->l] = 0;
	i = 0;
	map_form[i] = get_next_line(map->fd);
	i++;
	while (i < map->l)
	{
		map_form[i] = get_next_line(map->fd);
		if (check_map_width(map_form[i], map->w) == -1)
		{
			free_map(map, map_form);
			return (0);
		}
		i++;
	}
	return (map_form);
}

t_map	init_map(void *m_ptr, char *argv)
{
	t_map	map;
	int		i;

	i = 0;
	map.form = 0;
	map.mlx_ptr = m_ptr;
	map.win_ptr = 0;
	check_map_name(argv);
	map.path = ft_strjoin("./map/", argv);
	while (map.element[i])
	{
		map.element[i] = 0;
		i++;
	}
	map.l = get_map_length(map.path);
	map.w = get_map_width(map.path);
	map.fd = open(map.path, O_RDONLY);
	if (map.fd == -1)
	{
		perror("file open error");
		exit(1);
	}
	map.cur_p_i = -1;
	map.cur_p_j = -1;//이렇게 해도 되겠지?keyhook에서만 쓸거라?
	map.move = 0;
}

t_map	*map_main(void *mlx_ptr, char *argv)
{
	t_map	map;

	map = init_map(mlx_ptr, argv);
	map.form = read_map(&map);
	if (map.form == 0)
		exit(1);
	map_validate_main(&map);
	return (&map);
}