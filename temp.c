
{
    t_list *new;
    t_list *node;

    new = (t_list *)(malloc)(sizeof(t_list));
    if (new == 0)
        return (0);
    while (lst != 0)
    {
        f(lst->content);
        new = lst;
        lst = lst->next;
    }
    return (new);
}
// del과 free는 언제 쓰이는 것?


----


int	get_size(int temp)
{
	int	size;

	size = 0;
	if (temp < 0)
	{
		size = 1;
		temp *= -1;
	}
	while (temp > 0)
	{
		temp /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	int		temp;
	char	*result;

	if (n == -2147483648)
		return (-2147483648);
	temp = n;
	size = get_size(temp);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	result[size] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result[size - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (result);
}

-----------

	if (n == 0)
	{
		zero = (char *)malloc(sizeof(char) * 2);
		zero[0] = '0';
		zero[1] = '\0';
		return (zero);
	}

	---
	void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	unsigned char	*s_str;
	size_t			i;

	i = -1;
	d_str = (unsigned char *)dest;
	s_str = (unsigned char *)src;
	if (d_str == 0 && s_str == 0)
		return (0);
	if (d_str < s_str)
	{
		while (++i < n)
			d_str[i] = s_str[i];
	}
	else
	{
		while (n - (++i) > 0)
			d_str[n - i - 1] = s_str[n - i - 1];
	}
	return (dest);
}