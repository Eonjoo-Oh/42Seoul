/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:50 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 11:44:37 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/opengl/mlx.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define COLLECTOR 0
# define EXIT 1
# define PLAYERS 2

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
	int		cur_p_i;
	int		cur_p_j;
	int		move;
	int		collected;
}	t_map;

typedef struct s_visited{
	int					i;
	int					j;
	struct s_visited	*next;
}	t_visited;

typedef struct s_bfs {
	int	i;
	int	j;
}	t_bfs;

typedef struct s_queue {
	int				front;
	int				rear;
	int				col;
	int				exit;
	struct s_bfs	*bfs;
}	t_queue;

typedef struct s_img {
	void	*player;
	void	*map;
	void	*wall;
	void	*collector;
	void	*exit;
	int		size;
}	t_img;

typedef struct s_all {
	t_map	*map_all;
	t_img	*img_all;
	t_queue	*queue;
}	t_all;

t_map	*map_main(void *mlx_ptr, char *argv, t_all *all);
t_map	*init_map(void *m_ptr, char *argv);
char	**read_map(t_map *map);
void	free_map(t_map *map);

void	check_map_name(char *name, t_map *map);
void	get_map_length(char *name, t_map *map);
int		get_map_width(char *str);
void	get_map_length(char *name, t_map *map);

void	map_validate_main(t_map *map, t_all *all);
void	check_element(t_map *map);
void	check_element_num(t_map *map);
void	check_wall(t_map *map);
void	get_position(t_map *map);
void	free_check_element(t_map *map, char *msg);
void	check_map_size(t_map *map);

int		bfs_main(t_map *map, t_all *all);
t_queue	*init_queue(t_map *map);
void	enqueue_unvisited(t_queue *queue, t_map *map);
int		check_visited(t_queue *queue, int x, int y);

void	enqueue(t_queue *queue, t_map *map, int i, int j);
void	dequeue(t_queue *queue);
int		queue_full(t_queue *queue, t_map *map);
int		queue_empty(t_queue *queue);

int		rev_strncmp(char *s1, char *s2, int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_msg(char *message);
void	perror_msg(void);

t_img	*render_img_main(t_map *map);
void	render_img(void *mlx, void *win, t_img *img, t_map *map);
void	init_img(void *mlx, t_img *img);

int		check_keycode(int keycode, t_all *all);
int		key_esc(int keycode, t_all *all);
int		key_w(int keycode, t_all *all);
int		key_s(int keycode, t_all *all);
int		key_d(int keycode, t_all *all);
int		key_a(int keycode, t_all *all);

void	key_find_player(t_map *map);
int		get_collector_num(t_map *map);
int		key_check_movable(t_map *map, int keycode, t_all *all);
void	movable_exit_game(t_map *map, t_all *all);
int		exit_game(t_all *all);
void	free_all(t_all *all);
void	if_movable(char c, t_map *map, int new_i, int new_j);
int		get_new_j(int keycode, int j);
int		get_new_i(int keycode, int i);

#endif