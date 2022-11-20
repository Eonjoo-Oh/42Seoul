/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:01:19 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:05:16 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_l;
	size_t src_l;
	size_t i;

	src_l = ft_strlen(src);
	while (dst[dst_l])
	{
		dst_l++;
	}
	i = 0;
	if (dst == 0 || size == 0)
		return (src_l);
	if (size < dst_l)
		return (src_l + size);
	else
	{
		while (src[i] && i + 1 < size)
		{
			dst[dst_l] = src[i];
			dst_l++;
			i++;
		}
	}
	dst[dst_l] = '\0';
	return (dst_l + src_l);
}
