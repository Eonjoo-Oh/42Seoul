/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:58:15 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 10:40:09 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*s_str;
	size_t			i;

	s_str = (const char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = s_str[i];
		i++;
	}
	return (dest);
}
