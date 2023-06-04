/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:58:23 by eoh               #+#    #+#             */
/*   Updated: 2023/06/04 23:39:13 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_arg{
	char	**argv;
	char	**path;
	char	**cmd;
	char	**cmd1;//bonus
	char	**cmd2;//bonus
	char	*cmd_path;
	char	*cmd1_path;//bonus
	char	*cmd2_path;//bonus
	char	*limiter;//bonus
	int		fd[2];
	int		argc;
	int		order;
	int		infile_fd;
	int		outfile_fd;
	int		temp_fd;//bonus

}t_arg;

t_arg	init_arg(t_arg *arg, int argc, char **argv, char **envp);
void	get_path(char	**envp, t_arg *arg);
void	add_slash(t_arg *arg);//path = 을 구하고 slash 붙이는 작업
char	*get_cmd_path(t_arg *arg, char *cmd); //cmd의 경로를 구하는 작업
char	**get_cmd(char *cmd); //cmd를 이차원배열로 만들어주는 작업
void	find_order(t_arg *arg);//명령어 순서에따라 처리과정이 달라 순서먼저 구해줌
void	do_first(t_arg *arg);
void	do_last(t_arg *arg);

//utils
char	**ft_split(char const *s, char c);
//static char	**free_result(char **s);
//static size_t	count_word(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);//여기까지 split
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strlen(char *s);

#endif