/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:02:04 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 03:35:59 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(void *mlx, t_img *img)
{
	img->size = 64;
	img->player = mlx_xpm_file_to_image(mlx, "player.xpm", &(img->size), \
	&(img->size));
	if (img->player == 0)
		error_msg("img error");
	img->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &(img->size), \
	&(img->size));
	if (img->wall == 0)
		error_msg("img error");
	img->map = mlx_xpm_file_to_image(mlx, "map.xpm", &(img->size), \
	&(img->size));
	if (img->map == 0)
		error_msg("img error");
	img->collector = mlx_xpm_file_to_image(mlx, "collector.xpm", \
	&(img->size), &(img->size));
	if (img->collector == 0)
		error_msg("img error");
	img->exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &(img->size), \
	&(img->size));
	if (img->exit == 0)
		error_msg("img error");
}

void	render_img(void *mlx, void *win, t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->w)
		{
			mlx_put_image_to_window(mlx, win, img->map, j * 64, i * 64);
			if (map->form[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img->wall, j * 64, i * 64);
			else if (map->form[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img->collector, \
				j * 64, i * 64);
			else if (map->form[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img->exit, j * 64, i * 64);
			else if (map->form[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img->player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

t_img	*render_img_main(t_map *map)
{
	t_img	*img;
	void	*w_ptr;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (0);
	init_img(map->mlx_ptr, img);
	w_ptr = mlx_new_window(map->mlx_ptr, map->w * 64, map->l * 64, "so_long");
	map->win_ptr = w_ptr;
	if (w_ptr == 0)
		error_msg("mlx window error");
	render_img(map->mlx_ptr, w_ptr, img, map);
	return (img);
}
