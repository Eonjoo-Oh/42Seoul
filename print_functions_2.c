/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:18:34 by eoh               #+#    #+#             */
/*   Updated: 2022/12/07 17:27:30 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned(va_list ap)
{
	int				len;
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	len = ft_putnbr(temp);
	return (len);
}

int print_hexadecimal(va_list ap, const char *arg)
{
	unsigned long long	res;
	int 				len;

	res = va_arg(ap, unsigned long long);
	len = write_hex(res, arg);
	return (len);
}

/*int print_big_hex(va_list ap)
{
	unsigned long long	res;
	int 				len;

	res = va_arg(ap, unsigned long long);
	len = write_big_hex(res);
	return (len);
}*/