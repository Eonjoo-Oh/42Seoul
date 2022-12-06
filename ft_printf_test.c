/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:02:09 by eoh               #+#    #+#             */
/*   Updated: 2022/12/02 15:58:29 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    printf_c(const char *, )
int ft_printf(const char *arg, ...)
{
	va_list ap;
	va_start(ap, arg);
	len = init_print(ap, arg);
	va_end(ap);
	return(len);
}
printf("dsfsdf sdfsfs %d sfsfsdf", 10);
len = 0;
while(*arg)
{
	if(*arg == '%')
	{
		int tmp;
		arg++;
		if(*arg == 'd')
			tmp = print_demical(ap, arg);
			len += tmp;
	}
	else
	{
		write(1, arg, 1);
		len++;
		arg++;
	}
}
print_demical(va_list ap, char *arg)
{
	int num;
	char *buf;
	num = va_arg(ap, int);
	num -> len 
	buf = (char *)malloc(sizeof(char) * len + 1);
	
	arr[11]
	-
	num*-1
	word_len = write(1, buf, len);
	free(buf);
	return(word_len);
}

