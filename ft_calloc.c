/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:26:41 by eoh               #+#    #+#             */
/*   Updated: 2022/11/21 17:27:34 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = (void *)malloc(nmemb * size);
	if (arr == 0)
		return (0);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}
