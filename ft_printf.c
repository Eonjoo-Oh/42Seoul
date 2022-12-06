/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:32:21 by eoh               #+#    #+#             */
/*   Updated: 2022/12/06 12:09:34 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *arg, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, arg);
	len = write_arg(arg, ap);
	if (len == 0)
		return (0);
	va_end(ap);
	return (len);
}

int	write_arg(char *arg, va_list ap)
{
	int	temp;
	int	len;

	len = 0;
	while (*arg)
	{
		if (*arg == %)
		{
			temp = find_type(arg++, ap);
			if (temp == 0)
				return (0);
			arg++;//arg+2를해야하는지? 위에 arg++해서 이미 값이 바꼈을지?
			len += temp;
			continue ;
		}
		write(1, arg, 1);
		arg++;
		len++;
	}
	return (len);
}

int	find_type(char *arg, va_list ap)
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
	/*
	잘못된 값이 들어왔을때 오류처리를 해주고 싶었음. 근데 어떻게?
	-> 길이를 반환하고 길이가ㅏ 0인 경우는 잘못된 값이 들어온 경우이다.
	몇개비슷한 함수들을 하나로 합칠수없을까? 
	-> hexadecimal 과 heXadecimal이 같이 동작해서 합쳤고 %는 va_arg로 ap를 밀어줄 필요가 없으므로 
	바로 작성 후 길이는 1 
	*/
}
