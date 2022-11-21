/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:16 by eoh               #+#    #+#             */
/*   Updated: 2022/11/21 18:16:47 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		cnt;
	int		temp;
	char	*result;

	cnt = 0;
	if (n < 0)
	{
		cnt = 1;
		n *= -1;
	}
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		cnt++;
	}
	result = (char *)malloc(sizeof(char) * (cnt + 1));
	if (result == 0)
		return (0);
	result[cnt] = '\0';
	if (n < 0)
	{
		temp = 1;
		result[0] = '-';
	}
	while (temp < cnt)
	{
		result[temp] = n % 10;
		n /= 10;
		temp++;
	}
	return (result);
}
