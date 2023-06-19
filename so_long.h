/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:50 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 21:31:31 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

//# include "mlx.h"
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
	struct	s_visitied *visited;
	int		collector;
	int		exit;
}	t_queue;

typedef struct s_bfs {
	int	i;
	int	j;
	struct t_bfs *next;
}	t_bfs;

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
int	check_bfs(t_map *map);
void	init_cur_pos(t_bfs *cur_pos, t_map *map);
t_bfs	*get_next_pos(int num, t_bfs *cur_pos, t_queue *q, t_map *map);
void	get_position(t_map *map);
//queue
void	init_queue(t_queue *queue);
void	enqueue(t_queue *queue, t_bfs *pos);
void	dequeue(t_queue *queue);
void	free_queue(t_queue *queue);

//utils
int	rev_strncmp(char *s1, char *s2, int n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif