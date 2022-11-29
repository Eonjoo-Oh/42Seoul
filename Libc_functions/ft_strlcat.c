/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:01:19 by eoh               #+#    #+#             */
/*   Updated: 2022/11/27 12:15:21 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	i = 0;
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	if (size <= dst_l)
		return (src_l + size);
	else
	{
		while (src[i] && (i + 1 + dst_l < size))
		{
			dst[dst_l + i] = src[i];
			i++;
		}
	}
	if (dst_l + i < size)
		dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
