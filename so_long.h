/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:50 by eoh               #+#    #+#             */
/*   Updated: 2023/06/21 11:13:11 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

# include "mlx/opengl/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

#define COLLECTOR 0
#define EXIT 1
#define PLAYERS 2

typedef struct s_map{
	char	**form;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*path;
	int		element[3];
	int		l;
	int		w;
	int		fd;
	int		p_pos[2];
	int		c_pos[2];
	int		e_pos[2];
	int		cur_p_i;
	int		cur_p_j;
	int		move;
}	t_map;

typedef	struct s_visited{
	int	i;
	int	j;
	struct s_visited *next;
}	t_visited;

typedef struct s_queue {
	struct	s_bfs *front;
	struct	s_bfs *rear;
	struct	s_visited *visited;
	int		collector;
	int		exit;
}	t_queue;

typedef struct s_bfs {
	int	i;
	int	j;
	struct s_bfs *next;
}	t_bfs;

/*
typedef struct s_position
{
	int x;
	int y;
	int use;
} t_position;
t_position* arr = (t_position*)malloc(sizeof(t_position) * size);
arr[0].x = 10;
arr[0].y = 5;
arr[0].use = TRUE;
arr[1].x = 20;

구조체의 배열 array of struct

while(arr[i].use != FALSE)
{

}
*/

typedef struct s_img {
	void	*player;
	void	*map;
	void	*wall;
	void	*collector;
	void	*exit;
	int		size;
} t_img;

//map
t_map	*map_main(void *mlx_ptr, char *argv);
t_map *init_map(void *m_ptr, char *argv);
char	**read_map(t_map *map);
void	free_map(t_map *map, char **map_form);

//map_utils
void	check_map_name(char *name);
void	get_map_length(char *name, t_map *map);
int		get_map_width(char *str);
void	get_map_length(char *name, t_map *map);
//int		delete_n(char **res, t_map *map);

//map_validate
void	map_validate_main(t_map *map);
void	check_element(t_map *map);
void	check_element_num(int *element);
void	check_wall(t_map *map);

//bfs
int		check_bfs(t_map *map);
t_bfs	*init_cur_pos(t_map *map);
t_bfs	*get_next_pos(int num, t_bfs *cur_pos, t_queue *q, t_map *map);
void	get_position(t_map *map);
void	mark_visited(t_queue *queue, int i, int j);
//queue
t_queue	*init_queue(void);
void	enqueue(t_queue *queue, t_bfs *pos);
void	dequeue(t_queue *queue);
void	free_queue(t_queue *queue);

//utils
int	rev_strncmp(char *s1, char *s2, int n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif