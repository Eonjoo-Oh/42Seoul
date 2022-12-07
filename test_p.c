#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	find_hexlen(long long num);
int write_hex(long long num);
int	print_pointer(va_list ap);
int	write_arg(const char *arg, va_list ap);
int	find_type(const char *arg, va_list ap);

int hex_len(long long num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int write_hex(long long num)
{
	char *hex;
	char str[32];
	int	len;
	int i;

	hex = "0123456789abcdef";
	len = hex_len(num);
	i = len - 1;
	while (i > -1)
	{
		str[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	i = 0;
	while (i < len)
	{
		write (1, &(str[i]), 1);
		i++;
	}
	return (len);
}

int	print_pointer(va_list ap)
{
	int			len;
	long long	temp;
	temp = va_arg(ap, long long);
	write (1, "0x", 2);
	len = write_hex(temp);
	return (len + 2);
}

int	write_arg(const char *arg, va_list ap)
{
	int	temp;
	int	len;

	len = 0;
	while (*arg)
	{
		if (*arg == '%')
		{
			arg++;
			temp = find_type(arg, ap);
			if (temp == 0)
				return (0);
			arg++;
			len += temp;
			continue ;
		}
		write(1, arg, 1);
		arg++;
		len++;
	}
	return (len);
}

int	find_type(const char *arg, va_list ap)
{
	int	len;

	len = 0;
	/*
    if (*arg == 'c')
		len = print_char(ap);
	else if (*arg == 's')
		len = print_str(ap);
        */
	if (*arg == 'p')
		len = print_pointer(ap);
	/*
    else if (*arg == 'd')
		len = print_decimal(ap);
	else if (*arg == 'i')
		len = print_integer(ap);
	else if (*arg == 'u')
		len = print_unsigned(ap);
	else if (*arg == 'x' || *arg == 'X')
		len = print_hexadecimal(ap);
        */
	else if (*arg == '%')
	{
		write (1, "%", 1);
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *arg, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, arg);
	len = write_arg(arg, ap);
	va_end(ap);
	if (len == 0)
		return (0);
	return (len);
}

int main(void)
{
	int origin_res;
	int my_res;
    //int a = 3;
    my_res = ft_printf("my     : %p\n", (void *)-123);
    origin_res = printf("origin : %p\n", (void *)-123);
	printf("origin_res : %d\n", origin_res);
	printf("my_res : %d\n", my_res);
}
