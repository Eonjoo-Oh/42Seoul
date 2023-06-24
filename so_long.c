/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:59 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 13:14:17 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_all *all)
{
	free_all(all);
	exit(0);
	return (1);
}

void	perror_msg(void)
{
	perror(NULL);
	exit(1);
}

void	error_msg(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(1);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	t_map	*map;
	t_img	*img;
	t_all	*all;
	
	if (argc != 2)
		error_msg("check the arguments");
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (0);
	mlx_ptr = mlx_init();
	if (mlx_ptr == 0)
		error_msg("mlx init error");
	map = map_main(mlx_ptr, argv[1], all);
	img = render_img_main(map);
	all->map_all = map;
	all->img_all = img;
	mlx_key_hook(map->win_ptr, check_keycode, all);
	mlx_hook(map->win_ptr, 17, 0, exit_game, all);
	mlx_loop(mlx_ptr);
	system("leaks so_long");
}
