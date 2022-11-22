/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:23:19 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 11:15:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	const char		*s_str;
	char			*tmp;
	size_t			i;

	d_str = (unsigned char *)dest;
	s_str = (const char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	ft_memcpy(tmp, src, n);
	while (i < n)
	{
		d_str[i] = tmp[i];
		i++;
	}
	return (dest);
}
