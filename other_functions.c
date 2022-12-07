/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:41:14 by eoh               #+#    #+#             */
/*   Updated: 2022/12/07 17:25:28 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hex_len(unsigned long long num)
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

int write_hex(unsigned long long num, const char *arg)
{
	char *hex;
	char str[16];
	int	len;
	int i;

	hex = "0123456789abcdef";
	if (*arg == 'X')
		hex = "0123456789ABCDEF";
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

/*int write_big_hex(unsigned long long num)
{
	char *hex;
	char str[16];
	int	len;
	int i;

	hex = "0123456789ABCDEF";
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
*/
static int	print_n(int n)
{
	int		i;
	int		l;
	char	str[10];

	i = 0;
	l = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
		l++;
	}
	i = 1;
	while (i <= l)
	{
		write(1, &str[l - i], 1);
		i++;
	}
	return (l);
}

int	ft_putnbr(int n)
{
	int len;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		len = print_n(n);
		return (len + 1);
	}
	else
		len = print_n(n);
	return (len);
}

