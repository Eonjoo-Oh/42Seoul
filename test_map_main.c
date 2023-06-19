#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	t_map	*map;
	int		i;

	if (argc < 0)
		return (0);
	mlx_ptr = 0;
	map = map_main(mlx_ptr, argv[1]);
	i = 0;
	printf("%d\n", map->l);
	while (map->form[i])
	{
		printf("%s", map->form[i]);
		i++;
	}
}
//gcc -g -I ./gnl test_map_main.c map_main.c utils.c map_utils.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
//gcc -g -I ./gnl test_map_main.c map_main.c utils.c map_utils.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c map_validate.c
//gcc -g -I ./gnl test_map_main.c map_main.c utils.c map_utils.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c map_validate.c map_bfs.c queue.c