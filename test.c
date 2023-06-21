#include "so_long.h"

/*
int	main(void)
{
	void	*m_ptr;
	void	*w_ptr;
	t_img	img;


	m_ptr = mlx_init();
	w_ptr = mlx_new_window(m_ptr, 1200, 800, "test window");
	if (w_ptr == 0)
		return (0);
	//mlx_pixel_put(m_ptr, w_ptr, 250, 250, 0xFFFFFF);
	init_img(m_ptr, &img);
	//render_img(m_ptr, w_ptr, &img);
	mlx_loop(m_ptr);
	return (0);
}*/ //test basic window

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
} t_var;

int key_esc_test(int keycode, t_var *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 1 * 64, 1 * 64);
	}
	return (-1);
}

/*int	key_main(int keycode, t_var *vars)
{

}*/

int	main(void)
{
	void	*m_ptr;
	void	*w_ptr;
	t_var	vars;
	void	*img;
	void	*p_img;
	int		img_width = 64;
	int		img_height = 64;
	int		i = 0;
	int		j;
	char	map[5][13] = {
	{'1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'1','0','0','1','0','0','0','0','0','0','0','C','1'},
	{'1','0','0','0','0','1','1','1','1','1','0','0','1'},
	{'1','0','P','0','1','1','E','0','0','0','0','0','1'},
	{'1','1','1','1','1','1','1','1','1','1','1','1','1'}
	};

	m_ptr = mlx_init();
	w_ptr = mlx_new_window(m_ptr, 13 * img_width, 5 * img_height, "test window");
	if (w_ptr == 0)
		return (0);
	img = mlx_xpm_file_to_image(m_ptr, "./image/map.xpm", &img_width, &img_height);
	p_img = mlx_xpm_file_to_image(m_ptr, "./image/player.xpm", &img_width, &img_height);
	
	while (i < 5)
	{
		j = 0;
		while (j < 13)
		{
			mlx_put_image_to_window(m_ptr, w_ptr, img, j * 64, i * 64);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(m_ptr, w_ptr, p_img, j * 64, i * 64);
			j++;;
		}
		i++;
	}
	if (img == 0)
		return (0);
	vars.mlx = m_ptr;
	vars.win = w_ptr;
	vars.img = p_img;
	mlx_key_hook(vars.win, key_esc_test, &vars);
	mlx_loop(m_ptr);
	return (0);
} //test rendering image
//gcc -I ./mlx/opengl -c test.c
//gcc -L./mlx/opengl -lmlx -framework OpenGL -framework AppKit -o test test.o