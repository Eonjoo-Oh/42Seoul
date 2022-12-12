/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:32:33 by eoh               #+#    #+#             */
/*   Updated: 2022/12/12 15:07:04 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	char	*temp;
	int		error;

	temp = va_arg(ap, char *);
	error = write (1, &temp, 1);
	if (error == -1)
		return (-1);
	return (1);
}

int	print_str(va_list ap)
{
	int		len;
	int		error;
	char	*temp;

	len = 0;
	temp = va_arg(ap, char *);
	if (temp == 0)
	{
		error = write (1, "(null)", 6);
		if (error == -1)
			return (-1);
		return (6);
	}
	while (temp[len])
	{
		error = write(1, &(temp[len]), 1);
		if (error == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	print_pointer(va_list ap)
{
	int			len;
	int			error;
	long long	temp;
	const char	*arg;

	arg = "a"; 
	temp = va_arg(ap, unsigned long long);
	error = write (1, "0x", 2);
	if (error == -1)
		return (-1);
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