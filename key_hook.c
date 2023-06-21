/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:19:10 by eoh               #+#    #+#             */
/*   Updated: 2023/06/22 04:59:55 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_esc(int keycode, t_all *all)
{
	t_map	*map;

	map = all->map_all;
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (-1);
}

int	key_w(int keycode, t_all *all)
{
	t_map	*map;

	if (keycode == 13)
	{
		map = all->map_all;
		key_find_player(map);
		printf("%d, %d\n", map->p_pos[0], map->p_pos[1]);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		printf("%d, %d ->", map->cur_p_i, map->cur_p_j);
		printf("%d, %d\n", map->cur_p_i, map->cur_p_j);
		/*map->form[map->p_pos[0]][map->p_pos[1]] = '0';
		map->form[map->cur_p_i][map->cur_p_i] = 'P';
		map->p_pos[0] = map->cur_p_i;
		map->p_pos[1] = map->cur_p_j;*/
		//mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img(map->mlx_ptr, map->win_ptr, all->img_all, map);
		map->move++;
		ft_printf("numbers of movement : %d\n", map->move);//ftprintf 가져와야됨
		//display 
	}
	return (1);
}

int	key_s(int keycode, t_map *map)
{
	if (keycode == 1)
	{
		if (map->cur_p_i == -1 && map->cur_p_j == -1)
			key_find_player(map);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);
	}
	return (1);
}

int	key_d(int keycode, t_map *map)
{
	if (keycode == 2)
	{
		key_find_player(map);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);
	}
	return (1);
}

int	key_a(int keycode, t_map *map)
{
	if (keycode == 0)
	{
		key_find_player(map);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);
	}
	return (1);
}

int	check_keycode(int keycode, t_all *all)
{
	if (keycode == 53)
		key_esc(keycode, all);
	else if (keycode == 13)
		key_w(keycode, all);
	// else if (keycode == 1)
	// 	key_s(keycode, map);
	// else if (keycode == 2)
	// 	key_d(keycode, map);
	// else if (keycode == 0)
	// 	key_a(keycode, map);
	return (1);
}