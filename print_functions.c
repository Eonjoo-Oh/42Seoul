/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:32:33 by eoh               #+#    #+#             */
/*   Updated: 2022/12/07 18:52:01 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	char	*temp;

	temp = va_arg(ap, char *);
	write (1, &temp, 1);

	return (1);
}

int	print_str(va_list ap)
{
	int		len;
	char	*temp;

	len = 0;
	temp = va_arg(ap, char *);
	if (temp == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (temp[len])
	{
		write(1, &(temp[len]), 1);
		len++;
	}
	return (len);
}

int	print_pointer(va_list ap)
{
	int			len;
	long long	temp;
	const char	*arg;

	arg = "a"; 
	temp = va_arg(ap, unsigned long long);
	write (1, "0x", 2);
	len = write_hex(temp, arg);
	return (len + 2);
}

int	print_decimal(va_list ap)
{
	int				len;
	long long int	temp;

	temp = va_arg(ap, long long int);
	len = ft_putnbr((int)temp);
	return (len);
}

int print_integer(va_list ap)
{
	int		len;
	int		temp;

	temp = va_arg(ap, int);
	len = ft_putnbr(temp);
	return (len);
}