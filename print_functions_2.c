/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:18:34 by eoh               #+#    #+#             */
/*   Updated: 2022/12/06 14:51:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

char	*ft_itoa(int n);

int print_unsigned(va_list ap)
{
	int		len;
	int		temp;
	char	*result;

	len = 0;
	temp = va_arg(ap, int);
	if (temp < 0)
		return (0);
	result = ft_itoa(temp);
	while (result[len])
	{
		write(1, &(result[len]), 1);
		len++;
	}
	return (len);
}

int print_hexadecimal(va_list ap)
{
	char    *temp;
	char	res;
	char    *hexa;

	hexa = "0123456789abcdef";
	temp = va_arg(ap, char *);
	res = (char)temp;
	write (1, &(hexa[res / 16]), 1);
	write (1, &(hexa[res % 16]), 1);
	return (2);
}