/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:15:49 by eoh               #+#    #+#             */
/*   Updated: 2023/06/18 00:59:07 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->form[i])
	{
		j = 0;
		while (map->form[j])
		{
			if (map->form[j] == 'C')
			{
				map->c_pos[0] = i;
				map->c_pos[1] = j;
			}
			else if (map->form[j] == 'E')
			{
				map->e_pos[0] = i;
				map->e_pos[1] = j;
			}
			else if (map->form[j] == 'P')
			{
				map->p_pos[0] = i;
				map->p_pos[1] = j;
			}
		}
	}
}

void	check_wall(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (map->form[i])
	{
		line = map->form[i];
		if (i == 0 || i == map->l - 1)
		{
			j = 0;
			while (line[j])
			{
				if (line[j] != '1')
					exit(1);
				j++;
			}
		}
		else
		{
			if (line[0] != '1' || line[map->w - 1] != '1')
				exit(1);
		}
		i++;
	}
}

void	check_element_num(int *element)
{
	int	i;

	i = 0;
	while (element[i])
	{
		if (element[i] == 0)
			exit(1);
		i++;
	}
}//플레이어가 여러명이거나 출구가 여러 개이면?

void	check_element(t_map *map)
{
	int		i;
	int		j;
	char	*line;
	
	i = 0;
	while (map->form[i])
	{
		line = map->form[i];
		j = 0;
		while (line[j])
		{
			if (line[j] != '0' && line[j] != '1' && line[j] = 'C' && line[j] != 'E' && line[j] != 'P')
				exit(1);
			j++;
			if (line[j] == 'C')
				map->element[COLLECTOR]++;
			else if (line[j] == 'E')
				map->element[EXIT]++;
			else if (line[j] == 'P')
				map->element[PLAYERS]++;
		}
		i++;
	}
}

void	map_validate_main(t_map *map)
{
	check_element(map);
	check_element_num(map->element);
	check_wall(map);
	if (check_bfs(map) == -1);//막혀있지 않은지 검사하는 함수
		exit(1);
}