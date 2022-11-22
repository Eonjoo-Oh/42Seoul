

char	*ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		dst = src;
		dst++;
		src++;
	}
	return (dst);
}
