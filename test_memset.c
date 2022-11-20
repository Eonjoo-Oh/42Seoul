/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/10 16:25:05 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;
	size_t i;

	i = 0;
	str = s;
	if (c >= 32 && c <= 126)
	{
		while (i < n)
		{
			str[i] = c;
			i++;  
		}
		return (s);
	}
	return (0);
}

int main(void)
{
	char arr[6] = "123456";
	ft_memset(arr, 'c', 4 * sizeof(char));
	printf("%s", arr);

	return (0);
}

