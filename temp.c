void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*s_str;
	unsigned char	*d_str;
	size_t			i;

	if (dest == 0 || src == 0)
		return (NULL);
	d_str = dest;
	s_str = src;
	i = 0;
	while (i < n)
	{
		d_str[i] = s_str[i];
		i++;
	}
	return (dest);
}
