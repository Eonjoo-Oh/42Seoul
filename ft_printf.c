/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:32:21 by eoh               #+#    #+#             */
/*   Updated: 2022/12/02 15:36:40 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *arg, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, arg);
	write_arg(arg, ap);
	va_end(ap);
	return (len);
}

void	write_arg(char *arg, va_list ap)
{
	while (*arg)
	{
		if (*arg == %)
		{
			find_type(arg++, ap);
			arg++;//arg+2를해야하는지? 위에 arg++해서 이미 값이 바꼈을지?
			continue ;
		}
		write(1, arg, 1);
		arg++;
	}
}

int	find_type(char *arg, va_list ap)
{
	if (*arg == 'c')
		print_char(ap);
	else if (*arg == 's')
		print_str(ap);
	else if (*arg == 'p')
		print_pointer(ap);
	else if (*arg == 'd')
		print_decimal(ap);
	else if (*arg == 'i')
		print_integer(ap);
	else if (*arg == 'u')
		print_unsigned(ap);
	else if (*arg == 'x')
		print_hexadecimal(ap);
	else if (*arg == 'X')
		print_heXadecimal(ap);
	else if (*arg == '%')
		printf_percent(ap);
	else
		return (0);
	return (1);
	/*
	잘못된 값이 들어왔을때 오류처리를 해주고 싶었음. 근데 어떻게?
	몇개비슷한 함수들을 하나로 합칠수없을까?
	*/
}
