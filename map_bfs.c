#include "so_long.h"

typedef struct s_bfs {
	int	i;
	int	j;
	int	visited;
}	t_bfs;

typedef struct s_queue {
	int				front;
	int				rear;
	struct s_bfs	*bfs;
}	t_queue;

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
		return (0);
	queue->front++;
}
void	enqueue(t_queue *queue, t_map *map, int i, int j)
{
	if (queue_full(queue, map) == 0)
		return (0);
	queue->rear++;
	queue->bfs[queue->rear].i = map->p_pos[0];
	queue->bfs[queue->rear].j = map->p_pos[1];
	queue->bfs[queue->rear].visited = 1;//필요한지 다시 생각해보기. enqueue하는 순간 방문 했다는 의미니까 필요가 없을 수도..?
}//이렇게하지말고 int i, int j로 받아와야됨

void	enqueue_unvisited(t_queue *queue, t_map, *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = map->p_pos[0];
	y = map->p_pos[1];
	while (i < 4)
	{
		if (i == 0)
			x -= 1;//위
		else if (i == 1)
			x += 1;//아래
		else if (i == 2)
			y += 1;
		else
			y -= 1;
		if (x > 0 && y > 0 && map->form[x][y] != 'C')
		{

		}

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
	enqueue(q, map);
	while(queue_empty(q) != 0)
	{
		enqueue_unvisited(q, map);
		dequeue(q);
	}
	

}