/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:32:33 by eoh               #+#    #+#             */
/*   Updated: 2022/12/06 14:23:01 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_itoa(int n);

int	print_char(va_list ap)
{
	char	*temp;

	temp = va_arg(ap, char *);
	write (1, &temp, 1);

	return (1);//길이를 반환하게는 하는데 어디서 길이를 ft_prntf함수에 줄 수 있을까? 또 굳이 malloc 필요없을듯?
	/*
	len을 findtype 
	*/
}

int	print_str(va_list ap)
{
	int		len;
	char	*temp;

	len = 0;
	temp = va_arg(ap, char *);
	while (temp[len])
	{
		write(1, &(temp[len]), 1);
		len++;
	}
	return (len);
}

int	print_pointer(va_list ap)
{
	int		len;
	int		i;
	void	*temp;
	char	*result;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	len = 2;
	write (1, "0x", 2);
	temp = va_arg(ap, void *);
	result = (char *)temp;
	while (result[i])
	{
		write (1, &(hexa[result[i] / 16]), 1);
		write (1, &(hexa[result[i] % 16]), 1);
		len += 2;
		i++;
	}
	return (len);
}

int	print_decimal(va_list ap)
{
	int				len;
	long long int	temp;
	char			*result;

	len = 0;
	temp = va_arg(ap, long long int);
	result = ft_itoa((int)temp);
	while (result[len])
	{
		write(1, &(result[len]), 1);
		len++;
	}
	return (len);
}

int print_integer(va_list ap)
{
	int		len;
	int		temp;
	char	*result;

	len = 0;
	temp = va_arg(ap, int);
	result = ft_itoa(temp);
	while (result[len])
	{
		write(1, &(result[len]), 1);
		len++;
	}
	return (len);
}