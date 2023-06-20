/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:15:16 by eoh               #+#    #+#             */
/*   Updated: 2023/06/20 18:55:01 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bfs	*init_cur_pos(t_map *map)
{
	t_bfs	*cur_pos;
	int		i;
	int		j;

	cur_pos = (t_bfs *)malloc(sizeof(cur_pos));
	if (!cur_pos)
		return (0);
	get_position(map);
	i = map->p_pos[0];//왜여기안들어감?
	j = map->p_pos[1];//맵에 p_pos언제 설정하지?
	cur_pos->i = i;
	cur_pos->j = j;
	cur_pos->next = 0;
	return (cur_pos);
}//왜 변수에 한번 넣으면 들어감?

void	mark_visited(t_queue *queue)
{
	t_visited	*now_visit;//선언다시해보기
	t_visited	*temp;
	int			i;
	int			j;
	
	//now_visit = 0;
	i = queue->rear->i;
	j = queue->rear->j;
	now_visit->i = i;
	now_visit->j = j;
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

int	check_visited(t_queue *queue, int i, int j)
{
	t_visited *temp;

	temp = queue->visited;
	while (temp != NULL)
	{
		if (temp->i == i && temp->j == j)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

int	check_movable(t_map *map, int i, int j)
{
	if (i < map->w && j < map->l && map->form[i][j] != '1')
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
	t_queue	*q;
	t_bfs	*cur_pos;
	t_bfs	*next_pos;
	int		num;

	cur_pos = 0;
	next_pos = 0;
	q = init_queue();
	cur_pos = init_cur_pos(map);
	enqueue(q, cur_pos);
	while (q->front != NULL)
	{
		dequeue(q);
		if (map->form[q->front->i][q->front->j] == 'C')
			q->collector++;
		if (map->form[q->front->i][q->front->j] == 'C')
			q->exit++;
		if (q->collector == map->element[COLLECTOR] && q->exit == 1)
		{
			free_queue(q);
			return (1);
		}
		num = 0;
		while (num < 4)
		{
			next_pos = get_next_pos(num, cur_pos, q, map);
			if (next_pos != 0)
				enqueue(q, next_pos);
			num++;
		}
	}
	return (-1);
}