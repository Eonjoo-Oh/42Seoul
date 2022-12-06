/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:18:34 by eoh               #+#    #+#             */
/*   Updated: 2022/12/06 12:09:17 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int print_unsigned(va_list ap)
{
    int             len;
    unsigned int    temp;
    char            *result;

    len = 0;
    temp = va_arg(ap, unsigned int);
    result = ft_atoi((int)temp);
    while (result[len])
	{
		write(1, &(result[len]), 1);
		len++;
	}
	return (len);
}

int print_hexadecimal(va_list ap)
{
    char temp;
    char *hexa;

    hexa = "0123456789abcdef";
    temp = va_arg(ap, char);
    write (1, &(hexa[temp/16]), 1);
    write (1, &(hexa[temp%16]), 1);
    return (2);
}

int print_percent(va_list ap);
{
    write(1, "%", 1);
    return (1);
    //%는 va_arg로 인자를 밀어주지 않는다
}