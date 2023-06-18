/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:02:04 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 03:44:01 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(void *mlx, t_img *img)
{
	img->size = 64;
	img->player = mlx_xpm_file_to_image(mlx, "./image/player.xpm", &(img->size), &(img->size));
	if (img->player == 0)
		exit(1);
	img->wall = mlx_xpm_file_to_image(mlx, "./image/wall.xpm", &(img->size), &(img->size));
	if (img->wall == 0)
		exit(1);
	img->map = mlx_xpm_file_to_image(mlx, "./image/map.xpm", &(img->size), &(img->size));
	if (img->map == 0)
		exit(1);
	img->collector = mlx_xpm_file_to_image(mlx, "./image/collector.xpm", &(img->size), &(img->size));
	if (img->collector == 0)
		exit(1);
	img->exit = mlx_xpm_file_to_image(mlx, "./image/exit.xpm", &(img->size), &(img->size));
	if (img->exit == 0)
		exit(1);
}

void	render_img(void *mlx, void *win, t_img *img, t_map *map)
{
	int	i;
	int	j;
	char **map;

	i = 0;
	while (map->form[i])
	{
		j = 0;
		while (map->form[i][j])
		{
			mlx_put_image_to_window(mlx, win, img->map, i * img->size, j * img->size);
			if (map->form[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img->wall, i * img->size, j * img->size);
			else if (map->form[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img->collector, i * img->size, j * img->size);
			else if (map->form[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img->exit, i * img->size, j * img->size);
			else if (map->form[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img->player, i * img->size, j * img->size);
			j++;
		}
		i++;
	}
}//만약 이게안돌아가면 i < length 이런식으로 넣어보기

void	render_img_main(void *mlx, t_map *map)//map안에 mlxptr들지 않음?
{
	t_img	*img;
	void	*w_ptr;

	init_img(mlx, &img);
	w_ptr = mlx_new_window(mlx, map->w * img->size, map->l * img->size, "so_long");
	map->win_ptr = w_ptr;
	if (w_ptr == 0)
		exit(1);
	render_img(mlx, w_ptr, &img, map);
}
//직접 xpm이미지 다운받아서 띄워보기->test로 해봤음*/