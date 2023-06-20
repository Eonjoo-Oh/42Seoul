#include "so_long.h"

t_queue *init_queue(void)
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->front = 0;
	queue->rear = 0;
	queue->visited = 0;
	queue->collector = 0;
	queue->exit = 0;
	return (queue);
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
	mark_visited(queue);//여기서뭔가 문제. enqueue부터 보기
}

void	dequeue(t_queue *queue)
{
	t_bfs	*temp;

	if (queue->front == NULL)
		return ;
	temp = queue->front->next;
	free(queue->front);
	queue->front = temp;
}

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

//queue empty 
//queue front->NULL
//dummy