/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:49:59 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 04:22:39 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	queue_empty(t_queue *queue)
{
	if (queue->front == queue->rear)
		return (0);
	else
		return (1);
}

int	queue_full(t_queue *queue, t_map *map)
{
	if (queue->rear == map->l * map->w)
		return (0);
	else
		return (1);
}

void	dequeue(t_queue *queue)
{
	if (queue_empty(queue) == 0)
		return ;
	queue->front++;
}

void	enqueue(t_queue *queue, t_map *map, int i, int j)
{
	if (queue_full(queue, map) == 0)
		return ;
	queue->rear++;
	queue->bfs[queue->rear].i = i;
	queue->bfs[queue->rear].j = j;
}

t_queue	*init_queue(t_map *map)
{
	t_queue	*queue;
	t_bfs	*bfs;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	bfs = (t_bfs *)malloc(sizeof(t_queue) * (map->l * map->w));
	if (bfs == 0)
		return (0);
	queue->front = -1;
	queue->rear = -1;
	queue->col = 0;
	queue->exit = 0;
	queue->bfs = bfs;
	return (queue);
}
