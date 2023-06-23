/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:19:10 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 03:38:10 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_esc(int keycode, t_all *all)
{
	t_map	*map;

	map = all->map_all;
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		free_all(all);
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
	}
	return (1);
}

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
	}
	return (1);
}
