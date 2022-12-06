/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:32:21 by eoh               #+#    #+#             */
/*   Updated: 2022/12/06 14:35:23 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
//#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_pointer(va_list ap);
int	print_decimal(va_list ap);
int print_integer(va_list ap);
int print_unsigned(va_list ap);
int print_hexadecimal(va_list ap);
int write_arg(const char *arg, va_list ap);
int	find_type(const char *arg, va_list ap);

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
	if (*arg == 'c')
		len = print_char(ap);
	else if (*arg == 's')
		len = print_str(ap);
	else if (*arg == 'p')
		len = print_pointer(ap);
	else if (*arg == 'd')
		len = print_decimal(ap);
	else if (*arg == 'i')
		len = print_integer(ap);
	else if (*arg == 'u')
		len = print_unsigned(ap);
	else if (*arg == 'x' || *arg == 'X')
		len = print_hexadecimal(ap);
	else if (*arg == '%')
		write (1, "%", 1);
		len = 1;
	return (len);
}
