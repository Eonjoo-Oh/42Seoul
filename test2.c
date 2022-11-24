/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/24 21:35:36 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int get_size(int temp)
{
	int size;
	size = 0;

	if (temp < 0)
	{
		size = 1;
		temp *= -1;
	}
	while (temp > 0)
	{
		temp /= 10;
		size++;
	}
	return (size);
}

char *ft_itoa(int n)
{
	int size;
	int i;
	int temp;
	char *result;

	temp = n;
	size = get_size(temp);
	printf("size : %d\n", size);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	printf("n = %d\n", n);
	while (n > 0)
	{
		result[size - 1] = n % 10 + '0';
		printf("result[size - 1] : %c\n", result[size - 1]);
		n /= 10;
		i++;
	}
	result[size] = '\0';
	printf("n : %d\n", n);
	printf("result : %s", result);
	return (result);
}

int main(void)
{
	char *s1;
	int i = 12345;

	s1 = ft_itoa(i);
	printf("%s", s1);
	return (0);
}
