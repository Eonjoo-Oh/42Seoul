char	*find_cmd(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	*res;

	i = 0;

	path = find_envp(envp);
	if (path == 0)
		return (0);
	res = strcon(path, cmd);

	return (res);
}