#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*find_cmd(char **envp, char *cmd);
char	*find_envp(char **envp);

int		do_cmd(char *infile, char *cmd);
void	do_pipe(int temp_fd, char *cmd2, char *outfile);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcon(char *s1, char *s2);
int		ft_strlen(char *s);

#endif