/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:41:57 by eoh               #+#    #+#             */
/*   Updated: 2023/06/12 13:28:36 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_arg{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	int		fd[2];
	int		infile_fd;
	int		outfile_fd;
}	t_arg;

void	init_arg(t_arg *arg, char **argv, char **envp);
char	**get_cmd(char *cmd);
char	*get_cmd_path(t_arg *arg, int n);
char	**add_slash(char **path);
char	**get_path(char **envp);
void	do_cmd(t_arg *arg);
void	do_pid1(t_arg *arg);
void	do_pid2(t_arg *arg);
void	print_error(char *message);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *str, int start, int end);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char *s, char c);
char	**do_split(char *s, char **result, char c);
char	*when_charset(char	**s, char c);
int		count_quote(char *s, int i);
char	*split_quote(char *s);
char	*when_quote(char	**s);

//free
void	free_dimension(char **arg);
void	free_arg(t_arg *arg);

#endif