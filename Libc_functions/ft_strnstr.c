/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:25:03 by eoh               #+#    #+#             */
/*   Updated: 2022/11/27 12:53:38 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*find == '\0')
		return ((char *)src);
	if (*src == '\0' || len <= 0 || ft_strlen(src) < ft_strlen(find))
		return (0);
	while (src[i] && i < len)
	{
		j = 0;
		while (src[i + j] && (src[i + j] == find[j]) && i + j < len)
		{
			j++;
			if (find[j] == 0)
				return ((char *)&(src[i]));
		}
		i++;
	}
	return (0);
}
