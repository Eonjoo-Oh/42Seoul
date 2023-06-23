/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:17:54 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 04:19:25 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_visited(t_queue *queue, int x, int y)
{
	int	i;

	i = 0;
	if (queue->front == queue->rear)
		return (0);
	while (i <= queue->rear)
	{
		if (queue->bfs[i].i == x && queue->bfs[i].j == y)
			return (1);
		i++;
	}
	return (0);
}

void	enqueue_unvisited(t_queue *queue, t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < 4)
	{
		x = queue->bfs[queue->front + 1].i;
		y = queue->bfs[queue->front + 1].j;
		if (i == 0)
			x -= 1;
		else if (i == 1)
			x += 1;
		else if (i == 2)
			y += 1;
		else
			y -= 1;
		if (x >= 0 && y >= 0)
		{
			if (map->form[x][y] != '1' && check_visited(queue, x, y) == 0)
				enqueue(queue, map, x, y);
		}
		i++;
	}
}

int	bfs_main(t_map *map)
{
	t_queue	*q;

	q = init_queue(map);
	if (!q)
		error_msg("malloc error");
	get_position(map);
	enqueue(q, map, map->p_pos[0], map->p_pos[1]);
	while (queue_empty(q) != 0)
	{
		if (map->form[q->bfs[q->front + 1].i][q->bfs[q->front + 1].j] == 'C')
			q->col++;
		if (map->form[q->bfs[q->front + 1].i][q->bfs[q->front + 1].j] == 'E')
			q->exit++;
		if (q->col == map->element[COLLECTOR] && q->exit == map->element[EXIT])
			return (1);
		enqueue_unvisited(q, map);
		dequeue(q);
	}
	if (q->col == map->element[COLLECTOR] && q->exit == map->element[EXIT])
		return (1);
	return (-1);
}
