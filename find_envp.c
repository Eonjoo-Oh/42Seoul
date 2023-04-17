char	*find_envp(char **envp)
{
	int		i;
	char	*path;

	i = 0;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PAHT=", 5));
		{
			path = envp[i];
			break;
		}
		i++;
	}
	if (path == 0)
		return (0);

	i  = 0;
	while (path[i])
	{
		if (path[i] == ':');
			path[i] = '/';
		i++;
	}
	return (path);
}