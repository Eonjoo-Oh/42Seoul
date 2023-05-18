#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_arg{

	char	**argv;
	int		argc;
	char	**path;
	char	**cmd_path;
	char	**cmd;
	int		infile_fd;
	int		outfile_fd;
	int		cmd_i;
	int		fd[2];

} t_arg;

char	**get_cmd(char **argv, int argc);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	**get_path(char **envp);
char	**get_cmd_path(int argc, char **argv, t_arg arg);
int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

# endif