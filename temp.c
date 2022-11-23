
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	unsigned char	*s_str;
	size_t			i;

	i = 0;
	d_str = (unsigned char *)dest;
	s_str = (unsigned char *)src;
	if (d_str < s_str)
	{
		while (i < n)
		{
			d_str[i] = s_str[i];
			i++;
		}
	}
	else
	{
		while (n - i > 0)
		{
			d_str[n - i - 1] = s_str[n - i - 1];
			i++;
		}
	}
	return (dest);
}
