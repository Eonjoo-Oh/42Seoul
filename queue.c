/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:49:59 by eoh               #+#    #+#             */
/*   Updated: 2023/06/23 02:51:15 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	queue_empty(t_queue *queue)
{
	if (queue->front == queue->rear)
		return (0);
	else
		return (1);
}//비어있으면 0을, 비어있지 않으면 1을 반환

int	queue_full(t_queue *queue, t_map *map)
{
	if (queue->rear == map->l * map->w)
		return (0);
	else
		return (1);
}//꽉 차있으면 0을 꽉 차있지 않으면 1을 반환

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
	queue->bfs[queue->rear].visited = 1;//필요한지 다시 생각해보기. enqueue하는 순간 방문 했다는 의미니까 필요가 없을 수도..?
}//이렇게하지말고 int i, int j로 받아와야됨

t_queue	*init_queue (t_map *map)
{
	t_queue	*queue;
	t_bfs	*bfs;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	bfs = (t_bfs *)malloc(sizeof(t_queue) * (map->l * map->w));
	if (bfs == 0)
		return (0);//bfs안에 값을 다 초기화하고 싶은데 어떻게 하지? 그리고 이미 방문한 건 앞에서 조회가능하니 visited는 필요없나?
	queue->front = -1;
	queue->rear = -1;
	queue->col = 0;
	queue->exit = 0;
	queue->bfs = bfs;
	return (queue);
}
