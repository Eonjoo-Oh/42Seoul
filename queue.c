#include "so_long.h"

void	init_queue(t_queue *queue)
{
	t_queue queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return ;
	queue->front = 0;
	queue->rear = 0;
	queue->visited = 0;
	queue->collector = 0;
	queue->exit = 0;
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