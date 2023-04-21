#include "pipex.h"

char	**get_path(char **envp)
{
	char	*temp_path;
	char	**path;
	int		i;

	temp_path = NULL;
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp_path = envp[i];
			break ;
		}
		i++;
	}
	if (temp_path == 0)
		return (0);
	temp_path += 5;
	path = (ft_split(temp_path, ':'));
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}
