/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:59 by eoh               #+#    #+#             */
/*   Updated: 2023/06/23 01:50:32 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	error_msg(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(0);
}*/

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	t_map	*map;
	t_img	*img;
	t_all	*all;

	if (argc != 2)
		error_msg("check the arguments");
	mlx_ptr = mlx_init();
	if (mlx_ptr == 0)
		error_msg("mlx init error");
	map = map_main(mlx_ptr, argv[1]);
	img = render_img_main(mlx_ptr, map);
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		error_msg("malloc error");
	all->map_all = map;
	all->img_all = img;
	mlx_key_hook(map->win_ptr, check_keycode, all);
	mlx_loop(mlx_ptr);
}