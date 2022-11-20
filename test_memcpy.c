/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/12 16:05:25 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s_str;
	unsigned char	*d_str;
	size_t	i;

	d_str = dest;
	s_str = src;
	i = 0;
	while (i < n)
	{
		d_str[i] = s_str[i];
		i++;
	}
	return (d_str);
}

int main(void)
{
	char *str = "abcde";
	const char *str2 = "123";
	size_t size = 2;
	char *result;

	result = ft_memcpy(str, str2, size);

	printf("%s\n", result);

	return (0);
}
