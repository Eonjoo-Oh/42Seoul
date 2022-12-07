int	print_decimal(va_list ap)
{
	int				len;
	long long int	temp;
	char			*result;

	len = 0;
	temp = va_arg(ap, long long int);
	result = ft_putnbr((int)temp);
	while (result[len])
	{
		write(1, &(result[len]), 1);
		len++;
	}
	return (len);
}

int print_integer(va_list ap)
{
	int		len;
	int		temp;
	char	*result;

	len = 0;
	temp = va_arg(ap, int);
	result = ft_putnbr(temp);
	while (result[len])
	{
		write(1, &(result[len]), 1);
		len++;
	}
	return (len);
}