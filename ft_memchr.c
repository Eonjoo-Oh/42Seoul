/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:02:38 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:24:29 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	char a;
	char *str;

	str = (char *)s;
	i = 0;
	a = (char)c;
	while ((i < n) || (*str != 0))
	{
		if (*str == c)
			return (str);
	}
	return (0);
}
