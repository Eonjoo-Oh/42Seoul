#include "so_long.h"

void	key_find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->form[i][j] == 'P')
			{
				map->p_pos[0] = i;
				map->p_pos[1] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

int	get_collector_num(t_map *map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (i < map->l)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->form[i][j] == 'C')
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

int	key_check_movable(t_map *map, int keycode)
{
	int	new_i;
	int	new_j;
	int collection[2];

	new_i = map->p_pos[0];
	new_j = map->p_pos[1];
	collection[0] = get_collector_num(map);
	collection[1] = 0;
	if (keycode == 13)//위(w)
		new_i -= 1;
	else if (keycode == 1)//아래(s)
		new_i += 1;
	else if (keycode == 2)//오(d)
		new_j += 1;
	else if (keycode == 0)//왼(a)
		new_j -= 1;
	if (new_i < 0 || new_i >= map->w || new_j < 0 || new_i >= map->l)
		return (-1);
	if (map->form[new_i][new_j] == '1')
		return (-1);
	else if (map->form[new_i][new_j] == 'C')
	{
		collection[1]++;
		map->form[map->p_pos[0]][map->p_pos[1]] = '0';
		map->form[new_i][new_j] = 'P';
		map->p_pos[0] = new_i;
		map->p_pos[1] = new_j;
	}
	else if (map->form[new_i][new_j] == 'E')
	{
		if (collection[0] == collection[1])
		{
			mlx_destroy_window(map->mlx_ptr, map->win_ptr);//창끄는게맞나?아니면 그냥 플레이어없애기?
			exit(0);
		}
	}
	else if (map->form[new_i][new_j] == '0')
	{
		map->form[map->p_pos[0]][map->p_pos[1]] = '0';
		map->form[new_i][new_j] = 'P';
		map->p_pos[0] = new_i;
		map->p_pos[1] = new_j;
	}
	return (1);
}
