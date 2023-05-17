#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_arg{

	char	**cmd_path
	int		infile_fd;
	int		outfile_fd;
	int		num;
	int		fd[2];

} t_arg