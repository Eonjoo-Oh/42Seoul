/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:25:03 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:32:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*temp;
	int			cnt;
	size_t		i;
	size_t		j;

	while (i < len)
	{
		if (big[i] == *little)
		{
			cnt = 0;
			temp = big + i;//ㅇㅣ게 아마안될것임
			j = 0;
			while (little[j] != '\0')
			{
				if (big[i + j] != little[j])
					cnt++;
				j++;
			}
			if (cnt != 0)
				return (temp);
			i++;
		}
	}
	return (0);
}
