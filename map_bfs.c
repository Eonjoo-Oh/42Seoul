/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:15:16 by eoh               #+#    #+#             */
/*   Updated: 2023/06/18 00:58:38 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_queue(t_queue *queue)
{
	t_bfs	*temp;

	while (queue->front != NULL)
	{
		temp = queue->front->next;
		free(queue->front);
		queue->front = temp;
	}
	free(queue);
}

void	init_queue(t_queue *queue)
{
	t_queue queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->front = 0;
	queue->rear = 0;
	queue->visited = 0;
	queue->collector = 0;
	queue->exit = 0;
}

void	init_cur_pos(t_bfs *cur_pos, t_map *map)
{
	cur_pos = (t_bfs *)malloc(sizeof(cur_pos));
	if (!cur_pos)
		return (0);
	cur_pos->i = map->p_pos[0];
	cur_pos->i = map->p_pos[1];
	cur_pos->next = 0;
}

void	mark_visited(t_queue *queue)
{
	t_visited	*now_visit;
	t_visited	*temp;
	
	now_visit->i = queue->rear->i;
	now_visit->j = queue->rear->j;
	now_visit->next = NULL;
	if(queue->visited == 0)
		queue->visited = now_visit;
	else
	{
		temp = queue->visited;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = now_visit;
	}
}

void	enqueue(t_queue *queue, t_bfs *pos)
{
	if (queue->front == 0)
	{
		queue->front = pos;
		queue->rear = pos;
	}
	else
	{
		queue->rear->next = pos;
		queue->rear = pos;
	}
	mark_visited(queue);
}

void	dequeue(t_queue *queue)
{
	t_bfs	*temp;

	temp = queue->front->next;
	free(queue->front);
	queue->front = temp;
}

int	check_visited(t_queue *queue, int i, int j)
{
	t_visited *temp;

	temp = queue->visited;
	while (temp != NULL)
	{
		if (temp->i == i && temp->j == j)
			return (-1);
		temp = temp->next;
		return (1);
	}
}

int	check_movable(t_map *map, int i, int j)
{
	if (i < map->w && j < map->l && map->form[i][j] != "1")
		return (1);
	return (-1);
}

t_bfs	*get_next_pos(int num, t_bfs *cur_pos, t_queue *q, t_map *map)
{
	int		i;
	int		j;
	t_bfs	*next_pos;

	i = cur_pos->i;
	j = cur_pos->j;
	if (num == 0)
		i -= 1;
	else if (num == 1)
	{
		i += 1;
		j += 1;
	}
	else if (num == 2)
		j -= 1;
	else if (num == 3)
		i -= 1;
	if (check_movable(map, i, j) == -1 || check_visited(q, i, j) == -1)
		return (0);
	next_pos = (t_bfs *)malloc(sizeof(t_bfs));
	if (!next_pos)
		return (0);
	next_pos->i = i;
	next_pos->j = j;
	next_pos->next = NULL;
	return (next_pos);
}//위 아래 오 왼 순서

int	check_bfs(t_map *map)
{
	t_queue	q;
	t_bfs	*cur_pos;
	t_bfs	*next_pos;
	int		num;

	init_queue(&q);
	init_cur_pos(cur_pos, map);
	enqueue(&q, cur_pos);
	while (q.front != 0)
	{
		dequeue(&q);
		if (q.front->i == map->c_pos[0] && q.front->j == map->c_pos[1])
			q.collector++;
		if (q.front->i == map->e_pos[0] && q.front->j == map->e_pos[1])
			q.exit++;
		if (q.collector > 0 && q.exit > 0)
		{
			free_queue(&q);
			return (1);
		}
		num = 0;
		while (num < 4)
		{
			next_pos = get_next_pos(num, cur_pos, &q, map);
			if (next_pos != 0)
				enqueue(&q, next_pos);
			num++;
		}
	}
	return (-1);
}