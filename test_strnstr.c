/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 13:20:56 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*find == '\0')
		return (src);
	if (src == 0 || len <= 0)
		return (0);
	while (i < len)
	{
		j = 0;
		while ((src[i + j] == find[j]) && i + j < len)
		{
			j++;
			if (find[j] == 0)
				return (&(src[i]));
		}
		i++;
	}
	return (0);
}

int	main(void)
{
		char *s1 = "oh no not the empty string !";
        char *s2 = "";
        size_t max = strlen(s1);
        char *i1 = strnstr(s1, s2, max);
        const char *i2 = ft_strnstr(s1, s2, max);
		
		printf("i1 : %s\n", i1);
		printf("i2: %s\n", i2);
}
