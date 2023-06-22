/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:19:10 by eoh               #+#    #+#             */
/*   Updated: 2023/06/23 03:26:44 by eoh              ###   ########.fr       */
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
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img(map->mlx_ptr, map->win_ptr, all->img_all, map);
		// map->move++;
		// ft_printf("numbers of movement : %d\n", map->move);
	}
	return (1);
}//안움직여질때는 printf안찍고싶음(exit일때)

int	key_s(int keycode, t_all *all)
{
	t_map	*map;

	if (keycode == 1)
	{
		map = all->map_all;
		key_find_player(map);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img(map->mlx_ptr, map->win_ptr, all->img_all, map);
		// map->move++;
		// ft_printf("numbers of movement : %d\n", map->move);
	}
	return (1);
}

int	key_d(int keycode, t_all *all)
{
	t_map	*map;

	if (keycode == 2)
	{
		map = all->map_all;
		key_find_player(map);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img(map->mlx_ptr, map->win_ptr, all->img_all, map);
		// map->move++;
		// ft_printf("numbers of movement : %d\n", map->move);
	}
	return (1);
}

int	key_a(int keycode, t_all *all)
{
	t_map	*map;

	if (keycode == 0)
	{
		map = all->map_all;
		key_find_player(map);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img(map->mlx_ptr, map->win_ptr, all->img_all, map);
		// map->move++;
		// ft_printf("numbers of movement : %d\n", map->move);
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