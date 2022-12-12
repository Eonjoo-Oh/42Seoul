/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:32:21 by eoh               #+#    #+#             */
/*   Updated: 2022/12/12 15:45:20 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, arg);
	len = write_arg(arg, ap);
	va_end(ap);
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
			if (temp == -1)
				return (-1);
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

	len = -1;
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
		len = print_hexadecimal(ap, arg);
	else if (*arg == '%')
	{
		write (1, "%", 1);
		len = 1;
	}
	return (len);
}

int main(void) {
	int a, b;

	a = printf("%u\n", -10);
	b = ft_printf("%u\n", -10);
	printf("a : %d, b : %d", a, b);

	return (0);
}
