/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:17:54 by eoh               #+#    #+#             */
/*   Updated: 2023/06/23 02:40:49 by eoh              ###   ########.fr       */
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
	}//방문했으면 1, 아니면 0을 반환
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
		x = queue->bfs[queue->front + 1].i;//p_pos가 아니라 현재 큐의 좌표에서가 되야됨
		y = queue->bfs[queue->front + 1].j;
		if (i == 0)
			x -= 1;//위
		else if (i == 1)
			x += 1;//아래
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
	//현재 포지션의p_pos 위아래오왼검사 1이아니면 queue에 넣기
}

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

int	bfs_main(t_map *map)
{
	t_queue	*q;
	int		x;
	int		y;//first position이 map->p_pos에 저장되어있지 않나?->이걸 구하는 함수 get_position

	q = init_queue(map);
	if (!q)
		error_msg("malloc error");
	get_position(map);
	enqueue(q, map, map->p_pos[0], map->p_pos[1]);
	while(queue_empty(q) != 0)
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
	//종료조건 exit1개, collector 갯수만큼 추가해줘야됨
}