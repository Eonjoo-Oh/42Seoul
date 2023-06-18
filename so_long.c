/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:59 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 03:39:24 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int main(int argc, char **argv);
{
	void	*mlx_ptr;
	t_map	*map;
	t_img	*img;

	if (argc != 2)
		exit(1);
	mlx_ptr = mlx_init();
	if (mlx_ptr == 0)
		exit(1);
	if (mlx_ptr == 0)
		exit(1);
	map = map_main(mlx_ptr, argv[1]);
	img = render_img_main(mlx_ptr, map);
	key_hook_main(map);
	mlx_loop(mlx_ptr);
}