#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_pipe{
	char	**path;
	char	*cmd1;
	char	*cmd2;
	int		infile_fd;
	int		outfile_fd;
	int		fd;
} t_pipe;

char	*get_cmd(char **path, char *cmd);
char	**get_path(char **envp);

int		do_cmd(char *infile, char *cmd);
void	do_pipe(int temp_fd, char *cmd2, char *outfile);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcon(char *s1, char *s2);
int		ft_strlen(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif