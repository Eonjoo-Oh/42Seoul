/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:16 by eoh               #+#    #+#             */
/*   Updated: 2022/12/07 12:46:03 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>

static int	n_size(long long int n)
{
	int	len;

	if (n == 0)
	{
		len = 1;
		return (len);
	}
	if (n < 0)
	{
		n *= -1;
		len = 1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	tmp;
	char		*result;

	tmp = n;
	len = n_size(tmp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	result[len] = '\0';
	if (tmp < 0)
	{
		tmp *= -1;
		result[0] = '-';
	}
	while (tmp != 0)
	{
		result[len - 1] = tmp % 10 + '0';
		tmp /= 10;
		len--;
	}
	if (n == 0)
		result[0] = '0';
	return (result);
}
