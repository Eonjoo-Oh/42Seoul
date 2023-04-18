char	**arg_pipe(int fd)
{
	char	*temp_arg;
	char	*old_temp;
	char	*str;
	char	**arg;

	arg = 0;
	str = get_next_line(fd);
	while (str)
	{
		old_temp = temp_arg;
		temp_arg = strjoin(arg, str);
		free(old_temp);
		free(str);
		get_next_line(str);
	}
	if (temp_arg == 0)
		return (0);
	arg = ft_split(temp_arg, '\n');
	return (arg);
}
