/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:59 by eoh               #+#    #+#             */
/*   Updated: 2023/06/21 23:29:15 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	t_map	*map;
	t_img	*img;
	t_all	*all;

	if (argc != 2)
		exit(1);
	mlx_ptr = mlx_init();
	if (mlx_ptr == 0)
		exit(1);
	map = map_main(mlx_ptr, argv[1]);
	//printf("%s\n", map->form[2]);
	img = render_img_main(mlx_ptr, map);
	if (img == 0)
		return (0);
	ft_printf("%s\n", "yeap!");
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (0);
	all->map_all = map;
	all->img_all = img;
	mlx_key_hook(map->win_ptr, check_keycode, all);
	mlx_loop(mlx_ptr);
}