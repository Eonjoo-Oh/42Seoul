#include <stdio.h>
#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char	*temp_path;
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp_path = envp[i];
			break ;
		}
		i++;
	}
	temp_path += 5;
	path = (ft_split(temp_path, ':'));
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	i = 0;
	while(path[i])
	{
		printf("%s\n", path[i]);
		i++;
	}
	return (0);
}