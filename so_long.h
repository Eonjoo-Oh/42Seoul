/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:50 by eoh               #+#    #+#             */
/*   Updated: 2023/06/19 03:40:52 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

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

#endif