/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/14 09:31:14 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*temp;
	int		cnt;
	size_t	i;
	size_t	j;

	i = 0;
	temp = (char *)big;
	while (i < len)
	{
		if (big[i] == *little)
		{
			cnt = 0;
			j = 0;
			while (little[j] != '\0')
			{
				if (big[i + j] != little[j])
					cnt++;
				j++;
			}
			if (cnt != 0)
			{
				*temp = big[i];
				return ((const char *)temp);
			}
			i++;
		}
	}
	return (0);
}

int main(void)
{
	const char *str = "abcdcde";
	const char *str2 = "cd";
	char *result = ft_strnstr(str, str2, 7);
	printf("%s\n", result);

	return (0);
}
