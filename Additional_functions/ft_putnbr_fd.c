/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:25:07 by eoh               #+#    #+#             */
/*   Updated: 2022/11/27 12:40:52 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_n(int n, int fd)
{
	int		i;
	int		l;
	char	str[10];

	i = 0;
	l = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
		l++;
	}
	i = 1;
	while (i <= l)
	{
		write(fd, &str[l - i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		print_n(n, fd);
	}
	else
		print_n(n, fd);
}
