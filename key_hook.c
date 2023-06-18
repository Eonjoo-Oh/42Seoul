/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:19:10 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 03:45:46 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_esc(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (-1);
}

int	key_w(int keycode, t_map *map)
{
	if (keycode == 13)
	{
		key_find_player(map, keycode);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);//ftprintf 가져와야됨
		//display 
	}
}

int	key_s(int keycode, t_map *map)
{
	if (keycode == 1)
	{
		if (map->cur_p_i == -1 && map->cur_p_j == -1)
			key_find_player(map, keycode);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);
	}
}

int	key_d(int keycode, t_map *map)
{
	if (keycode == 2)
	{
		key_find_player(map, keycode);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);
	}
}

int	key_a(int keycode, t_map *map)
{
	if (keycode == 0)
	{
		key_find_player(map, keycode);
		if (key_check_movable(map, keycode) == -1)
			return (0);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		render_img_main(map->mlx_ptr, map);
		map->move++;
		ft_printf("number of movement : %d\n", map->move);
	}
}

void	key_hook_main(t_map *map)
{
	mlx_key_hook(map->win_ptr, key_esc, map);
	mlx_key_hook(map->win_ptr, key_w, map);
	mlx_key_hook(map->win_ptr, key_s, map);
	mlx_key_hook(map->win_ptr, key_d, map);
	mlx_key_hook(map->win_ptr, key_a, map);
}