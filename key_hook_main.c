/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:40:03 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 04:15:30 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_movable(char c, t_map *map, int new_i, int new_j)
{
	if (c == 'C')
	{
		map->collected++;
		map->form[map->p_pos[0]][map->p_pos[1]] = '0';
		map->form[new_i][new_j] = 'P';
		map->p_pos[0] = new_i;
		map->p_pos[1] = new_j;
		map->move++;
		ft_printf("numbers of movement : %d\n", map->move);
	}
	else if (c == '0')
	{
		map->form[map->p_pos[0]][map->p_pos[1]] = '0';
		map->form[new_i][new_j] = 'P';
		map->p_pos[0] = new_i;
		map->p_pos[1] = new_j;
		map->move++;
		ft_printf("numbers of movement : %d\n", map->move);
	}
}

int	key_check_movable(t_map *map, int keycode)
{
	int	i;
	int	j;
	int	collection[2];

	i = map->p_pos[0];
	j = map->p_pos[1];
	collection[0] = get_collector_num(map);
	collection[1] = 0;
	i = get_new_i(keycode, i);
	j = get_new_j(keycode, j);
	if (i < 0 || i >= map->w || j < 0 || i >= map->l || map->form[i][j] == 1)
		return (-1);
	else if (map->form[i][j] == 'C' || map->form[i][j] == '0')
		if_movable(map->form[i][j], map, i, j);
	else if (map->form[i][j] == 'E')
	{
		if (map->collected == map->element[COLLECTOR])
		{
			map->move++;
			ft_printf("numbers of movement : %d\n", map->move);
			mlx_destroy_window(map->mlx_ptr, map->win_ptr);
			exit(0);
		}
	}
	return (1);
}

int	check_keycode(int keycode, t_all *all)
{
	if (keycode == 53)
		key_esc(keycode, all);
	if (keycode == 13)
		key_w(keycode, all);
	if (keycode == 1)
		key_s(keycode, all);
	else if (keycode == 2)
		key_d(keycode, all);
	else if (keycode == 0)
		key_a(keycode, all);
	return (1);
}
