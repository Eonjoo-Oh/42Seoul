/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:51:33 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 04:15:14 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->form[i][j] == 'P')
			{
				map->p_pos[0] = i;
				map->p_pos[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	get_collector_num(t_map *map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->form[i][j] == 'C')
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

int	get_new_i(int keycode, int i)
{
	int	new_i;

	new_i = i;
	if (keycode == 13)
		new_i -= 1;
	else if (keycode == 1)
		new_i += 1;
	return (new_i);
}

int	get_new_j(int keycode, int j)
{
	int	new_j;

	new_j = j;
	if (keycode == 2)
		new_j += 1;
	else if (keycode == 0)
		new_j -= 1;
	return (new_j);
}
