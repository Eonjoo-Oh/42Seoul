#include "so_long.h"

/*typedef	struct s_visit {
	int	i;
	int	j;
}	t_visit;*/

typedef	struct s_bfs {
	int	i;
	int	j;
	int	visited;
}	t_bfs;

typedef struct s_queue {
	int	front;
	int	rear;
	t_bfs	*bfs;
}	t_queue;

void	enqueue(t_queue *q, int i, int j)
{
	if (q->bfs[0]->i == -1)
	{

	}//첫번째요소
}

t_queue	*init_queue(t_map *map)
{
	int		w;
	int		l;
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->front = 0;
	queue->rear = 0;
	//queue->bfs = 0;
	//queue->visited = 0;
	queue->bfs = (t_bfs *)malloc(sizeof(t_bfs) * (w * l));
	if (!queue->bfs)
		return (0);
	queue->bfs[0]->i = -1;
	queue->bfs[1]->j = -1;
	queue->bfs->visited = -1;

	return (queue);
}

int	check_bfs(t_map *map)
{
	t_queue	*q;

	q = init_queue(map);
	get_position(map);
	enqueue(q, map->p_pos[0], map->p_pos[1]);
}