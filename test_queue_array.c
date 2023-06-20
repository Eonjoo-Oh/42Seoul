#include stdlib.h

typedef struct s_queue {
	int	front;
	int	rear;

}t_queue;

typedef struct s_bfs {
	int	i;
	int	j;
}t_bfs;

t_bfs *bfs = (t_bfs*)malloc(sizeof(bfs) * (해상도 / 64));