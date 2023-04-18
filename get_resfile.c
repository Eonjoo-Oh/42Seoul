const char	*get_resfile(char *filename)
{
	char	*path;
	const char	*result;

	path = "./";
	result = (const char *)ft_strjoin(path, filename);

	return (result);
}