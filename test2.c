/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 15:44:55 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_itoa(int n)
{
	int		cnt;
	int		temp;
	char	*result;

	cnt = 0;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		cnt++;
	}
	printf("cnt : %d\n", cnt);
	result = (char *)malloc(sizeof(char) * (cnt + 1));
	if (result == 0)
		return (0);
	result[cnt] = '\0';
	while (cnt - 1 >= 0)
	{
		result[cnt - 1] = n % 10;//왜 안들어가지?
		printf("n : %d\n", n % 10);
		printf("result[%d] : %c\n", cnt - 1, result[cnt - 1]);
		n /= 10;
		cnt--;
	}
	return (result);
}

int main(void)
{
	char *str = ft_itoa(321);
	printf("%s\n", str);

	return (0);
}
