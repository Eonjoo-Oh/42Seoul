#include "pipex.h"

char	*find_envp(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = 0;
	
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PAHT=", 5))
		{
			path = envp[i];
			break;
		}
		i++;
	}
	if (path == NULL)
		return (0);

	i  = 0;
	while (path[i])
	{
		if (path[i] == ':')
			path[i] = '/';
		i++;
	}//split을 쓴다고 하는데 왜 split을 써야하지?
	return (path);
}