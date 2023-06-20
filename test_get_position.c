#include "so_long.h"

void	get_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->form[i][j] == 'C')
			{
				map->c_pos[0] = i;
				map->c_pos[1] = j;
			}
			else if (map->form[i][j] == 'E')
			{
				map->e_pos[0] = i;
				map->e_pos[1] = j;
			}
			else if (map->form[i][j] == 'P')
			{
				map->p_pos[0] = i;
				map->p_pos[1] = j;
			}
			j++;
		}
		i++;
	}
}

int	main()
{
	char	map[5][13] = {
	{'1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'1','0','0','1','0','0','0','0','0','0','0','C','1'},
	{'1','0','0','0','0','1','1','1','1','1','0','0','1'},
	{'1','0','P','0','1','1','E','0','0','0','0','0','1'},
	{'1','1','1','1','1','1','1','1','1','1','1','1','1'}
	};
	t_map *new;

	new = (t_map *)malloc(sizeof(map) * 1);
	new->form = map;
	new->l = 5;
	new->w = 13;
	get_position(new);
	printf("%d, %d\n", new->c_pos[0], new->c_pos[1]);
}