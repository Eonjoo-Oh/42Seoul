/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:02:38 by eoh               #+#    #+#             */
/*   Updated: 2022/11/21 16:41:23 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (*str == c)
			return (str);
		i++;
		str++;
	}
	return (0);
}
