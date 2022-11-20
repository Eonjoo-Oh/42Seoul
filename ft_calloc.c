/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:26:41 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:20:35 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (nmemb + 1));
	if (arr == 0)
		return (0);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
